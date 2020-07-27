/*
1152. Analyze User Website Visit Pattern
Medium

74

600

Add to List

Share
We are given some website visits: the user with name username[i] visited the website website[i] at time timestamp[i].

A 3-sequence is a list of websites of length 3 sorted in ascending order by the time of their visits.  (The websites in a 3-sequence are not necessarily distinct.)

Find the 3-sequence visited by the largest number of users. If there is more than one solution, return the lexicographically smallest such 3-sequence.

 

Example 1:

Input: username = ["joe","joe","joe","james","james","james","james","mary","mary","mary"], timestamp = [1,2,3,4,5,6,7,8,9,10], website = ["home","about","career","home","cart","maps","home","home","about","career"]
Output: ["home","about","career"]
Explanation: 
The tuples in this example are:
["joe", 1, "home"]
["joe", 2, "about"]
["joe", 3, "career"]
["james", 4, "home"]
["james", 5, "cart"]
["james", 6, "maps"]
["james", 7, "home"]
["mary", 8, "home"]
["mary", 9, "about"]
["mary", 10, "career"]
The 3-sequence ("home", "about", "career") was visited at least once by 2 users.
The 3-sequence ("home", "cart", "maps") was visited at least once by 1 user.
The 3-sequence ("home", "cart", "home") was visited at least once by 1 user.
The 3-sequence ("home", "maps", "home") was visited at least once by 1 user.
The 3-sequence ("cart", "maps", "home") was visited at least once by 1 user.
*/


class Solution {
public:
    struct node{
        string user,site;
        int time;
        node(string u, int t, string s){
            user = u;
            time = t;
            site = s;
        }
    };
    static bool comp(node a, node b){
        return a.time < b.time;
    }
    vector<string> conv(string& res){
        stringstream SS(res);
        vector<string> ans;
        do{
            string word;
            SS >> word;
            ans.push_back(word);
        }while(SS);
        ans.pop_back();
        return ans;
    }
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        int n = username.size();
        vector<node> visits;
        for(int i=0; i<n; i++){
            visits.push_back(node(username[i],timestamp[i],website[i]));
        }
        sort(visits.begin(),visits.end(),comp);
        unordered_map<string,vector<string>> ump;
        for(int i=0; i<n; i++){
            ump[visits[i].user].push_back(visits[i].site);
        }
        map<string,int> count;
        for(auto p: ump){
            int N = p.second.size();
            unordered_set<string> ust;
            for(int i=0; i<N; i++)
                for(int j=i+1; j<N; j++)
                    for(int k=j+1; k<N; k++)
                        ust.insert(p.second[i]+" "+p.second[j]+" "+p.second[k]);
            for(auto s: ust)
                ++count[s];
        }
        int max = 0;
        string res;
        for(auto p:count)
            if(p.second>max){
                max = p.second;
                res = p.first;
            }
        return conv(res);
    }
};