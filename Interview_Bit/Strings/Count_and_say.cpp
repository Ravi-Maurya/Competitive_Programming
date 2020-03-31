string Solution::countAndSay(int A) {
    if(A==1)
        return "1";
    A-=1;
    string start = "1";
    int count = 0;
    string s = "";
    while(A--){
        int n = start.size(),i=0;
        while(i<n){
            count = 1;
            while(i<n-1 and start[i]==start[i+1]){
                count++;
                i++;
            }
            s += to_string(count) + start[i];
            i++;
        }
        start = s;
        s = "";
    }
    return start;
}
