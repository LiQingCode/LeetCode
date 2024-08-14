/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-08-14 15:05:30
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-08-14 15:05:35
 * @FilePath: \code\LeetCode\C++\productExceptSelf.cpp
 * @Description: 238.除自身以外数组的乘积
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        // 首先计算前缀乘
        vector<int> dpF(n, 1);
        for(int i = 1; i < n; i++){
            dpF[i] = dpF[i-1]*nums[i-1];
        }
        // 再计算后缀乘
        vector<int> dpB(n, 1);
        for(int j = n-2; j >= 0; j--){
            dpB[j] = dpB[j+1]*nums[j+1];
        }
        // 最后计算每个元素的前缀乘 * 后缀乘
        for(int k = 0; k < n; k++){
            ans[k] = dpF[k]*dpB[k];
        }
        return ans;
    }
};