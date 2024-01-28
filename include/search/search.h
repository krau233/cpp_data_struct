//
// Created by Admin on 2024/1/22.
//

#ifndef DATASTRUCT_SEARCH_H
#define DATASTRUCT_SEARCH_H

#include "../list/array.h"
#include "../../src/list/array.cpp"
#include "../tree/BiTree.h"
#include "../../src/tree/BiTree.cpp"


//顺序查找
template<typename T>
int search_seq(CArrayList<T> array,T key){
    for(int i = 1;i<=array.length;i++){
        if(array[i]==key){
            return i;
        }
    }
    return 0;
}

//折半查找
template<typename T>
int binary_search(CArrayList<T> array,T key){
    int low=1,high=array.length;
    int mid;
    while(low<=high){
        mid = (low+high)/2;
        if (array[mid]== key) return mid;
        else if(array[mid]<key) low = mid+1;
        else  high = mid-1;
    }
    return 0;
}

//二叉排序树的查找
template<typename T>
BiTNode<T> *BST_Search(BiTree<T> t,T key){
    BiTNode<T>* p = t.getRoot();
    while(p!= nullptr&&p->getData()!=key){
        if(key<p->getData()) p = p->getLchild();
        else p = p->getRchild();
    }
    return p;
}

//二叉排序树的插入
template<typename T>
bool BST_Insert(BiTNode<T>* &p,T key){
    if(p == nullptr){
        p = new BiTNode<T>(key);
        return true;
    }
    else if(key==p->getData()) return false;
    else if(key<p->getData()) return BST_Insert(p->getLchild(),key);
    else return BST_Insert(p->getRchild(),key);
}

//构造二叉排序树
template<typename T>
void Creat_BST(BiTree<T> t,T arr[],int n){
    t.setRoot(nullptr);
    for(int i = 0 ;i<n;++i) BST_Insert(t.getRoot(),arr[i]);
}


#endif //DATASTRUCT_SEARCH_H
