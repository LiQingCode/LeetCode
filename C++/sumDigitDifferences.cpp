/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-08-30 09:52:41
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-08-30 09:52:53
 * @FilePath: \code\LeetCode\C++\sumDigitDifferences.cpp
 * @Description: 3153. 所有数对中位数不同之和
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */

// 暴力求解（超时）
class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        int test = nums[0], count = 1;
        while(test/10){
            test /= 10;
            ++count;
        }
        vector<vector<int>> Ns(n, vector<int>(count, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < count; j++){
                Ns[i][j] = nums[i]%10;
                nums[i] /= 10;
            }
        }
        for(int k = 0; k < count; k++){
            for(int i = 0; i < n-1; i++){
                for(int j = i + 1; j < n; j++){
                    if(Ns[i][k]!=Ns[j][k])
                        ++ans;
                }
            }
        }
        return ans;
    }
};
// 按位计数
class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        while(nums[0]>0){
            vector<long long> cnt(10, 0);
            for(int i = 0; i < n; i++){
                ++cnt[nums[i]%10];
                nums[i] /= 10;
            }
            for(int i = 0; i < 10; i++){
                ans += (n-cnt[i])*cnt[i];
            }
        }
        return ans/2;
    }
};