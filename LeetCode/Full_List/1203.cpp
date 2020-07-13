class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<vector<int>> group2item(m);
        for (int item = 0; item < n; ++item) {
            int& g = group[item];
            if (g == -1) {
                g = m++;
                group2item.emplace_back();
            }
            group2item[g].push_back(item);
        }
        vector<vector<int>> itemadj(n);
        vector<vector<int>> groupadj(m);
        for (int v = 0; v < n; ++v) {
            int gv = group[v];
            for (int u : beforeItems[v]) {
                int gu = group[u];
                if (gu == gv)  itemadj[u].push_back(v);
                else groupadj[gu].push_back(gv);
            }
        }

        vector<int> ret;
        auto sortedGroup = TopologicalSort(groupadj);
        if (sortedGroup.empty()) return {};

        auto indegree = Indegree(itemadj);
        for (int g : sortedGroup) {
            if (group2item[g].empty()) continue;
            auto ans = Helper(itemadj, indegree, group2item[g]);
            if (ans.empty()) return {};
            copy(ans.begin(), ans.end(), back_inserter(ret));
        }
        return ret;
    }
    
    vector<int> Indegree(vector<vector<int>>& adj) {
        int size = adj.size();
        vector<int> indegree(size, 0);
        for (int u = 0; u < size; ++u) {
            for (int v : adj[u]) {
                ++indegree[v];
            }
        }
        return indegree;
    }
    
    vector<int> TopologicalSort(vector<vector<int>>& adj) {
        int size = adj.size();
        auto indegree = Indegree(adj);
        vector<int> vertices(size, 0);
        for (int pos = 0; pos < size; ++pos) vertices[pos] = pos;
        return Helper(adj, indegree, vertices);
    }
    
    vector<int> Helper(vector<vector<int>>& adj, vector<int>& indegree, vector<int>& vertices) {
        vector<int> ret;
        queue<int> que;
        for (int v : vertices) {
            if (indegree[v] == 0) que.push(v);
        }
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            ret.push_back(u);
            for (int v : adj[u]) {
                --indegree[v];
                if (indegree[v] == 0) que.push(v);
            }
        }

        if (ret.size() != vertices.size()) ret.clear();
        return ret;
    }
};
