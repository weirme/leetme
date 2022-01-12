#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

int do_ops(int a, int b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case 'x':
            return a * b;
        case '/':
            return a / b;
        default:
            return 0;
    }
}

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

void push_pop(stack<int>& nums, stack<char>& ops) {
    int b = nums.top();
    nums.pop();
    int a = nums.top();
    nums.pop();
    char op = ops.top();
    ops.pop();
    int res = do_ops(a, b, op);
    nums.push(res);
}

int main() {
    stack<int> nums;
    stack<char> ops;
    int n;
    string str;
    cin >> n;
    getchar();
    while (n--) {
        string str;
        cin >> str;
        for (auto it = str.begin(); it < str.end(); it++) {
            char c = *it;
            if (is_digit(c)) {
                nums.push(c - '0');
                if (!ops.empty() && (ops.top() == 'x' || ops.top() == '/'))
                    push_pop(nums, ops);
            }
            else {
                ops.push(c);
            }
        }
        while (!ops.empty()) {
            push_pop(nums, ops);
        }
        if (nums.top() == 24) cout << "Yes" << endl;
        else cout << "No" << endl;
        nums.pop();
    }
	return 0;
}
