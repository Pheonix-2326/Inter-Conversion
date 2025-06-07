#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <map>
#include <cctype>
#include "connector.h"

/**
 * @file hexadecimal_to_decimal.cpp
 * @brief Converts a hexadecimal number to its decimal equivalent.
 */

using namespace std;

int hexadecimal_to_decimal()
{
    size_t position, index = 0, power = 0;

    long long hex_dec_result = 0;
    string input_str, original_value = "";
    
    vector<long long> hex_dec_value, power_value;
    vector<char> hex_digits;
    
    // Map for hexadecimal to decimal conversion
    map<char, long long> hex_to_dec_map = 
    {
        {'0', 0},  {'1', 1},  {'2', 2},  {'3', 3},
        {'4', 4},  {'5', 5},  {'6', 6},  {'7', 7},
        {'8', 8},  {'9', 9},  {'A', 10}, {'B', 11},
        {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}
    };

    // Step 1: Input hexadecimal number and validate
    cout << "Enter a Hexadecimal Number: ";
    cin >> input_str;

    if (input_str.empty()) 
    {
        cerr << "Error: Input cannot be empty!" << endl;
        return 1;
    }
    
    for (char c : input_str)
    {
        if (!isxdigit(c))
        {
            cerr << "Error: Input is not a valid hexadecimal number!" << endl;
            return 1;
        }
    }

    original_value = input_str;

    // Step 2: Store hexadecimal digits in reverse (for least significant digit first)
    for (position = input_str.length(); position-- > 0;)
    {
        hex_digits.push_back(toupper(input_str[position]));
        index++;
    }

    // Step 3: Convert hex digits to decimal values
    for (position = 0; position < index; position++)
    {
        hex_dec_value.push_back(hex_to_dec_map[hex_digits[position]]);
    }

    // Step 4: Calculate the decimal result using powers of 16
    for (position = 0; position < index; position++)
    {
        power = 1LL << (4 * position);  // 16^position = 2^(4*position)
        power_value.push_back(power * hex_dec_value[position]);
        hex_dec_result += power_value[position];     
    }

    // Step 5: Display the conversion process
    cout << "----------------------------------------------" << endl;
    for (position = 0; position < index; position++)
    {
        cout << setw(3) << position + 1 << ")" << setw(5) << hex_digits[position]
             << setw(5) << "->" << setw(10) << "( 16 ^ " << position << " ) * "
             << setw(2) << hex_dec_value[position] << setw(6) << " =" << setw(9) << power_value[position] << endl;
    }

    // Step 6: Show final result
    cout << "----------------------------------------------" << endl;
    cout << setw(36) << "Total   =" << setw(9) << hex_dec_result << endl;
    cout << "----------------------------------------------" << endl;
    cout << endl << "Decimal number of " << original_value << " is " << hex_dec_result;

    return 0;
}
