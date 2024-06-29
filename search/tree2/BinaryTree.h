#include "Node.h"
#include <queue>
class BinaryTree {
private:
    Node* root;

public:
   
    BinaryTree() {
        root = nullptr;
    }
    Node *getRoot() {
        return root;
    }
    void addElement(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;

        if (root == nullptr) {
            root = newNode;
        }
        else {
            Node* current = root;
            while (true) {
                if (data < current->data) {
                    if (current->left == nullptr) {
                        current->left = newNode;
                        break;
                    }
                    else {
                        current = current->left;
                    }
                }
                else if (data > current->data) {
                    if (current->right == nullptr) {
                        current->right = newNode;
                        break;
                    }
                    else {
                        current = current->right;
                    }
                }
                else {
                    break;
                }
            }
        }
    }

    void preOrderTraversal(Node* node) {
        if (node != nullptr) {
            std::cout << node->data << " ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }

    void inOrderTraversal(Node* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            std::cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

    void postOrderTraversal(Node* node) {
        if (node != nullptr) {
            postOrderTraversal(node->left);
            postOrderTraversal(node->right);
            std::cout << node->data << " ";
        }
    }

    void levelOrderTraversal() {
        if (root == nullptr) {
            return;
        }

        std::queue<Node*> queue;
        queue.push(root);

        while (!queue.empty()) {
            Node* currentNode = queue.front();
            std::cout << currentNode->data << " ";
            queue.pop();

            if (currentNode->left != nullptr) {
                queue.push(currentNode->left);
            }

            if (currentNode->right != nullptr) {
                queue.push(currentNode->right);
            }
        }
    }
};
