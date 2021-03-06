// Alphabet Spam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <assert.h>
#include <string>

using namespace std;

string input;
string file;
ifstream fin;
char c;
int asciival, denom;
double whitespace, lowercase, upperletter, symbols, string_size = 0;
double whitespace_ratio, lowercase_ratio, upperletter_ratio, symbols_ratio;

void output()
{
	/*Math to determine the ratios of the respective characters*/
	whitespace_ratio = whitespace / denom;
	lowercase_ratio = lowercase / denom;
	upperletter_ratio = upperletter / denom;
	symbols_ratio = symbols / denom;

	/*Output Value*/
	cout << "Whitespace: " << whitespace_ratio << "\n";
	cout << "Lowercase: " << lowercase_ratio << "\n";
	cout << "Uppercase: " << upperletter_ratio << "\n";
	cout << "Symbols: " << symbols_ratio << "\n";
	cout << "Total: " << whitespace_ratio + lowercase_ratio + upperletter_ratio + symbols_ratio << "\n";
}

int main()
{
	cout << "Insert File Location (.txt): " << endl;
	cin >> file;
	fin.open(file, ios::in);
	assert(!fin.fail());

	while (!fin.eof()) {
		getline(fin, input);
		string_size = input.length();
		for (int i = 0; i < input.length(); i++) {
			char c = input[i]; //Gets individual character from string
			asciival = int(c); //Converts said character to Interval ASCII Value
							   /* Based on ASCII Value, add 1 to associated category (assumes numbers count as symbols) */
			if (asciival == 32) //Convert spaces to 
				asciival = 95;
			if (asciival == 95)
				whitespace++;
			else if (asciival >= 97 && asciival <= 122)
				lowercase++;
			else if (asciival >= 65 && asciival <= 90)
				upperletter++;
			else if (asciival >= 33 && asciival <= 64)
				symbols++;
			else if (asciival >= 91 && asciival <= 96)
				symbols++;
			else if (asciival >= 123 && asciival <= 126)
				symbols++;
			denom++;
		}
			
	}
	fin.close();
	assert(!fin.fail());
	output();
	return 0;
}


//This will be the basis of this program, essentially checking the value of a character and comparing it against values in the ASCII table
/*
char c;
cin >> c;
cout << "Value of " << c << " is: " << int(c) << "\n";
*/