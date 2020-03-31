string Solution::addBinary(string A, string B) {
    int a = A.size();
    int b = B.size();
    if(b>a){
        swap(a,b);
        swap(A,B);
    }
    int count = a-b;
    string tmp = "";
    while(count--){
        tmp += '0';
    }
    B = tmp+B;
    b = a;
    tmp = "";
    int carry = 0;
    for(int i=a-1;i>=0;i--){
        if(A[i]=='1' && B[i]=='1'){
            if(carry==1){
                tmp += '1';
            }
            else{
                tmp += '0';
                carry = 1;
            }
        }
        else if(A[i]=='1' && B[i]=='0' || A[i]=='0' && B[i]=='1'){
            if(carry==1){
                tmp += '0';
            }
            else{
                tmp += '1';
            }
        }
        else{
            if(carry==1){
                tmp += '1';
                carry = 0;
            }
            else{
                tmp += '0';
                carry = 0;
            }
        }
    }
    if(carry==1)
        tmp += '1';
    reverse(tmp.begin(),tmp.end());
    return tmp;
}
