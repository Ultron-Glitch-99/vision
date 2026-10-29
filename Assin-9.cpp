
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Maze {
private:
    int rows, cols;
    vector<vector<int>> grid;
    pair<int, int> start, goal;

    bool isValid(int r, int c) {
        return r >= 0 && r < rows &&
               c >= 0 && c < cols &&
               grid[r][c] == 0;
    }

    void printPath(vector<vector<pair<int, int>>>& parent) {
        vector<pair<int, int>> path;
        pair<int, int> current = goal;

        while (current != make_pair(-1, -1)) {
            path.push_back(current);
            if (current == start) break;
            current = parent[current.first][current.second];
        }

        if (path.back() != start) {
            cout << "No path found.\n";
            return;
        }

        for (int i = static_cast<int>(path.size()) - 1; i >= 0; i--) {
            cout << "(" << path[i].first << ","
                 << path[i].second << ")";
            if (i > 0) cout << " -> ";
        }
        cout << endl;
    }

public:
    Maze(int r, int c) {
        rows = r;
        cols = c;
        grid.resize(rows, vector<int>(cols));
    }

    void inputMaze() {
        cout << "Enter maze grid (0 = open, 1 = blocked):\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> grid[i][j];
            }
        }

        cout << "Enter start row and column: ";
        cin >> start.first >> start.second;

        cout << "Enter goal row and column: ";
        cin >> goal.first >> goal.second;
    }

    void displayMaze() {
        cout << "\nMaze:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (make_pair(i, j) == start)
                    cout << "S ";
                else if (make_pair(i, j) == goal)
                    cout << "G ";
                else
                    cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }

    void DFS() {
        if (!isValid(start.first, start.second) ||
            !isValid(goal.first, goal.second)) {
            cout << "Invalid start or goal cell.\n";
            return;
        }

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<vector<pair<int, int>>> parent(
            rows, vector<pair<int, int>>(cols, {-1, -1}));

        stack<pair<int, int>> st;
        st.push(start);
        visited[start.first][start.second] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!st.empty()) {
            pair<int, int> current = st.top();
            st.pop();

            if (current == goal) {
                cout << "DFS Path:\n";
                printPath(parent);
                return;
            }

            for (int i = 0; i < 4; i++) {
                int nr = current.first + dr[i];
                int nc = current.second + dc[i];

                if (isValid(nr, nc) && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    parent[nr][nc] = current;
                    st.push({nr, nc});
                }
            }
        }

        cout << "DFS: No path found.\n";
    }

    void BFS() {
        if (!isValid(start.first, start.second) ||
            !isValid(goal.first, goal.second)) {
            cout << "Invalid start or goal cell.\n";
            return;
        }

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<vector<pair<int, int>>> parent(
            rows, vector<pair<int, int>>(cols, {-1, -1}));

        queue<pair<int, int>> q;
        q.push(start);
        visited[start.first][start.second] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();

            if (current == goal) {
                cout << "BFS Shortest Path:\n";
                printPath(parent);
                return;
            }

            for (int i = 0; i < 4; i++) {
                int nr = current.first + dr[i];
                int nc = current.second + dc[i];

                if (isValid(nr, nc) && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    parent[nr][nc] = current;
                    q.push({nr, nc});
                }
            }
        }

        cout << "BFS: No path found.\n";
    }
};

int main() {
    int rows, cols;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    if (rows <= 0 || cols <= 0) {
        cout << "Invalid maze dimensions.\n";
        return 0;
    }

    Maze maze(rows, cols);
    maze.inputMaze();
    maze.displayMaze();

    int choice;

    do {
        cout << "\n===== MAZE PATH FINDER =====\n";
        cout << "1. Find Path using DFS\n";
        cout << "2. Find Shortest Path using BFS\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            maze.DFS();
            break;
        case 2:
            maze.BFS();
            break;
        case 3:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 3);

    return 0;
}
