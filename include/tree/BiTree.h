//
// Created by Admin on 2024/1/17.
//

#ifndef DATASTRUCT_BITREE_H
#define DATASTRUCT_BITREE_H

template<typename T>
class BiTNode{
private:
    T data;
    BiTNode<T> *lchild,*rchild;
public:
    BiTNode();

    BiTNode(T data);

    virtual ~BiTNode();

    T getData() const;

    void setData(T data);

    BiTNode<T> *getLchild();

    void setLchild(BiTNode<T> *lchild);

    BiTNode<T> *getRchild();

    void setRchild(BiTNode<T> *rchild);

    void preOrder();

};




template<typename T>
class BiTree{
private:
    BiTNode<T> *root;
    int amount;

public:
    BiTree();

    void PreOder();

    BiTNode<T> *getRoot() ;

    void setRoot(BiTNode<T> *root);

    int getAmount() const;

    void setAmount(int amount);

    void PreOrderByIteration();
};



#endif //DATASTRUCT_BITREE_H
