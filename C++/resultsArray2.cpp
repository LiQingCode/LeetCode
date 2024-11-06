/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-11-06 16:46:18
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-11-06 16:46:34
 * @FilePath: \code\LeetCode\C++\resultsArray2.cpp
 * @Description: 3254.长度为k的子数组的能量值Ⅰ
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> ans(n-k+1, -1);
        int pre = nums[0];
        for(int i = 1; i < n; ++i){
            if(nums[i]-pre==1){
                dp[i] = dp[i-1]+1;
            }
            pre = nums[i];
        }
        for(int i = k-1; i < n; ++i){
            if(dp[i]>=k){
                ans[i-k+1] = nums[i];
            }
        }
        return ans;
    }
};