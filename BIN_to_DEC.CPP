#include <iostream>
#include <iomanip>
#include <vector>
#include "connector.h"

/**
 * @file binary_to_decimal.cpp
 * @brief Converts a binary number to its decimal equivalent.
 */

using namespace std;

int binary_to_decimal()
{
    // -------------------- Declare variables ------------------------
    long long input, power = 0, bin_dec_result = 0, original_value = 0;

    size_t position;
    
    vector<long long> bin_dec_value;  // Stores the binary digits
    vector<long long> power_value;    // Stores intermediate results of binary digits * 2^position

    // -------------------- Read input ------------------------------
    cout << "Enter a Binary number: ";
    cin >> input;
    original_value = input;
    cout << endl;

    // -------------------- Validate input ---------------------------
    // Ensure the input consists only of binary digits (0 or 1)
    if (input < 0) 
    {
        cerr << "Error: Binary numbers cannot be negative." << endl;
        return 1;
    }

    if (input == 0) 
    {
        cerr << "Error: No binary number entered." << endl;
        return 1;
    }
    
    while (input > 0)
    {
        if (input % 10 > 1 || input % 10 < 0) // Invalid digit detected
        {
            cerr << "Error: Input is not a valid binary number." << endl;
            return 1; 
        }
        bin_dec_value.push_back(input % 10); // Store the binary digit
        input = input / 10;                  // Remove the last digit
    }

    // -------------------- Convert to decimal -----------------------
    for (position = 0; position < bin_dec_value.size(); position++)
    {
        power = 1LL << position;                                // Calculate 2^position using bit shifting
        power_value.push_back(power * bin_dec_value[position]); // Multiply by the binary digit
        bin_dec_result += power_value[position];                // Add to the total decimal result
    }

    // -------------------- Output Conversion Process --------------
    cout << " ---------------------------------------" << endl;
    for (position = 0; position < bin_dec_value.size(); position++)
    {
        cout << setw(3) << position + 1 << ") " << setw(2) << bin_dec_value[position] << setw(2)
             << "  \u2192  ( 2 ^ " << setw(2) << position << " ) * " << setw(2) << bin_dec_value[position]
             << " = " << setw(5) << power_value[position] << endl;
    }

    // -------------------- Display Total Decimal Result -----------
    cout << " ---------------------------------------" << endl
         << setw(31) << "Total =" << setw(5) << bin_dec_result << endl
         << " ---------------------------------------" << endl;

    // -------------------- Final Output ----------------------------
    cout << endl << "Decimal number of " << original_value << " is " << bin_dec_result << endl;

    return 0;
}