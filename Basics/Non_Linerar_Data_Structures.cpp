#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

class BinarySearchTree{
    public:
    struct Node{
        int val;
        Node *left, *right;
        Node(int x): val(x), left(NULL), right(NULL) {}
    };
    Node* insert_node(Node* root, int key){
        
        if(!root)
            return new Node(key);
        
        if(key< root->val)
            root->left = insert_node(root->left, key);
        else if(key>root->right)
            root->right = insert_node(root->right, key);
        return root;
    }

    Node* delete_node(Node* root, int k){
        if(!root)
            return root;
        if(root->val > k){
            root->left = delete_node(root->left, k);
            return root;
        }
        else if(root->val < k){
            root->right = delete_node(root->right, k);
            return root;
        }

        if(!root->left){
            Node* tmp = root->right;
            delete root;
            return tmp;
        }
        else if(!root->right){
            Node* tmp = root->left;
            delete root;
            return tmp;
        }
        else{
            Node* succParent = root;
            Node* succ = root->right;
            while(succ->left){
                succParent = succ;
                succ = succ->left;
            }
            if(succParent != root)
                succParent->left = succ->right;
            else
                succParent->right = succ->right;
            root->val = succ->val;
            delete succ;
            return root;
        }
    }
};

class BinaryTree{
    public:
    struct Node{
        int val;
        Node *left, *right;
        Node(int x): val(x), left(NULL), right(NULL) {}
    };
    Node* insert(Node* root, int key){
        Node* res = new Node(key);
        Node* head = root;
        queue<Node*> q;
        if(root)
            q.push(root);
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            if(!curr->left){
                curr->left = res;
                return head;
            }
            else
                q.push(curr->left);
            
            if(!curr->right){
                curr->right = res;
                return head;
            }
            else
                q.push(curr->right);
        }
        return res;
    }
    void delete_deepest(Node* root, Node* node){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            auto tmp = q.front(); q.pop();
            if(tmp == node){
                tmp = NULL;
                delete (node);
                return;
            }
            if(tmp->right){
                if(tmp->right == node){
                    tmp->right = NULL;
                    delete (node);
                    return;
                }
                else
                    q.push(tmp->right);
            }
            if(tmp->left){
                if(tmp->left == node){
                    tmp->left = NULL;
                    delete (node);
                    return;
                }
                else
                    q.push(tmp->left);
            }
        }
        return;
    }
    
    Node* delete_key(Node* root, int key){
        if(root)
            return NULL;
        if(!root->left && !root->right){
            if(root->val == key)
                return NULL;
            else
                return root;
        }
        queue<Node*> q;
        q.push(root);
        Node* node = NULL;
        Node* tmp;
        while(!q.empty()){
            auto tmp = q.front();q.pop();
            if(tmp->val == key)
                node = tmp;
            if(tmp->left)
                q.push(tmp->left);
            if(tmp->right)
                q.push(tmp->right);
        }
        if(node){
            int x = tmp->val;
            delete_deepest(root,tmp);
            node->val = x;
        }
        return root;
    }
    
};

class PriorityQueue{
    public:
    struct Node{
        int val;
        int priority;
        Node *next;
        Node(int x, int p): val(x), priority(p), next(NULL) {}
    };
    int top(Node* head){
        return head->val;
    }
    void pop(Node* head){
        Node* curr = head;
        head = head->next;
        free(curr);
    }
    void push(Node* head, int d, int p){
        Node* curr = head;
        Node* res = new Node(val,p);
        if(head->priority < p){
            res->next = head;
            head = res;
        }
        else{
            while(curr->next && curr->next->priority < p)
                curr = curr->next;
            res->next = curr->next;
            curr->next = res;
        }
    }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}