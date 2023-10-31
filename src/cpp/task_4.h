#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> fragments(n);

    for (int i = 0; i < n; i++) {
        cin >> fragments[i];
    }

    set<char> unique_chars;
    for (const string& fragment : fragments) {
        for (char c : fragment) {
            unique_chars.insert(c);
        }
    }

    vector<char> order;
    vector<int> current_indices(n, 0);

    queue<char> q;
    for (char c : unique_chars) {
        q.push(c);
    }

    while (!q.empty()) {
        char c = q.front();
        q.pop();
        order.push_back(c);

        for (int i = 0; i < n; i++) {
            while (current_indices[i] < fragments[i].size() && fragments[i][current_indices[i]] != c) {
                current_indices[i]++;
            }
            if (current_indices[i] < fragments[i].size() && fragments[i][current_indices[i]] == c) {
                current_indices[i]++;
                if (current_indices[i] < fragments[i].size()) {
                    q.push(fragments[i][current_indices[i] - 1]);
                }
            }
        }
    }

    string minimal_genome(order.begin(), order.end());
    cout << minimal_genome << endl;

    return 0;
}
