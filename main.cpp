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
    Weight testWeight = Weight();

    testWeight.setWeight( 20.3, Weight::KILO );
    testWeight.dump();


}