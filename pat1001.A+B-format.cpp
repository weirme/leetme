#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    string sum = to_string(a + b);
    for (auto it = sum.begin(); it < sum.end(); it++) {
        cout << *it;
        if (*it == '-') continue;
        if ((sum.end() - it) % 3 == 1 && it + 1 != sum.end()) cout << ",";
    }
    return 0;
}
