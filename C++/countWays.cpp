/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-09-04 09:32:25
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-09-04 09:32:31
 * @FilePath: \code\LeetCode\C++\countWays.cpp
 * @Description: 2860. 让所有学生保持开心的分组方法数
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n+1, 0);
        dp[0] = nums[0]==0?0:1;
        dp[n] = n>nums[n-1]?1:0;
        for(int i = 0; i < n-1; i++){
            int a = 0;
            if(i+1>nums[i] && i+1<nums[i+1])
                a = 1;
            dp[i+1] = dp[i] + a;
        }
        return dp[n]+dp[n-1];
    }
};