/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinarySearchTree.h
 * Author: cwood
 *
 * Created on March 24, 2019, 3:24 PM
 */

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "BinaryTreeADT.h"
#include "BinaryNode.h"

template <class T>
class BinarySearchTree : BinaryTreeADT<T> {
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree& orig);
    virtual ~BinarySearchTree();
    
    //interface methods
    bool isEmpty() const;
    bool add(const T& newItem);
    bool remove(const T& delItem);
    void clear();
    //bool contains(const T& findItem) const;
    
    void inorderTraverse(void visit(T& item)) const;
    
 
private:
    BinaryNode<T>* root;
    
    //recursive methods
    void destroyTree(BinaryNode<T>* currRoot);
    BinaryNode<T>* copyTree(const BinaryNode<T>* currRoot) const;
    BinaryNode<T>* placeNode(BinaryNode<T>* currRoot, BinaryNode<T>* newNode);
    bool findNode(BinaryNode<T>* currRoot, const T& item) const;
    void inorder(BinaryNode<T>* currRoot, void visit(T& item)) const;
};

#include "BinarySearchTree.cpp"
#endif /* BINARYSEARCHTREE_H */

