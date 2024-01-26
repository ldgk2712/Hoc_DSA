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

// kiem tra 1 nut la nut leaf
int isLeaf(TreeNode *curr)
{
    return(curr != NULL && curr->left == NULL && curr->right == NULL);
}

// dem so nut leaf (de quy)
int countLeaf(TreeNode *curr)
{
    if (curr == NULL) return 0;
    if (isLeaf(curr)) return 1;
    return countLeaf(curr->left) + countLeaf(curr->right);
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

// đếm tổng node trong cây
int sumBinaryTree(TreeNode *node)
{
    // Kiểm tra nếu node là NULL (là lá của cây)
    if (node == NULL)
        return 0;

    // Tính tổng của node hiện tại và tổng của các node con
    return node->data + sumBinaryTree(node->left) + sumBinaryTree(node->right);
}

// in ra node ở level n của cây
void printNodeLevel(TreeNode *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (level == 1)
    {
        printf("Node address: %p | ", root);
        printf("data = %d\n", root->data);
    }
    else if (level > 1)
    {
        printNodeLevel(root->left, level - 1);
        printNodeLevel(root->right, level - 1);
    }
}

// đếm số node ở level n của cây
int countNodeLevel(TreeNode *root, int level)
{
    if (root == NULL)
    {
        return 0;
    }
    if (level == 1)
    {
        return 1;
    }
    else if (level > 1)
    {
        return countNodeLevel(root->left, level-1) + countNodeLevel(root->right, level-1);
    }
}

// tính tổng data trên nhánh có chiều dài nhất của cây
int sumLongestBranch(TreeNode* root) {
    // BASECASE: Cây rỗng
    if (root == NULL)
        return 0;

    // Tính chiều cao của các nhánh con
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    // So sánh chiều cao của hai nhánh
    if (leftHeight > rightHeight)
        // Nếu chiều cao bên trái lớn hơn, thực hiện đệ quy cho nhánh trái
        return root->data + sumLongestBranch(root->left);
    else
        // Ngược lại, thực hiện đệ quy cho nhánh phải
        return root->data + sumLongestBranch(root->right);
}

// Hàm tìm và trả về tổng lớn nhất trên nhánh nào
int findMaxBranchSum(TreeNode* root) {
    // BASECASE: Cây rỗng
    if (root == NULL)
        return 0;

    // Tính tổng lớn nhất trên nhánh con bên trái
    int leftSum = findMaxBranchSum(root->left);
    
    // Tính tổng lớn nhất trên nhánh con bên phải
    int rightSum = findMaxBranchSum(root->right);

    // Trả về tổng lớn nhất giữa nhánh con bên trái và bên phải cộng thêm giá trị của node hiện tại
    return root->data + (leftSum > rightSum ? leftSum : rightSum);
}

// Hàm xóa số nguyên lẻ trên cây nhị phân
void XoaNodeLeTruRoot(BinaryTree* tree, TreeNode* node, TreeNode* prev, int root) {
    // Nếu node là NULL, kết thúc đệ quy
    if (node == NULL) {
        return;
    }
    // Nếu node có giá trị lẻ và khác với giá trị của root
    if (node->data % 2 != 0 && node->data != root) {
        delete(tree, node->data); // xóa node đó
        node = prev; // Đặt con trỏ node về node cha để tránh xử lý node này một lần nữa
    }
    prev = node; // Cập nhật node cha cho lần đệ quy tiếp theo
    XoaNodeLeTruRoot(tree, node->left,prev,root); // Đệ quy qua nhánh trái
    XoaNodeLeTruRoot(tree, node->right,prev,root); // Đệ quy qua nhánh phải
}

// Check là các node chỉ có 1 node con
int isNodeOneChild(TreeNode* node) {
    return ((node->left == NULL && node->right != NULL) || (node->right == NULL && node->left != NULL));
}

// Tổng các node chỉ có 1 node con
void sumNodeOneChild(TreeNode* node, int* sum) {
    if (node == NULL) {
        return ;
    }
    if (isNodeOneChild(node)) {
        *sum += node->data;
    }
    sumNodeOneChild(node->left, sum);
    sumNodeOneChild(node->right, sum);
}


int main()
{
    BinaryTree tree;
    init(&tree);

    int arr[] = {15, 16, -20, 18, 23, -5, 3, 12, -10, 6, 7, -13};
    int n = sizeof(arr) / sizeof(arr[0]);
    // Insert values into the tree
    for (int i = 0; i < n; i++)
    {
        insert(&tree, arr[i]);
    }

    // Print the original tree
    printf("Original Binary Tree: ");
    print(tree.root);
    printf("\n");

    // Delete nodes with odd values
    XoaNodeLeTruRoot(&tree, tree.root, NULL, tree.root->data);

    // Print the modified tree
    printf("Modified Binary Tree: ");
    print(tree.root);
    printf("\n");

    return 0;
}