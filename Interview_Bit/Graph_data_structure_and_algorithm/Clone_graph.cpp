/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> visited;
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    if(!node)
        return NULL;
    UndirectedGraphNode* root = new UndirectedGraphNode(node->label);
    visited[node] = root;;
    for(auto x:node->neighbors){
        if(visited.find(x)==visited.end())
            (root->neighbors).push_back(cloneGraph(x));
        else
            (root->neighbors).push_back(visited[x]);
    }
    return root;
}
