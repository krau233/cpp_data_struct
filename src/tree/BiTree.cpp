//
// Created by Admin on 2024/1/17.
//

#include "../../include/tree/BiTree.h"
#include<iostream>
#include<stack>
#include"../../include/queue/queue.h"
#include "../queue/queue.cpp"

using namespace std;

//****************************************************************************************************** BiNode ************************************************************************************************
template<typename T>
BiTNode<T>::BiTNode() {
    lchild = nullptr;
    rchild = nullptr;
}

template<typename T>
BiTNode<T>::BiTNode(T data) {
    this->data = data;
    lchild = nullptr;
    rchild = nullptr;
}

template<typename T>
T BiTNode<T>::getData() const {
    return data;
}

template<typename T>
void BiTNode<T>::setData(T data) {
    BiTNode::data = data;
}

template<typename T>
BiTNode<T> *BiTNode<T>::getLchild()  {
    return lchild;
}

template<typename T>
void BiTNode<T>::setLchild(BiTNode<T> *lchild) {
    BiTNode::lchild = lchild;
}

template<typename T>
BiTNode<T> *BiTNode<T>::getRchild()  {
    return rchild;
}

template<typename T>
void BiTNode<T>::setRchild(BiTNode<T> *rchild) {
    BiTNode::rchild = rchild;
}
/***
 * 先序遍历，先打印根，再打印左子树，最终打印右子树
 * 中序遍历，后序遍历的代码类似，仅需要改变if中的三条语句即可
 * @tparam T
 */
template<typename T>
void BiTNode<T>::preOrder() {
    if(this != nullptr){
        cout<<this->data<<endl;
        lchild->preOrder();
        rchild->preOrder();
    }
}

template<typename T>
BiTNode<T>::~BiTNode() {
    if (lchild!= nullptr) delete lchild;
    if (rchild!= nullptr) delete rchild;
}

//****************************************************************************************************** BiTree ************************************************************************************************
template<typename T>
BiTree<T>::BiTree() {
    amount = 0;
    root = nullptr;
}



template<typename T>
BiTNode<T> *BiTree<T>::getRoot() {
    return root;
}

template<typename T>
void BiTree<T>::setRoot(BiTNode<T> *root) {
    BiTree::root = root;
}

template<typename T>
int BiTree<T>::getAmount() const {
    return amount;
}

template<typename T>
void BiTree<T>::setAmount(int amount) {
    BiTree::amount = amount;
}

template<typename T>
void BiTree<T>::PreOrder() {
    BiTNode<T> *p = root;
    root->preOrder();
}

template<typename T>
void BiTree<T>::PreOrderByIteration() {
    stack<BiTNode<T> *> s;
    auto p = getRoot();
    while(p||!s.empty()){
        if(p){
            cout<<p->getData();
            s.push(p);
            p = p->getLchild();
        }
        else{
            p = s.top()->getRchild();
            s.pop();
        }
    }
}

template<typename T>
void BiTree<T>::levelOrder() {
    CQueue<BiTNode<T> *> queue;
    queue.EnQueue(root);
    BiTNode<T> * p ;
    while(!queue.isEmpty()){
        queue.DeQueue(p);
        if(p->getLchild()) queue.EnQueue(p->getLchild());
        if(p->getRchild()) queue.EnQueue(p->getRchild());
        cout<<p->getData()<<endl;
    }
}







