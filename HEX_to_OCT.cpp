#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include "connector.h"

/**
 * @file hexadecimal_to_octal.cpp
 * @brief Converts a hexadecimal number to its octal equivalent.
 */

using namespace std;

int hexadecimal_to_octal()
{
    size_t position_1, index_1 = 0;

    string input_str, hex_bin_result = "", original_value_1 = "";

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
    map<string, string> bin_to_oct_map = 
    {
        {"000", "0"}, {"001", "1"}, {"010", "2"}, {"011", "3"},
        {"100", "4"}, {"101", "5"}, {"110", "6"}, {"111", "7"}
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

    original_value_1 = input_str;
    cout << endl;

    // Step 2: Convert each hex digit to uppercase and store them in hex_digits
    for (position_1 = 0; position_1 < input_str.length(); position_1++)
    {
        hex_digits.push_back(toupper(input_str[position_1]));  // Convert to uppercase and store
        index_1++;
    }

    // Step 3: Convert Hexadecimal digits to their binary equivalents
    for (position_1 = 0; position_1 < index_1; position_1++)
    {
        hex_bin_values.push_back(hex_to_bin_map[hex_digits[position_1]]);
    }

    // Step 4: Display Hexadecimal to Binary Conversion Table
    cout << "Hexadecimal to Binary Conversion:" << endl;
    cout << setw(15) << "Hexadecimal Digit" << setw(20) << "Binary Value" << endl;

    // Step 5: Display each hexadecimal digit and its corresponding binary value
    for (position_1 = 0; position_1 < index_1; position_1++)
    {
        cout << setw(10) << hex_digits[position_1] << setw(10) << "->";
        cout << setw(10) << hex_bin_values[position_1] << endl;
        hex_bin_result += hex_bin_values[position_1];  // Concatenate to final binary string
    }

    // Step 6: Output the final binary number (concatenated binary values)
    cout << endl << "Binary number of " << original_value_1 << " is: " << hex_bin_result << endl << endl;


    /*-------------------------------------------------------------------*/


    string input, binarygroup, original_value_2, bin_oct_result = "";

    vector<string> bin_oct_value_1, bin_oct_value_2;

    int position_2, position_3;

    input = original_value_2 = hex_bin_result;

    // Step 7: Group binary digits into chunks of 3 and convert to octal
    for (position_2 = 0; position_2 < input.length(); position_2 += 3)
    {
        binarygroup = input.substr(position_2, 3);

        // Ensure each group is 3 bits long by adding leading zeros
        while (binarygroup.length() < 3) 
        {
            binarygroup = "0" + binarygroup;
        }

        bin_oct_value_1.push_back(binarygroup);
        bin_oct_value_2.push_back(bin_to_oct_map[binarygroup]);  // Use map to find the octal equivalent
    }

    // Step 8: Display the binary-to-octal conversion process
    cout << "Binary to Octal Conversion:" << endl;
    cout << setw(14) << "Binary Value" << setw(18) << "Octal Value" << endl;
    for (position_2 = bin_oct_value_1.size() - 1, position_3 = 1; position_2 >= 0; position_2--, position_3++)
    {
        bin_oct_result = bin_oct_value_2[position_2] + bin_oct_result;
        cout << position_3 << ") " << setw(7) << bin_oct_value_1[position_2]
             << setw(10) << "\u2192" << setw(10) << bin_oct_value_2[position_2] << endl;
    }

    // Step 9: Output the final octal result
    cout << endl << "Octal number of " << original_value_2 << " is " << bin_oct_result << endl;
    cout << endl << "Octal Value of " << original_value_1 << " is " << bin_oct_result << endl;

    return 0;
}
