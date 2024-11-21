/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-11-21 08:44:49
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-11-21 09:20:16
 * @FilePath: \code\LeetCode\C++\KthCharacter2.cpp
 * @Description: 3307.找出第K个字符Ⅱ
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if(k == 1)
        {
            return 'a';
        }
        // 与前面的题目差不多，只不过变为了要么单纯复制，要么复制后循环+1（后者就是前一道题目的情况）
        // 前一道题目求的是前m位的第n位字符问题，主要求n
        // 这一道题目，不仅要求n，还要求m
        // 因为m对应的是复制操作
        // 例如k=5的情况下，n为1，m为4（对应2的2次方，也就是复制了2次，采用operations[2-1]）
        // 所以k任意取值的情况下，计算出复制次数count
        // 只需要把上一题中的1+kthCharacter(k）替换为operations[count-1]+kthCharacter(k, operations)即可
        // 考虑k的范围可能很大
        // 返回 (operations[count-1] + kthCharacter(k, operations) - 'a')%26 + 'a';
        long long i = 1, count = 0;
        while(i < k)
        {
            i = i << 1;
            ++count;
        }
        k = k - i / 2;
        return (operations[count-1] + kthCharacter(k, operations) - 'a')%26 + 'a';
    }
};