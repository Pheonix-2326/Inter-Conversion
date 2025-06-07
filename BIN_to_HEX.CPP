#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include "connector.h"

/**
* @file binary_to_hexadecimal.cpp
* @brief Converts a binary number to its hexa-decimal equivalent.
*/

using namespace std;

int binary_to_hexadecimal()
{
    string input_str, group = "", original_value = "";
    stringstream bin_hex_result;

    // Declare size_t once for indexing and size calculations
    size_t index = 0, position_1, position_2;

    // Vectors to store binary and hexadecimal values
    vector<string> bin_hex_value_1;
    vector<char> bin_hex_value_2;

    // Binary-to-hexadecimal lookup map
    map<string, char> bin_to_hex_map = 
    {
        {"0000", '0'}, {"0001", '1'}, {"0010", '2'}, {"0011", '3'},
        {"0100", '4'}, {"0101", '5'}, {"0110", '6'}, {"0111", '7'},
        {"1000", '8'}, {"1001", '9'}, {"1010", 'A'}, {"1011", 'B'},
        {"1100", 'C'}, {"1101", 'D'}, {"1110", 'E'}, {"1111", 'F'}
    };

    // Input the binary number as a string
    cout << "Enter a Binary number: ";
    cin >> input_str;

    if (input_str.empty()) 
    {
        cerr << "Error: Input cannot be empty!" << endl;
        return 1;
    }        

    // Validate the input to ensure it's a valid binary number
    for (char c : input_str)
    {
        if (c != '0' && c != '1')
        {
            cerr << "Error: Input is not a valid binary number!" << endl;
            return 1;                                   // Exit with error code 1
        }
    }

    // Save the original binary string as is
    original_value = input_str;

    // Convert the input into groups of 4 bits
    for (position_1 = 0; position_1 < input_str.size(); position_1 += 4)
    {
        // If the input's length is not a multiple of 4, pad with leading zeros
        while (input_str.length() % 4 != 0)
        {
            input_str = "0" + input_str;
        }
        group = input_str.substr(position_1, 4);
        bin_hex_value_1.push_back(group);               // Push each group of 4 bits
        index++;                                        // Increment the index
    }

    // Convert each group of 4 bits to a hexadecimal value
    for (const auto& binaryGroup : bin_hex_value_1) 
    {
        bin_hex_value_2.push_back(bin_to_hex_map[binaryGroup]);
    }

    // Display formatted binary and hexadecimal values using iomanip
    cout << setw(15) << "Binary Value" << setw(25) << "Hexadecimal Value" << endl;
    for (position_1 = 0; position_1 < bin_hex_value_1.size(); position_1++)
    {
        cout << position_1 + 1 << ")" << setw(8) << bin_hex_value_1[position_1] 
             << setw(11) << "\u2192" << setw(11) << bin_hex_value_2[position_1] << endl;
    }

    // Display the final binary number in hexadecimal format
    cout << endl << "Hexadecimal value of " << original_value << " is: ";
    for (char hexChar : bin_hex_value_2) 
    {
        bin_hex_result << hexChar;
    }
    cout << bin_hex_result.str() << endl;

    return 0;
}
