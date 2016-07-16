//
//  main.c
//  MinNumber
//
//  Created by Yans on 16/6/10.
//  Copyright © 2016年 Yans. All rights reserved.
//

#include <stdio.h>

/*
    找出旋转数组中最小的元素。
    利用二分法一步步逼近最小值。
*/
//顺序查找。
int MinInOrder(int a[], int start, int end) {
    int result = a[start];
    for (int i = start+1; i <= end; i++) {
        if (result >= a[i]) {
            result = a[i];
        }
    }
    return  result;
}

int MinNumber(int a[], int length) {
    if (a == NULL || length < 0) {
        return 0;
    }
    int start = 0;
    int end = length - 1;
    int mid = start;
    //如果旋转后的数组就是原来的递增数组，那么直接返回第一个元素的值即可。
    while (a[start] >= a[end]) {
        //找到最小元素的条件。
        if (end - start == 1) {
            mid = end;
            break;
        }
        mid = (start+end)/2;
        //如果首、尾和中间指向的值都相等，不能判断在前后哪个子数组中，那么就只能调用顺序查找的方法。
        if (a[start] == a[end] && a[mid] == a[start]) {
            return MinInOrder(a, start, end);
        }
        if (a[mid] >= a[start]) {
            start = mid;
        }
        else if (a[mid] <= a[end]) {
            end = mid;
        }
    }
    return a[mid];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, FindMinNumber!\n");
    int a[] = {6,7,7,8,8,9,4,4,4,5,6};
    int length = sizeof(a)/sizeof(int);
    int min = MinNumber(a, length);
    printf("min：%d\n",min);
    return 0;
}
