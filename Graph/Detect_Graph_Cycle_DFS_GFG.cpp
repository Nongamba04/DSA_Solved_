
//Link : https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int node, vector<int>adj[], vector<int>& vis, int parent){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(vis[it] != 1){
                if(dfs(it,adj,vis,node)){
                 return true;   
                }
                
            }
            else if(it != parent){
                return true;
            }
        }
        
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V,0);
        
        for(int i = 0; i < V; i++){
            if(vis[i] != 1){
                if(dfs(i,adj,vis,-1)) return true;
            }
        }
        
        return false;
        
    }
