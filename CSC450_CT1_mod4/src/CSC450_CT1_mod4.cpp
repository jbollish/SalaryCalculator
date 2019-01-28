//============================================================================
// Name        : CSC450_CT1_mod4.cpp
// Author      : Joseph Bollish
// Purpose	   : Employee Salary Calculator
// Algthm Used : *pHours * *pRate + (*pOvertime * *pRate * 1.5)
// Inputs      : two to three integers
// Outputs     : three integer values and pay stub
// Limitations : could cause a integer overflow
// Errors      : none
//=============================================================================

#include <iostream>
#include <limits>
#include <iomanip>
#include <thread>
using namespace std;

/**
 *  Method to get and validate hours
 *  @returns double
 */
double getHoursWorked()
{
	double dHours = 0.0;
	bool done = false;
	const double standard = 40.0;
	const double minHours = 0.0;
	do{
		cin >> dHours;
		done = cin.fail();
		if(dHours > standard || dHours < minHours)
		{
			done = true;
		}
		if(done == true)
		{
			cout << "The hours must be valid (Max: 40 hours per week)" << endl;
	    }
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignores till the end of the line

	  }while(done == true); // end do-while

	return dHours;
} // end getHoursWorked

/**
 *  Method to get and validate rate of pay
 *  @param dHours check for overload using hours entered
 *  @returns double
 */
double getRateOfPay(double dHours)
{
	double dPay = 0.0;
	bool done = false;
	const double minWage = 9.0;
	do{
		cin >> dPay;
		done = cin.fail();
		if(dPay < minWage || dPay > numeric_limits<double>::max()/dHours)
		{
			done = true;
		}
		if(done == true)
		{
			cout << "The rate of pay must be valid (Minimum wage is $9.00.)" << endl;
	    }
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignores till the end of the line

	  }while(done == true); // end do-while

	return dPay;

} // end getRateOfPay

/**
 * Method to calculate total income
 * @param pHours number of standard hours
 * @param pRate rate of pay
 * @param pOvertime number of overtime hours
 * @returns a pointer
 */
double* payCheck(double* pHours, double* pRate, double* pOvertime)
{
	double dTotal;
	double * pTotal = &dTotal;
	*pTotal = *pHours * *pRate + (*pOvertime * *pRate * 1.5);
	return pTotal;
} // end payCheck

/**
 *  Method to get and validate overtime hours
 */
double getOvertime()
{
	double dHours = 0.0;
	bool done = false;
	const double standard = 36.0;
	const double minHours = 0.0;
	do{
		cin >> dHours;
		done = cin.fail();
		if(dHours > standard || dHours < minHours)
		{
			done = true;
		}
		if(done == true)
		{
			cout << "The hours must be valid (Max of 36 hours of overtime per week)" << endl;
	    }
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignores till the end of the line

	  }while(done == true); // end do-while

	return dHours;
} // end getOvertime

int main(int argc, char* argv[]) {

	if(argc != 1 )
		{
			cout << "usage : <executable name> " << endl;
			return(-1);
		}

	// define variables and parameters
	double dHoursWorked = 0.0;
	double dRateOfPay = 0.0;
	double dOvertimeHours = 0.0;
	double dPay;
	double *pPay = &dPay;
	const double hourMax = 40.0;
	double *pHoursWorked;
	double *pRateOfPay;
	double *pOvertimeHours;

	// prompt user, check input and display input
	cout << fixed;
	cout << setprecision(2);
	cout << "Enter standard hours worked this week: " << endl;
	dHoursWorked = getHoursWorked();
	cout <<"Standard hours worked: " << dHoursWorked << " hours." << endl;
	cout << "Enter rate of pay: " << endl;
	dRateOfPay = getRateOfPay(dHoursWorked);
	printf("Rate of pay: $%.2f\n", dRateOfPay); // example of printing format printf
    cout << endl;

    // if hours are under 40
	if(dHoursWorked < hourMax)
	{
		pHoursWorked = new double(dHoursWorked);
		pRateOfPay = new double(dRateOfPay);
		pOvertimeHours = new double(dOvertimeHours);
		pPay = payCheck(pHoursWorked, pRateOfPay, pOvertimeHours);

	}// end if statement

	// if hours are equal to 40 check for overtime
	if(dHoursWorked == hourMax)
	{
		cout << "Enter hour of overtime (0 if none)" << endl;
		dOvertimeHours = getOvertime();
		cout << "Overtime worked " << dOvertimeHours << " hours" << endl;
		cout << endl;
		pHoursWorked = new double(dHoursWorked);
		pRateOfPay = new double(dRateOfPay);
		pOvertimeHours = new double(dOvertimeHours);
		pPay = payCheck(pHoursWorked, pRateOfPay, pOvertimeHours);
	}// end if statement

	// print statements
	double holdPay = *pPay;
	cout << fixed;
	cout << setprecision(2);
	cout <<  "Pay stub:\n";
	cout << "STD Hours: " << *pHoursWorked;
	cout << setw(20) << "Overtime hours: " << *pOvertimeHours;
	cout << setw(12) << "Rate: $" << *pRateOfPay << endl;
	cout << "Total income: \n$" << holdPay <<endl;
	cout << endl;
	cout<<"argc = " << argc;

	// free memory
	delete pHoursWorked;
	delete pRateOfPay;
	delete pOvertimeHours;
	delete pPay;

	// wait for output screen
	cin.get();

	// main return statement
	return 0;
}
