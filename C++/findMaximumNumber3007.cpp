/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-08-21 09:36:14
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-08-21 10:43:54
 * @FilePath: \code\LeetCode\C++\findMaximumNumber3007.cpp
 * @Description: 3007. 价值和小于等于K的最大数字
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */

/*
* 模拟 暴力求解（超时）
*/

class Solution {
public:
    long long findMaximumNumber(long long k, int x) {
        long long accPrice = 0;
        long long num = 1;
        while(accPrice <= k){
            int bitLen = (int)log2(num)+1;
            for(int i = 1; i <= bitLen; i++){
                if(x*i <= bitLen)
                    accPrice += (num>>(x*i-1))&1;
            }
            // cout << "num=" << num << ", accPrice=" << accPrice << endl;
            ++num;
        }
        return num-2;
    }
};

/*
* 优化一下下试试
* 以x=7，k=363举例
* 也就是说当num为64（2^6）前是不存在任何价值的，有价值的位在第6位、第13位、第20位、第27位、第34位、第41位、第48位等等
* 第6位对应的num为64，第13位对应的num为2^13，第20位对应的num为2^20，第27位对应的num为2^27等等
* 而第6位到第7位之间的num是一直累加1，累加2^6，直到第7位为1，第六位为0，此后的64个数都没有价值，循环往复......
* 感觉还是有问题，代码通不过，还是得二分，数位dp也得学一下。
*/