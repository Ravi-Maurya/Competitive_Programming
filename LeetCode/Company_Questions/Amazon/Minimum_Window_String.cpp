class Solution {
public:
    string minWindow(string A, string B) {
    int n = A.size();
    int m = B.size();
    if(n<m)
        return "";
    unordered_map<char,int> text;
    unordered_map<char,int> pat;
    for(int i=0;i<m;i++){
        pat[B[i]]++;
    }
    int size = INT_MAX, start = -1, count=0,i=0,j;
    for(j=0;j<n;j++){
        text[A[j]]++;
        if(pat.find(A[j])!=pat.end() && text[A[j]]<=pat[A[j]])
            count++;
        if(count==m){
            while(pat.find(A[i])==pat.end() || text[A[i]]>pat[A[i]]){
                if(text[A[i]]>pat[A[i]])
                    text[A[i]]--;
                i++;
            }
            if(size>j-i+1){
                size = j-i+1;
                start = i;
            }
        }
    }
    if(start==-1)
        return "";
    return A.substr(start,size);
    }
};