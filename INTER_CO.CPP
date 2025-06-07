#include <iostream>
#include "connector.h"

using namespace std;

class Calc 
{
    int num;

    public:
        void show_option();
        void get_option(char);
        void binary(char);
        void decimal(char);
        void octal(char);
        void hexa(char);
};

void Calc::show_option() 
{
    cout << "1] Binary       (B)" << endl;
    cout << "2] Decimal      (D)" << endl;
    cout << "3] Octal        (O)" << endl;
    cout << "4] Hexadecimal  (H)" << endl;
    cout << "Enter the Initial of option: ";
}

void Calc::get_option(char opt1) 
{
    if (opt1 == 'B' || opt1 == 'b') 
    {
        cout << "1] Decimal      (D)" << endl;
        cout << "2] Octal        (O)" << endl;
        cout << "3] Hexadecimal  (H)" << endl;
    }
    else if (opt1 == 'D' || opt1 == 'd') 
    {
        cout << "1] Binary       (B)" << endl;
        cout << "2] Octal        (O)" << endl;
        cout << "3] Hexadecimal  (H)" << endl;
    }
    else if (opt1 == 'O' || opt1 == 'o') 
    {
        cout << "1] Binary       (B)" << endl;
        cout << "2] Decimal      (D)" << endl;
        cout << "3] Hexadecimal  (H)" << endl;
    }
    else if (opt1 == 'H' || opt1 == 'h') 
    {
        cout << "1] Binary       (B)" << endl;
        cout << "2] Decimal      (D)" << endl;
        cout << "3] Octal        (O)" << endl;
    }
    else 
    {
        cerr << "You have entered a wrong option...!" << endl;
    }
}

void Calc::binary(char b) 
{
    if (b == 'D' || b == 'd') 
    {
		binary_to_decimal();
    }
	
    else if (b == 'H' || b == 'h') 
    {
		binary_to_hexadecimal();
    }
    else if (b == 'O' || b == 'o') 
    {
		binary_to_octal();
    }
    else 
    {
        cout << "You have entered a wrong option...!" << endl;
    }
}

void Calc::decimal(char d) 
{
    if (d == 'B' || d == 'b') 
    {
		decimal_to_binary();
    }
    else if (d == 'H' || d == 'h') 
    {
		decimal_to_hexadecimal();
    }
	else if (d == 'O' || d == 'o') 
    {
		decimal_to_octal();
    }
    else 
    {
        cout << "You have entered a wrong option...!" << endl;
    }
}

void Calc::octal(char o) 
{
    if (o == 'B' || o == 'b') 
    {
		octal_to_binary();
    }
    else if (o == 'D' || o == 'd') 
    {
		octal_to_decimal();
    }
    else if (o == 'H' || o == 'h')
    {
		octal_to_hexadecimal();
    }
    else 
    {
        cout << "You have entered a wrong option...!" << endl;
    }
}

void Calc::hexa(char h) 
{
    if (h == 'B' || h == 'b') 
    {
		hexadecimal_to_binary();
    }
    else if (h == 'D' || h == 'd') 
    {
		hexadecimal_to_decimal();
    }
    else if (h == 'O' || h == 'o') 
    {
		hexadecimal_to_octal();
    }
    else 
    {
        cout << "You have entered a wrong option...!" << endl;
    }
}

int main() 
{
    Calc c;
    char opt1, opt2, choice;

    do {
		cout << "Choose your input option: " << endl << endl;
    	c.show_option();
	    cin >> opt1;

	    cout << endl << "Choose your output option: " << endl << endl;
	    c.get_option(opt1);
	    cout << "Enter the Initial of option: ";
	    cin >> opt2;
    	cout << endl;

	    if (opt1 == 'B' || opt1 == 'b') c.binary(opt2);
    	else if (opt1 == 'D' || opt1 == 'd') c.decimal(opt2);
	    else if (opt1 == 'O' || opt1 == 'o') c.octal(opt2);
    	else if (opt1 == 'H' || opt1 == 'h') c.hexa(opt2);
	    else cout << "Invalid input option!" << endl;

		cout << endl << "Do you want to continue? (Y/N): ";
        cin >> choice;
        cout << endl;

	} while (choice == 'Y' || choice == 'y');
	
    return 0;
}
