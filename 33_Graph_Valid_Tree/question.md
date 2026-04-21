You are given an undirected graph of n nodes (numbered from 0 to n-1) and m edges. Return 1 if the graph is a tree, else return 0.

Note: The input graph can have self-loops and multiple edges.

Example 1:
Input: n = 4, m = 3, edges = [[0, 1], [1, 2], [1, 3]]
Output: 1
Explanation: Every node is reachable and the graph has no loops, so it is a tree

Example 2:
Input: n = 4, m = 3, edges = [[0, 1], [1, 2], [2, 0]]
Output: 0
Explanation: 3 is not connected to any node and there is a cycle 0->1->2->0, so it is not a tree.
