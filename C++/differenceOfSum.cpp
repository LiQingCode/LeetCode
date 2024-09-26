/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-09-26 08:42:43
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-09-26 08:42:51
 * @FilePath: \code\LeetCode\C++\differenceOfSum.cpp
 * @Description: 2535. 数组元素和与数字和的绝对差
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int ans = 0;
        for(auto num:nums){
            ans += num;
            while(num){
                ans -= num%10;
                num /= 10;
            }
        }
        return ans;
    }
};