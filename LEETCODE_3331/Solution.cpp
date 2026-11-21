class Solution {
public:
    vector<vector<int>> graph;
    vector<int> res;
    unordered_map<char, int> ancestors;
    void dfs(int node, string& s, vector<int>& parent){
        char ch = s[node];
        int prevAncestorWithSameCh = -1;
        if(ancestors.count(ch)) prevAncestorWithSameCh = ancestors[ch];
        ancestors[ch] = node;
        for(auto& it : graph[node]){
            dfs(it, s, parent);
            res[parent[it]] += res[it];
        }
        if(prevAncestorWithSameCh == -1) ancestors.erase(ch);
        else ancestors[ch] = prevAncestorWithSameCh;
        if(prevAncestorWithSameCh != -1) parent[node] = prevAncestorWithSameCh;
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        graph.assign(n, {});
        res.assign(n, 1);
        ancestors.clear();
        for(int i = 1; i < n; i++) graph[parent[i]].push_back(i);
        dfs(0, s, parent);
        return res;
    }
};