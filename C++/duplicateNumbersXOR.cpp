/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-10-12 08:39:51
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-10-12 08:40:04
 * @FilePath: \code\LeetCode\C++\duplicateNumbersXOR.cpp
 * @Description: 3158. 求出出现两次数字的异或值（XOR）
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        vector<int> vec(51,0);
        int ans = 0;
        for(auto num: nums){
            ++vec[num];
            if(vec[num]==2){
                ans ^= num;
            }
        }
        return ans;
    }
};