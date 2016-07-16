//
//  main.c
//  SeqList
//
//  Created by Yans on 16/5/13.
//  Copyright © 2016年 Yans. All rights reserved.
//

#include <stdio.h>
#define MAXSIZE 10
typedef int datatype;
typedef struct {
    datatype data[MAXSIZE];
    int last;
}SeqList;

/*顺序表的初始化*/
void Init_SeqList(SeqList *L){
    L->last=0;
}

/*求顺序表的长度*/
int Length_SeqList(SeqList *L){
    return L->last+1;
}

/*取出顺序表中某一元素*/
int Get_SeqList(SeqList *L,int i){
    return L->data[i-1];
}

/*插入运算*/
int Insert_SeqList(SeqList *L , int i , datatype x){
    int j;
    if(L -> last == MAXSIZE - 1){
        printf("此线性表已满");
        return 0;
    }
    if(i < 1 || i > L -> last + 2){
        printf("插入的位置有误");
        return 0;
    }
    for(j = L -> last ; j >= i - 1 ; j --){
        L -> data[j + 1] = L -> data[j];
    }
    L -> data[i - 1] = x;
    return L -> last ++;
}

/*删除运算*/
int Delete_SeqList(SeqList *L , int i){
    int j;
    if(L -> last == 0){
        printf("此线性表为空表,无法删除");
        return 0;
    }
    if(i < 1 || i > L -> last + 1){
        printf("要删除的位置有误,无法删除");
        return 0;
    }
    for(j = i ; j <= L -> last ; j ++){
        L -> data[j - 1] = L -> data[j];
    }
    return L -> last --;
}

/*按值查找*/
int Location_SeqList(SeqList *L , datatype x){
    int i = 0 ;
    while (i <= L -> last && L -> data[i] != x) {
        i ++;
    }
    if(i > L -> last)
        return 0;
    else
        return i;
}

int main(){
    SeqList L;
    int i;
    datatype x;
    Init_SeqList(&L);
    for(i = 1 , x = 10 ; i <= 5 ; i ++ , x += 10){
        Insert_SeqList(&L, i, x);
    }
    printf("线性表的长度%d\n",L.last+1);
    printf("第5个元素的值%d\n",Get_SeqList(&L,5));
    Delete_SeqList(&L, 3);
    printf("删除一个元素后线性表的长度%d\n",L.last+1);
    printf("删除一个元素后第4个元素的值%d\n",Get_SeqList(&L,4));
    printf("查找值是20个元素位置%d\n",Location_SeqList(&L,20));
}

