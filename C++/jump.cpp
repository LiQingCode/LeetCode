/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-08-14 16:54:11
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-08-14 16:54:14
 * @FilePath: \code\LeetCode\C++\jump.cpp
 * @Description: 45. 跳跃游戏 II
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return 0;
        vector<int> minSteps(n, n-1);
        minSteps[0] = 0;
        for(int i = 0; i < n; i++){
            if(nums[i]!=0){
                for(int j = 1; j <= nums[i] && i+j < n; j++){
                    minSteps[i+j] = min(minSteps[i+j],minSteps[i]+1);
                }
            }
        }
        return minSteps[n-1];
    }
};