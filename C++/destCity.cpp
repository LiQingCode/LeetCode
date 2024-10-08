/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-10-08 08:43:31
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-10-08 08:43:49
 * @FilePath: \code\LeetCode\C++\destCity.cpp
 * @Description: 1436. 旅行终点站
 *
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> map;
        for(auto path: paths){
            map[path[0]] = 0;
            if(map.find(path[1])==map.end()){
                map.insert({path[1], 1});
            }else{
                map[path[1]] = 0;
            }
        }
        for(auto m:map){
            if(m.second==1){
                return m.first;
            }
        }
        return "";
    }
};