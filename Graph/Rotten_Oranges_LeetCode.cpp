// 994. Rotting Oranges

// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.


//Link : https://leetcode.com/problems/rotting-oranges/description/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = 0;

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(rows, vector<int>(cols, 0));

        // Initialize the queue with all the rotten oranges and mark them as visited
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
            }
        }

        vector<int> addRows = {-1, 0, 1, 0};
        vector<int> addCols = {0, -1, 0, 1};

        // BFS traversal
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            ans = t;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int adjRow = r + addRows[i];
                int adjCol = c + addCols[i];

                if (adjRow >= 0 && adjRow < rows && adjCol >= 0 && adjCol < cols &&
                    vis[adjRow][adjCol] == 0 && grid[adjRow][adjCol] == 1) {
                    q.push({{adjRow, adjCol}, t + 1});
                    vis[adjRow][adjCol] = 2; // Mark this orange as rotten in visited
                }
            }
        }

        // Check for any fresh oranges that were not visited
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (vis[i][j] != 2 && grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return ans;
    }
};
