//
//  main.c
//  LinkList
//
//  Created by Yans on 16/5/16.
//  Copyright © 2016年 Yans. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef int datatype;
typedef struct node{
    datatype data;
    struct node *next;
}LNode;

#define Maxsize 1024
typedef struct {
    datatype data[Maxsize];
    int top;
}SeqStack;

/*创建一个空的单链表*/
LNode *Init_LinkList(){
    return NULL;
}

/*创建带头结点的单链表*/
LNode *creatLinkList(){
    LNode *head;
    head = (LNode *)malloc(sizeof(LNode));
    int n;
    LNode *p , *q;
    p = head;
    printf("创建一个有N个元素的单链表:\n");
    scanf("%d",&n);
    while(n--){
        q = (LNode *)malloc(sizeof(LNode));
        scanf("%d",&q->data);
        q->next = NULL;
        p->next = q;
        p = q;
    }
    return head;
}

/*遍历链表数据*/
void printInfo(LNode *head){
    if(head == NULL){
        printf("这是一个空链表\n");
    }else{
        LNode *p = head->next;
        while(p){
            printf("%2d",p->data);
            p = p->next;
        }
        printf("\n");
    }
}

/*查找某个位置的结点*/
LNode *locationLinkList(LNode *head, datatype x){
    LNode *p = head;
    while (p && p->data != x) {
        p = p->next;
    }
    return p;
}

/*插入运算*/
LNode *insertLinkList(LNode *head, int i, datatype x){
    if(i < 0){
        printf("插入位置错误!\n");
        return 0;
    }
    if(i == 0){
        LNode *q = (LNode *)malloc(sizeof(LNode));
        q->data = x;
        q->next = head;
        head = q;
        return head;
    }
    else{
        LNode *p = Location_LinkList(head, i - 1);
        LNode *q = (LNode *)malloc(sizeof(LNode));
        q->data = x;
        q->next = p->next;
        p->next = q;
        return head;
    }
}

/*删除运算*/
LNode *deleteLinkList(LNode *head, int i){
    if(head == NULL){
        printf("此链表为空,无法进行删除\n");
        return head;
    }
    if(i == 0){
        head = head->next;
    }else{
        LNode *p,*q;
        p = locationLinkList(head, i - 1);
        if(p && p->next){
            q = p->next;
            p->next = q->next;
            free(q);
        }
    }
    return head;
}

//从尾到头来遍历链表。  利用栈的原理，先进后出。
SeqStack *initSeqStack() {
    SeqStack *s;
    s = (SeqStack*)malloc(sizeof(SeqStack));
    s->top = -1;
    return s;
}

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
int isEmptySeqStack(SeqStack *s) {
    if (s->top == -1) {
        printf("is Empty!\n");
        return 1;
    }
    else {
        return 0;
    }
}
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

void printLinkListReversing(LNode *head) {
    SeqStack *stack;
    stack = initSeqStack();
    
    LNode *p = head->next;
    while (p != NULL) {
        pushSeqStack(stack, p->data);
        p = p->next;
        
    }
    while (stack->top != -1) {
        printElementInSeqStack(stack);
    }
    
}

//运用递归的方式来从后到头的遍历。
void printLinkListReversingRecursively (LNode *head) {
    if (head != NULL) {
        if (head ->next != NULL) {
            printLinkListReversingRecursively(head->next);
        }
        printf("%2d",head->data);
    }
}


int main(){
    LNode *h;
    h = creatLinkList();
    printInfo(h);
    deleteLinkList(h, 3);
    printLinkListReversing(h);
    printLinkListReversingRecursively(h);
}























