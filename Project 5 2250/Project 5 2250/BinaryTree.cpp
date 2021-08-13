//
//  BinaryTree.cpp
//  Project 5 2250
//
//  Created by Charissa M Martin on 5/2/18.
//  Copyright © 2018 Charissa M Martin. All rights reserved.
//

#include "BinaryTree.h"
#include <iostream>
#include <string>
using namespace std;


BinaryTree :: BinaryTree(){
    root = new node;
    root -> right = nullptr;
    root -> left = nullptr;
}

//outputs tree in order
void BinaryTree :: output(node * inOrder){
    if (inOrder -> left != nullptr) output (inOrder -> left);
    if (!inOrder -> holder.empty())
        cout << "The string " << inOrder -> holder << " has " << inOrder -> xtimes << " occurrences.\n";
        if (inOrder -> right != nullptr) output (inOrder -> right);
}

//inserts nodes onto the tree
void BinaryTree :: insert(node * leaf, string string){
    if (root -> holder.empty()){
        root -> holder = string;
        increment(root);
    }
    
    else if (string == leaf -> holder) //puts the first character on the root node
        increment(leaf);
    else if (string > leaf -> holder){ //puts characters on appropriate nodes
        if (leaf -> right == nullptr){
            leaf -> right = new node;
            leaf -> right -> holder = string;
            leaf -> right -> xtimes = 1;
            leaf -> right -> left = nullptr;
            leaf -> right -> right = nullptr;
        }
    else
        insert(leaf -> right, string);
    }
    else if (string < leaf -> holder){
        if (leaf -> left == nullptr){
            leaf -> left = new node;
            leaf -> left -> holder = string;
            leaf -> left -> xtimes = 1;
            leaf -> left -> left = nullptr;
            leaf -> left -> right = nullptr;
        }
        else
            insert(leaf -> left, string);
    }
}

//increments xtimes when a duplicate character is found
void BinaryTree :: increment(node * leaf){
        leaf -> xtimes++;
    }
