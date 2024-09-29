/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-09-29 09:06:35
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-09-29 09:06:48
 * @FilePath: \code\LeetCode\C++\timeRequiredToBuy.cpp
 * @Description: 2073.买票需要的时间
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += tickets[i]<=tickets[k]?tickets[i]:tickets[k];
            ans -= i>k && tickets[i]>=tickets[k] ? 1 : 0;
        }
        return ans;
    }
};