//
//  main.c
//  SeqStack
//
//  Created by Yans on 16/5/28.
//  Copyright © 2016年 Yans. All rights reserved.
//

#include <stdio.h>
#define Maxsize 1024
typedef int datatype;
typedef struct {
    datatype data[Maxsize];
    int top;
}SeqStack;

//初始化
SeqStack *initSeqStack() {
    SeqStack *s;
    s = (SeqStack*)malloc(sizeof(SeqStack));
    s->top = -1;
    return s;
}

//判断是否为空栈
int isEmptySeqStack(SeqStack *s) {
    if (s->top == -1) {
        printf("is Empty!\n");
        return 1;
    }
    else {
        return 0;
    }
}

//入栈
SeqStack *pushSeqStack(SeqStack *s, datatype data) {
    if (s->top == Maxsize-1) {
        printf("is Full!\n");
        return s;
    }
    else {
        s->top++;
        s->data[s->top] = data;
        printf("%d push is completed!\n",data);
        return s;
    }
}

//出栈
SeqStack *popSeqStack(SeqStack *s) {
    if (isEmptySeqStack(s)) {
        return s;
    }
    else {
        printf("%d pop is completed!\n",s->data[s->top]);
        s->top--;
        return s;
    }
}

//取栈顶元素
int topElementInSeqStack(SeqStack *s) {
    if (isEmptySeqStack(s)) {
        return 0;
    }
    else {
        printf("Element of top is %d\n",s->data[s->top]);
        return 1;
    }
}

//遍历栈元素
int printElementInSeqStack(SeqStack *s) {
    if (isEmptySeqStack(s)) {
        return 0;
    }
    else {
        for (s->top; s->top>-1; s->top--) {
            printf("%3d",s->data[s->top]);
        }
        printf("\n");
        return 1;
    }
}

/*
 用两个栈来实现队列。
*/
void queueAddTail(SeqStack *s1, datatype data) {
    pushSeqStack(s1, data);
}

void queueDeleteHead(SeqStack *s1, SeqStack *s2) {
    if (s2->top == -1) {
        while (s1->top > -1) {
            datatype data = s1->data[s1->top];
            printf("Form s1:  ");
            popSeqStack(s1);
            printf("To s2:    ");
            pushSeqStack(s2, data);
            
        }
    }
    
    if (isEmptySeqStack(s2)) {
        printf("queue is empty");
    }
    popSeqStack(s2);
}

int main(int argc, const char * argv[]) {
    printf("Hello, SeqStack!\n");
    SeqStack *s , *s1 , *s2;
    printf("测试栈!\n");
    s = initSeqStack();
    isEmptySeqStack(s);
    pushSeqStack(s, 10);
    pushSeqStack(s, 20);
    pushSeqStack(s, 30);
    pushSeqStack(s, 40);
    pushSeqStack(s, 50);
    pushSeqStack(s, 60);
    popSeqStack(s);
    topElementInSeqStack(s);
    printElementInSeqStack(s);
    printf("测试用两个栈实现队列!\n");
    s1 = initSeqStack();
    s2 = initSeqStack();
    queueAddTail(s1, 11);
    queueAddTail(s1, 22);
    queueAddTail(s1, 33);
    queueAddTail(s1, 44);
    queueAddTail(s1, 55);
    queueAddTail(s1, 66);
    queueDeleteHead(s1, s2);
    queueAddTail(s1, 77);
    queueDeleteHead(s1, s2);
    return 0;
}
