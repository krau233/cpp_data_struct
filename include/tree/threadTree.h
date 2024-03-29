//
// Created by Admin on 2024/1/20.
//

#ifndef DATASTRUCT_THREADTREE_H
#define DATASTRUCT_THREADTREE_H

template<typename T>
class threadNode {
private:
    T data;
    threadNode<T> *lchild, *rchild;
    bool ltag, rtag;
private:
    void InThread(threadNode<T> *&pre);
    threadNode<T> * firstNode();
    threadNode<T> * nextNode();
public:
    //中序线索化
    void creatInThread();
    void inOrder();

};



template<typename T>
using threadTree = threadNode<T> *;

#endif //DATASTRUCT_THREADTREE_H
