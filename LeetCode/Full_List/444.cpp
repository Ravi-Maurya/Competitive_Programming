/*
444. Sequence Reconstruction
Medium

262

922

Add to List

Share
Check whether the original sequence org can be uniquely reconstructed from the sequences in seqs. The org sequence is a permutation of the integers from 1 to n, with 1 ≤ n ≤ 104. Reconstruction means building a shortest common supersequence of the sequences in seqs (i.e., a shortest sequence so that all sequences in seqs are subsequences of it). Determine whether there is only one sequence that can be reconstructed from seqs and it is the org sequence.

 

Example 1:

Input: org = [1,2,3], seqs = [[1,2],[1,3]]
Output: false
Explanation: [1,2,3] is not the only one sequence that can be reconstructed, because [1,3,2] is also a valid sequence that can be reconstructed.
Example 2:

Input: org = [1,2,3], seqs = [[1,2]]
Output: false
Explanation: The reconstructed sequence can only be [1,2].
Example 3:

Input: org = [1,2,3], seqs = [[1,2],[1,3],[2,3]]
Output: true
Explanation: The sequences [1,2], [1,3], and [2,3] can uniquely reconstruct the original sequence [1,2,3].
Example 4:

Input: org = [4,1,5,2,6,3], seqs = [[5,2,6,3],[4,1,5,2]]
Output: true
 

Constraints:

1 <= n <= 10^4
org is a permutation of {1,2,...,n}.
1 <= segs[i].length <= 10^5
seqs[i][j] fits in a 32-bit signed integer.
*/

class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        unordered_map<int, unordered_set<int>>graph;
        vector<int>indegree(n + 1, -1);
        for(auto& v: seqs){
            for(int i = 0; i < v.size(); i++){
                if(v[i] > n || v[i] < 0)
                    return false;
                if(indegree[v[i]] == -1)
                    indegree[v[i]] = 0;
                if(i + 1 < v.size() && graph[v[i]].insert(v[i + 1]).second)
                    if(v[i + 1] > n || v[i + 1] < 0)
                        return false;
                    else
                        indegree[v[i + 1]] += ((indegree[v[i + 1]] < 0 )? 2 : 1);
            }
        }
        for(int i = 0; i < n - 1; i++){
            if(indegree[org[i]] || !indegree[org[i + 1]])
                return false;
            else
                for(auto x: graph[org[i]])
                    indegree[x]--;
        }
        return (indegree[org.back()] == 0);
    }
};