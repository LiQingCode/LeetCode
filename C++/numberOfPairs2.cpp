/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-10-11 08:57:39
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-10-11 08:57:54
 * @FilePath: \code\LeetCode\C++\numberOfPairs2.cpp
 * @Description: 3164. 优质数对的总数Ⅱ
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, int> count1, count2;
        int maxN1 = 0;
        for(auto n1: nums1){
            ++count1[n1];
            maxN1 = max(n1, maxN1);
        }
        for(auto n2: nums2){
            ++count2[n2];
        }
        long long ans = 0;
        for(auto pair: count2){
            int a = pair.first, cnt = pair.second;
            for(int b = a*k; b <= maxN1; b+=a*k){
                if(count1.count(b)>0){
                    ans += 1L*count1[b] * cnt;
                }
            }
        }
        return ans;
    }
};