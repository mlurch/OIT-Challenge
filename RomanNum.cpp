#include <cctype>
#include "RomanNum.h"

int RomanNum::toDecimal(string& input) {
    int total = 0;
    for (unsigned int i = 0; i < input.size(); i++) {
        input = makeUpper(input); //to allow for upper and lowercase inputs
        if (!isRomNumKey(input.at(i))) { //checks if character is a valid roman numeral
            return -1;
        } 

        auto itr = romMap.find(input.at(i));
        if (i == (input.size() - 1)) { 
            total += itr->second; //RULE 1
        }
        else if (!isRomNumKey(input.at(i + 1))) {
            return -1;
        }
        else {
            auto itr2 = romMap.find(input.at(i + 1));
            if ((itr->second < itr2->second)) { 
                if (itr2->second > ((itr->second * 10) + 1)) { //RULE 4
                    return -1;
                }
                total += (itr2->second - itr->second); //RULE 2
                i++; //RULE 3
            }
            else { 
                total += itr->second; //RULE 1
            } 
        }        
    }
    return total;
}
string RomanNum::toRom(int input) {
    string answer;
    if (input <= 0) {
        return "invalid";
    }
    char key = isRomNumValue(input);
    if (key != 'P') {
        answer += key;
    }
    else {
        int intMod = determineMod(input);
        if (input % intMod == 4 || input % intMod == 9) {
            answer += 'M'; //FIXME
        }
    }
    return answer;
}
bool RomanNum::isRomNumKey(char toCheck) const {
    if(romMap.find(toCheck) != romMap.end()) {
        return true;
    }
    return false;
}
char RomanNum::isRomNumValue(int toCheck) const {
    for (auto kv : romMap) {
        if (kv.second == toCheck) {
            return kv.first;
        }
    }
    return 'P';
}
int RomanNum::determineMod(int toMod) { //returns the number you need to get the value of the greatest place number using modulo
    int numZeros = to_string(toMod).size() - 2;
    string strMod = "1";
    for (int i = 0; i < numZeros; i++) {
        strMod += "0";
    }
    
    int intMod = stoi(strMod);
    return intMod;
}
string RomanNum::makeUpper(string& toChange) {
    for (unsigned int i = 0; i < toChange.size(); i++) {
        toChange.at(i) = toupper(toChange.at(i));
    }
    return toChange;
}