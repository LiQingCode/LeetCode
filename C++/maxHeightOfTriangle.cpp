/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-10-15 08:50:15
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-10-15 08:50:31
 * @FilePath: \code\LeetCode\C++\maxHeightOfTriangle.cpp
 * @Description: 3200. 三角形的最大高度
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int ans = 0;
        // red frist
        int k = 1, red1 = red, blue1 = blue;
        while(red1 >= 0 && blue1 >= 0){
            red1 -= k++;
            blue1 -= k++;
        }
        if(red1 < 0)
            ans = k - 3;
        else
            ans = k - 2;
        // blue frist
        int red2 = red, blue2 = blue;
        k = 1;
        while(red2 >=0 && blue2 >= 0){
            blue2 -= k++;
            red2 -= k++;
        }
        if(blue2 < 0)
            ans = max(ans, k - 3);
        else
            ans = max(ans, k - 2);
        return ans;
    }
};