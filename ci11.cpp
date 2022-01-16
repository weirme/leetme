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

int minArray(int* numbers, int numbersSize){
    int low = 0;
    int high = numbersSize - 1;
    int mid;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (numbers[mid] < numbers[high])
            high = mid;
        else if (numbers[mid] > numbers[high])
            low = mid + 1;
        else high--;
    }
    return numbers[low];
}
