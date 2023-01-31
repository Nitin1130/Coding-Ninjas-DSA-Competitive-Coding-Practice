//
// Created by nitin on 28-01-2023.
//

/*
Code: Search in BST
Given a BST and an integer k. Find if the integer k is present in given BST or not. You have to return true, if node with data k is present, return false otherwise.
Note: Assume that BST contains all unique elements.
Input Format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
The following line of input contains an integer, that denotes the value of k.
Output Format:
The first and only line of output contains a boolean value. Print true, if node with data k is present, print false otherwise.
Constraints:
Time Limit: 1 second
Sample Input 1 :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2
Sample Output 1 :
true
Sample Input 2 :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12
Sample Output 2 :
false
*/

#include<iostream>
#include<queue>

template<typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    explicit BinaryTreeNode(T data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }

    ~BinaryTreeNode() {
        delete left;
        delete right;
    }
};

using namespace std;

bool searchInBST(BinaryTreeNode<int> *root, int k) {
    if(root == nullptr) {
        return false;
    }
    if(root->data == k) {
        return true;
    }
    else if(root->data < k) {
        return searchInBST(root->right, k);
    }
    else {
        return searchInBST(root->left, k);
    }
}

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if(rootData == -1) {
        return nullptr;
    }
    auto *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> queue;
    queue.push(root);
    while(!queue.empty()) {
        BinaryTreeNode<int> *currentNode = queue.front();
        queue.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if(leftChild != -1) {
            auto *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            queue.push(leftNode);
        }
        cin >> rightChild;
        if(rightChild != -1) {
            auto *rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            queue.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int> * root = takeInput();
    int k;
    cin >> k;
    cout << ((searchInBST(root, k)) ? "true": "false");
    delete root;
}
