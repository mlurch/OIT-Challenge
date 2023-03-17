#include <string>
#include <cctype>
#include <map>

using namespace std;

class RomanNum {
private:
    map<char, int> romMap = {
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000}
    };
public:
    RomanNum();
    int toDecimal(string& input);
    string toRom(int input);
    bool isRomNum(char toCheck) const;
    string makeUpper(string& toChange);
};