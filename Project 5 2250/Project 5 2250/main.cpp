//
//  main.cpp
//  Project 5 2250
//
//  Created by Charissa M Martin on 5/2/18.
//  Copyright © 2018 Charissa M Martin. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cctype>
#include "BinaryTree.h"
using namespace std;


    
int main() {
    int max; //maximum # of characters that will be stored in the tree
    int counter = 1;
    BinaryTree * cherryBlossom = new BinaryTree; //I named my tree cherryBlossom because it's my favorite kind of tree. I'm tired. 
    
    cout << "Enter your maximum string length: ";
    cin >> max;
    
    //Error checking for negative numbers and non-integers
    while (!max || max < 1){
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Error! Please enter a positive number.";
        cin >> max;
    }

    string spot; //placeholder. I didn't want to name it placeholder.
    string input = "";
    ifstream * inputFile = new ifstream("input.txt");
        if (inputFile -> fail())
            cout << "Error reading the file.";
    
    while (*inputFile >> spot){
        *inputFile >> spot;
        input.append(spot);
        for (int i = 0; i < input.length(); i++){
            if (!isalpha(input[i]))
                input.erase(i);
            if (isupper(input[i]))
                input [i] = tolower(input[i]);
        }
    }
    
    for (int i = 0; i < max; i++){
        for (int j = 0; j < input.length()-i; j++){
            cherryBlossom -> insert(cherryBlossom -> root, input.substr(j, counter));
        }
        counter++;
    }
    cherryBlossom -> output(cherryBlossom -> root);
    return 0;
}
