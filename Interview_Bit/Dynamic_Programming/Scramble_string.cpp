map<pair<string, string>, bool> mapp;
int rec(const string &A, const string &B) {
    pair<string, string> p = make_pair(A, B);
    if (mapp.find(p) != mapp.end()) 
        return mapp[p];
    string temp1 = A;
    string temp2 = B;
    sort(temp1.begin(), temp1.end());
    sort(temp2.begin(), temp2.end());
    if(temp1.compare(temp2) != 0)
        return false;
    if(temp1.size() <= 2)
        return true;
    for(int i = 1; i < A.length(); i++) {
        if(rec(A.substr(0, i), B.substr(0, i)) && rec(A.substr(i), B.substr(i))){
            mapp[p] = true;
            return true;
        }
        if(rec(A.substr(0, i), B.substr(B.length() - i)) && rec(A.substr(i), B.substr(0, B.length() - i))){
            mapp[p] = true;
            return true;
        }
    }
    mapp[p] = false;
    return false;
}
int Solution::isScramble(const string A, const string B) {
    if(A.size()!=B.size())
        return false;
    mapp.clear();
    return rec(A,B);
}
