#include <iostream>
#include "RomanNum.h"

int main() {
    int userInt;
    string userStr;
    bool end = false;
    int loopCount = 0;

    cout << "Welcome!\n" << endl;
    RomanNum rn;
    while (!end) {
        cout << " 1: Roman Numeral to Decimal" << endl;
        cout << " 2: Decimal to Roman Numeral" << endl;
        //cout << "\t3: Read in file" << endl; //will add this functionality if there is time
        cout << "-1: Exit\n" << endl;
        cout << "Please enter your choice numerically: ";


        cin >> userInt;
        if (userInt == 1) { //FIXME: loop on one mode to allow for ease of multiple inputs
            cout << "Enter the roman numeral you would like to convert: ";
            cin >> userStr;
            int out = rn.toDecimal(userStr);
            if (out == -1) {
                cout << "Not a valid roman numeral!" << endl;
            }
            else {
                cout << "\n" << userStr << " is " << out << "\n" << endl;
            }            
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
            cout << "Invalid input.\n" << endl;
            loopCount++;
            if (loopCount == 2) { //to deal with user inputs that would cause inf loop i.e. string/char
                end = true;
                cout << "Terminating program due to bad input." << endl;
            }
        }

    }
    return 0;
}