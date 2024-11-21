/*
 * @Author: LiQingCode 2535735432@qq.com
 * @Date: 2024-11-21 08:43:26
 * @LastEditors: LiQingCode 2535735432@qq.com
 * @LastEditTime: 2024-11-21 09:11:15
 * @FilePath: \code\LeetCode\C++\kthCharacter1.cpp
 * @Description: 3304.找出第K个字符Ⅰ
 * 
 * Copyright (c) 2024 by LiQingCode, All Rights Reserved. 
 */
class Solution {
public:
    char kthCharacter(int k) {
        // 当k为1时，字符串中只有a字符
        if(k == 1)
        {
            return 'a';
        }
        // 当k大于1时，字符串相当于复制了一遍后对复制的字符循环加1
        // 因此可以有以下结果（中间加空格是为了区分上一层的结果，实际上没有空格）
        // j为复制次数
        // j = 1时（长度为2）， a b
        // j = 2时（长度为4）， ab bc
        // j = 3时（长度为8）， abbc bccd
        // j = 4时（长度为16）， abbcbccd bccdcdde
        // 显而易见，长度的产生符合2的j次方
        // 当k=5时，k介于4与8之间，且k比4大1，所以k对应的是前4位中的第1位字符加1
        // 而前4位的第1位字符显而易见是a，所以我们递归的结果必然是 1+kthCharacter(1)
        // 再考虑一个k=10的例子
        // k介于8和16之间，那么k对应的是前8位中的第2位字符加1
        // 那么递归结果应该是1+kthCharacter(2)
        // 很明显，2并不是我们想要的递归结果，我们需要继续深入
        // k=2时，k对应的是前1位中的第1位字符加1
        // 该层递归的结果是1+kthCharacter(1)
        // 那么问题就转换为了如何求前m位的第n位字符问题（主要是第n位字符）
        // 可以初始化i为1
        int i = 1;
        while(i < k)
        {
            // 循环左移，每左移一次相当于i = i*2
            i = i << 1;
        }
        // 当i大于等于k时，将i恢复到i/2（例如k=5，介于4和8，此时的i就是8，需要恢复到4）
        k = k - i / 2;
        // 计算得到的新k就是第n位字符，可以打印出来看一看
        cout << k;
        // 将第n位字符继续递归，但别忘记+1，因为每复制一次都会对字符+1（由于本题k的范围是1~500，所以不会出现z变a的情况）
        return 1 + kthCharacter(k);
        // 如果k的取值范围很大的情况下，将递归结果-'a'，得到+1的次数，对其与26取余，最后加上'a'就是最终结果。
        // return (1 + kthCharacter(k) - 'a')%26 + 'a';
    }
};