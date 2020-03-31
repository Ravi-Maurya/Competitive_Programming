int Solution::power(string A) {
    int n = A.size();
    int num = 0;
    if(n==1 && (A[0]=='2' || A[0]=='4'))
        return 1;
    if(n==1 && A[0]=='1')
        return 0;
    while(n!=1 || A[n-1]!='1'){
        if((int)(A[n-1]-'0')&1)
            return 0;
        int i,j;
        for(i=0,j=0;i<n;i++){
            num = num*10+(int)(A[i]-'0');
            if(num<2){
                if(i!=0)
                    A[j++] = '0';
                continue;
            }
            A[j++] = int(num/2)+'0';
            num = num - (num/2)*2;
        }
        A[j] = '\0';
        n = j;
    }
    return 1;
}
