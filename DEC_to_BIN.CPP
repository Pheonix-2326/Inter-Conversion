#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "connector.h"

/**
 * @file decimal_to_binary.cpp
 * @brief Converts a decimal number to its binary equivalent.
 */

using namespace std;

int decimal_to_binary()
{
    // Variable declarations and input setup
    long long input, original_value;
    string dec_bin_result = "";
    
    vector<long long> dec_bin_value, dec_bin;
    
    size_t position;

    // Input from user
    cout << "Enter a Decimal number: ";
    if (!(cin >> input) || input < 0)
    {
        cerr << "Error: Invalid input! Please enter a valid decimal number." << endl;
        return 1;
    }

    original_value = input;
    dec_bin.push_back(input);

    // Special handling for input 0
    if (input == 0) 
    {
        cout << "Binary number of 0 is 0" << endl;
        return 0;
    }

    // Convert decimal to binary and store steps
    while (input > 0)
    {
        dec_bin_value.push_back(input % 2);
        input /= 2;
        dec_bin.push_back(input);
    }

    // Display table header for division steps
    cout << setw(15) << "Number" << setw(12) << "Divide by" << setw(13) << "Remainder" << endl;

    // Display all conversion steps
    for (position = 0; position < dec_bin.size(); position++)
    {
        dec_bin_result = to_string(dec_bin_value[position]) + dec_bin_result;

        if (dec_bin[position] == 2)
        {
            cout << setw(15) << dec_bin[position] << setw(7) << "2" << setw(8) 
                 << "-> " << setw(6) << dec_bin_value[position] << endl;
            break;
        }

        if (dec_bin[position] == 1)
        {
            cout << setw(15) << dec_bin[position] << setw(10) << "-----"
                 << setw(6) << "-> " << setw(6) << dec_bin_value[position] << endl;
            break;
        }

        cout << setw(15) << dec_bin[position] << setw(8) << "2" << setw(8) 
             << "-> " << setw(6) << dec_bin_value[position] << endl;
    }

    // Final binary output display
    cout << endl << "Binary number of " << original_value << " is " << dec_bin_result << endl;
    return 0;
}
