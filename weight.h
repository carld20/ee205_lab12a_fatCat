///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file weight.h
/// @version 1.0
///
/// @author Carl Domingo <carld20@hawaii.edu>
/// @date   15_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <ostream>
#include <string>

using namespace std;

class Weight {
public:
    enum UnitOfWeight {POUND, KILO, SLUG};

public:
    Weight() noexcept;
    Weight( float newWeight );
    Weight( UnitOfWeight newUnitOfWeight ) noexcept;
    Weight( float newWeight, UnitOfWeight newUnitOfWeight );
    Weight( float newWeight, float maxWeight );
    Weight( UnitOfWeight newUnitOfWeight, float newMaxWeight );
    Weight( float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight );

public:
    bool isWeightKnown() const noexcept;
    bool hasMaxWeight() const noexcept;
    float getWeight() const noexcept;
    float getWeight( UnitOfWeight ) const noexcept;
    float getMaxWeight() const noexcept;

public:
    UnitOfWeight getWeightUnit() const noexcept;

public:
    void setWeight( float newWeight );
    void setWeight( float newWeight, UnitOfWeight weightUnits );
    bool isWeightValid( float checkWeight ) const noexcept;
    void dump() const noexcept;
    bool operator==(const Weight &rhs_Weight ) const;
    bool operator<( const Weight &rhs_Weight ) const;
    Weight &operator+=( float rhs_addToWeight );

public:
    static float fromKiloToPound(float kilogram ) noexcept;
    static float fromPoundToKilo( float pound ) noexcept;
    static float fromSlugToPound( float slug ) noexcept;
    static float fromPoundToSlug( float pound ) noexcept;

public:
    static const float UNKNOWN_WEIGHT;
    static const float KILOS_IN_POUND; //kg to lb conv
    static const float SLUGS_IN_POUND; //slug to lb conv
    static const string POUND_LABEL; //lb label
    static const string KILO_LABEL; //kg label
    static const string SLUG_LABEL; //slug label

private:
    void setMaxWeight( float newMaxWeight );

    bool bIsKnown = false;
    bool bHasMax = false;
    enum UnitOfWeight unitOfWeight = POUND;
    float weight{};
    float maxWeight {};


};
