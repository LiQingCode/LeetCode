/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-08-29 10:36:23
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-08-29 10:36:25
 * @FilePath: \code\LeetCode\C++\addTwoNumbers.cpp
 * @Description: 2. 两数相加
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *tail = nullptr;
        int cur = 0;
        while(l1 || l2){
            cur += (l1?l1->val:0) + (l2?l2->val:0);
            if(!head){
                head = tail = new ListNode(cur % 10);
            }else{
                tail->next = new ListNode(cur % 10);
                tail = tail->next;
            }
            cur = cur / 10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(cur > 0) tail->next = new ListNode(cur);
        return head;
    }
};