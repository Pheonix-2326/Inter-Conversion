#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include "connector.h"

/**
 * @file octal_to_decimal.cpp
 * @brief Converts a octal number to its decimal equivalent.
 */

using namespace std;

int octal_to_decimal()
{
    int position, power;
    long long oct_dec_result = 0;
    string input_str, original_value = "";

    vector<long long> power_value, oct_dec_value;

    cout << "Enter a Octal number: ";
    cin >> input_str;
    original_value = input_str;
    cout << endl;

    // Validate input: ensure all characters are digits and <= '7'
    for (char c : input_str)
    {
        if (!isdigit(c) || c > '7')
        {
            cerr << "Error: Invalid input! Please enter a valid octal number." << endl;
            return 1;
        }
    }

    // Extract digits from string and store as integers
    for (position = 0; position < input_str.length(); position++)
    {
        oct_dec_value.push_back(input_str[position] - '0');
    }

    // Convert octal to decimal using (8^position) = (1 << (3 * position))
    for (position = input_str.length() - 1; position >= 0; position--)
    {
        power = (1LL << (3 * (input_str.length() - 1 - position)));
        power_value.push_back(power * oct_dec_value[position]);
        oct_dec_result += power_value[power_value.size() - 1];
    }

    // Display conversion steps
    cout << "----------------------------------------------" << endl;
    for (position = 0; position < input_str.length(); position++)
    {
        cout << setw(3) << position + 1 << ")" << setw(4) << oct_dec_value[position];
        cout << setw(5) << "->" << setw(10) << "( 8 ^ " << position << " ) * " << oct_dec_value[position];
        cout << setw(5) << " =" << setw(7) << power_value[position] << endl;
    }

    cout << "----------------------------------------------" << endl;
    cout << setw(35) << "Total =" << setw(7) << oct_dec_result << endl;
    cout << "----------------------------------------------" << endl;

    // Display the final result
    cout << endl << "Decimal number of " << original_value << " is " << oct_dec_result;

    return 0;
}
