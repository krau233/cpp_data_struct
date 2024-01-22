//
// Created by Admin on 2024/1/12.
//
#include "../../include/list/array.h"
#include<iostream>
#include "vector"

//构造函数
template<typename T>
CArrayList<T>::CArrayList(){
    this->MaxSize = InitSize;
    this->length = 0;
    this->data = new T[InitSize];
}

//析构函数
template<typename T>
CArrayList<T>::~CArrayList(){
    delete[] this->data;
}


/***
功能：插入元素，在第i个位置插入元素e
参数：L：待插入列表
	  i：插入位置
	  e：插入元素
***/
template<typename T>
bool CArrayList<T>::ListInsert(int i,T e){
    //位置无效处理
    if(i<1||i>this->length+1){
        std::cout<<"插入位置无效"<<std::endl;
        return false;
    }
    //空间不足处理
    if(this->length>=this->MaxSize){
        std::cout<<"列表已分配空间不足"<<std::endl;
        return false;
    }
    //后续元素向后移动
    for(int j=this->length;j>=i;j--){
        this->data[j]=this->data[j-1];
    }
    //元素插入指定位置
    this->data[i-1]=e;
    //长度自增
    this->length++;
    return true;
}

/***
功能：删除指定元素，并用e接受删除的元素
参数：i：待删除元素的位置
	  e：接受待删除元素的值
***/
template<typename T>
bool CArrayList<T>::ListDelete(int i,T &e){
    //位置无效处理
    if(i<1||i>this->length){
        std::cout<<"删除位置无效"<<std::endl;
        return false;
    }
    e = this->data[i-1];
    for(int j = i;j<this->length;j++){
        this->data[i-1]=this->data[i];
    }
    this->length--;
    return true;
}

/***
功能：找到指定值的元素的位置，若不存在则返回0
参数：e：查找的值
***/
template<typename T>
int CArrayList<T>::LocateElem(T e){
    int i;
    for(i=0;i<this->length;i++){
        if(this->data[i]==e){
            return i+1;
        }
    }
    return 0;
}


//打印列表中的元素
template<typename T>
void CArrayList<T>::Print(){
    if(this->length == 0){
        std::cout<<"[]"<<std::endl;
        return;
    }
    std::cout<<"[";
    for(int i=0;i<this->length-1;i++){
        std::cout<<this->data[i]<<",";
    }
    std::cout<<this->data[this->length-1]<<"]"<<std::endl;
}

template<typename T>
T& CArrayList<T>::operator[](int i){
    return this->data[i-1];
}


//获取列表的长度
template<typename T>
int CArrayList<T>::GetLength(){
    return this->length;
}

