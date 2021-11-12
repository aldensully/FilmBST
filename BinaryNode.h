/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinaryNode.h
 * Author: cwood
 *
 * Created on October 26, 2018, 6:16 PM
 */

#ifndef BINARYNODE_H
#define BINARYNODE_H

template <class T>
class BinaryNode {
public:
    BinaryNode();
    BinaryNode(const T& newItem,
            BinaryNode<T>* left = nullptr, 
            BinaryNode<T>* right = nullptr);
    BinaryNode(const BinaryNode& orig);
    virtual ~BinaryNode();
    
    T getItem() const;
    void setItem(const T& newItem);
    
    BinaryNode<T>* getLeftChild() const;
    BinaryNode<T>* getRightChild() const;
    
    void setLeftChild(BinaryNode<T>* left);
    void setRightChild(BinaryNode<T>* right);
    
    bool isLeaf() const;
    
private:
    T item;
    BinaryNode<T>* leftChild;
    BinaryNode<T>* rightChild;
};

#include "BinaryNode.cpp"
#endif /* BINARYNODE_H */

