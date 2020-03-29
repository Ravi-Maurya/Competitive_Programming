/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
TreeNode* bst(ListNode* start, ListNode* finish){
    if(start==NULL || start==finish)
        return NULL;
    ListNode* fast = start;
    ListNode* slow = start;
    while(fast->next!=finish && fast->next->next!=finish){
        slow = slow->next;
        fast = fast->next->next;
    }
    TreeNode* root = new TreeNode(slow->val);
    root->left = bst(start,slow);
    root->right = bst(slow->next,finish);
    return root;
}
TreeNode* Solution::sortedListToBST(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(!A)
        return NULL;
    if(!A->next){
        TreeNode* root = new TreeNode(A->val);
        return root;
    }
    return bst(A,NULL);
}
