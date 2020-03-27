string Solution::fractionToDecimal(int A, int B) {
    long long int a = A;
    long long int b = B;
    int sign = 1;
    string s = "";
    if((a<0 && b>0) || (a>0 && b<0)){
        s += "-";
    }
    a = abs(a);
    b = abs(b);
    // cout<<A<<B;
    if(a==0)
        return "0";
    long long int division = a/b;
    s += to_string(division);
    a %= b;
    if(a==0)
        return s;
    s += ".";
    bool repeat = false;
    int val;
    unordered_map<long long int,long long int> hash;
    while(a!=0 && !repeat){
        a*= 10;
        if(hash.find(a)==hash.end())
            hash.insert({a,s.size()});
        else{
            repeat = true;
            val = hash[a];
            break;
        }
        int t = a/b;
        s += to_string(t);
        a %= b;
    }
    if(repeat){
        s += ")";
        s.insert(val,"(");
    }
    return s;
}
