/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-09-09 09:09:10
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-09-09 09:09:28
 * @FilePath: \code\LeetCode\C++\mergeNodes.cpp
 * @Description: 2181. 合并零之间的节点
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
    ListNode* mergeNodes(ListNode* head) {
        int tmp = 0;
        ListNode* p = head->next, *q = head;
        while(p->next){
            if(p->val != 0){
                tmp += p->val;
            }else{
                q->val = tmp;
                q = q->next;
                tmp = 0;
            }
            p = p->next;
        }
        q->val = tmp;
        q->next = nullptr;
        return head;
    }
};