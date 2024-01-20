#include <stdio.h>
#include <stdlib.h>

// Định nghĩa về TreeNode
typedef struct NodeType
{
    int data;
    struct NodeType *left, *right;
} TreeNode;

// Định nghĩa về BinaryTree
typedef struct BinaryTreeType
{
    struct NodeType *root;
} BinaryTree;

// Tạo TreeNode mới
TreeNode *makeNode(int data)
{
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// In cây theo thứ tự giữa - trái - phải
void print(TreeNode *node)
{
    if (node != NULL)
    {
        printf("%d ",node->data);
        print(node->left);
        print(node->right);
    }
}

// Khởi tạo BinaryTree
void init(BinaryTree *tree)
{
    tree->root = NULL;
}

// Chèn node mới vào cây
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

// Tìm giá trị val trong cây
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


//  Hàm xử lí one child
void handleOneChild(BinaryTree *tree, TreeNode *curr, TreeNode *prev, int val, TreeNode *child)
{
    if (prev == NULL)
    {
        printf("\nDelete at root\n");
        tree->root = child;
    }
    else
    {
        if (prev->data > val)
        {
            prev->left = child;
        }
        else
        {
            prev->right = child;
        }
    }
    free(curr);
}

// Kiểm tra node là leaf
int isLeaf(TreeNode *node)
{
    return (node != NULL && node->left == NULL && node->right == NULL);
}

// Hàm xử lí khi có 2 children(leafs)
void handleTwoChildrenLeafs(BinaryTree *tree, TreeNode *curr)
{
    curr->data = curr->right->data;
    free(curr->right);
    curr->right = NULL;
} 

// Hàm xử lí khi curr->right is not a leaf
void handleRightNotLeaf(BinaryTree *tree, TreeNode *curr)
{
    TreeNode *leftMost = curr->right;
    TreeNode *parent = NULL;

    while (!isLeaf(leftMost))
    {
        parent = leftMost;
        leftMost = leftMost->left;
    }

    printf("Leaf data %d\n",leftMost->data);
    curr->data = leftMost->data;
    free(leftMost);
    parent->left = NULL;
}

// Hàm xóa val khỏi cây nếu có
void delete(BinaryTree *tree, int val)
{
    TreeNode *curr = tree->root;
    TreeNode *prev = NULL;

    while (curr != NULL)
    {
        if (curr->data == val) // Found
        {
            // Case 1: No chill / leaf
            if (curr->left == NULL && curr->right == NULL)
            {
                free(curr);
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

            // Case 2: One child
            if (curr->left == NULL)
            {
                handleOneChild(tree, curr, prev, val, curr->right);
                return;
            }
            if (curr->right == NULL) 
            {
                handleOneChild(tree, curr, prev, val, curr->left);
                return;
            }

            // Case 3: 2 children (leafs)
            if (isLeaf(curr->left) && isLeaf(curr->right))
            {
                handleTwoChildrenLeafs(tree, curr);
                return;
            }

            // Case 4: curr->right is not leaf
            if (!isLeaf(curr->right))
            {
                handleRightNotLeaf(tree, curr);
                return;
            }
        }

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
    return;
}

int main()
{
    int arr[] = {50, 25, 75, 10, 33, 56, 89, 4, 11, 40, 52, 61, 82, 95};
    int n = sizeof(arr)/sizeof(arr[0]);
    BinaryTree tree;
    init(&tree);

    // Nhập giá trị cho cây
    for (int i = 0; i < n; i++)
    {
        insert(&tree, arr[i]);
    }

    // In cây
    printf("Binary Tree: ");
    print(tree.root);
    printf("\n");

    int val = 75;
    delete(&tree, val);
    printf("After deleted %d: ",val);
    print(tree.root);

    return 0;
}