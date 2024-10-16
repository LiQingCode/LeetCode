/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-10-16 08:39:14
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-10-16 08:39:27
 * @FilePath: \code\LeetCode\C++\minimumAverage.cpp
 * @Description: 3194.最小元素和最大元素的最小平均值
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        double ans = (nums[0] + nums[n-1])/2.0;
        for(int left = 1, right = n-2; left < right; ++left, --right){
            ans = min((nums[left]+nums[right])/2.0, ans);
        }
        return ans;
    }
};