/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-09-19 08:44:08
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-09-19 08:44:28
 * @FilePath: \code\LeetCode\C++\longestContinuousSubstring.cpp
 * @Description: 2414. 最长的字母序连续子字符串的长度。
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.length();
        vector<int> ans(n, 1);
        char pre = s[0];
        int maxAns = 1;
        for(int i = 1; i < n; i++){
            if((int)(s[i]-pre)==1){
                ans[i] += ans[i-1];
            }
            pre = s[i];
            maxAns = max(maxAns, ans[i]);
        }
        return maxAns;
    }
};