/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/** 
 * @file:   BinaryNode.cpp
 * @author: cwood
 * @class:  BinaryNode
 * 
 * Created on October 26, 2018, 6:16 PM
 */

#include "BinaryNode.h"
#include <cstddef>
#include <iostream>
template <class T>
BinaryNode<T>::BinaryNode() : leftChild(nullptr), rightChild(nullptr) {
    
}
template <class T>
BinaryNode<T>::BinaryNode(const T& newItem,
        BinaryNode<T>* left, BinaryNode<T>* right) :
item(newItem), leftChild(left), rightChild(right) {
}
template <class T>
BinaryNode<T>::BinaryNode(const BinaryNode& orig) {
    item = orig.item;
    leftChild = orig.leftChild;
    rightChild = orig.rightChild;
}
template <class T>
BinaryNode<T>::~BinaryNode() {
//    std::cout << this->getItem().getRanking() << " node destroyed" << std::endl;
}
template <class T>
T BinaryNode<T>::getItem() const {
    return item;
}
template <class T>
void BinaryNode<T>::setItem(const T& newItem) {
    item = newItem;
}

template <class T>
BinaryNode<T>* BinaryNode<T>::getLeftChild() const {
    return leftChild;
}
template <class T>
BinaryNode<T>* BinaryNode<T>::getRightChild() const {
    return rightChild;
}
template <class T>
void BinaryNode<T>::setLeftChild(BinaryNode<T>* left) {
    leftChild = left;
}
template <class T>
void BinaryNode<T>::setRightChild(BinaryNode<T>* right) {
    rightChild = right;
}

template <class T>
bool BinaryNode<T>::isLeaf() const {
    return (leftChild == nullptr && rightChild == nullptr);
}
