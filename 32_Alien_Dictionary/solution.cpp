/*
    Approach: Topological Sort using DFS

    Step 1: Build the graph
        - Mark all unique letters in exists[] (since some letters
          may not appear in any edge but must be in the answer)
        - Compare consecutive word pairs character by character
        - On first mismatch → add edge: word1[j] → word2[j]
        - Edge case: if no mismatch found and w1.length > w2.length
          (e.g. "abcd" before "ab") → invalid order, return ""

    Step 2: DFS with cycle detection + topological order
        - Use vis[] to track all visited nodes
        - Use pathVis[] to track nodes in current DFS path
        - If a neighbor is in pathVis → cycle found → return ""
        - When a node finishes, push it into the stack

    Step 3: Build the result
        - Pop stack and convert each index back to char
          using (char)(index + 'a')

    TC: O(N * L)   // N = number of words, L = avg word length
    SC: O(N)       // adjacency list dominates; other arrays O(26)
*/
class Solution {

private:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis,
             vector<int>& pathVis, stack<int>& st) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, pathVis, st))
                    return true;
            } else if (pathVis[it]) {
                return true;
            }
        }
        pathVis[node] = 0;
        st.push(node);
        return false;
    }

public:
    string findOrder(vector<string>& words) {
        // Step 1: Build graph (nodes+edges from word pairs)

        vector<vector<int>> adj(26);
        vector<bool> exists(26, false);

        for (auto& word : words) {
            for (char c : word) {
                exists[c - 'a'] = true;
            }
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];

            bool foundMisMatch = false;

            int minLen = min(w1.length(), w2.length());
            for (int j = 0; j < minLen; j++) {
                if (w1[j] != w2[j]) {
                    adj[w1[j] - 'a'].push_back(w2[j] - 'a');
                    foundMisMatch = true;
                    break;
                }
            }
            if (!foundMisMatch && w1.length() > w2.length()) {
                return "";
            }
        }
        // Step 2: DFS + cycle detection + topological order

        vector<int> vis(26, 0);
        vector<int> pathVis(26, 0);

        stack<int> st;

        for (int i = 0; i < 26; i++) {
            if (exists[i] && !vis[i]) {
                if (dfs(i, adj, vis, pathVis, st)) {
                    return ""; // Cycle
                }
            }
        }

        string result = "";
        while (!st.empty()) {
            result += (char)(st.top() + 'a');
            st.pop();
        }
        return result;
    }
};
