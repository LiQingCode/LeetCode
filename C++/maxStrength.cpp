/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-09-03 09:10:02
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-09-03 09:11:29
 * @FilePath: \code\LeetCode\C++\maxStrength.cpp
 * @Description: 2708. 一个小组的最大实力值
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
// 没想到用动态规划做，直接乘积+分情况判断
class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        int count = 0, Acount = 0, maxNeg = -9;
        for(int i = 0; i < n; i++){
            if(nums[i]!=0){
                if(ans != 0)
                    ans *= nums[i];
                else
                    ans = nums[i];
            }
            if(nums[i]<0){
                maxNeg = max(nums[i], maxNeg);
                ++count;
            }
            if(nums[i]>0){
                ++Acount;
            }
        }
        if(ans < 0 && n==1)
            return ans;
        if(ans < 0)
            ans /= maxNeg;
        if(Acount==0 && count == 1)
            ans = 0;
        return ans;
    }
};

// 动态规划
class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long mn = nums[0], mx = mn;
        for (int i = 1; i < nums.size(); i++) {
            long long x = nums[i];
            long long tmp = mn;
            mn = min({mn, x, mn * x, mx * x});
            mx = max({mx, x, tmp * x, mx * x});
        }
        return mx;
    }
};