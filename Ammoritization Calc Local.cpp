// Ammoritization Calc Local.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <iomanip>

using namespace std;

float A; // Payment Amount Per Period
float P; // Initial Principal (Loan Amount)
float r; // Interest rate per period
float interest; //interest prtion of payment
int n; // Total number of payments or periods
int i; // for the for loop
float principal;
float balance;
int payNum;

int main()
{

	// Does the calculation for the Payment Amount.
	cout << "Enter the Loan Amount(P): " << endl;
	cin >> P;
	cout << "Enter the Interest Rate (r) (0.01 = 1%): " << endl;
	cin >> r;
	cout << "Enter the Number of Payments(n): " << endl;
	cin >> n;
	A = (P) * ((r*pow(1 + r, n)) / (pow((1 + r), n) - 1));
	cout << fixed << setprecision(2) << "Payment Amount is: " << A << endl;
	balance = P;
	cout << "Balance is: " << balance << endl;
	
	//Does the Ammoritization Schedule
	for (i = 0; i < n; i++) {
		interest = balance * r;
		principal = A - interest;
		balance -= principal;
		payNum++;


		cout << setw(2) << payNum << " " << setw(8) << A << " " << setw(8) << interest << " " << setw(8) << principal << " " << setw(8) << balance << endl;
	}
	return 0;
}


