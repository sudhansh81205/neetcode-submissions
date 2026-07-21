class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int count = 0;
        vector<bool>vis(n,false);
        vector<vector<int>>adjls(n);
        for(int i=0;i<edges.size();i++){
            adjls[edges[i][0]].push_back(edges[i][1]);
            adjls[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                queue<int>q;
                q.push(i);
                while(!q.empty()){
                    int u = q.front();
                    q.pop();

                    for(auto it:adjls[u]){
                        if(!vis[it]){
                            q.push(it);
                            vis[it]=true ;
                    }
                }
            }
        }
    }
    return count ;
 }
};

