class Solution {
  public:
    // Function to find the number of islands.
    void dfs(int row, int col, vector<vector<int>>&visited, vector<vector<char>>&grid){
        visited[row][col] = 1;
        
        for(int minRow = -1; minRow < 2; minRow++){
            for(int minCol = -1; minCol < 2; minCol++){
                int rNeighbour = row + minRow;
                int cNeighbour = col  + minCol;
                
                if(rNeighbour >= 0 && rNeighbour < grid.size() && cNeighbour >= 0 && cNeighbour < grid[0].size()
                && grid[rNeighbour][cNeighbour] == '1' && visited[rNeighbour][cNeighbour] != 1){
                    dfs(rNeighbour,cNeighbour, visited, grid);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int>>visited(rows,vector<int>(cols,0));
        int count = 0;
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '1' && visited[i][j] != 1){
                    dfs(i,j,visited,grid);
                    count++;
                }
            }
        }
        
        return count;
    }
};
