/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-08-26 09:48:55
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-08-26 09:49:16
 * @FilePath: \code\LeetCode\C++\getImportance.cpp
 * @Description: 690. 员工的重要性
 *
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved.
 */
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution
{
public:
    int getImportance(vector<Employee *> employees, int id)
    {
        int n = employees.size();
        unordered_map<int, int> map;
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            map.insert({employees[i]->id, i});
            if (id == employees[i]->id)
                index = i;
        }
        return employees[index]->importance + sub_add(employees, employees[index]->subordinates, map);
    }
    int sub_add(vector<Employee *> employees, vector<int> ids, unordered_map<int, int> map)
    {
        if (ids.size() == 0)
            return 0;
        int subAll = 0;
        for (int subId : ids)
        {
            subAll += sub_add(employees, employees[map[subId]]->subordinates, map) + employees[map[subId]]->importance;
        }
        return subAll;
    }
};