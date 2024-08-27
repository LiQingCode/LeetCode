/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-08-27 13:57:11
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-08-27 13:57:25
 * @FilePath: \code\LeetCode\C++\firstMissingPositive.cpp
 * @Description: 41. 缺失的第一个正数
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int index = 0, cur = 1;
        while(index < n && nums[index]<=0)
            ++index;
        while(index < n && nums[index]<=cur){
            if(nums[index]==cur)
                ++cur;
            ++index;
        }
        return cur;
    }
};