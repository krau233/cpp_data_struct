//
// Created by Admin on 2024/1/15.
//
#include"../../include/stack/stack.h"
#include "iostream"
using std::cout;
using std::endl;

template<typename T>
int Stack<T>::getLength() {
    return this->list.GetLength();
}

template<typename T>
bool Stack<T>::isEmpty() {
    if (this->list.length==0){
        return true;
    }
    return false;
}

template<typename T>
bool Stack<T>::push(const T e) {
    this->list.ListInsert(this->list.length+1,  e);
    return true;
}

template<typename T>
bool Stack<T>::pop(T &e) {
    this->list.ListDelete(this->list.length,e);
    return true;
}

template<typename T>
T &Stack<T>::getTop() {
    if(this->isEmpty()){
        cout<<"栈空"<<endl;
    }
    return this->list[this->list.length];
}

