#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;
    int sum = 0;
    for (auto it = str.begin(); it < str.end(); it++)
        sum = sum + *it - '0';
    string s = to_string(sum);
    string map[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    cout << map[*s.begin() - '0'];
    for (auto it = s.begin()+1; it < s.end(); it++)
        cout << " " << map[*it - '0'];
    return 0;
}
