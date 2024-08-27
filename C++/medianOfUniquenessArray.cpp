/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-08-27 09:58:19
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-08-27 09:58:37
 * @FilePath: \code\LeetCode\C++\medianOfUniquenessArray.cpp
 * @Description: 3134.找出为一性数组的中位数
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class Solution {
public:
    int medianOfUniquenessArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(n, 1);
        for(int left = 0; left < n-1; left++){
            unordered_set<int> set;
            set.insert(nums[left]);
            int sn = 1;
            for(int right = left+1; right < n; right++){
                if(set.find(nums[right])==set.end()){
                    set.insert(nums[right]);
                    vec.emplace_back(++sn);
                }else{
                    vec.emplace_back(sn);
                }
            }
        }
        sort(vec.begin(), vec.end());
        int vn = vec.size();
        if(vn%2==0){
            return min(vec[vn/2], vec[vn/2-1]);
        }else{
            return vec[vn/2];
        }
    }
};