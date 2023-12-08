void dfs(vector<vector<int>>&graph, int v, vector <inr> &visited){
    visited[v] = 1;
    for (int to:graph[v]){
        if(!visited[to]) dfs(graph, to, visited);
    }
}