/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-08-15 09:56:46
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-08-15 09:56:48
 * @FilePath: \code\LeetCode\C++\maxScore.cpp
 * @Description: 3148. 矩阵中的最大得分
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> mat(m, vector<int>(n, -99999));
        int ans = -99999;
        // compute last row
        for(int i = n-2; i > -1; i--){
            mat[m-1][i] = max(grid[m-1][i+1]-grid[m-1][i], mat[m-1][i+1]+grid[m-1][i+1]-grid[m-1][i]);
            ans = max(ans, mat[m-1][i]);
        }
        // compute last col
        for(int i = m-2; i > -1; i--){
            mat[i][n-1] = max(grid[i+1][n-1]-grid[i][n-1], mat[i+1][n-1]+grid[i+1][n-1]-grid[i][n-1]);
            ans = max(ans, mat[i][n-1]);
        }
        // compute other data
        for(int i = m-2; i > -1; i--){
            for(int j = n-2; j > -1; j--){
                mat[i][j] = max(max(grid[i+1][j]-grid[i][j], mat[i+1][j]+grid[i+1][j]-grid[i][j]), max(grid[i][j+1]-grid[i][j], mat[i][j+1]+grid[i][j+1]-grid[i][j]));
                ans = max(ans, mat[i][j]);
            }
        }
        return ans;
    }
};