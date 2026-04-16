/*
We model the courses as a directed graph.
Each prerequisite [a, b] means b → a (you must take b before a).

We use DFS to detect a cycle in the graph.

vis[] → marks nodes that are already visited  
pathVis[] → marks nodes in the current DFS path  

If during DFS we reach a node that is already in pathVis,
it means we found a cycle → return false.

If no cycle is found in the entire graph,
we can finish all courses → return true.

TC: O(V + E)
SC: O(V + E)
*/
bool dfs(int node ,vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis) {
    vis[node] = 1;
    pathVis[node] = 1;

    for(auto it: adj[node]) {
        if(!vis[it]) {
            if(dfs(it,adj,vis,pathVis)) {
                return true;
            }
        } else if(pathVis[it]) {
            return true;
        }
    }
    pathVis[node] = 0;
    return false;
}
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);

    for(auto &it: prerequisites) {
        int a = it[0];
        int b = it[1];

        adj[b].push_back(a);
    
    }
    vector<int> vis(numCourses, 0);
    vector<int> pathVis(numCourses, 0);

    for(int i = 0;i<numCourses;i++) {
        if(!vis[i]) {
            if(dfs(i,adj,vis,pathVis)) {
                return false;
            }
        }
    }
    return true;
}
