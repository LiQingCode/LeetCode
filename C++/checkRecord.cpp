/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-08-19 08:37:15
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-08-19 08:37:22
 * @FilePath: \code\LeetCode\C++\checkRecord.cpp
 * @Description: 551. 学生出勤记录 I
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class Solution {
public:
    bool checkRecord(string s) {
        int As = 0, Ls = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'A'){
                ++As;
                Ls = 0;
            }
            if(s[i] == 'P'){
                Ls = 0;
            }
            if(s[i] == 'L'){
                Ls++;
            }
            if(Ls>=3 || As>=2)
                return false;
        }
        return true;
    }
};