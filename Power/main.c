//
//  main.c
//  Power
//
//  Created by Yans on 7/14/16.
//  Copyright © 2016 Yans. All rights reserved.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/**
    实现函数double Power(double base, int exponent),求base 的exponent次方.
    不得使用库函数,不需要考虑大数问题.
 */
/*
    由于计算机表示小数(float和double)都有误差,我们不能直接用==来判断两个数是否相等.
    如果两个小数的差的绝对值很小,例如0.0000001,就可以认为他们相等.
*/
bool equal(double num1, double num2) {
    if ((num1 - num2 < 0.0000001) && (num1 - num2 > -0.0000001)) {
        return true;
    }
    else
        return false;
}

double PowerWithUnsignedExponent(double base, int exponent) {
    double result = 1.0;
    for (int i = 1; i <= exponent; i++) {
        result *= base;
    }
    return result;
}
/*
    求a的n次方.
    当n为偶数的时候:a^n = a^(n/2)*a^(n/2);
    当n为奇数的时候:a^n = a^((n-1)/2)*a^((n-1)/2)*a;
 */
double PowerWithUnsignedExponent_best(double base, int exponent) {
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;
    
    double result = PowerWithUnsignedExponent_best(base, exponent >> 1);
    result *= result;
    if ((exponent & 1) == 1)
        result *= base;
    
    return result;
}
double Power(double base, int exponent) {
    //判断底数是0的情况.
    if (equal(base, 0.0) && exponent < 0) {
        return 0.0;
    }
    
    unsigned int absExponent = (unsigned int)exponent;
    
    //判断指数exponent是负数的情况.
    if (exponent < 0) {
        absExponent = (unsigned int)(-exponent);
    }
    //执行乘积.
    double result = PowerWithUnsignedExponent_best(base, absExponent);
    //负数情况取倒数.
    if (exponent < 0) {
        result = 1.0/result;
    }
    return result;
}
/**
    转换成二进制
 */
char* itoa(int num,char*str,int radix)
{/*索引表*/
    char index[] = "0123456789ABCDEF";
    unsigned unum;/*中间变量*/
    int i = 0,j,k;
    /*确定unum的值*/
    if(radix == 10 && num < 0)/*十进制负数*/
    {
        unum = (unsigned) -num;
        str[i++] = '-';
    }
    else unum = (unsigned)num;/*其他情况*/
    /*转换*/
    do{
        str[i++] = index[unum % (unsigned)radix];
        unum /= radix;
    }while(unum);
    str[i] = '\0';
    /*逆序*/
    if(str[0] == '-')
        k = 1;/*十进制负数*/
    else
        k = 0;
    char temp;
    for(j = k;j <= (i-1)/2;j++)
    {
        temp = str[j];
        str[j] = str[i-1+k-j];
        str[i-1+k-j] = temp;
    }
    return str;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    printf("%f\n",Power(-2, 6));
    
    int x = -25;
    char string[25];
    itoa(x,string,2);
    printf("十进制数：%d，二进制数：%s\n",x,string);
    return 0;
}
