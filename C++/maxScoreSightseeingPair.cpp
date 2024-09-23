/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-09-23 09:11:38
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-09-23 09:11:53
 * @FilePath: \code\LeetCode\C++\maxScoreSightseeingPair.cpp
 * @Description: 1014. 最佳观光组合
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int mx = values[0];
        int ans = mx + values[1] - 1;
        for(int i = 1; i < n-1; ++i){
            mx = max(mx, values[i]+i);
            ans = max(ans, mx + values[i+1]-i-1);
        }
        return ans;
    }
};