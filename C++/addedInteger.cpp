/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-08-08 15:26:14
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-08-08 15:58:02
 * @FilePath: \code\LeetCode\addedInteger.cpp
 * @Description: 
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */

class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        return *min_element(nums2.begin(),nums2.end())-*min_element(nums1.begin(), nums1.end());
    }
};