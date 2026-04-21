/*
    Approach: DFS + Combinatorics

    Goal: Count connected components that are "complete"
          (every pair of nodes has a direct edge)

    Key Insight:
        - A complete component with k nodes has exactly
          k*(k-1)/2 edges (every pair connected)
        - In an undirected graph, adjacency list stores
          each edge twice → sum of degrees = 2 * edges
        - So check: edgeCount == k * (k-1)
          (both sides multiplied by 2, no division needed)

    Steps:
        1. Build adjacency list (undirected → push both ways)
        2. For each unvisited node, run DFS:
           - Count nodes in the component (nodeCount)
           - Sum up degrees of all nodes (edgeCount)
        3. After DFS, check: edgeCount == nodeCount * (nodeCount - 1)
           If true → complete component → increment counter
        4. Return final count

    Why it works:
        - DFS naturally finds one full component per call
        - Degree sum trick avoids counting edges manually
        - Formula handles all sizes (k=1, 2, 3, ...) cleanly

    TC: O(N + E)   // DFS visits each node and edge once
    SC: O(N + E)   // adjacency list + visited + recursion stack
*/
class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis,
             int& nodeCount, int& edgeCount) {
        vis[node] = 1;
        nodeCount++;
        edgeCount += adj[node].size();

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, nodeCount, edgeCount);
            }
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // Find Each connectdd component in the graph
        // Check if each component is complete - and counf how many are
        //  Total no of edge count = k*(k-1)/2

        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            int a = e[0];
            int b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> vis(n, 0);
        int completeCount = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int nodeCount = 0, edgeCount = 0;

                dfs(i, adj, vis, nodeCount, edgeCount);

                if (edgeCount == nodeCount * (nodeCount - 1)) {
                    completeCount++;
                }
            }
        }
        return completeCount;
    }
};
