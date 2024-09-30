/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-09-30 09:07:43
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-09-30 09:08:39
 * @FilePath: \code\LeetCode\C++\SeatManager.cpp
 * @Description: 1845. 座位预约管理系统
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> smallHeap;
    int minSeat;
public:
    SeatManager(int n) {
        this->minSeat = 0;
    }
    
    int reserve() {
        int tmpSeat = 0;
        if(!smallHeap.empty()){
            tmpSeat = smallHeap.top();
            smallHeap.pop();
            return tmpSeat;
        }else{
            tmpSeat = this->minSeat += 1;
        }
        return tmpSeat;
    }
    
    void unreserve(int seatNumber) {
        smallHeap.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */