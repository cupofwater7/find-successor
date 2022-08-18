#include <iostream>

using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
    int value;
    BinaryTree* left = nullptr;
    BinaryTree* right = nullptr;
    BinaryTree* parent = nullptr;

    BinaryTree(int value) { this->value = value; }
};

BinaryTree* findSuccessor(BinaryTree* tree, BinaryTree* node);
BinaryTree* getLeftMostChild(BinaryTree* node);
BinaryTree* getRightmostParent(BinaryTree* node);

int main()
{
    BinaryTree* root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->left->parent = root;
    root->right = new BinaryTree(3);
    root->right->parent = root;
    root->left->left = new BinaryTree(4);
    root->left->left->parent = root->left;
    root->left->right = new BinaryTree(5);
    root->left->right->parent = root->left;
    root->left->left->left = new BinaryTree(6);
    root->left->left->left->parent = root->left->left;
    auto node = root->left->right;

    cout << findSuccessor(root, node)->value << " ";
    return 0;
}

BinaryTree* findSuccessor(BinaryTree* tree, BinaryTree* node) {
    // Write your code here.
    if (node->right != nullptr)
    {
        return getLeftMostChild(node->right);

    }

    return getRightmostParent(node);
}

BinaryTree* getLeftMostChild(BinaryTree* node) {
    // Write your code here
    auto currentNode = node;
    while (currentNode->left != nullptr)
    {
        currentNode = currentNode->left;
    }
    return currentNode;
}

BinaryTree* getRightmostParent(BinaryTree* node) {
    // Write your code here.
    auto currentNode = node;

    while (currentNode->parent != nullptr && currentNode->parent->right == currentNode)
    {
        currentNode = currentNode->parent;
    }
    return currentNode->parent;
}
