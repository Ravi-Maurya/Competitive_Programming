/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// O(NlogN)
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
            return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        if(prev==NULL){
            if(fast->next == NULL)
                return root;
            root->right = sortedListToBST(slow->next);
            return root;
        }
        prev->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};

// Second Approach O(n) - time;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode* Node;
    int length(ListNode* curr){
        int count = 0;
        while(curr){
            count++;
            curr = curr->next;
        }
        return count;
    }
    TreeNode* convert(int l, int r){
        if(l>r)
            return NULL;
        int mid = l+  (r-l)/2;
        auto left = convert(l,mid-1);
        TreeNode* root = new TreeNode(Node->val);
        root->left = left;
        
        Node = Node->next;
        
        root->right = convert(mid+1,r);
        return root;
        
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
            return NULL;
        Node = head;
        int n = length(head);
        return convert(0,n-1);
    }
};