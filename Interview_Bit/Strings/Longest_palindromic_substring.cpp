string Solution::longestPalindrome(string A) {
    int length = 1,start=0,n=A.size(),l,h,i;
    for(i=1;i<n;i++){
        l=i-1;
        h=i;
        while(0<=l && h<n && A[l]==A[h]){
            if(h-l+1>length){
                start = l;
                length = h-l+1;
            }
            --l;
            ++h;
        }
        l = i-1;
        h = i+1;
        while(0<=l && h<n && A[l]==A[h]){
            if(h-l+1>length){
                start = l;
                length = h-l+1;
            }
            --l;
            ++h;
        }
    }
    return A.substr(start,length);
}