/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (46.65%)
 * Total Accepted:    347K
 * Total Submissions: 741.4K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array'end length.
 * 
 */

#include <iostream>
#include <vector>

class Solution {
public:
    void sift(std::vector<int>& nums, int front, int end) {
        int i = front, j = 2*i;
        while (j <= end) {
            if (j < end && nums[j] < nums[j+1]) j++;
            if (nums[j] < nums[i]) return;
            nums[0] = nums[i];
            nums[i] = nums[j];
            nums[j] = nums[0];
            i = j;
            j = 2*i;
        }
        return;
    }

    int findKthLargest(std::vector<int>& nums, int k) {
        nums.insert(nums.begin(), 0);
        int end = nums.size()-1;
        for (int i = end/2; i > 0; i--) sift(nums, i, end);
        for (int i = 0; i < k; i++) {
            nums[0] = nums[end-i];
            nums[end-i] = nums[1];
            nums[1] = nums[0];
            sift(nums, 1, end-i-1);
            for (int i = 0; i <= end; i++) 
                std::cout << nums[i] << " ";
            std::cout << std::endl;
        }
        return nums[end-k+1];
    }
};
