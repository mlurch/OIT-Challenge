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
    int toDecimal(string& input);
    string toRom(int input);
    bool isRomNumKey(char toCheck) const;
    char isRomNumValue(int toCheck) const;
    int determineMod(int toMod);
    string makeUpper(string& toChange);
};