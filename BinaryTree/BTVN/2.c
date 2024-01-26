#include <stdio.h>
#include <stdlib.h>

//  Definition of TreeNode
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

// Tim max cua ben trai
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

// Tim min cua ben phai
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

    // Không tìm thấy val
    if (curr == NULL)
    {
        printf("Not found %d in binary tree.\n", val);
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
    BinaryTree tree1;
    init(&tree1);
    BinaryTree tree2;
    init(&tree2);
    BinaryTree tree3;
    init(&tree3);
    BinaryTree tree4;
    init(&tree4);

    // cay 1
    int arr1[] = {1, 2, 4, 8, 9, 5, 10, 11, 3, 6, 12, 13, 7, 14, 15};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    for (int i = 0; i < n1; i++)
    {
        insert(&tree1,arr1[i]);
    }
    int val = 25;
    TreeNode *resutl1 = search(tree1.root,val);
    if (result1 != NULL)
    {
        printf("Found %d in binary tree 1.\n",val);
    }
    else
    {
        printf("Not found %d in binary tree 1.\n", val);
    }
    delete(&tree1, val);

    // cay 2
    int arr2[] = {50, 17, 9, 14, 12, 23, 19, 76, 54, 72, 67};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    for (int i = 0; i < n2; i++)
    {
        insert(&tree2,arr2[i]);
    }
    printf("Cay 2: ");
    print(tree2.root);
    printf("\n");

    // cay 3
    int arr3[] = {15, 11, 8, 6, 9, 12, 14, 26, 20, 30, 35};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    for (int i = 0; i < n3; i++)
    {
        insert(&tree3,arr3[i]);
    }
    printf("Cay 3: ");
    print(tree3.root);
    printf("\n");

    // cay 4
    int arr4[] = {3, 1, 13, 5, 6, 10, 11, 16, 15, 9, 4, 2};
    int n4 = sizeof(arr4)/sizeof(arr4[0]);
    for (int i = 0; i < n4; i++)
    {
        insert(&tree4,arr4[i]);
    }
    printf("Cay 4: ");
    print(tree4.root);

    return 0;
}