#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<bool> visited;
unordered_map<int, int> mp;
vector<int> parents;
vector<int> children;

void dfs(int v, vector<bool> visited, vector<int> parents, vector<int> children) {
    visited[v] = true;
        if (!visited[u]) {
            parents[u] = v;
            children[v]++;
            dfs(u, visited, parents, children);
        }
}                   

int countBigFam(int N, vector<pair<int, int>>& edges) {
    unordered_map<int, vector<int>> graph;
    for (auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(N + 1, false);
    vector<int> parents(N + 1, 0);
    vector<int> children(N + 1, 0);

   

    return bigFam;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> edges(M);
    for (int i = 0; i < M; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }

    int bigFam = countBigFam(N, edges);
    cout << bigFam << endl;

    return 0;
}
