class Solution {
private:
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visited) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = 1; // Mark the starting cell as visited
        
        // Possible directions for moving in the grid (up, right, down, left)
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};
        
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            // Explore the 4 possible directions
            for (int i = 0; i < 4; ++i) {
                int nRow = r + dRow[i];
                int nCol = c + dCol[i];
                
                // Check if the new position is within the grid and not visited
                if (nRow >= 0 && nRow < rows && nCol >= 0 && nCol < cols 
                    && grid[nRow][nCol] == 'X' && visited[nRow][nCol] == 0) {
                    q.push({nRow, nCol});
                    visited[nRow][nCol] = 1; // Mark as visited
                }
            }
        }
    }
public:
    // Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        int count = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 'X' && visited[i][j] == 0) {
                    bfs(i, j, grid, visited);
                    count++;
                }
            }
        }
        
        return count;
    }
};
