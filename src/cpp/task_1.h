#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> graph(n + 1);
    vector<pair<int, int>> edges;
    map<pair<int, int>, int> edge_indices;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        edges.push_back({a, b});
        edge_indices[{a, b}] = i + 1;
        edge_indices[{b, a}] = i + 1;
    }

    set<tuple<int, int, int>> forbidden_triples;

    for (int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        forbidden_triples.insert({a, b, c});
    }

    vector<int> distance(n + 1, -1);
    vector<int> parent(n + 1, -1);

    queue<int> q;
    q.push(1);
    distance[1] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (distance[neighbor] == -1 && forbidden_triples.count({parent[node], node, neighbor}) == 0) {
                q.push(neighbor);
                distance[neighbor] = distance[node] + 1;
                parent[neighbor] = node;
            }
        }
    }

    if (distance[n] == -1) {
        cout << "-1" << endl;
    } else {
        vector<int> shortest_path;
        int current_node = n;

        while (current_node != -1) {
            shortest_path.push_back(current_node);
            current_node = parent[current_node];
        }

        cout << shortest_path.size() - 1 << endl;
        for (int i = shortest_path.size() - 1; i >= 0; i--) {
            cout << shortest_path[i];
            if (i != 0) {
                int a = shortest_path[i];
                int b = shortest_path[i - 1];
                int edge_index = edge_indices[{a, b}];
                cout << " " << edge_index;
            }
        }
        cout << endl;
    }

    return 0;
}
