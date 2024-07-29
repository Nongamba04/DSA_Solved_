class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int> &visited){
        visited[node] = 1;

        for(int i = 0;i < visited.size();i++){
            int val = isConnected[node][i];

            if(val == 1 && visited[i] != 1){
                dfs(i,isConnected,visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int count = 0;

        for(int i = 0; i < n; i++){
                if(visited[i] != 1){
                    dfs(i,isConnected,visited);
                    count++;
                }
            
        } 

        return count;   
    }
};
