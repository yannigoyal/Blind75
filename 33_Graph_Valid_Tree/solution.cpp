/*
    Approach: DFS (Two simple checks)

    A graph is a valid tree if:
        1. It has exactly N-1 edges
        2. All N nodes are connected

    Why only 2 checks?
        - If E = N-1 AND graph is connected → cycle is impossible
          (because any extra edge would create a cycle, but we have exactly N-1)
        - So we don't need a separate cycle check!

    Steps:
        1. Check if m == n - 1, else return 0
           (handles extra edges, duplicates, self-loops, missing edges)
        2. Build adjacency list (undirected → push both ways)
        3. Run DFS from node 0, count all visited nodes
        4. If visitedCount == n → all connected → it's a tree (return 1)
           Else → disconnected → not a tree (return 0)

    Edge cases handled:
        - Self-loops (e.g. [0,0]) → fails either edge count or connectivity
        - Multi-edges (e.g. [0,1] twice) → fails edge count check
        - Disconnected nodes → caught by DFS visit count

    TC: O(N + M)   // DFS visits each node and edge once
    SC: O(N + M)   // adjacency list + visited array + recursion stack
*/

class Solution {
  private:
    int dfs(vector<vector<int>>& adj, int node, vector<int>& vis) {
        vis[node] = 1;
        int count = 1;
        
        for(auto it:adj[node]) {
            if(!vis[it]) {
                count += dfs(adj,it,vis);
            }
        }
        return count;
    }
  public:
    int isTree(int n, int m, vector<vector<int>> &edges) {
        if(m != n-1) return 0;
        
        vector<vector<int>> adj(n);
        
        for(auto &it: edges) {
            int a = it[0];
            int b = it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            
        }
        
        vector<int> vis(n, 0);
        int visitedCount = dfs(adj,0,vis);
        
        return (visitedCount == n) ?1 : 0;
        
    }
};

