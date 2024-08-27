/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-08-27 14:19:54
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-08-27 14:19:57
 * @FilePath: \code\LeetCode\C++\setZeroes.cpp
 * @Description: 73.矩阵置零
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_set<int> setR;
        unordered_set<int> setC;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j]==0){
                    setR.insert(i);
                    setC.insert(j);
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(auto c:setC)
                matrix[i][c] = 0;
        }
        for(int i = 0; i < n; i++){
            for(auto r:setR)
                matrix[r][i] = 0;
        }
    }
};