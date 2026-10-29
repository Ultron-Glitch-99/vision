
#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <limits>
using namespace std;

class Graph {
private:
    int vertices;
    vector<string> locations;
    vector<vector<pair<int, int>>> adjList;

public:
    Graph(int n) {
        vertices = n;
        locations.resize(n);
        adjList.resize(n);
    }

    void inputLocations() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < vertices; i++) {
            cout << "Enter location " << i << ": ";
            getline(cin, locations[i]);
        }
    }

    void addRoute(int u, int v, int distance) {
        adjList[u].push_back({v, distance});
        adjList[v].push_back({u, distance});
    }

    void displayGraph() {
        cout << "\nSupply Chain Network:\n";

        for (int i = 0; i < vertices; i++) {
            cout << i << " (" << locations[i] << ") -> ";

            for (auto route : adjList[i]) {
                cout << locations[route.first]
                     << " (" << route.second << " km) ";
            }

            cout << endl;
        }
    }

    void dijkstra(int source, int destination) {
        vector<int> distance(vertices, INT_MAX);
        vector<int> parent(vertices, -1);
        vector<bool> visited(vertices, false);

        distance[source] = 0;

        for (int count = 0; count < vertices; count++) {
            int u = -1;

            for (int i = 0; i < vertices; i++) {
                if (!visited[i] &&
                    (u == -1 || distance[i] < distance[u])) {
                    u = i;
                }
            }

            if (u == -1 || distance[u] == INT_MAX) {
                break;
            }

            visited[u] = true;

            if (u == destination) {
                break;
            }

            for (auto route : adjList[u]) {
                int v = route.first;
                int weight = route.second;

                if (!visited[v] &&
                    distance[u] <= INT_MAX - weight &&
                    distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    parent[v] = u;
                }
            }
        }

        if (distance[destination] == INT_MAX) {
            cout << "No route exists between these locations.\n";
            return;
        }

        vector<int> path;

        for (int current = destination; current != -1;
             current = parent[current]) {
            path.push_back(current);
        }

        cout << "\nShortest Route:\n";

        for (int i = static_cast<int>(path.size()) - 1; i >= 0; i--) {
            cout << locations[path[i]];

            if (i > 0) {
                cout << " -> ";
            }
        }

        cout << "\nTotal Distance: "
             << distance[destination] << " km\n";
    }
};

int main() {
    int n, m;

    cout << "Enter number of supply chain locations: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of locations.\n";
        return 0;
    }

    Graph supplyChain(n);
    supplyChain.inputLocations();

    cout << "Enter number of transportation routes: ";
    cin >> m;

    if (m < 0) {
        cout << "Invalid number of routes.\n";
        return 0;
    }

    cout << "Enter each route as: source destination distance(km)\n";

    for (int i = 0; i < m; i++) {
        int u, v, distance;
        cin >> u >> v >> distance;

        if (u < 0 || u >= n || v < 0 || v >= n ||
            u == v || distance < 0) {
            cout << "Invalid route. Enter it again.\n";
            i--;
            continue;
        }

        supplyChain.addRoute(u, v, distance);
    }

    supplyChain.displayGraph();

    int source, destination;

    cout << "\nEnter source location index: ";
    cin >> source;

    cout << "Enter destination location index: ";
    cin >> destination;

    if (source < 0 || source >= n ||
        destination < 0 || destination >= n) {
        cout << "Invalid source or destination.\n";
        return 0;
    }

    supplyChain.dijkstra(source, destination);

    return 0;
}
