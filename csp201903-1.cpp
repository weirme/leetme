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
const int N = 100010;


int main() {
    int vmin, vmax;
    float vmid;
    int arr[N];
    int n;
    bool flag = false;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    vmin = min(arr[0], arr[n-1]);
    vmax = max(arr[0], arr[n-1]);
    if (n % 2 == 0) {
        int t = arr[n/2-1] + arr[n/2];
        flag = (t % 2);
        vmid = t / 2.0;
    }
    else vmid = arr[n/2];
    if (flag) printf("%d %.1f %d\n", vmax, vmid, vmin);
    else printf("%d %d %d\n", vmax, int(vmid), vmin);
	return 0;
}
