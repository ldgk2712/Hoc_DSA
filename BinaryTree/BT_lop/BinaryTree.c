#include <stdio.h>
#include <stdlib.h>

// Definition of TreeNode
typedef struct NodeType
{
    int data;
    struct NodeType *left, *right;
} TreeNode;

// Definition of BinaryTree
typedef struct BinaryTreeType
{
    struct NodeType *root;
} BinaryTree;

// Create a new TreeNode
TreeNode *makeNode(int data)
{
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Pre-order traversal of the tree
void print(TreeNode *node)
{
    if (node != NULL)
    {
        printf("%d ", node->data);
        print(node->left);
        print(node->right);
    }
}

// Initialize BinaryTree
void init(BinaryTree *tree)
{
    tree->root = NULL;
}

// Insert a new node into the tree
void insert(BinaryTree *tree, int data)
{
    TreeNode *node = makeNode(data);

    if (tree->root == NULL)
    {
        tree->root = node;
    }
    else
    {
        TreeNode *current = tree->root;
        TreeNode *parent = NULL;

        while (current != NULL)
        {
            parent = current;
            if (data < current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }

        if (data < parent->data)
        {
            parent->left = node;
        }
        else
        {
            parent->right = node;
        }
    }
}

// Search for a value in the tree
TreeNode *search(TreeNode *node, int val)
{
    if (node == NULL || node->data == val)
    {
        return node;
    }
    if (val < node->data)
    {
        return search(node->left, val);
    }
    return search(node->right, val);
}

// Check if a node is a leaf
int isLeaf(TreeNode *node)
{
    return (node != NULL && node->left == NULL && node->right == NULL);
}

void handleLeftNotLeaf(BinaryTree *tree, TreeNode *curr)
{
    TreeNode *rightMost = curr->left;
    TreeNode *parent = NULL;
    while (rightMost->right != NULL)
    {
        parent = rightMost;
        rightMost = rightMost->right;
    }
    curr->data = rightMost->data;
    if (parent != NULL)
    {
        parent->right = rightMost->left;
    }
    else
    {
        curr->left = rightMost->left;
    }
}

void handleRightNotLeaf(BinaryTree *tree, TreeNode *curr)
{
    TreeNode *leftMost = curr->right;
    TreeNode *parent = NULL;
    while (leftMost->left != NULL)
    {
        parent = leftMost;
        leftMost = leftMost->left;
    }
    curr->data = leftMost->data;
    if (parent != NULL)
    {
        parent->left = leftMost->right;
    }
    else
    {
        curr->right = leftMost->right;
    }
}

// delete node
void delete(BinaryTree *tree, int val)
{
    if (tree->root == NULL)
    {
        return;
    }

    TreeNode *curr = tree->root;
    TreeNode *prev = NULL;

    // Tìm curr có giá trị val trong cây
    while (curr != NULL && curr->data != val)
    {
        prev = curr;
        if (val < curr->data)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }

    // Không tìm thấy curr
    if (curr == NULL)
    {
        return;
    }
    
    // case 1: no child / leaf
    if (curr->left == NULL && curr->right == NULL)
    {
        free(curr);

        // curr là root
        if (prev == NULL)
        {
            tree->root = NULL;
        }
        else
        {
            if (val < prev->data)
            {
                prev->left = NULL;
            }
            else
            {
                prev->right = NULL;
            }
        }
        return;
    }

    // case 2: one child

    // curr chỉ có node trái
    if (curr->right == NULL)
    {
        handleLeftNotLeaf(tree, curr);
    }
    else if (curr->left == NULL)
    {
        handleRightNotLeaf(tree, curr);
    }

    // case 3: 2 children
    else
    {
        handleRightNotLeaf(tree, curr);
    }
    
    return;
}

int main()
{
    int arr[] = {15, 16, -20, 18, 23, -5, 3, 12, -10, 6, 7, -13};
    int n = sizeof(arr) / sizeof(arr[0]);
    BinaryTree tree;
    init(&tree);

    // Insert values into the tree
    for (int i = 0; i < n; i++)
    {
        insert(&tree, arr[i]);
    }

    // Print the tree
    printf("Binary Tree: ");
    print(tree.root);
    printf("\n");

    int val = -20;
    delete(&tree, val);
    printf("After deleting %d: ", val);
    print(tree.root);

    return 0;
}