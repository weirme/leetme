#include <iostream>

using namespace std;

int main() {
    int n;
    int res = 0;
    int last = 0;
    int cur;
    cin >> n;
    while (n--) {
        cin >> cur;
        if (cur > last) res += (cur - last) * 6;
        else res += (last - cur) * 4;
        last = cur;
        res += 5;
    }
    cout << res;
    return 0;
}
