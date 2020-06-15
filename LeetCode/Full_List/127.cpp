class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int wordsize = beginWord.size();
        unordered_set<string> words(wordList.begin(),wordList.end()),visited;
        if(!words.count(endWord))
            return 0;
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        visited.insert(beginWord);
        while(!q.empty()){
            string beginWord = q.front().first;
            int count = q.front().second;
            q.pop();
            for(int i=0; i<wordsize; i++){
                char tmp = beginWord[i];
                for(int k = 0; k<26; k++){
                    beginWord[i] = (char)(k+'a');
                    if(words.count(beginWord) && !visited.count(beginWord)){
                        if(beginWord == endWord)
                            return (count+1);
                        visited.insert(beginWord);
                        q.push({beginWord,count+1});
                    }
                }
                beginWord[i] = tmp;
            }
        }
        return 0;
    }
};