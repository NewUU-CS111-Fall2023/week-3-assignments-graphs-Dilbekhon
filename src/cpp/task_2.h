#include <iostream>
#include <vector>

using namespace std;

bool dfs(int x, int y, int spikes_left, int n, int m, vector<vector<char>>& maze) {
    if (x < 0 || x >= n || y < 0 || y >= m || maze[x][y] == '#') {
        return false;
    }
    if (maze[x][y] == 'x') {
        return true;
    }
    if (maze[x][y] == 's') {
        spikes_left--;
        if (spikes_left < 0) {
            return false;
        }
    }
    maze[x][y] = '#'; 
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (const auto& dir : directions) {
        int dx = dir.first;
        int dy = dir.second;
        if (dfs(x + dx, y + dy, spikes_left, n, m, maze)) {
            return true;
        }
    }
    maze[x][y] = '.'; 
    return false;
}

string canEscape(int n, int m, int j, vector<vector<char>>& maze) {
    int start_x, start_y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == '@') {
                start_x = i;
                start_y = j;
                break;
            }
        }
    }

    return dfs(start_x, start_y, j, n, m, maze) ? "SUCCESS" : "IMPOSSIBLE";
}

int main() {
    int n, m, j;
    cin >> n >> m >> j;
    vector<vector<char>> maze(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    string result = canEscape(n, m, j, maze);
    cout << result << endl;

    return 0;
}
