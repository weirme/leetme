#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int rear = m + n - 1;
        m--; n--;
        while (m >= 0 && n >= 0) {
            if (nums1[m] >= nums2[n]) nums1[rear--] = nums1[m--];
            else nums1[rear--] = nums2[n--];
        }
        while (n >= 0) nums1[rear--] = nums2[n--];
    }
};


int main() {
    int a1[] = {1,2,3,0,0,0}, a2[] = {2,5,6};
    vector<int> nums1(a1, a1+6), nums2(a2, a2+3);
    Solution s;
    s.merge(nums1, 3, nums2, 3);
    return 0;
}
