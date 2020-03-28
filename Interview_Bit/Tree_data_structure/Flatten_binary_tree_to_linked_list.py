# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
 
class Solution:
    # @param A : root node of tree
    # @return the root node in the tree
    def __init__(self):
        self.last = None
    def rec(self,root):
        if root is None:
            return
        left = root.left
        right = root.right
        if root is not self.last:
            self.last.right = root
            self.last.left = None
            self.last = root
        self.rec(left)
        self.rec(right)
        if left == None and right ==None:
            self.last = root
        
    def flatten(self, A):
        self.last = A
        self.rec(A)
        return A