#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> tree;
vector<int> depth;

void calculateDepth(int node, int parent) {
    depth[node] = depth[parent] + 1;
    for (int child : tree[node]) {
        if (child != parent) {
            calculateDepth(child, node);
        }
    }
}

int main() {
    int n, x;
    cin >> n >> x;
    tree.resize(n + 1);
    depth.resize(n + 1, 0);

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    calculateDepth(1, 0);

    int maxDepth = 0;
    for (int i = 1; i <= n; i++) {
        if (depth[i] > maxDepth) {
            maxDepth = depth[i];
        }
    }

    int aliceMoves = depth[x] - 1; 
    int bobMoves = maxDepth - depth[x];

    int totalMoves = aliceMoves + bobMoves;

    cout << totalMoves << endl;

    return 0;
}
