#include <stdio.h>
#include <stdlib.h>

typedef struct NodeType {
    int data;
    struct NodeType* left;
    struct NodeType* right;
} TreeNode;

typedef struct BinaryTreeType {
    struct NodeType* root;
} BinaryTree;

TreeNode* makeNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void print(TreeNode* node) {
    if (node != NULL) {
        printf("%d ", node->data);
        print(node->left);
        print(node->right);
    }
}

void init(BinaryTree* tree) {
    tree->root = NULL;
}

void insert(TreeNode** node, int data) {
    if (*node == NULL) {
        *node = makeNode(data);
    } else {
        if (data < (*node)->data) {
            insert(&(*node)->left, data);
        } else {
            insert(&(*node)->right, data);
        }
    }
}

TreeNode* search(TreeNode* node, int val) {
    if (node == NULL || node->data == val) {
        return node;
    }
    if (val < node->data) {
        return search(node->left, val);
    }
    return search(node->right, val);
}

void delete(BinaryTree* tree, int val) {
    TreeNode* curr = tree->root; // Current node
    TreeNode* prev = NULL;       // Previous node

    // Find the node to delete
    while (curr != NULL && curr->data != val) {
        prev = curr;
        if (val < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    // Case 1: Value not found
    if (curr == NULL) {
        printf("Value %d not found in the binary tree.\n", val);
        return;
    }

    // Case 2: No child / leaf
    if (curr->left == NULL && curr->right == NULL) {
        if (prev == NULL) {
            // The root is the only node in the tree
            tree->root = NULL;
        } else if (prev->left == curr) {
            prev->left = NULL;
        } else {
            prev->right = NULL;
        }
        free(curr);
        return;
    }

    // Case 3: One child
    if (curr->left == NULL || curr->right == NULL) {
        TreeNode* child;
        if (curr->left != NULL) {
            child = curr->left;
        } else {
            child = curr->right;
        }
        if (prev == NULL) {
            // Deleting the root node with one child
            tree->root = child;
        } else if (prev->left == curr) {
            prev->left = child;
        } else {
            prev->right = child;
        }
        free(curr);
        return;
    }

    // Case 4: Two children (leafs)
    TreeNode* successor = curr->right;
    TreeNode* successorParent = curr;
    while (successor->left != NULL) {
        successorParent = successor;
        successor = successor->left;
    }
    curr->data = successor->data;
    if (successorParent->left == successor) {
        successorParent->left = successor->right;
    } else {
        successorParent->right = successor->right;
    }
    free(successor);
    return;

    // Case 5: curr->right is not a leaf
    // (Not implemented in this code snippet)
}

int main() {
    BinaryTree tree;
    init(&tree);

    int arr[] = {50, 25, 75, 10, 33, 56, 89, 4 ,11, 40 ,52, 61, 82 ,95};
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        insert(&tree.root,arr[i]);
    }
    print(&tree);
    return 0;
}