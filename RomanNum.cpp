#include <cctype>
#include "RomanNum.h"

RomanNum::RomanNum() { }
int RomanNum::toDecimal(string& input) {
    int total = 0;
    for (unsigned int i = 0; i < input.size(); i++) {
        input = makeUpper(input); //to allow for upper and lowercase inputs
        if (!isRomNum(input.at(i))) { //checks if character is a valid roman numeral
            return -1;
        } 

        auto itr = romMap.find(input.at(i));
        if (i == (input.size() - 1)) {
            total += itr->second;
        }
        else if (!isRomNum(input.at(i + 1))) {
            return -1;
        }
        else {
            auto itr2 = romMap.find(input.at(i + 1));
            if (itr->second < itr2->second) {
                if (itr2->second > ((itr->second * 10) + 1)) {
                    return -1;
                }
                total += (itr2->second - itr->second);
                i++;
            }
            
            else {
                total += itr->second;
            } 
        }        
    }
    return total;
}
string RomanNum::toRom(int input) {
    return "nice";
}
bool RomanNum::isRomNum(char toCheck) const {
    if(romMap.find(toCheck) != romMap.end()) {
        return true;
    }
    return false;
}
string RomanNum::makeUpper(string& toChange) {
    for (unsigned int i = 0; i < toChange.size(); i++) {
        toChange.at(i) = toupper(toChange.at(i));
    }
    return toChange;
}