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

// đếm số bậc của BST
int getHeight(TreeNode *root)
{
    // cây rỗng
    if (root == NULL)
    {
        return 0;
    }

    // tính chiều cao dựa vào chiều cao các nhánh con
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
}

// tính tổng data trên nhánh có chiều dài (chiều cao) nhất của cây
int sumLongestBranch(TreeNode* root) {
    // cây rỗng
    if (root == NULL)
        return 0;
    
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    if (leftHeight > rightHeight)
        return root->data + sumLongestBranch(root->left);
    else
        return root->data + sumLongestBranch(root->right);
}