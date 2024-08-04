// Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, 
// check whether it contains any cycle or not. Graph is in the form of adjacency list
// where adj[i] contains all the nodes ith node is having edge with.

//   A particular node can be marked visited only by its parent so when 
//   we reach a node and traverse all its adjacent node and 
//   find more than one visited ,that shows this node has more 
//   than one parent or we can simply say this particular node is 
//   also getting visited from another direction 

// Ek hi parent hota hai which is the only one that will be already visited in all the adjacent nodes 
// for a particular node for a non - cyclic graph.
  //and in that case we can say there is cycle presert 

// Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph
    bool bfs(int idx,vector<int>adj[],vector<int>&vis){
        vis[idx] = 1;
        
        queue<int>q;
        q.push(idx);
        
        while(!q.empty()){
            int i = q.front();
            q.pop();
            
            int cnt = 0;
            for(auto it : adj[i]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
                else{
                    cnt++;
                }
            }
            
            if(cnt > 1) return true;
        }
        
        return false;
        
        
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V, 0);
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(bfs(i,adj,vis)){
                return true;}
            }
            
        }
        
        return false;
    }
