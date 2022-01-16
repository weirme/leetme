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

void quickSort(int * arr, int low, int high) {
    if (low < high) {
        int i = low;
        int j = high;
        int x = arr[i];
        while (i < j) {
            while (i < j && x < arr[j]) j--;
            if (i < j) arr[i] = arr[j];
            while (i < j && x > arr[i]) i++;
            if (i < j) arr[j] = arr[i];
        }
        arr[i] = x;
        quickSort(arr, low, i-1);
        quickSort(arr, i+1, high);
    }
}
