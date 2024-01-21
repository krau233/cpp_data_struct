//
// Created by Admin on 2024/1/17.
//

#ifndef DATASTRUCT_BITREE_H
#define DATASTRUCT_BITREE_H

//二叉树结点
template<typename T>
class BiTNode {
private:
    T data;
    BiTNode<T> *lchild, *rchild;
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
class BiTree {
private:
    BiTNode<T> *root;

public:
    BiTree();

    BiTNode<T> *getRoot();

    void setRoot(BiTNode<T> *root);

    //递归版本前序遍历
    void PreOrder();

    //迭代版本前序遍历
    void PreOrderByIteration();

    //层次遍历
    void levelOrder();
};


#endif //DATASTRUCT_BITREE_H
