//
//  main.c
//  Search
//
//  Created by Yans on 16/6/5.
//  Copyright © 2016年 Yans. All rights reserved.
//

#include <stdio.h>
/**
    二分法，折半查找
*/
int BinSearch(int *a, int length, int data) {
    int low = 0, high = length - 1;
    while (low < high) {
        int mid = (low + high) / 2;
        if (a[mid] == data) {
            return mid;
        }
        if (a[mid] > data) {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    
    return 0;
}
/**
    索引查找，先给定索引值，在给定关键值。
*/
typedef struct indexTable {
    int index;   //索引号
    int start;   //开始位置
    int length;  //索引长度
}indexTable;

indexTable *bulidIndex(int a[], int length, int indexCount) {
    int indexNumber;
    int indexLength;
    indexTable index[indexCount];
    for (int i = 0; i < indexCount; i++) {
        printf("indexNumber is:");
        scanf("%d",&indexNumber);

        printf("indexLength is:");
        scanf("%d",&indexLength);
        if (indexLength > length) {
            printf("indexLength is overflow!");
        }
        
        index[i].index = indexNumber;
        index[i].length = indexLength;
        for (int j = 0; j <= length; j++) {
            if (a[j] == indexNumber) {
                index[i].start = j;
                break;
            }
        }
    }
    for (int k = 0; k < indexCount; k++) {
        printf("%d,%d,%d ",index[k].index,index[k].start,index[k].length);
    }
    return index;
    
}

int indexSearch(int a[], int length, int key, int value) {
//    indexTable index[] = {101,0,5,201,10,4,301,20,3};
    indexTable *index = bulidIndex(a,length,3);
    for (int i = 0; i < 3; i++) {
        if (index[i].index == key) {
            for (int j = index[i].start; j < index[i].start + index[i].length; j++) {
                if (a[j] == value) {
                    return j+1;
                }
            }
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    printf("二分法：\n");
    int b[] = {1,2,3,4,5,6,7,8,9,10};
    int dataIndex = BinSearch(b, 10, 3);
    printf("%d",dataIndex);
    printf("索引查找：\n");
    int a[] =
    {101, 102, 103, 104, 105, 0, 0, 0, 0, 0, 201, 202,
        203, 204, 0, 0, 0, 0, 0, 0, 301, 302, 303, 0, 0, 0, 0, 0, 0, 0};
    int length = 20;
    int index = indexSearch(a, length, 301, 302);
    printf("\n%d\n",index);
       return 0;
}
