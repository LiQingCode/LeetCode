/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-09-02 08:39:36
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-09-02 08:39:52
 * @FilePath: \code\LeetCode\C++\resultsArray.cpp
 * @Description: 3275. 第K近障碍物查询
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> heap;
        int n = queries.size();
        vector<int> ans(n, -1);
        if(k>n)
            return ans;
        for(int i = 0; i < n; i++){
            int d = abs(queries[i][0])+abs(queries[i][1]);
            if(i > k-1){
                if(heap.top()>d){
                    heap.pop();
                    heap.push(d);
                }
                ans[i] = heap.top();
            }
            else if(i <= k-1){
                heap.push(d);
                if(i==k-1)
                    ans[i] = heap.top();
                else
                    ans[i] = -1;
            }
        }
        return ans;
    }
};