//
// Created by Admin on 2024/1/12.
//

#ifndef DATASTRUCT_ARRAY_H
#define DATASTRUCT_ARRAY_H
#define InitSize 100

template<typename T> class CArrayList{
public:
    CArrayList();
    virtual ~CArrayList();

public:
    /***
    功能：插入元素，在第i个位置插入元素e
    参数：L：待插入列表
          i：插入位置
          e：插入元素
    ***/
    bool ListInsert(int i,T e);

    /***
    功能：删除指定元素，并用e接受删除的元素
    参数：i：待删除元素的位置
          e：接受待删除元素的值
    ***/
    bool ListDelete(int i,T &e);

    /***
    功能：找到指定值的元素的位置，若不存在则返回0
    参数：e：查找的值
    ***/
    int  LocateElem(T e);

    /***
    功能：打印列表中的元素
    ***/
    void Print();
    /***
    功能：获取列表的长度
    ***/
    int GetLength();
public :
    /***
    功能：插入元素，在第i个位置插入元素e
    参数：L：待插入列表
          i：插入位置
          e：插入元素
    ***/
    T& operator[](int i);
public:
    //数组列表
    T *data;
    //容量
    int MaxSize;
    //长度
    int length;
};

#endif //DATASTRUCT_ARRAY_H
