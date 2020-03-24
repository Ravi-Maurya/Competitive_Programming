string Solution::convertToTitle(int A) {
    string ans="";
    while(A){
        int rem=A%26;
        if(rem){
            char c=rem-1+'A';
            string s;
            s.push_back(c);
            ans.insert(0,s);
            A=A/26;
        }
        else{
            ans.insert(0,"Z");
            A=A/26-1;
        }
    }
    return ans;
    
}
