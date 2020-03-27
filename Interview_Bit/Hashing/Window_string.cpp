string Solution::minWindow(string A, string B) {
    int n = A.size();
    int m = B.size();
    if(n<m)
        return "";
    unordered_map<char,int> text;
    unordered_map<char,int> pat;
    for(int i=0;i<m;i++){
        if(pat.find(B[i])==pat.end())
            pat[B[i]] = 0;
        pat[B[i]]+=1;
    }
    int size = INT_MAX, start = -1, count=0,i=0,j;
    for(j=0;j<n;j++){
        if(text.find(A[j])==text.end())
            text[A[j]] = 0;
        text[A[j]]+=1;
        if(pat.find(A[j])!=pat.end() && text[A[j]]<=pat[A[j]])
            count++;
        if(count==m){
            while(pat.find(A[i])==pat.end() || text[A[i]]>pat[A[i]]){
                if(text[A[i]]>pat[A[i]])
                    text[A[i]]-=1;
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
