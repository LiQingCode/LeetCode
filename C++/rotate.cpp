/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-08-27 15:17:47
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-08-27 15:17:59
 * @FilePath: \code\LeetCode\C++\rotate.cpp
 * @Description: 48. 旋转图像
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> ans = matrix;
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < matrix.size(); j++){
                ans[j][n-1-i] = matrix[i][j];
            }
        }
        matrix = ans;
    }
};