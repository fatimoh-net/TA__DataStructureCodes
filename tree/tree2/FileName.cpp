#include "BinaryTree.h"
int main() {
    BinaryTree tree;

    tree.addElement(12);
    tree.addElement(5);
    tree.addElement(7);
    tree.addElement(3);
    tree.addElement(9);
    tree.addElement(15);
    tree.addElement(10);
  
    std::cout << "Pre-order traversal: ";
    tree.preOrderTraversal(tree.getRoot());
    std::cout << std::endl;

    std::cout << "In-order traversal: ";
    tree.inOrderTraversal(tree.getRoot());
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    tree.postOrderTraversal(tree.getRoot());
    std::cout << std::endl;

    std::cout << "Level-order traversal: ";
    tree.levelOrderTraversal();
    std::cout << std::endl;

    return 0;
}