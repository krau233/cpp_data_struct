//
// Created by Admin on 2024/1/16.
//

#include "../../include/queue/queue.h"
#define MaxSize 100

template<typename T>
CQueue<T>::CQueue() {
    front = 0;
    rear = 0;
    data = new T[MaxSize];
    capacity = MaxSize;
}

template<typename T>
CQueue<T>::CQueue(int capacity) {
    front = 0;
    rear = 0;
    data = new T[capacity];
    this->capacity = capacity;
}

template<typename T>
CQueue<T>::~CQueue() {
    delete[] data;
}

template<typename T>
bool CQueue<T>::isEmpty() {
    if(front==rear){
        return true;
    }
    return false;
}

template<typename T>
bool CQueue<T>::isFull() {
    if((rear+1)%capacity==front){
        return true;
    }
    return false;
}

template<typename T>
bool CQueue<T>::EnQueue(T e) {
    if(this->isFull()) return false;
    data[rear] = e;
    rear = (rear+1)%capacity;
    return true;
}

template<typename T>
bool CQueue<T>::DeQueue(T &e) {
    if(front==rear) return false;
    e = data[front];
    front=(front+1)%capacity;
    return true;
}


