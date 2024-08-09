/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-08-09 16:37:25
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-08-09 16:38:13
 * @FilePath: \code\LeetCode\merge.cpp
 * @Description: 
 * 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
 * 请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<int> pre = intervals[0];
        int i = 1;
        for(; i < n; i++){
            if(pre[1]>=intervals[i][0]){
                pre[1] = max(intervals[i][1], pre[1]);
            }else{
                ans.emplace_back(pre);
                pre = intervals[i];
            }
        }
        if(i==n){
            ans.emplace_back(pre);
        }
        return ans;
    }
};