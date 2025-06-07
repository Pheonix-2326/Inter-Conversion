#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include "connector.h"

/**
 * @file octal_to_hexadecimal.cpp
 * @brief Converts a octal number to its hexadecimal equivalent.
 */

using namespace std;

int octal_to_hexadecimal()
{
    size_t position_1;

    string input_str, oct_bin_result, original_value_1 = "";
    
    vector<char> oct_bin_value_1;
    vector<string> oct_bin_value_2;

    // Octal to Hexa-Decimal lookup map
    map<char, string> oct_to_bin_map = {
        {'0', "000"}, {'1', "001"}, {'2', "010"}, {'3', "011"},
        {'4', "100"}, {'5', "101"}, {'6', "110"}, {'7', "111"}
    };
    map<string, char> bin_to_hex_map = {
        {"0000", '0'}, {"0001", '1'}, {"0010", '2'}, {"0011", '3'},
        {"0100", '4'}, {"0101", '5'}, {"0110", '6'}, {"0111", '7'},
        {"1000", '8'}, {"1001", '9'}, {"1010", 'A'}, {"1011", 'B'},
        {"1100", 'C'}, {"1101", 'D'}, {"1110", 'E'}, {"1111", 'F'}
    };

    // Get input from user
    cout << "Enter a Octal number: ";
    cin >> input_str;
    original_value_1 = input_str;
    cout << endl;

    // Input validation
    for (char c : input_str)
    {
        if (!isdigit(c) || c > '7')
        {
            cerr << "Error: Invalid input! Please enter a valid octal number." << endl;
            return 1;
        }
    }

    if (input_str.empty())
    {
        cerr << "Error: Input cannot be empty!" << endl;
        return 0;
    }

    // Octal to binary conversion
    for (position_1 = 0; position_1 < input_str.length(); position_1++)
    {
        oct_bin_value_1.push_back(input_str[position_1]);
        oct_bin_value_2.push_back(oct_to_bin_map[input_str[position_1]]);
    }

    // Print the conversion
    cout << endl << "Octal to Binary Conversion:" << endl;
    cout << setw(15) << "Octal Digit" << setw(20) << "Binary Value" << endl;

    for (position_1 = 0; position_1 < input_str.length(); position_1++)
    {
        cout << setw(10) << oct_bin_value_1[position_1] << setw(10) << "->";
        cout << setw(10) << oct_bin_value_2[position_1] << endl;
        oct_bin_result += oct_bin_value_2[position_1];
    }

    cout << endl << "Binary number of " << original_value_1 << " is: " << oct_bin_result << endl;


    /*-------------------------------------------------------------------*/


    string input_str_2, binarygroup = "", original_value_2 = "", bin_hex_result = "";
    int index = 0, position_2, position_3;
    
    vector<string> bin_hex_value_1;
    vector<char> bin_hex_value_2;

    // Saving the binary input
    input_str_2 = original_value_2 = oct_bin_result;

    // Split binary string into 4-bit groups and convert to hexadecimal
    for (position_2 = 0; position_2 < input_str_2.size(); position_2 += 4)
    {
        // Pad with zeros to make binary string length a multiple of 4
        while (input_str_2.length() % 4 != 0)
        {
            input_str_2 = "0" + input_str_2;
        }

        binarygroup = input_str_2.substr(position_2, 4);
        bin_hex_value_1.push_back(binarygroup);
        bin_hex_value_2.push_back(bin_to_hex_map[binarygroup]);
    }

    // Printing the conversion
    cout << endl << "Binary to Hexa-Decimal Conversion:" << endl;
    cout << setw(14) << "Binary Value" << setw(18) << "Hexa-Decimal Value" << endl;

    for (position_2 = bin_hex_value_1.size() - 1, position_3 = 0; position_2 >= 0; position_2--, position_3++)
    {
        bin_hex_result += bin_hex_value_2[position_3];
        cout << (position_3 + 1) << ") " << setw(7) << bin_hex_value_1[position_2]
             << setw(10) << "\u2192" << setw(10) << bin_hex_value_2[position_2] << endl;
    }

    // Final result output
    cout << endl << "Hexa-Decimal number of Binary value " << original_value_2 << " is " << bin_hex_result << endl;
    cout << endl << "Hexa-Decimal Value of Octal value " << original_value_1 << " is " << bin_hex_result << endl;

    return 0;
}
