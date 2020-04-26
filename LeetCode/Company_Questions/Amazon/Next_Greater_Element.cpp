class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map ;        
        for(int i=0;i<nums1.size();i++)
            map.insert(make_pair(nums1[i],i));
        
        vector<int>res(nums1.size());
        stack<int> st;
        
        for(int i=nums2.size()-1;i>=0;i--)
        {
            if(map.count(nums2[i]))             // if this element is in nums1
            {
                while(st.size()>0 &&st.top()<nums2[i])
                    st.pop();
                res[map[nums2[i]]]= st.size()==0?-1:st.top();       // that's why I used map so that I can put the result on it's right position 
            }
            st.push(nums2[i]);
        }
        return res;
    }
};