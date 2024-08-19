/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-08-19 08:32:51
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-08-19 08:35:36
 * @FilePath: \code\LeetCode\C++\minimumOperationsToMakeKPeriodic.cpp
 * @Description: 3137.K周期字符串需要的最少操作次数
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n = word.length();
        int t = n/k;
        int ans = 0;
        unordered_map<string, int> map;
        for(int i = 0; i < n; i = i + k){
            if(map.find(word.substr(i, k))==map.end()){
                map.insert({word.substr(i, k), 1});
            }else{
                ++map[word.substr(i, k)];
            }
        }
        for(auto item : map){
            ans = max(item.second, ans);
        }
        return t-ans;
    }
};