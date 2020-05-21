typedef long int ll;
class Solution {
public:
    struct Tree{
        ll start,end;
        int count;
        Tree* left;
        Tree* right;
        Tree(ll s, ll e, int cnt){
            start = s;
            end = e;
            count = cnt;
            left = right = NULL;
        }
    };
    Tree* build(vector<ll> &sum, int start, int end){
        Tree* root = new Tree(sum[start],sum[end],0);
        if(start==end)
            return root;
        int mid = (start+end)/2;
        root->left = build(sum,start,mid);
        root->right = build(sum,mid+1,end);
        return root;
    }
    
    int query(Tree* root, ll start, ll end){
        if(!root || end<root->start || start>root->end)
            return 0;
        if(start<=root->start && end>=root->end)
            return root->count;
        return (query(root->left,start,end)+query(root->right,start,end));
    }
    void update(Tree* root, ll val){
        if(!root || val<root->start || val>root->end)
            return;
        root->count++;
        if(root->start==root->end)
            return;
        update(root->left,val);
        update(root->right,val);
        return;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if(nums.empty())
            return 0;
        set<ll> st;
        ll tmp = 0;
        for(auto& n: nums){
            tmp += n;
            st.insert(tmp);
        }
        vector<ll> sum;
        for(auto& s:st)
            sum.push_back(s);
        Tree* root = build(sum,0,sum.size()-1);
        int count = 0;
        for(int i=nums.size()-1; i>=0; i--){
            update(root,tmp);
            tmp -= nums[i];
            count += query(root,lower+tmp, upper+tmp);
        }
        return count;
    }
};