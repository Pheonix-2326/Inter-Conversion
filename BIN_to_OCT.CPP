#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>  // For using map
#include "connector.h"

/**
 * @file binary_to_octal.cpp
 * @brief Converts a binary number to its octal equivalent.
 */

using namespace std;

int binary_to_octal()
{
    long long input, bin_oct_result = 0, original_value = 0;
    string input_str, binaryGroup;

    vector<long long> bin_oct_value_1, bin_oct_value_2;
    vector<string> bin_oct_value_3;

    // Create a map for binary-to-octal lookup
    map<string, long long> bin_to_oct_map = 
    {
        {"000", 0}, {"001", 1}, {"010", 2}, {"011", 3},
        {"100", 4}, {"101", 5}, {"110", 6}, {"111", 7}
    };

    int position_1, position_2;

    // Input the binary number as a string
    cout << "Enter a Binary number: ";
    cin >> input_str;
    input = stoll(input_str);
    original_value = input;
    cout << endl;

    if (input_str.empty()) 
    {
        cerr << "Error: Input cannot be empty!" << endl;
        return 1;
    }
    for (char c : input_str) 
    {
        if (c != '0' && c != '1') 
        {
            cerr << "Error: Input is not a valid binary number." << endl;
            return 1;  // Exit the program with error code 1
        }
    }

    if (input == 0) 
    {
        cerr << "Error: No binary number entered." << endl;
        return 1;
    }

    // Process the input in groups of 3 binary digits (octal conversion)
    while (input > 0)
    {
        bin_oct_value_1.push_back(input % 1000);
        input /= 1000;
    }

    // Convert the binary groups to octal equivalents using the map
    for (position_1 = 0; position_1 < bin_oct_value_1.size(); position_1++)
    {
        binaryGroup = to_string(bin_oct_value_1[position_1]);
        while (binaryGroup.length() < 3) 
        {
            binaryGroup = "0" + binaryGroup;
        }

        bin_oct_value_2.push_back(bin_to_oct_map[binaryGroup]);  // Use map to find the octal equivalent
        bin_oct_value_3.push_back(binaryGroup);
    }

    // Display the binary-to-octal conversion process
    cout << setw(14) << "Binary Value" << setw(18) << "Octal Value" << endl;
    for (position_1 = bin_oct_value_1.size() - 1, position_2 = 1; position_1 >= 0; position_1--, position_2++)
    {
        cout << position_2 << ") " << setw(7) << bin_oct_value_3[position_1]
             << setw(10) << "\u2192" << setw(10) << bin_oct_value_2[position_1] << endl;
    }

    // Combine the octal digits to form the final octal number
    for (position_1 = bin_oct_value_2.size() - 1; position_1 >= 0; position_1--)
    {
        bin_oct_result = (bin_oct_result * 10) + bin_oct_value_2[position_1];
    }

    cout << endl << endl;
    cout << "Octal number of " << original_value << " is " << bin_oct_result << endl;

    return 0;
}
