string Solution::multiply(string A, string B) {
    if(A.size()==0 || B.size()==0)
        return 0;
    int sign = 1;
    if(A[0]=='-' || B[0]=='-'){
        if(A[0]=='-'){
            sign = -1*sign;
            A = A.substr(1);
        }
        if(B[0]=='-')
            sign = -1*sign;
            B = B.substr(1);
    }
    string ans = "";
    if(sign==-1)
        ans += '-';
    int a = A.size();
    int b = B.size();
    vector<int> res(a+b,0);
    int i_n1=0,i_n2=0;
    for(int i=a-1;i>=0;i--){
        int carry = 0;
        int n1 = A[i]-'0';
        i_n2 = 0;
        for(int j=b-1;j>=0;j--){
            int n2 = B[j]-'0';
            int sum = n1*n2 + res[i_n2+i_n1] + carry;
            carry = sum/10;
            res[i_n2 + i_n1] = sum%10;
            i_n2++;
        }
        if(carry>0)
            res[i_n2 + i_n1] += carry;
        i_n1++;
    }
    int i=res.size()-1;
    while(i>=0 && res[i]==0)
        i--;
    if(i==-1)
        return "0";
    while(i>=0)
        ans+=to_string(res[i--]);
    return ans;
}
