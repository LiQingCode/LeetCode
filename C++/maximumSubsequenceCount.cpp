/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-09-24 08:53:09
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-09-24 08:53:29
 * @FilePath: \code\LeetCode\C++\maximumSubsequenceCount.cpp
 * @Description: 2207.字符串中最多数目的子序列
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        vector<char> patext;
        for(auto ch:text){
            if(ch == pattern[0] || ch == pattern[1]){
                patext.emplace_back(ch);
            }
        }
        int n = patext.size();
        int count = 0;
        long long ans = 0;
        for(auto pa:patext){
            if(pa==pattern[0]){
                count += 1;
            }else{
                ans += count;
            }
        }
        if(pattern[0]==pattern[1]){
            return (long long)n*(n+1)/2;
        }
        return ans + max(n-count, count);
    }
};