/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-08-09 08:41:02
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-08-09 09:45:42
 * @FilePath: \code\LeetCode\minimunAddedInteger.cpp
 * @Description: 
 * 给两个整数数组nums1和nums2，从nums1中移除两个元素，并且其他元素与x相加后，nums1与nums2相等。
 * 返回能够实现数组相等的最小整数x。
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        // 获取nums1的长度
        int n1 = nums1.size();
        // 对nums1和nums2进行从小到大的排序
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        // 获取nums2的最小值
        int y = nums2[0];
        // 初始化并获取nums1与nums2最小值的元素差值数组
        // 因为只移除两个元素且经过了排序，所以xs的有效长度应该是为3
        vector<int> xs(n1, 0);
        for(int i = 0; i < 3; i++){
            xs[i] = y - nums1[i];
        }
        // 对xs逐一进行验证
        for(int i = 2; i > -1; i--){
            // 定义两个指针index1和index2来验证xs[i]是否满足nums1与nums2相等
            int index1 = i, index2 = 0;
            while(index2<n1-2 && index1 < n1){
                if(nums1[index1]+xs[i]==nums2[index2])
                    ++index2;
                ++index1;
            }
            // 当index2到达nums2的最后一个元素时，说明xs[i]满足nums1与nums2相等，返回xs[i]
            if(index2 == n1-2)
                return xs[i];
        }
        return 0;
    }
};