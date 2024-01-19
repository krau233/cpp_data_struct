//
// Created by Admin on 2024/1/15.
//

#ifndef DATASTRUCT_STACK_H
#define DATASTRUCT_STACK_H

#include "../list/array.h"

template <typename T>
class Stack {
private:
   CArrayList list;
public:
    //获取栈内元素个数
    int getLength();
    //判断栈是否为空
    bool isEmpty();
    // 压栈
    bool push(const T e);
    //弹栈
    bool pop(T& e);
    //读栈顶元素
    T &getTop();
};


#endif //DATASTRUCT_STACK_H
