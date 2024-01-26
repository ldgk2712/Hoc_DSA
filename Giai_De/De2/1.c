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

TreeNode *search(TreeNode *node, int val)
{
    // Nếu không thấy node hoặc node đầu tiên có giá trị val
    if (node == NULL || node->data == val)
    {
        return node;
    }
    // Nếu val < node.data rẻ sang nhánh trái
    if (val < node->data)
    {
        return search(node->left, val);
    }
    // Nếu val > node.data rẻ sang nhánh phải
    return search(node->right, val);
}

// 15 -20 -5 -10 -13 3 12 6 7 16 18 23

// TH1: không tìm thấy giá trị val, cho val = 17
// 1.BASECASE: node == NULL

// 2. result of BASECASE: 
// search(NULL,17) = NULL

// 3. before BASECASE: 
// search(18,17) = search(18->left,17)
// = search(NULL,17) = NULL

// 4. before before BASECASE:
// search(16,17) = search(16->right,17)
// = search(18,17) = search(18->left,17)
// = search(NULL,17) = NUL

// TH2: tìm thấy giá trị val, cho val = -5
// 1.BASECASE: -5->data == val

// 2. result of BASECASE: 
// search(-5,-5) = địa chỉ tại node -5

// 3. before BASECASE: 
// search(-20,-5) = search(-20->right,-5)
// = search(-5,-5) = địa chỉ tại node -5

// 4. before before BASECASE:
// search(15,-5) = search(15->left,-5)
// = search(-20,-5) = search(-20->right,-5)
// = search(-5,-5) = địa chỉ tại node -5