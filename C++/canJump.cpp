/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-08-14 16:03:32
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-08-14 16:05:59
 * @FilePath: \code\LeetCode\C++\canJump.cpp
 * @Description: 55. 跳跃游戏
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int to = nums.size()-1;
        if(to == 0)
            return true;
        int from = to-1;
        while(from>=0){
            if(nums[from]+from>=to)
                to = from;
            --from;
        }
        return to == 0;
    }
};