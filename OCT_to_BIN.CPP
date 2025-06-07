#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include "connector.h"

/**
 * @file octal_to_binary.cpp
 * @brief Converts a octal number to its binary equivalent.
 */

using namespace std;

int octal_to_binary()
{
    size_t position;

    string input_str, oct_bin_result, original_value = "";
    
    vector <char> oct_bin_value_1;
    vector <string> oct_bin_value_2;

    // Create a map for octal-to-binary lookup
    map<char, string> oct_to_bin_map = 
    {
        {'0', "000"}, {'1', "001"}, {'2', "010"}, {'3', "011"},
        {'4', "100"}, {'5', "101"}, {'6', "110"}, {'7', "111"}
    };

    // Get input from user
    cout << "Enter a Octal number: ";
    cin >> input_str;
    original_value = input_str;
    cout << endl;

    // Validate input to ensure it's a valid octal number
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

    // Convert each octal digit to its binary equivalent
    for (position = 0; position < input_str.length(); position++)
    {
        oct_bin_value_1.push_back(input_str[position]);
        oct_bin_value_2.push_back(oct_to_bin_map[input_str[position]]);
    }

    cout << endl;
    cout << "Octal to Binary Conversion:" << endl << endl;
    cout << setw(15) << "Octal Digit" << setw(20) << "Binary Value" << endl;

    // Print each octal digit and its corresponding binary value
    for (position = 0; position < input_str.length(); position++)
    {
        cout << setw(10) << oct_bin_value_1[position] << setw(10) << "->";
        cout << setw(10) << oct_bin_value_2[position] << endl;
        oct_bin_result += oct_bin_value_2[position];
    }

    cout << endl << endl;
    cout << "Binary number of " << original_value << " is: ";
    cout << oct_bin_result << endl;

    return 0;
}
