//
// Created by Admin on 2024/1/16.
//

#ifndef DATASTRUCT_QUEUE_H
#define DATASTRUCT_QUEUE_H

template<typename T>
class CQueue {
private:
    T* data;
    int front,rear;
    int capacity;
public:
    CQueue();

    CQueue(int capacity);

    virtual ~CQueue();

    //判断是否队空
    bool isEmpty();
    //判断是否队满
    bool isFull();
    // 入队
    bool EnQueue(T e);
    //出队
    bool DeQueue(T &e);

};



#endif //DATASTRUCT_QUEUE_H
