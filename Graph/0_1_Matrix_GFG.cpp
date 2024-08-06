// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

// The distance between two adjacent cells is 1.

//Link : https://leetcode.com/problems/01-matrix/description/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
       
        queue<pair<pair<int,int>,int>> q;
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> ans(m,vector<int>(n,0));
         vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        vector<int> addRows = {-1,0,1,0};
        vector<int> addCols = {0,-1,0,1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dis = q.front().second;
            q.pop();

            ans[r][c] = dis;
            for(int i = 0; i < 4; i++){
                int adjRow = r + addRows[i];
                int adjCol = c + addCols[i];

                if(adjRow >= 0 && adjRow < m && adjCol >= 0 && adjCol < n && vis[adjRow][adjCol]!=1){
                    q.push({{adjRow,adjCol},dis+1});
                    vis[adjRow][adjCol] = 1;
                }
            }

            


        }

        return ans;
    }
};
