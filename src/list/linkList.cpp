//
// Created by Admin on 2024/1/14.
//
#include "iostream"
#include "../../include/list/linkList.h"
using namespace std;
//***************************************************************         LNode         ***************************************************************
template<typename T>  LNode<T>::LNode() {
    this->next = nullptr;
}

template<typename T>
LNode<T>::~LNode() {
    cout<<"�ڵ�������"<<endl;
    if(this->next!= nullptr){
        delete this->next;
    }
}

template<typename T>
T& LNode<T>::getData()  {
    return data;
}

template<typename T>
void LNode<T>::setData(T data) {
    LNode::data = data;
}

template<typename T>
LNode<T> *LNode<T>::getNext()  {
    return next;
}

template<typename T>
void LNode<T>::setNext(LNode<T> *next) {
    LNode::next = next;
}


//***************************************************************         CLinkList         ***************************************************************
template<typename T>
CLinkList<T>::CLinkList() {
    this->length=0;
    this->data = new  LNode<T>();
    this->tail = data;
}

template<typename T>
CLinkList<T>::~CLinkList() {
    delete this->data;
}

template<typename T>
int CLinkList<T>::getLength()  {
    return length;
}

template<typename T>
void CLinkList<T>::setLength(int length) {
    CLinkList::length = length;
}

template<typename T>
LNode<T> *CLinkList<T>::getData()  {
    return data;
}

template<typename T>
void CLinkList<T>::setData(LNode<T> *data) {
    CLinkList::data = data;
}

template<typename T>
LNode<T> *CLinkList<T>::getTail()  {
    return tail;
}

template<typename T>
void CLinkList<T>::setTail(LNode<T> *tail) {
    CLinkList::tail = tail;
}


//ͷ�巨
template<typename T>
bool CLinkList<T>::HeadInsert(T element) {

    LNode<T> *lNode = new LNode<T>();
    if(this->length==0){
        this->tail=lNode;
    }
    lNode->setData(element);
    lNode->setNext(this->data->getNext());
    this->data->setNext(lNode);
    this->length++;
    return true;
}

//β�巨
template<typename T>
bool CLinkList<T>::TailInsert(T element) {
    auto *lNode = new LNode<T>();
    lNode->setData(element);
    lNode->setNext(this->tail->getNext());
    this->tail->setNext(lNode);
    this->length++;
    this->tail = lNode;
    return true ;
}

//��ӡ�б�
template<typename T>
void CLinkList<T>::Print() {
    if(this->length == 0){
        std::cout<<"[]"<<std::endl;
        return;
    }
    cout<<"[";
    LNode<T>* p = this->data->getNext();
    while(p->getNext()!= nullptr){
        cout<<p->getData()<<",";
        p = p->getNext();
    }
    cout<<p->getData()<<"]"<<endl;
}

//����Ų���
template<typename T>
T& CLinkList<T>::operator[](int position) {
    if(position<1||position>this->length){
        cout<<"����ֵ��Ч"<<endl;
    }
    int pos = 1;
    auto p = this->data->getNext();
    while(pos<position){
        p = p->getNext();
        pos++;
    }
    return p->getData();
}

//��ֵ����
template<typename T>
LNode<T> *CLinkList<T>::locateElem(T e) {
    auto p = this->data->getNext();
    while(p!= nullptr){
        if(p->getData()==e){
            break;
        }
        p = p->getNext();
    }
    return p;
}

//�����λ�ò���
template<typename T>
bool CLinkList<T>::ListInsert(int i, T e) {
    int pos = 1;
    if(i<1||i>this->length+1){
        std::cout<<"����λ����Ч"<<std::endl;
        return false;
    }
    auto p = this->data->getNext();
    while(pos<i-1){
        p = p->getNext();
        pos++;
    }
    auto lNode = new LNode<T>();
    lNode->setData(e);
    lNode->setNext(p->getNext());
    p->setNext(lNode);
    this->length++;
    return true;
}

//ɾ�����λ�õĽڵ�
template<typename T>
bool CLinkList<T>::ListDelete(int i, T &e) {
    if(i<1||i>this->length){
        std::cout<<"ɾ��λ����Ч"<<std::endl;
        return false;
    }
    int pos = 1;
    auto p = this->data->getNext();
    while(pos<i-1){
        p = p->getNext();
        pos++;
    }
    auto d = p->getNext();
    p->setNext(p->getNext()->getNext());
    d->setNext(nullptr);
    e = d->getData();
    delete d;
    this->length--;
    return true;
}
