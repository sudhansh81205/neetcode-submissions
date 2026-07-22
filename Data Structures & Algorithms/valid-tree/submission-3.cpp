class Solution {
public:
    bool dfs(int node, int par,vector<vector<int>>&adjls, vector<bool>&vis,int n){
    
        vis[node]= true ;
        
        for(auto it :adjls[node]){
            if(!vis[it]){
               if(!dfs(it,node,adjls,vis,n))
            return false;
            }
            else if(it!=par) return false;
           
        }
        return true  ;
    }


    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adjls(n);
        for(int i=0;i<edges.size();i++){
            adjls[edges[i][0]].push_back(edges[i][1]);
            adjls[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool>vis(n,false);

        bool isvalid= dfs(0,-1,adjls,vis,n);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                return false;
            }
        }
        return isvalid;
        
    }
};
