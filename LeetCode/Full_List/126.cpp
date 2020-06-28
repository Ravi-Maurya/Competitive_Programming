class Solution {
    
    vector<vector<string>> res;
    vector<string> path;
    unordered_map<string,vector<string>> graph;
    
public:
    
    bool bfs(const string& beginWord,const string& endWord, unordered_set<string>& wordList){ // create a graph with bfs 
    // like this
    // hit -> hot -> (dot,lot) -> (dog,log) -> (cog,cog)
    // i.e. all the shortest path from hit to cog
        unordered_set<string> current, next;
        current.insert(beginWord);
        while(true){
            for(auto word: current)
                wordList.erase(word);
            for(auto parent: current){
                string word = parent;
                for(int i=0; i<word.size(); i++){
                    char ch = word[i];
                    for(char c='a'; c<='z'; c++){
                        word[i] = c;
                        if(wordList.count(word)){
                            next.insert(word);
                            graph[parent].push_back(word);
                        }
                    }
                    word[i] = ch;
                }
            }
            if(next.empty())
                return false;
            if(next.count(endWord))
                return true;
            current.clear();
            swap(current,next);
        }
        return false;
    }
    
    void dfs(string beginWord, string endWord){
        // traverse the graph created dfs wise;
        if(beginWord == endWord){
            res.push_back(path);
            return;
        }
        for(auto child: graph[beginWord]){
            path.push_back(child);
            dfs(child,endWord);
            path.pop_back();
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> ust(wordList.begin(), wordList.end());
        if(!ust.count(endWord))
            return res;
        if(beginWord == endWord){
            res.push_back({beginWord});
            return res;
        }
        if(!bfs(beginWord,endWord,ust))
            return res;
        path.push_back(beginWord);
        dfs(beginWord,endWord);
        return res;
    }

};