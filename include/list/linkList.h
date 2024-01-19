//
// Created by Admin on 2024/1/14.
//

#ifndef DATASTRUCT_LINKLIST_H
#define DATASTRUCT_LINKLIST_H



template<typename T>  class LNode{
private:
    //数据域
    T data;
    //指针域
    class LNode<T>* next;

//构造函数，析构函数和get set
public:
    LNode() ;

    virtual ~LNode();

    T& getData() ;

    void setData(T data);

    LNode<T> *getNext() ;

    void setNext(LNode<T> *next);
} ;

//带头节点
template<typename T> class CLinkList{
//属性
private:
    int length{};
    LNode<T>* data;
    LNode<T>* tail;

//构造函数，析构函数，get和set
public:
    CLinkList() ;

    virtual ~CLinkList() ;

    int getLength() ;

    void setLength(int length);

    LNode<T> *getData() ;

    void setData(LNode<T> *data);

    LNode<T> *getTail() ;

    void setTail(LNode<T> *tail);

//方法
public:

    //头插法插入
    bool HeadInsert(T element);
    //尾插法插入
    bool TailInsert(T element);
    //打印列表
    void Print();
    //按序号查找
    T& operator[](int position);
    //按值查找
    LNode<T>* locateElem(T e);
    //在序号位置插入
    bool ListInsert(int i,T e);
    //删除序号位置的节点
    bool ListDelete(int i,T& e);

};

#endif //DATASTRUCT_LINKLIST_H
