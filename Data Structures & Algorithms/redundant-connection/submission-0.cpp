class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();   // Number of edges = number of nodes

        // Try removing each edge from last to first
        for (int skip = n - 1; skip >= 0; skip--) {

            vector<vector<int>> adj(n + 1);

            // Build graph without the skipped edge
            for (int i = 0; i < n; i++) {
                if (i == skip) continue;

                int u = edges[i][0];
                int v = edges[i][1];

                adj[u].push_back(v);
                adj[v].push_back(u);
            }

            // BFS
            vector<bool> vis(n + 1, false);
            queue<int> q;

            q.push(1);
            vis[1] = true;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int nei : adj[node]) {
                    if (!vis[nei]) {
                        vis[nei] = true;
                        q.push(nei);
                    }
                }
            }

            // Check if all nodes were visited
            bool connected = true;
            for (int i = 1; i <= n; i++) {
                if (!vis[i]) {
                    connected = false;
                    break;
                }
            }

            if (connected)
                return edges[skip];
        }

        return {};
    }
};