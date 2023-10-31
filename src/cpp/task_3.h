#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    
    vector<int> sequence;
    sequence.push_back(b);
    
    while (b > a) {
        if (b % 10 == 1) {
            b /= 10;
            sequence.push_back(b);
        } else if (b % 2 == 0) {
            b /= 2;
            sequence.push_back(b);
        } else {
            break;
        }
    }
    
    if (b == a) {
        cout << "YES" << endl;
        cout << sequence.size() << endl;
        for (int i = sequence.size() - 1; i >= 0; i--) {
            cout << sequence[i];
            if (i != 0) {
                cout << " ";
            }
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
