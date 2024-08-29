/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-08-29 08:44:53
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-08-29 08:45:16
 * @FilePath: \code\LeetCode\C++\satisfiesConditions.cpp
 * @Description: 3142. 判断矩阵是否满足条件
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int j = 1; j < n; j++){
            if(grid[0][j-1]==grid[0][j])
                return false;
        }
        for(int j = 0; j < n; j++){
            for(int i = 1; i < m; i++){
                if(grid[0][j]!=grid[i][j])
                    return false;
            }
        }
        return true;
    }
};