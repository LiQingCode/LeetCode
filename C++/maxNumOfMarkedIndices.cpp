/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-09-12 09:30:20
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-09-12 09:30:37
 * @FilePath: \code\LeetCode\C++\maxNumOfMarkedIndices.cpp
 * @Description: 
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = n/2, ans = 0;
        while(left < n/2 && right < n){
            if(nums[left]*2 <= nums[right]){
                ans += 2;
                left += 1;
            }
            right += 1;
        }
        return ans;
    }
};