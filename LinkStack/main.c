//
//  main.c
//  LinkStack
//
//  Created by Yans on 16/5/28.
//  Copyright © 2016年 Yans. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct node{
    datatype data;
    struct node *next;
}StackNode,*Pointer;

typedef struct LinkStack{
    Pointer top;
    int count;
}LinkStack;

//初始化
int initLinkStack(LinkStack *ls){
    ls->top = (Pointer)malloc(sizeof(StackNode));
    if(!ls->top)
    {
        return 0;
    }
    
    ls->top = NULL;
    ls->count = 0;
    return 1;
}

//判断空
int isEmptyLinkStack(LinkStack *ls) {
    if (ls->count == 0) {
        printf("is Empty!\n");
        return 1;
    }
    else {
        return 0;
    }
}

//入栈
LinkStack *pushLinkStack(LinkStack *ls, datatype data) {
    Pointer node;
    node = (Pointer)malloc(sizeof(StackNode));
    node->data = data;
    node->next = ls->top;
    ls->top = node;
    ls->count++;
    printf("%d push is completed\n",data);
    return ls;
}

//出栈
LinkStack *popLinkStack(LinkStack *ls) {
    if (ls->count == 0) {
        return NULL;
    }
    else {
        Pointer p;
        p = ls->top;
        ls->top = ls->top->next;
        printf("%d pop is completed\n",p->data);
        ls->count--;
        free(p);
        return ls;
    }
}

//取栈顶元素
int topElementLinkStack(LinkStack *ls) {
    if (isEmptyLinkStack(ls)) {
        return 1;
    }
    else {
        printf("top element is %d\n",ls->top->data);
        return 0;
    }
}

//遍历栈元素
int printElementLinkStack(LinkStack *ls) {
    if (isEmptyLinkStack(ls)) {
        return 1;
    }
    else {
        Pointer p;
        p = ls->top;
        while (p) {
            printf("%4d",p->data);
            p = p->next;
        }
        printf("\n");
        return 0;
    }
}

//栈中元素个数
int getCountLinkStack(LinkStack *ls) {
    printf("%d",ls->count);
    return ls->count;
}

int main(int argc, const char * argv[]) {
    printf("Hello, LinkStack!\n");
    LinkStack ls;
    initLinkStack(&ls);
    pushLinkStack(&ls, 10);
    pushLinkStack(&ls, 20);
    pushLinkStack(&ls, 30);
    pushLinkStack(&ls, 40);
    pushLinkStack(&ls, 50);
    popLinkStack(&ls);
    topElementLinkStack(&ls);
    printElementLinkStack(&ls);
    getCountLinkStack(&ls);
    return 0;
}
