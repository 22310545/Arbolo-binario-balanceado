#include "Tree.h"

int main() {
    struct TreeNode* root = nullptr;

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 7);
    root = insert(root, 3);

    std::cout << "Imprimiendo arbol binario in-order traversal: ";
    inOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "Imprimiendo arbol binario pre-order traversal: ";
    preOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "Imprimiendo arbol binario post-order traversal: ";
    postOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "Imprimiendo arbol binario por niveles: " << std::endl;
    printLevelOrder(root);

    // Balancear el árbol
    root = leftRotate(root);
    root = rightRotate(root);

    std::cout << "Imprimiendo arbol binario balanceado: " << std::endl;
    printLevelOrder(root);

    return 0;
}
