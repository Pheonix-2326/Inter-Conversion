#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "connector.h"

/**
 * @file decimal_to_hexadecimal.cpp
 * @brief Converts a decimal number to its hexadecimal equivalent.
 */

using namespace std;

int decimal_to_hexadecimal()
{
    // Variable declarations and input setup
    string dec_hex_result = "";
    long long input, original_value;

    vector<string> dec_hex_value_2;
    vector<long long> dec_hex_value_1, dec_hex;
    
    size_t position;

    // Input from user
    cout << "Enter a Decimal number: ";
    if (!(cin >> input) || input < 0)
    {
        cerr << "Error: Invalid input! Please enter a valid decimal number." << endl;
        return 1;
    }

    original_value = input;
    dec_hex.push_back(input);
    cout << endl;

    // Handle edge case for input 0
    if (input == 0)
    {
        cerr << "Decimal number of 0 is 0 in hexadecimal." << endl;
        return 0;
    }

    // Convert decimal to hexadecimal and store values
    while (input > 0)
    {
        dec_hex_value_1.push_back(input % 16);
        input = input / 16;
        dec_hex.push_back(input);
    }

    // Map decimal remainders to hexadecimal characters
    for (position = 0; position < dec_hex_value_1.size(); position++)
    {
        if (dec_hex_value_1[position] <= 9)
            dec_hex_value_2.push_back(to_string(dec_hex_value_1[position]));
        else
            dec_hex_value_2.push_back(string(1, 'A' + dec_hex_value_1[position] - 10));
    }

    // Display conversion steps
    cout << setw(15) << "Number" << setw(13) << "Divide by"
         << setw(18) << "Remainder" << setw(26) << "Hexa-decimal value" << endl;

    for (position = 0; position < dec_hex_value_1.size(); position++)
    {
        dec_hex_result = dec_hex_value_2[position] + dec_hex_result;

        if (dec_hex[position] < 16)
        {
            cout << setw(13) << dec_hex[position] << setw(6) << "/" << setw(5) << "----"
                 << setw(9) << "-> " << setw(8) << dec_hex_value_1[position] << setw(10)
                 << "-> " << setw(10) << dec_hex_value_2[position] << endl;
            break;
        }

        cout << setw(13) << dec_hex[position] << setw(5) << "/" << setw(5) << "16"
             << setw(10) << "-> " << setw(8) << dec_hex_value_1[position] << setw(10)
             << "-> " << setw(10) << dec_hex_value_2[position] << endl;
    }

    // Display final result
    cout << "Decimal number of " << original_value << " is " << dec_hex_result << endl;
    return 0;
}
