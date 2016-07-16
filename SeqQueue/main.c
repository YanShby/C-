//
//  main.c
//  SeqQueue
//
//  Created by Yans on 16/5/30.
//  Copyright © 2016年 Yans. All rights reserved.
//

#include <stdio.h>
#define Maxsize 10

/*
 * 为了避免假溢出的现象,我们使用循环队列.
 */
typedef int datatype;
typedef struct {
    datatype data[Maxsize];
    int front, rear;
    int num;
}LoopSeqQueue;

//初始化
LoopSeqQueue initLoopSeqQueue(LoopSeqQueue *lsq) {
    lsq = (LoopSeqQueue *)malloc(sizeof(LoopSeqQueue));
    lsq->front = lsq->rear = -1;
    lsq->num = 0;
    return *lsq;
}

//判队空
int isEmpty(LoopSeqQueue *lsp) {
    if (lsp->num == 0) {
        printf("Queue is empty!\n");
        return 1;
    }
    else {
        return 0;
    }
}

//入队
LoopSeqQueue *inLoopSeqQueue(LoopSeqQueue *lsp, datatype data) {
    if (lsp->num == Maxsize) {
        printf("Queue is full!\n");
        return 0;
    }
    else {
        lsp->rear = (lsp->rear + 1) % Maxsize;
        lsp->data[lsp->rear] = data;
        lsp->num++;
        printf("%d in Queue!\n",data);
        return lsp;
    }
}

//出队
LoopSeqQueue *outLoopSeqQueue(LoopSeqQueue *lsp) {
    if (isEmpty(lsp)) {
        return 0;
    }
    else {
        lsp->front = (lsp->front + 1) % Maxsize;
        printf("%d out Queue!\n",lsp->data[lsp->front]);
        lsp->num--;
        return lsp;
    }
}

//取对头元素
datatype frontElment(LoopSeqQueue *lsp) {
    if (isEmpty(lsp)) {
        return 0;
    }
    else {
        return lsp->data[(lsp->front + 1) % Maxsize];
    }
}


int main(int argc, const char * argv[]) {
    printf("Hello, LoopSeqQueue!\n");
    
    LoopSeqQueue queue;
    initLoopSeqQueue(&queue);
    inLoopSeqQueue(&queue, 10);
    inLoopSeqQueue(&queue, 20);
    inLoopSeqQueue(&queue, 30);
    inLoopSeqQueue(&queue, 40);
    isEmpty(&queue);
    outLoopSeqQueue(&queue);
    int x = frontElment(&queue);
    printf("%d\n",x);
    return 0;
}
