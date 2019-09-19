#include <string>
#include <stdlib.h>

using namespace std;

class AutoMachine {
private:
    int state = 0;

public:
    void step(char c) {
        switch (state) {
            case 0:
                if (isspace(c));
                else if (isdigit(c)) state = 1;
                else if (c == '+' || c == '-') state = 8;
                else if (c == '.') state = 7;
                else state = -1;
                break;
            case 1:
                if (isdigit(c));
                else if (c == '.') state = 2;
                else if (c == 'e') state = 3;
                else if (isspace(c)) state = 6;
                else state = -1;
                break;
            case 2:
                if (isdigit(c)) state = 4;
                else if (c == 'e') state = 3;
                else if (isspace(c)) state = 6;
                else state = -1;
                break;
            case 3:
                if (isdigit(c)) state = 5;
                else if (c == '+' || c == '-') state = 9;
                else state = -1;
                break;
            case 4:
                if (isdigit(c));
                else if (c == 'e') state = 3;
                else if (isspace(c)) state = 6;
                else state = -1;
                break;
            case 5:
                if (isdigit(c));
                else if (isspace(c)) state = 6;
                else state = -1;
                break;
            case 6:
                if (isspace(c));
                else state = -1;
                break;
            case 7:
                if (isdigit(c)) state = 4;
                else state = -1;
                break;
            case 8:
                if (isdigit(c)) state = 1;
                else if (c == '.') state = 7;
                else state = -1;
                break;
            case 9:
                if (isdigit(c)) state = 5;
                else state = -1;
                break;
            default:
                state = -1;
                break;
        }
    }
    
    bool isAccepted() {
        return state == 1 || state == 2 || state == 4 || state == 5 || state == 6;
    }
};

class Solution {
public:
    bool isNumber(string s) {
        AutoMachine AM;
        for (string::iterator it = s.begin(); it < s.end(); it++)
            AM.step(*it);
        return AM.isAccepted();
    }
};


int main() {
    string str = " 6e-1";
    Solution s;
    bool res = s.isNumber(str);
    return 0;
}
