/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-09-05 09:04:23
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-09-05 09:04:35
 * @FilePath: \code\LeetCode\C++\clearDigits.cpp
 * @Description: 3174. 清除数字
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class Solution {
public:
    string clearDigits(string s) {
        int len = s.length();
        string ans = "";
        int count = 0;
        for(int i = len-1; i > -1; i--){
            if(s[i]>='0' && s[i]<='9'){
                count++;
            }else{
                if(count>0){
                    --count;
                }else{
                    ans += s[i];
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};