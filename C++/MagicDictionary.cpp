/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-08-12 09:18:17
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-08-12 09:18:35
 * @FilePath: \code\LeetCode\C++\MagicDictionary.cpp
 * @Description: leetcode 676. 实现一个魔法字典
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class MagicDictionary {
public:
    vector<string> dic;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(int i = 0; i < dictionary.size(); i++){
            dic.emplace_back(dictionary[i]);
        }
    }
    
    bool search(string searchWord) {
        int len = searchWord.length();
        for(int i = 0; i < dic.size(); i++){
            if(len == dic[i].length()){
                int count = 0;
                for(int j = 0; j < len; j++){
                    if(count < 2 && dic[i][j]!=searchWord[j]){
                        ++count;
                    }else if(count>1){
                        break;
                    }
                }
                if(count==1){
                    return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */