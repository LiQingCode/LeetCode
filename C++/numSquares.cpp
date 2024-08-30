/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-08-30 15:12:09
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-08-30 15:12:30
 * @FilePath: \code\LeetCode\C++\numSquares.cpp
 * @Description: 279. 完全平方数
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        for(int i = 1; i < n+1; i++){
            int minv = n;
            for(int j = 1; j*j<=i; j++){
                minv = min(minv, dp[i-j*j]);
            }
            dp[i] = minv + 1;
        }
        return dp[n];
    }
};