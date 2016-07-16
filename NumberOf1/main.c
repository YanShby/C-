//
//  main.c
//  NumberOf1
//
//  Created by Yans on 7/14/16.
//  Copyright © 2016 Yans. All rights reserved.
//

#include <stdio.h>

/**
    二进制中1的个数
    e.g 9的二进制是1001,那个输入9,输出2.
 
    记,把一个整数减去1之后再和原来的证书做与运算,得到的结果相当于是把整数的二进制表示中的最右一个1变成0.
    记,把整数右移一位和把整数除以2在数学上是等价的.但是除法的效率比位移运算要低得多.
 */
//没有考虑到负数的情况,会造成死循环.
int NumberOf1_1(int n) {
    int count = 0;
    while (n) {
        if (n & 1) {
            count ++;
        }
        n = n >> 1;
    }
    return count;
}
//常规解法
int NumberOf1_2(int n) {
    int count = 0;
    int flag = 1;
    while (flag) {
        if (n & flag) {
            count ++;
        }
        flag = flag << 1;
    }
    return count;
}
//循环次数少的解法,优等解法.
int NumberOf1_3(int n) {
    int count = 0;
    while (n) {
        count ++;
        n = (n-1) & n;
    }
    return count;
}
//判断是否是2的倍数.
int isTwo(int n){
    if ((n-1) & n) {
        return 0;
    }
    else
        return 1;
}
//输入两个整数m和n, 计算需要改变m的二进制表示中的多少位才能得到n.
int changeNumber(int m, int n) {
    int t = m ^ n;
    return NumberOf1_3(t);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int x;
    scanf("%d",&x);
    printf("NumberOf1_1(x):%d\nNumberOf1_2(x):%d\nNumberOf1_3(x):%d\n",NumberOf1_1(x),NumberOf1_2(x),NumberOf1_3(x));
    printf("%d\n",isTwo(x));
    printf("%d\n",changeNumber(10, 13));
    return 0;
}
