/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-09-14 08:42:27
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-09-14 08:42:54
 * @FilePath: \code\LeetCode\C++\removeStars.CPP
 * @Description: 2390. 从字符串中移除星号
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class Solution {
public:
    string removeStars(string s) {
        int n = s.length();
        int count = 0;
        string ans = "";
        for(int i = n-1; i >= 0; i--){
            if(s[i]=='*'){
                count += 1;
            }else{
                if(count > 0){
                    count -= 1;
                }else{
                    ans += s[i];
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};