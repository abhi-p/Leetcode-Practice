'''
Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.


        3      maxVal 3 goodNode 1      
       /  \
      1    4   maxVal 4 goodNode 2
     /    / \
    3    1   5 maxVal 5 goodNode 3
               maxVal 4 
               maxVal 3 goodNode 4
'''

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        goodNodes=0      
        
        
        def dfs(node,maxVal):
            nonlocal goodNodes
            if maxVal<=node.val:
                goodNodes+=1
            
            if (node.left):
                dfs(node.left,max(maxVal,node.val))
            
            if (node.right):
                dfs(node.right,max(maxVal,node.val))
            
            
        dfs(root,float("-inf"))
        return goodNodes

 