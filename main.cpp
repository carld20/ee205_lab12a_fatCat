///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file main.cpp
/// @version 1.0
///
/// @author Carl Domingo <carld20@hawaii.edu>
/// @date   15_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "weight.h"


int main() {
    Weight testWeight1 = Weight();
    testWeight1.dump();


    Weight testWeight2 = Weight( 15, Weight::KILO,45 );

    testWeight2.isWeightValid( 30 );
    testWeight2.dump();


}