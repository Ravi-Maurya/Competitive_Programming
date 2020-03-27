int gcd (int a, int b)
{
    if (a == 0) return b;
    if (b == 0) return a;
    if (a < 0) return gcd(a*-1, b);
    if (b < 0) return gcd(a, b*-1);
    if (a > b) return gcd(b, a);
    return gcd(b%a, a);
}

int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int res = 0;
    map<pair<int,int>,int> hash;
    int n = A.size(),i;
    for(i=0;i<n;i++){
        hash.clear();
        int repeat = 1, currmax = 0;
        for(int j=i+1;j<n;j++){
            int xdiff = A[i]-A[j], ydiff = B[i]-B[j];
            if(xdiff==0 && ydiff==0){
                repeat++;
                continue;
            }
            if(xdiff<0){
                xdiff *= -1;
                ydiff *= -1;
            }
            int g = gcd(xdiff,ydiff);
            hash[make_pair(xdiff/g,ydiff/g)]++;
            currmax = max(currmax,hash[make_pair(xdiff/g,ydiff/g)]);
        }
        currmax += repeat;
        res = max(res,currmax);
    }
    return res;
}
