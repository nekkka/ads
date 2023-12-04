#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

typedef pair<int, int> pii;

vector<vector<pii>> adj; // adjacency list of the graph
vector<bool> visited; // visited array to keep track of visited vertices

int prim(int start) {
    int n = adj.size();
    int mstWeight = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq; // priority queue to select the next edge to add to the MST

    pq.push(make_pair(0, start)); // start from the given vertex with weight 0

    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (visited[u]) continue; // skip visited vertices
        visited[u] = true;
        mstWeight += w;

        for (auto& v : adj[u]) {
            if (!visited[v.first]) {
                pq.push(make_pair(v.second, v.first)); // add edges connected to the current vertex
            }
        }
    }

    return mstWeight;
}

int main() {
    // define the graph
    adj.resize(5); // 5 vertices

    // add edges to the graph
    adj[0].push_back(make_pair(1, 2)); // edge from vertex 0 to 1 with weight 2
    adj[1].push_back(make_pair(0, 2)); // edge from vertex 1 to 0 with weight 2

    adj[0].push_back(make_pair(3, 6)); // edge from vertex 0 to 3 with weight 6
    adj[3].push_back(make_pair(0, 6)); // edge from vertex 3 to 0 with weight 6

    adj[1].push_back(make_pair(2, 3)); // edge from vertex 1 to 2 with weight 3
    adj[2].push_back(make_pair(1, 3)); // edge from vertex 2 to 1 with weight 3

    adj[1].push_back(make_pair(3, 8)); // edge from vertex 1 to 3 with weight 8
    adj[3].push_back(make_pair(1, 8)); // edge from vertex 3 to 1 with weight 8

    adj[1].push_back(make_pair(4, 5)); // edge from vertex 1 to 4 with weight 5
    adj[4].push_back(make_pair(1, 5)); // edge from vertex 4 to 1 with weight 5

    adj[2].push_back(make_pair(4, 7)); // edge from vertex 2 to 4 with weight 7
    adj[4].push_back(make_pair(2, 7)); // edge from vertex 4 to 2 with weight 7

    adj[3].push_back(make_pair(4, 9)); // edge from vertex 3 to 4 with weight 9
    adj[4].push_back(make_pair(3, 9)); // edge from vertex 4 to 3 with weight 9

    visited.resize(5, false); // set all vertices as unvisited

    int mstWeight = prim(0); // find the MST starting from vertex 0

    cout << "Minimum spanning tree weight: " << mstWeight << endl;

    return 0;
}