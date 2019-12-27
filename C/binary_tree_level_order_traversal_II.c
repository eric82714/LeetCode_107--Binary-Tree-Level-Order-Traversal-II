/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int height(struct TreeNode* n) {
    if (n == NULL) return 0;
    int left = n->left ? height(n->left) : 0;
    int right = n->right ? height(n->right) : 0;
    return left > right ? left + 1 : right + 1;
}

void layer(struct TreeNode* node, int** result, int* depth, int** columnSizes) {
        if(node == NULL) return;
        
        if(*(result+(* depth)-1) == NULL) {
            *(result+(* depth)-1) = malloc(100 * sizeof(int));
            *(*(result+(* depth)-1)+0) = node->val;
            *((* columnSizes)+(* depth)-1) = 1;
        }
        else { 
            int length = *((* columnSizes)+(* depth)-1);
            *(*(result+(* depth)-1)+length-1) = node->val;
            *((* columnSizes)+(* depth)-1) = *((* columnSizes)+(* depth)-1) + 1;
        }
        
        (* depth) --;
        
        layer(node->left, result, depth, columnSizes);

        layer(node->right, result, depth, columnSizes);
}

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    (* returnSize) = height(root);
    (* returnColumnSizes) = malloc((* returnSize) * sizeof(int));
    int** result = malloc((* returnSize) * sizeof(int*));
    
    layer(root, result, returnSize, returnColumnSizes);
    
    return result;
}
