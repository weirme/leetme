#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size(), n = b.size();
        int p = max(m, n)+1;
        int sum;
        vector<int> res(p, 0);
        while (m && n) {
            m--; n--; p--;
            sum = (a[m]-'0') + (b[n]-'0') + res[p];
            res[p] = sum % 2;
            res[p-1] = sum / 2;
        }
        while (m) {
            m--; p--;
            sum = (a[m]-'0') + res[p];
            res[p] = sum % 2;
            res[p-1] = sum / 2;
        }
        while (n) {
            n--; p--;
            sum = (b[n]-'0') + res[p];
            res[p] = sum % 2;
            res[p-1] = sum / 2;
        }
        string ret;
        if (res[0]) ret.push_back(res[0]+'0');
        for (auto it = res.begin()+1; it < res.end(); it++) ret.push_back(*it+'0');
        return ret;
    }
};


int main() {
    string a = "1", b = "11111111111";
    Solution s;
    string res = s.addBinary(a, b);
    return 0;
}
