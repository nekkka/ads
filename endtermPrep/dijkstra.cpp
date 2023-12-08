vector<int>dijkstra(vector<vector<pair<int, int>>> graph, int start){
    vector <int> dist (graph.size());
    dist[start] = 0;
    vector<bool>visited(graph.size());
    for (int i = 0; i<graph.size(); v++){
        int nearest = -1;
        for (int v = 0; v<graph.size(); v++){
            if (!visited[v] && (nearest ==-1 || dist[nearest]>dist[v])){
                nearest = v;
            }
            visitted[nearest] = 1;
            for (auro[to, weight]: graph[nearest]){
                if(dist[to]> dist[nearest] + weight) dist[to] = dist[nearest] + weight;
            }
        }
    }
    return dist;
}