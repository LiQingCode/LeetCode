/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-08-13 08:43:36
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-08-13 08:45:01
 * @FilePath: \code\LeetCode\C++\isArraySpecial.cpp
 * @Description: 3151.特殊数组Ⅰ
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size()<=1)
            return true;
        int status = nums[0]%2;
        int index = 1;
        while(index < nums.size() && status!=nums[index]%2){
            status = nums[index]%2;
            ++index;
        }
        return index==nums.size()?true:false;
    }
};