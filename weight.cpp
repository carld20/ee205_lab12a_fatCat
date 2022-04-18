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

//Constructors
Weight::Weight() noexcept{
    weight = 1.0;
    maxWeight = 10.0;
    unitOfWeight = POUND;
}

Weight::Weight( float newWeight ){
    weight = newWeight;
}

Weight::Weight( UnitOfWeight newUnitOfWeight ) noexcept{
    unitOfWeight = newUnitOfWeight;
}

Weight::Weight( float newWeight, const Weight::UnitOfWeight newUnitOfWeight ){
    weight = newWeight;
}

Weight::Weight( float newWeight, float maxWeight ){
    newWeight = maxWeight;
}

Weight::Weight( const Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight ){
    maxWeight = newMaxWeight;
}

Weight::Weight( float newWeight, const Weight::UnitOfWeight newUnitOfWeight, const float newMaxWeight ): Weight( newUnitOfWeight ){
    setMaxWeight( newMaxWeight );
}
