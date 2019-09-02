#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool cmp(char a, char b) {
        return a == b || b == '.';
    }
    bool isMatch(string s, string p) {
        const int M = s.size(), N = p.size();
        bool dp[M+1][N+1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;
        for (int j = 1; j < M; j++)
            dp[j+1][0] = p[j] == '*' && dp[j-1][0];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (cmp(s[j], p[i])) dp[j+1][i+1] = dp[j][i];
                else if (p[i] == '*') dp[j+1][i+1] = dp[j+1][i-1] || cmp(s[j], p[i-1]) && dp[j][i+1];
            }
        }
        return dp[M][N];
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string p = stringToString(line);
        
        bool ret = Solution().isMatch(s, p);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}