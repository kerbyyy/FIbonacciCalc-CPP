#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/*Current limit is until the 1474th term of the Fibonacci Sequence.
Anything higher would cause it to output "inf".*/

double form1, form2;
double stageDiv1, stageDiv2;
double stagePow1, stagePow2;
double finalAns, lastStg;
double squareFive;
double fibTerm;

int main() {
    string choice;

    do {
        cout << "Input the Fibonacci term you're looking for: ";
        cin >> fibTerm;

        /*Checks if the inputted value is an integer.
        If not, it will ask the user to input a value again*/
        while (cin.fail() || fibTerm < 0 || fibTerm > 1474) {
            cout << "Invalid Input. Input an integer again: ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> fibTerm;
        }

        // Gets the square root of 5
        squareFive = sqrt(5);

        // First part of Binet's Formula: (1 + √5 / 2)^n
        form1 = 1 + squareFive;
        stageDiv1 = form1 / 2;
        stagePow1 = pow(stageDiv1, fibTerm);

        // Second part of the Binet's Formula: (1 - √5 / 2)^n
        form2 = 1 - squareFive;
        stageDiv2 = form2 / 2;
        stagePow2 = pow(stageDiv2, fibTerm);

        // Final part of the Binet's Formula
        lastStg = stagePow1 - stagePow2;
        finalAns = lastStg / squareFive;

        cout << fixed;
        cout << "F" << setprecision(0) << fibTerm << " = " << "(" << setprecision(20) << stageDiv1 << ")" << "^" << setprecision(0) << fibTerm << " - " << "(" << setprecision(20) << stageDiv2 << ")" << "^" << setprecision(0) << fibTerm << " / " << setprecision(20) << squareFive << endl;
        cout << "F" << setprecision(0) << fibTerm << " = " << setprecision(20) << "(" << stagePow1 << ")" << " - " << setprecision(20) << "(" << stagePow2 << ")" << " / " << setprecision(20) << squareFive << endl;
        cout << "F" << setprecision(0) << fibTerm << " = " << setprecision(20) << lastStg << " / " << setprecision(20) << squareFive << endl;

        cout.imbue(locale(""));
        int width = to_string(finalAns).length();
        cout << "F" << setprecision(0) << fibTerm << " = " << setw(width) << setfill(' ') << finalAns;

        cout << "\n\nDo you want to try again? [Y/N] ";
        cin >> choice;
    }
    while (choice == "Yes" || choice == "yes" || choice == "Y" || choice == "y");
}