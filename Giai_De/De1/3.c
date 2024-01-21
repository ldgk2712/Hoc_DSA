/*
Cây nhị phân trên có lỗi
Vì 7 phải nằm ở bên trái 8 chứ không phải bên trái 19
Theo quy tắc:
1. 7 < 34 đẩy qua trái
2. 7 < 10 đẩy qua trái
3. 7 < 8 đẩy qua trái
*/

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

// delete node
void delete(BinaryTree *tree, int value)
{
    if (tree->root == NULL)
    {
        return;
    }

    TreeNode *curr = tree->root;
    TreeNode *prev = NULL;

    // Tìm curr có giá trị val trong cây
    while (curr != NULL && curr->data != value)
    {
        prev = curr;
        if (value < curr->data)
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
            if (value < prev->data)
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
        TreeNode *rightMost = curr->left;
        TreeNode *parent = NULL;
        while (rightMost->right != NULL)
        {
            parent = rightMost;
            rightMost = rightMost->right;
        }
        curr->data = rightMost->data;

        // curr khong la root
        if (parent != NULL)
        {
            parent->right = rightMost->left;
        }
        else
        {
            curr->left = rightMost->left;
        }
    } 
    // curr chỉ có node phải
    else if (curr->left == NULL)
    {
        TreeNode *leftMost = curr->right;
        TreeNode *parent = NULL;
        while (leftMost->left != NULL)
        {
            parent = leftMost;
            leftMost = leftMost->left;
        }
        curr->data = leftMost->data;

        // curr khong la root
        if (parent != NULL)
        {
            parent->left = leftMost->right;
        }
        else
        {
            curr->right = leftMost->right;
        }
    }

    // case 3: 2 children
    else
    {
        TreeNode *leftMost = curr->right;
        TreeNode *parent = NULL;
        while (leftMost->left != NULL)
        {
            parent = leftMost;
            leftMost = leftMost->left;
        }
        curr->data = leftMost->data;

        // curr khong la root
        if (parent != NULL)
        {
            parent->left = leftMost->right;
        }
        else
        {
            curr->right = leftMost->right;
        }
    }
    return;
}

int main()
{
    BinaryTree tree;
    init(&tree);

    /*
    Test case:
    12
    34 10 8 7 29 19 26 75 65 50 55 70
    */

    // Nhap vao cay nhi phan
    int n;
    scanf("%d",&n);
    // Insert values into the tree
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d",&val);
        insert(&tree, val);
    }

    // Print the tree
    printf("Binary Tree: ");
    print(tree.root);
    printf("\n");

    int val[3] = {7, 50, 65};
    for (int i = 0; i < 3; i++)
    {
        delete(&tree, val[i]);
        printf("After deleting %d: ", val[i]);
        print(tree.root);
        printf("\n");
    }

    return 0;
}