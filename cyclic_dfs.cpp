#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool iterativeDFS(int start, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& traversal) {
    stack<pair<int, int>> st;
    st.push({start, -1});

    while (!st.empty()) {
        int node = st.top().first;
        int parent = st.top().second;
        st.pop();

        if (visited[node]) {
            if (parent != -1 && node != parent)
                return true;
            continue;
        }

        visited[node] = true;
        traversal.push_back(node);

        for (int neighbor = adj.size() - 1; neighbor >= 0; --neighbor) {
            if (adj[node][neighbor]) {
                if (!visited[neighbor]) {
                    st.push({neighbor, node});
                } else if (neighbor != parent) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    char choice;

    do {
        int size;
        cout << "\nThis is for Depth First Search Cycle Detection\n";
        cout << "Input the size of the adjacency matrix: ";
        cin >> size;

        vector<vector<int>> adj(size, vector<int>(size));
        cout << "Enter the adjacency matrix (" << size << " x " << size << "):\n";

        for (int i = 0; i < size; i++) {
            cout << "Row " << i << ": ";
            for (int j = 0; j < size; j++) {
                cin >> adj[i][j];
            }
        }

        vector<bool> visited(size, false);
        vector<int> traversal;
        bool isCyclic = false;

        for (int i = 0; i < size; i++) {
            if (!visited[i]) {
                if (iterativeDFS(i, adj, visited, traversal)) {
                    isCyclic = true;
                }
            }
        }

        cout << "\nDFS Traversal: ";
        for (int v : traversal)
            cout << v << " ";

        cout << "\nThe graph is ";
        if (isCyclic)
            cout << "cyclic.\n";
        else
            cout << "acyclic.\n";

        cout << "\nTry again? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    cout << ">:(\n";
    return 0;
}
