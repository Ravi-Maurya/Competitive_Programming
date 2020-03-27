vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    int words = B.size(),n = A.size();
    vector<int> res;
    if(n==0 || words==0)
        return res;
    int wordsize = B[0].size();
    unordered_map<string, int> hash;
    for(auto& s: B)
        ++hash[s];
    int i = 0;
    while(i+wordsize*words-1 < n){
        unordered_map<string, int> temp;
        int j=0;
        while(j<n){
            string tmp = A.substr(i+j*wordsize,wordsize);
            if(hash.find(tmp)!=hash.end()){
                if(++temp[tmp]>hash[tmp])
                    break;
                ++j;
            }
            else
                break;
            if(j==words)
                res.push_back(i);
        }
        ++i;
    }
    return res;
}
