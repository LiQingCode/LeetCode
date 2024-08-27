/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-08-27 15:07:57
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-08-27 15:08:00
 * @FilePath: \code\LeetCode\C++\spiralOrder.cpp
 * @Description: 54. 螺旋矩阵
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int top = 0, bottom = m-1, left = 0, right = n-1, i = 0, j = 0, flag = 0;
        while(left<=right && top <= bottom){
            ans.emplace_back(matrix[i][j]);
            if(flag%4 == 0){
                if(j<right){
                    ++j;
                }else{
                    ++flag;
                    ++top;
                    ++i;
                }
            }else if(flag%4 == 1){
                if(i<bottom){
                    ++i;
                }else{
                    ++flag;
                    --right;
                    --j;
                }
            }else if(flag%4 == 2){
                if(j>left){
                    --j;
                }else{
                    ++flag;
                    --bottom;
                    --i;
                }
            }else if(flag%4 == 3){
                if(i>top){
                    --i;
                }else{
                    ++flag;
                    ++left;
                    ++j;
                }
            }
        }
        return ans;
    }
};