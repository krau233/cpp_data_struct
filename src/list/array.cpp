//
// Created by Admin on 2024/1/12.
//
#include "../../include/list/array.h"
#include<iostream>
#include "vector"

//���캯��
CArrayList::CArrayList(){
    this->MaxSize = InitSize;
    this->length = 0;
    this->data = new ElemType[InitSize];
}

//��������
CArrayList::~CArrayList(){
    delete[] this->data;
}


/***
���ܣ�����Ԫ�أ��ڵ�i��λ�ò���Ԫ��e
������L���������б�
	  i������λ��
	  e������Ԫ��
***/
bool CArrayList::ListInsert(int i,ElemType e){
    //λ����Ч����
    if(i<1||i>this->length+1){
        std::cout<<"����λ����Ч"<<std::endl;
        return false;
    }
    //�ռ䲻�㴦��
    if(this->length>=this->MaxSize){
        std::cout<<"�б��ѷ���ռ䲻��"<<std::endl;
        return false;
    }
    //����Ԫ������ƶ�
    for(int j=this->length;j>=i;j--){
        this->data[j]=this->data[j-1];
    }
    //Ԫ�ز���ָ��λ��
    this->data[i-1]=e;
    //��������
    this->length++;
    return true;
}

/***
���ܣ�ɾ��ָ��Ԫ�أ�����e����ɾ����Ԫ��
������i����ɾ��Ԫ�ص�λ��
	  e�����ܴ�ɾ��Ԫ�ص�ֵ
***/
bool CArrayList::ListDelete(int i,ElemType &e){
    //λ����Ч����
    if(i<1||i>this->length){
        std::cout<<"ɾ��λ����Ч"<<std::endl;
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
���ܣ��ҵ�ָ��ֵ��Ԫ�ص�λ�ã����������򷵻�0
������e�����ҵ�ֵ
***/
int CArrayList::LocateElem(ElemType e){
    int i;
    for(i=0;i<this->length;i++){
        if(this->data[i]==e){
            return i+1;
        }
    }
    return 0;
}


//��ӡ�б��е�Ԫ��
void CArrayList::Print(){
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

ElemType& CArrayList::operator[](int i){
    return this->data[i-1];
}


//��ȡ�б�ĳ���
int CArrayList::GetLength(){
    return this->length;
}

