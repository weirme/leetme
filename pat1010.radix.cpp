#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int char2int(char c) {
    if (c <= '9') return c - '0';
    else return c - 'a' + 10;
}

long long string2decimal(string str, long long radix) {
    long long res = 0;
    for (auto it = str.begin(); it < str.end(); it++) {
        res = res * radix + char2int(*it);
    }
    return res;
}

int main() {
    string sa, sb, snotag;
    long long numtag;
    int tag;
    long long radix;
    cin >> sa >> sb >> tag >> radix;
    if (tag == 1) {
        numtag = string2decimal(sa, radix);
        snotag = sb;
    } else {
        numtag = string2decimal(sb, radix);
        snotag = sa;
    }
    long long start, end, mid;
    auto it = max_element(snotag.begin(), snotag.end());
    start = char2int(*it) + 1;
    end = max(start, numtag);
    while (start <= end) {
        mid = (start + end) / 2;
        long long numnotag = string2decimal(snotag, mid);
        if (numnotag < numtag) start = mid + 1;
        else if (numnotag > numtag || numnotag < 0) end = mid - 1;
        else {
            cout << mid;
            return 0;
        }
    }
    cout << "Impossible";
    return 0;
}
