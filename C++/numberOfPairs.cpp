/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-10-10 08:50:54
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-10-10 08:51:07
 * @FilePath: \code\LeetCode\C++\numberOfPairs.cpp
 * @Description: 3162.优质数对的总数Ⅰ
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n = nums1.size(), m = nums2.size(), nIndex = 0, mIndex = 0;
        for(int i = 0; i < n; ++i){
            nums1[i] = (nums1[i]/k>0)&&(nums1[i]%k==0)?nums1[i]/k:0;
        }
        int ans = 0;
        for(int i = 0; i < n; ++i){
            if(nums1[i] != 0){
                for(int j = 0; j < m; ++j){
                    ans += (nums1[i]/nums2[j]>0)&&(nums1[i]%nums2[j]==0)?1:0;
                }
            }
        }
        return ans;
    }
};