# Definition for a  binary tree node
# class TreeNode:
#	def __init__(self, x):
#		self.val = x
#		self.left = None
#		self.right = None

from collections import namedtuple
class Solution:
	# @param A : root node of tree
	# @param B : integer
	# @param C : integer
	# @return an integer
	def lca(self, A, B, C):
	    status = namedtuple('status',('number_target_nodes','ancestor'))
	    def rec(root,n1,n2):
	        if not root:
	            return status(0,None)
	        left = rec(root.left,n1,n2)
	        if left.number_target_nodes == 2:
	            return left
	        right = rec(root.right,n1,n2)
	        if right.number_target_nodes == 2:
	            return right
	        num = (left.number_target_nodes + right.number_target_nodes + int(root.val == n1) + int(root.val == n2))
	        return status(num,root.val if num==2 else -1)
	    return rec(A,B,C).ancestor