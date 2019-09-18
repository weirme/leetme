#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> arr;
        for (int i = 1; i <= n; i++) arr.push_back(i);
        string res;
        int t;
        k--;
        while (!arr.empty()) {
            n--;
            t = k / factorial[n];
            k = k % factorial[n];
            res.push_back(arr[t]+'0');
            arr.erase(arr.begin()+t);
        }
        return res;
    }

private:
    int factorial[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
};


int main() {
    int n = 4, k = 9;
    Solution s;
    string res = s.getPermutation(n, k);
}
