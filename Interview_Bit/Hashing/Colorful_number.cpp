int Solution::colorful(int A) {
    unordered_map<int,int> hash;
    long long int prod=1, num=0;
    while(A>0){
        int rem=0, temp=A;
        num=0, prod=1;
        while(temp>0){
            rem=temp%10;
            num=num*10+rem;
            prod=prod*rem;
            temp=temp/10;
            if(hash.find(prod)==hash.end())
                hash[prod]=num;
            else
                return 0;
        }
        A/=10;
    }
    return 1;
}
