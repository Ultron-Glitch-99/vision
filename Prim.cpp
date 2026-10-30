
#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Graph {
    int n;
    vector<string> locations;
    vector<vector<int>> cost;

public:
    Graph(int vertices) {
        n = vertices;
        locations.resize(n);
        cost.resize(n, vector<int>(n, 0));
    }

    void inputLocations() {
        for (int i = 0; i < n; i++) {
            cout << "Enter location " << i << " name: ";
            getline(cin >> ws, locations[i]);
        }
    }

    void inputEdges() {
        int edges;

        cout << "Enter number of connections: ";
        cin >> edges;

        for (int i = 0; i < edges; i++) {
            int u, v, weight;

            cout << "Enter source index, destination index and distance: ";
            cin >> u >> v >> weight;

            if (u < 0 || u >= n || v < 0 || v >= n || weight <= 0) {
                cout << "Invalid connection. Try again.\n";
                i--;
                continue;
            }

            cost[u][v] = weight;
            cost[v][u] = weight;
        }
    }

    void primsAlgorithm() {
        vector<int> key(n, INT_MAX);
        vector<int> parent(n, -1);
        vector<bool> selected(n, false);

        key[0] = 0;

        int totalCost = 0;

        cout << "\nMinimum Spanning Tree:\n";
        cout << "Connection\tDistance\n";

        for (int count = 0; count < n; count++) {
            int u = -1;
            int minimum = INT_MAX;

            for (int i = 0; i < n; i++) {
                if (!selected[i] && key[i] < minimum) {
                    minimum = key[i];
                    u = i;
                }
            }

            if (u == -1) {
                cout << "\nGraph is disconnected. MST cannot be formed.\n";
                return;
            }

            selected[u] = true;

            if (parent[u] != -1) {
                cout << locations[parent[u]] << " - "
                     << locations[u] << "\t"
                     << cost[parent[u]][u] << "\n";

                totalCost += cost[parent[u]][u];
            }

            for (int v = 0; v < n; v++) {
                if (cost[u][v] != 0 &&
                    !selected[v] &&
                    cost[u][v] < key[v]) {

                    key[v] = cost[u][v];
                    parent[v] = u;
                }
            }
        }

        cout << "\nTotal Minimum Cost: " << totalCost << endl;
    }
};

int main() {
    int n;

    cout << "Enter number of locations: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of locations.\n";
        return 0;
    }

    Graph g(n);

    g.inputLocations();
    g.inputEdges();

    g.primsAlgorithm();

    return 0;
}
