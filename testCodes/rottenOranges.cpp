#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    queue<pair<int, int>> q;
    int fresh_count = 0;

    // Initialize the queue with all the rotten oranges and count the fresh oranges
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (grid[r][c] == 2) {
                q.push({r, c});
            } else if (grid[r][c] == 1) {
                fresh_count++;
            }
        }
    }

    if (fresh_count == 0) return 0;  // No fresh oranges, return 0

    int minutes = 0;
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // BFS process
    while (!q.empty()) {
        int size = q.size();
        bool has_rotted = false;

        for (int i = 0; i < size; ++i) {
            auto [r, c] = q.front();
            q.pop();

            for (auto [dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                    fresh_count--;
                    has_rotted = true;
                }
            }
        }

        if (has_rotted) {
            minutes++;
        }
    }

    return fresh_count == 0 ? minutes : -1;
}

int main() {
    vector<vector<int>> grid1 = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << orangesRotting(grid1) << endl;  // Output: 4

    vector<vector<int>> grid2 = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
    cout << orangesRotting(grid2) << endl;  // Output: -1

    vector<vector<int>> grid3 = {{0, 2}};
    cout << orangesRotting(grid3) << endl;  // Output: 0

    return 0;
}
