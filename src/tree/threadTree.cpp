//
// Created by Admin on 2024/1/20.
//
#include "../../include/tree/threadTree.h"

template<typename T>
void threadNode<T>::InThread(threadNode<T> *&pre) {
    if(this!= nullptr){
        lchild->InThread(pre);
        if(lchild== nullptr){
            lchild = pre;
            ltag = true;
        }
        if(pre!= nullptr&&pre->rchild== nullptr){
            pre->rchild=this;
            pre->rtag=true;
        }
        pre = this;
        rchild->InThread(pre);
    }
}

template<typename T>
void threadNode<T>::creatInThread() {
    threadNode<T> *pre = nullptr;
    if(this){
        this->InThread(pre);
        pre->rchild= nullptr;
        pre->rtag = true;
    }

}

