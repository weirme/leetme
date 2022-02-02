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

void quick_sort(vector<int>& nums, int begin, int end) {
    if (begin < end) {
        int i = begin, j = end;
        int x = nums[i];
        while (i < j) {
            while (i < j && nums[j] >= x) j--;
            if (i < j) nums[i] = nums[j];
            while (i < j && nums[i] <= x) i++;
            if (i < j) nums[j] = nums[i];
        }
        nums[i] = x;
        quick_sort(nums, begin, i-1);
        quick_sort(nums, i+1, end);
    }
}

void merge_sort(vector<int>& nums, int begin, int end) {
    static vector<int> vec(nums.size());
    if (begin < end) {
        int mid = begin + (end-begin)/2;
        merge_sort(nums, begin, mid);
        merge_sort(nums, mid+1, end);
        int i = begin, j = mid+1, k = begin;
        while (i <= mid && j <= end) {
            if (nums[i] < nums[j]) vec[k++] = nums[i++];
            else vec[k++] = nums[j++];
        }
        while (i <= mid) vec[k++] = nums[i++];
        while (j <= end) vec[k++] = nums[j++];
        for (i = begin; i <= end; i++) {
            nums[i] = vec[i];
        }
    }
}

void insert_sort(vector<int>& nums, int n) {
    for (int i = 1; i < n; i++) {
        int j = i-1;
        int x = nums[i];
        while (j >= 0 && nums[j] > x) {
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = x;
    }
}

void bubble_sort(vector<int>& nums, int n) {
    for (int i = 0; i < n-1; i++) {
        bool flag = true;
        for (int j = 0; j < n-i-1; j++) {
            if (nums[j] > nums[j+1]) {
                swap(nums[j], nums[j+1]);
                flag = false;
            }
        }
        if (flag) break;
    }
}

void select_sort(vector<int>& nums, int n) {
    for (int i = 0; i < n-1; i++) {
        int t = i;
        for (int j = i+1; j < n; j++) {
            if (nums[j] < nums[t]) t = j;
        }
        swap(nums[t], nums[i]);
    }
}


int main() {
    vector<int> nums = {8,7,4,7,8,1,4,5,0,9,2,3};
    select_sort(nums, 12);
    return 0;
}
