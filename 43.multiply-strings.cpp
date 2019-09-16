#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        const int M = num1.size(), N = num2.size();
        int res[M+N];
        memset(res, 0, sizeof(res));
        for (int i = M-1; i >= 0; i--) {
            for (int j = N-1; j >= 0; j--) {
                int prod = (num1[i] - '0') * (num2[j] - '0');
                int sum = res[i+j+1] + prod;
                res[i+j+1] = sum % 10;
                res[i+j] += sum / 10;
            }
        }
        string ret;
        for (int item : res) 
            if (!(ret.empty() && item == 0)) ret.push_back(item + '0');
        return ret.empty() ? "0" : ret;
    }
};