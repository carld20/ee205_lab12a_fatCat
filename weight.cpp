///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file weight.cpp
/// @version 1.0
///
/// @author Carl Domingo <carld20@hawaii.edu>
/// @date   15_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <cstring>

#include "weight.h"

using namespace std;

#define FORMAT_LINE( className, member) cout << setw(8) << (className) << setw(20) << (member) << setw(52)

const float Weight::UNKNOWN_WEIGHT = -1;
const float Weight::KILOS_IN_POUND = 0.453592;
const float Weight::SLUGS_IN_POUND = 0.031081;
const string Weight::POUND_LABEL = "Pound";
const string Weight::KILO_LABEL = "Kilo";
const string Weight::SLUG_LABEL = "Slug";


//Weight conversions
float Weight::fromKiloToPound(float kilogram) noexcept {
    return kilogram / KILOS_IN_POUND;
}

float Weight::fromPoundToKilo(float pound) noexcept {
    return pound * KILOS_IN_POUND;
}

float Weight::fromSlugToPound(float slug) noexcept {
    return slug / SLUGS_IN_POUND;
}

float Weight::fromPoundToSlug(float pound) noexcept {
    return pound * SLUGS_IN_POUND;
}

float Weight::convertWeight(float fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit) {
    if( toUnit == POUND ){
        if( fromUnit == KILO ) {
            return fromKiloToPound(fromWeight);
        }
        if( fromUnit == SLUG ){
            return fromSlugToPound( fromWeight );
        }
    }
    if( toUnit == KILO ){
        if( fromUnit == POUND ){
            return fromPoundToKilo( fromWeight );
        }
        if( fromUnit == SLUG ){
            return fromPoundToKilo(fromSlugToPound( fromWeight ) );
        }
    }
    if( toUnit == SLUG ){
        if( fromUnit == POUND ){
            return fromPoundToSlug( fromWeight );
        }
        if( fromUnit == KILO ){
            return fromPoundToSlug(fromKiloToPound( fromWeight ) );
        }
    }
    throw logic_error("FatCat: Parameters are invalid");
}

bool Weight::isWeightValid( const float checkWeight ) const noexcept {
    if( checkWeight <= 0 && checkWeight > maxWeight ){
        throw invalid_argument( "FatCat: Weight has reached maxWeight or is not possible" );
        return false;
    }
    return true;
}

bool Weight::isWeightKnown() const noexcept {
    assert( validate () );
    return bIsKnown;
}

bool Weight::hasMaxWeight() const noexcept{
    assert( validate() );
    return bHasMax;
}

float Weight::getWeight() const noexcept {
    assert( validate () );
    if( !bIsKnown ){
        return UNKNOWN_WEIGHT;
    }
    return weight;
}

float Weight::getWeight( UnitOfWeight weightUnits ) const noexcept{
    assert( validate() );
    if( !bHasMax ){
        return UNKNOWN_WEIGHT;
    }
    return weight;
}

float Weight::getMaxWeight() const noexcept {
    if( !bHasMax ){
        return UNKNOWN_WEIGHT;
    }
    return maxWeight;
}

ostream& operator<<( ostream& lhs_stream, const Weight::UnitOfWeight rhs_UnitOfWeight ){
    switch( rhs_UnitOfWeight ) {
        case Weight::POUND:
            return lhs_stream << Weight::POUND_LABEL;
        case Weight::KILO:
            return lhs_stream << Weight::KILO_LABEL;
        case Weight::SLUG:
            return lhs_stream << Weight::SLUG_LABEL;
        default:
            throw out_of_range("FatCat: The unit can't be mapped to a string" );
    }
}

Weight::UnitOfWeight Weight::getWeightUnit() const noexcept {
    assert( validate () );
    return unitOfWeight;
}

Weight::Weight() noexcept{
    assert( validate() );
}

Weight::Weight( float newWeight ){
    setWeight( newWeight );
    assert( validate() );
}

Weight::Weight( const Weight::UnitOfWeight newUnitOfWeight ) noexcept{
    unitOfWeight = newUnitOfWeight;
    assert( validate() );
}

Weight::Weight( const float newWeight, const Weight::UnitOfWeight newUnitOfWeight ): Weight( newUnitOfWeight ){
    setWeight( newWeight, newUnitOfWeight );
    assert( validate() );

}

Weight::Weight( const float newWeight, const float newMaxWeight ){
    setWeight( newWeight );
    setMaxWeight( newMaxWeight );
    assert( validate() );
}

Weight::Weight( const Weight::UnitOfWeight newUnitOfWeight, const float newMaxWeight ):Weight ( newUnitOfWeight ){
    setMaxWeight( newMaxWeight );
    assert( validate() );
}

Weight::Weight( const float newWeight, const Weight::UnitOfWeight newUnitOfWeight, const float newMaxWeight ):Weight( newUnitOfWeight, newMaxWeight ){
    setWeight( newWeight );
    assert( validate() );
}

void Weight::setMaxWeight(float newMaxWeight) {
    assert( !bHasMax );
    if( !isWeightValid( newMaxWeight ) ){
        throw out_of_range("FatCat: Max weight is not valid");
    }
    maxWeight = newMaxWeight;
    bHasMax = true;
}

void Weight::setWeight( float newWeight ){
    assert( validate() );

    if( !isWeightValid( newWeight ) ){
        throw out_of_range("FatCat: Weight is not valid");
    }
    weight = newWeight;
    bIsKnown = true;
    assert( validate() );
}

void Weight::setWeight( const float newWeight, const Weight::UnitOfWeight weightUnits ) {
    setWeight(convertWeight( newWeight, weightUnits, unitOfWeight ) );
}

void Weight::dump() const noexcept{
    cout << setw(80) << setfill('=') << "" << endl;
    cout << setfill( ' ' );
    cout << left;
    cout << boolalpha;

    FORMAT_LINE( "Weight", "isKnown" )          << bIsKnown << endl;
    FORMAT_LINE( "Weight", "weight" )           << weight << endl;
    FORMAT_LINE( "Weight", "unitOfWeight" )     << unitOfWeight << endl;
    FORMAT_LINE( "Weight", "hasMax" )           << bHasMax << endl;
    FORMAT_LINE( "Weight", "maxWeight" )        << maxWeight << endl;

}

bool Weight::validate() const noexcept{
    if( bIsKnown ){
        if( !isWeightValid( weight ) ){
            return false;
        }
        assert ( weight > 0 );
    }
    if( bHasMax ){
        if( !isWeightValid( maxWeight ) ){
            throw logic_error("FatCat: Max weight must be > 0");
            return false;
        }

        assert(maxWeight > 0);
    }
    return true;
}

//Operators
bool Weight::operator==(const Weight &rhs_Weight) const {
    float lhs_weight = ( bIsKnown ) ? getWeight( Weight::POUND ): 0;
    float rhs_weight = ( rhs_Weight.bIsKnown ) ? rhs_Weight.getWeight( Weight::POUND ): 0;

    return lhs_weight == rhs_weight;
}

bool Weight::operator<( const Weight &rhs_Weight ) const{
    float lhs_weight = ( bIsKnown ) ? getWeight( Weight::POUND ): 0;
    float rhs_weight = (rhs_Weight.bIsKnown ) ? rhs_Weight.getWeight( Weight:: POUND ): 0;

    return rhs_weight > lhs_weight;
}