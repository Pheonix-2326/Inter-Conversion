#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "connector.h"

/**
 * @file decimal_to_octal.cpp
 * @brief Converts a decimal number to its octal equivalent.
 */

using namespace std;

int decimal_to_octal()
{
    // Variable declarations and input setup
    long long input, original_value;
    string dec_oct_result = "";

    vector<long long> dec_oct_value, dec_oct;
    
    size_t position;

    // Input from user
    cout << "Enter a Decimal number: ";
    if (!(cin >> input) || input < 0)
    {
        cerr << "Error: Invalid input! Please enter a valid decimal number." << endl;
        return 1;
    }

    original_value = input;
    dec_oct.push_back(input);
    cout << endl;

    // Handle edge case for input 0
    if (input == 0) 
    {
        cout << "Decimal number of 0 is 0 in Octal." << endl;
        return 0;
    }

    // Convert decimal to octal and store values
    while (input > 0) 
    {
        dec_oct_value.push_back(input % 8);
        input /= 8;
        dec_oct.push_back(input);
    }

    // Display conversion steps
    cout << setw(15) << "Number" << setw(13) << "Divide by" << setw(18) << "Remainder" << endl;

    for (position = 0; position < dec_oct.size() - 1; position++) 
    {
        dec_oct_result = to_string(dec_oct_value[position]) + dec_oct_result;

        if (dec_oct[position] < 8) 
        {
            cout << setw(15) << dec_oct[position] << setw(10) << "----"
                 << setw(9) << "-> " << setw(8) << dec_oct_value[position] << endl;
            break;
        }

        cout << setw(15) << dec_oct[position] << setw(9) << "8"
             << setw(10) << "-> " << setw(8) << dec_oct_value[position] << endl;
    }

    // Display final result
    cout << endl << "Decimal number " << original_value << " is " << dec_oct_result << " in Octal." << endl;

    return 0;
}
