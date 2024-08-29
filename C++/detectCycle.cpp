/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-08-29 09:31:21
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-08-29 09:31:29
 * @FilePath: \code\LeetCode\C++\detectCycle.cpp
 * @Description: 142. 环形链表Ⅱ
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)
            return NULL;
        unordered_set<ListNode*> set;
        set.insert(head);
        ListNode* p = head->next;
        while(p != NULL && set.find(p)==set.end()){
            set.insert(p);
            p = p->next;
        }
        return p;
    }
};