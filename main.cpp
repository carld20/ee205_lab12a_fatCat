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

using namespace std;

int main() {
    cout << "Starting FatCat:" << endl;
    cout << "Weight noWeight" << endl;
    Weight noWeight;
    noWeight.dump();

    cout<< "Weight catWeight( 3.14, Kilo, 15" << endl;
    Weight catWeight( 3.14, Weight::KILO, 15 );
    catWeight.dump();

    cout << "Done with FatCat" << endl;
    return EXIT_SUCCESS;
}