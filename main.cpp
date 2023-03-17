#include <iostream>
#include "RomanNum.h"

int main() {
    int userInt;
    string userStr;
    bool end = false;
    int loopCount = 0;

    cout << "Welcome!" << endl;
    RomanNum rn;
    while (!end) {
        cout << "Please enter the number of which you would like to do. Enter -1 to exit." << endl;
        cout << "\t1: Roman Numerals to Decimal" << endl;
        cout << "\t2: Decimal to Roman Numerals" << endl;
        //cout << "\t3: Read in file" << endl; //will add this functionality if there is time

        cin >> userInt;
        if (userInt == 1) {
            cout << "Enter the roman numeral you would like to convert: ";
            cin >> userStr;
            int out = rn.toDecimal(userStr);
            cout << "\n" << userStr << " is " << out << "\n" << endl;
        } 
        else if (userInt == 2) {
            cout << "Enter the decimal you would like to convert: ";
            cin >> userInt;
            string out = rn.toRom(userInt);
            cout << "\n" << userInt << " is " << out << "\n" << endl;
        }
        /* else if (userInt == 3) {
            cout << "Enter the name of the file you would like to parse: ";
        } */
        else if (userInt == -1) {
            cout << "Thank you!" << endl;
            end = true;
        }
        else {
            cout << "Invalid input." << endl;
            loopCount++;
            if (loopCount == 3) { //to deal with user inputs that would cause inf loop i.e. string/char
                end = true;
                cout << "Terminating program due to bad input." << endl;
            }
        }

    }
    return 0;
}