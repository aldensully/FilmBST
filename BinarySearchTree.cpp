/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/** 
 * @file:   BinarySearchTree.cpp
 * @author: cwood
 * @class:  BinarySearchTree
 * 
 * Created on March 24, 2019, 3:24 PM
 */

#include <iostream>
#include "BinarySearchTree.h"

template <class T>
BinarySearchTree<T>::BinarySearchTree() : root(nullptr) {
}
template <class T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree& orig) {
    root = this->copyTree(orig.root);
}
template <class T>
BinarySearchTree<T>::~BinarySearchTree() {
    this->clear();
}

//interface methods
template <class T>
bool BinarySearchTree<T>::isEmpty() const {
    return (root == nullptr);
}
template <class T>
bool BinarySearchTree<T>::add(const T& newItem) {
    BinaryNode<T>* newNode = new BinaryNode<T>(newItem);
    root = placeNode(root, newNode);
    return true;
}

template <class T>
bool BinarySearchTree<T>::remove(const T& delItem) {
    return false;
}
template <class T>
void BinarySearchTree<T>::clear() {
    destroyTree(root);
    root = nullptr;
}

//recursive methods
template <class T>
BinaryNode<T>* BinarySearchTree<T>::copyTree(const BinaryNode<T>* currRoot) const {
    BinaryNode<T>* newTree = nullptr;
    if (currRoot != nullptr) {
        newTree = new BinaryNode<T>(currRoot->getItem(), nullptr, nullptr);
        newTree->setLeftChild(copyTree(currRoot->getLeftChild()));
        newTree->setRightChild(copyTree(currRoot->getRightChild()));
    }
    return newTree;
}
template <class T>
bool BinarySearchTree<T>::findNode(BinaryNode<T>* currRoot, const T& item) const {
    if (currRoot == nullptr)
        return false;
    else if (currRoot->getItem() == item)
        return true;
    else if (item < currRoot->getItem()) 
        return findNode(currRoot->getLeftChild(), item);
    else
        return findNode(currRoot->getRightChild(), item);
}
template <class T>
BinaryNode<T>* BinarySearchTree<T>::placeNode(BinaryNode<T>* currRoot, BinaryNode<T>* newNode) {
    if (currRoot == nullptr)
        return newNode;
    else {
        if (newNode->getItem() < currRoot->getItem()) {
//            std::cout << "Going left" << std::endl;
            BinaryNode<T>* tempPtr = placeNode(currRoot->getLeftChild(), newNode);
            currRoot->setLeftChild(tempPtr);
        } else {
//            std::cout << "Going right" << std::endl;
            currRoot->setRightChild(placeNode(currRoot->getRightChild(), newNode));
        }
        return currRoot;
    }
}
template <class T>
void BinarySearchTree<T>::destroyTree(BinaryNode<T>* currRoot) {
//    if (currRoot == nullptr)
//        ;//base case - just return
    if (currRoot != nullptr) {
        destroyTree(currRoot->getLeftChild());
        destroyTree(currRoot->getRightChild());
        delete currRoot;
        currRoot = nullptr;
    }
}

//traversals
template <class T>
void BinarySearchTree<T>::inorderTraverse(void visit(T& item)) const {
    inorder(root, visit);
}
template <class T>
void BinarySearchTree<T>::inorder(BinaryNode<T>* currRoot, void visit(T& item)) const {
    if (currRoot != nullptr) {
        inorder(currRoot->getLeftChild(), visit);
        T item = currRoot->getItem();
        visit(item);
        inorder(currRoot->getRightChild(), visit);
    }
}
