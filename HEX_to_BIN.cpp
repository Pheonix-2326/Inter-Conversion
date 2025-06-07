#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include "connector.h"

/**
 * @file hexadecimal_to_binary.cpp
 * @brief Converts a hexadecimal number to its binary equivalent.
 */

using namespace std;

int hexadecimal_to_binary()
{
    size_t position, index = 0;

    string input_str, hex_bin_result = "", original_value = "";

    vector<char> hex_digits;       // Store individual hex digits
    vector<string> hex_bin_values;  // Store corresponding binary values

    // Create a map for hexadecimal to binary conversion
    map<char, string> hex_to_bin_map = 
    {
        {'0', "0000"}, {'1', "0001"}, {'2', "0010"}, {'3', "0011"},
        {'4', "0100"}, {'5', "0101"}, {'6', "0110"}, {'7', "0111"},
        {'8', "1000"}, {'9', "1001"}, {'A', "1010"}, {'B', "1011"},
        {'C', "1100"}, {'D', "1101"}, {'E', "1110"}, {'F', "1111"}
    };

    // Step 1: Take input from the user
    cout << "Enter a Hexadecimal Number: ";
    cin >> input_str;

    // Validate input
    if (input_str.empty()) 
    {
        cerr << "Error: Input cannot be empty!" << endl;
        return 1;
    }
    
    for (char c : input_str)
    {
        if (!isxdigit(c))  // Check if each character is a valid hex digit
        {
            cerr << "Error: Input is not a valid hexadecimal number!" << endl;
            return 1;
        }
    }

    original_value = input_str;

    // Step 2: Convert each hex digit to uppercase and store them in hex_digits
    for (position = 0; position < input_str.length(); position++)
    {
        hex_digits.push_back(toupper(input_str[position]));  // Convert to uppercase and store
        index++;
    }

    // Step 3: Convert Hexadecimal digits to their binary equivalents
    for (position = 0; position < index; position++)
    {
        hex_bin_values.push_back(hex_to_bin_map[hex_digits[position]]);
    }

    // Step 4: Display Hexadecimal to Binary Conversion Table
    cout << "Hexadecimal to Binary Conversion:" << endl;
    cout << setw(15) << "Hexadecimal Digit" << setw(20) << "Binary Value" << endl;

    // Step 5: Display each hexadecimal digit and its corresponding binary value
    for (position = 0; position < index; position++)
    {
        cout << setw(10) << hex_digits[position] << setw(10) << "->";
        cout << setw(10) << hex_bin_values[position] << endl;
        hex_bin_result += hex_bin_values[position];  // Concatenate to final binary string
    }

    // Step 6: Output the final binary number (concatenated binary values)
    cout << "Binary number of " << original_value << " is: " << hex_bin_result << endl;

    return 0;
}
