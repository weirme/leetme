#include <iostream>

using namespace std;
const int N = 10010;

int main() {
    int n;
    cin >> n;
    int arr[N];
    int max = -1;
    int temp = -1;
    int start = 0;
    int tempStart = 0;
    int end = n-1;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        if (temp >= 0) {
            temp += arr[i];
        } else {
            temp = arr[i];
            tempStart = i;
        }
        if (temp > max) {
            max = temp;
            start = tempStart;
            end = i;
        }
    }
    if (max == -1) max = 0;
    cout << max << " " << arr[start] << " " << arr[end];
    return 0;
}
