# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        result = []
        
        self.layer(root, 0, result)
        
        return result[::-1]
        
    def layer(self, node, depth, result):
        if not node: return
        
        if len(result) == depth: result.append([])
            
        result[depth].append(node.val)
        
        self.layer(node.left, depth+1, result)
        
        self.layer(node.right, depth+1, result)
