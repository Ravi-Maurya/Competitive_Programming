int Solution::solve(string A, string B, vector<string> &C) {
    int wordsize = A.size();
    if(A==B)
        return 0;
    unordered_set<string> words;
    for(auto x:C)
        words.insert(x);
    queue<pair<string,int>> q;
    unordered_set<string> visited;
    visited.insert(A);
    q.push({A,1});
    while(!q.empty()){
        pair<string,int> word = q.front();
        q.pop();
        for(int pos =0; pos<wordsize;pos++){
            char org = word.first[pos];
            for(char c='a';c<='z';c++){
                word.first[pos]=c;
                if(word.first == B)
                    return word.second+1;
                if(words.find(word.first)!=words.end() && visited.find(word.first)==visited.end()){
                    visited.insert(word.first);
                    q.push({word.first,word.second+1});
                    if(word.first == B)
                        return word.second+1;
                }
            }
            word.first[pos] = org;
        }
    }
    return 0;
}