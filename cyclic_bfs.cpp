#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isCyclicBFS(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<pair<int, int>> q;
    q.push({start, -1});
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int neighbor = 0; neighbor < adj.size(); neighbor++) {
            if (adj[node][neighbor]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, node});
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
        cout << "\nThis is for Breadth First Search Cycle Detection (Undirected Graph)\n";
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
        bool hasCycle = false;

        for (int i = 0; i < size; i++) {
            if (!visited[i]) {
                if (isCyclicBFS(i, adj, visited)) {
                    hasCycle = true;
                    break;
                }
            }
        }

        cout << "The graph is ";
        if (hasCycle)
            cout << "cyclic.\n";
        else
            cout << "acyclic.\n";

        cout << "\nTry again? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    cout << "Ceeeeeeb\n";
    return 0;
}
