/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-08-14 08:32:40
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-08-14 09:18:35
 * @FilePath: \code\LeetCode\C++\isArraySpecial_plus.cpp
 * @Description: 3152.特殊数组Ⅱ
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */

// 暴力求解（超时）
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<bool> ans;
        for(int i = 0; i < n; i++){
            int from = queries[i][0];
            int to = queries[i][1];
            int pre = nums[from]%2;
            int index = from + 1;
            while(index <= to && nums[index]%2!=pre){
                pre = nums[index++]%2;
            }
            if(index == to + 1){
                ans.emplace_back(true);
            }else{
                ans.emplace_back(false);
            }
        }
        return ans;
    }
};

// 换一种思路，将两两相邻的整数进行比较，最后查表（依然超时）
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<bool> ans;
        vector<bool> all;
        int pre = nums[0]%2;
        for(int i = 1; i < n; i++){
            pre == nums[i]%2 ? all.emplace_back(false) : all.emplace_back(true);
            pre = nums[i]%2;
        }
        for(int j = 0; j < queries.size(); j++){
            find(all.begin()+queries[j][0], all.begin()+queries[j][1], false) != all.begin()+queries[j][1] ? ans.emplace_back(false):ans.emplace_back(true);
        }
        return ans;
    }
};

// 动态规划
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<bool> ans;
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++){
            if(nums[i-1]%2 != nums[i]%2){
                dp[i] = dp[i-1] + 1;
            }
        }
        for(int j = 0; j < queries.size(); j++){
            ans.emplace_back(dp[queries[j][1]]>=queries[j][1]-queries[j][0]+1);
        }
        return ans;
    }
};