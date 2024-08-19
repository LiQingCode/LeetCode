/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-08-19 08:38:25
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-08-19 10:05:02
 * @FilePath: \code\LeetCode\C++\checkRecord2.cpp
 * @Description: 552. 学生缺勤记录Ⅱ
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */

class Solution {
public:
    static constexpr int MOD = 1000000007;
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3)));
        dp[0][0][0] = 1;
        for(int i = 1; i <= n ; i++){
            // P
            for(int j = 0; j < 2; j++){
                for(int k = 0; k < 3; k++){
                    dp[i][j][0] = (dp[i][j][0] + dp[i-1][j][k])%MOD;
                }
            }
            // A
            for(int k = 0; k < 3; k++){
                dp[i][1][0] = (dp[i][1][0] + dp[i-1][0][k])%MOD;
            }
            // L
            for(int j = 0; j < 2; j++){
                for(int k = 1; k < 3; k++){
                    dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k-1])%MOD;
                }
            }
        }
        int sum = 0;
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 3; k++){
                sum = (sum + dp[n][j][k])%MOD;
            }
        }
        return sum;
    }
};