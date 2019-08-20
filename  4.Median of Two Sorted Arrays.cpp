/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (25.82%)
 * Total Accepted:    403K
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */

#include <iostream>
#include <vector>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        
        int s = nums1.size() + nums2.size();
        std::vector<int> v(s);
        int i = 0, j = 0, k = 0;

        while(i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) v[k++] = nums1[i++];
            else v[k++] = nums2[j++];
        }
        while (i < nums1.size()) v[k++] = nums1[i++];
        while (j < nums2.size()) v[k++] = nums2[j++];
        
        double res;
        if (s % 2 == 0) res = (v[s/2-1] + v[s/2]) / 2.0;
        else res = v[s/2];

        return res;
    }
};