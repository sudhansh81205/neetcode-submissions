class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adjls(n+1);
        for(int i=0;i<times.size();i++){
            adjls[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue<pair<int ,int>,vector<pair<int ,int>>,greater<pair<int ,int>>>pq;
        
        pq.push({0,k});
        vector<int>dist(n+1,INT_MAX);
        dist[k] = 0;
        while(!pq.empty()){
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            if (wt > dist[u])
                continue;
            for(auto it: adjls[u]){
                int v = it.first;
               if(dist[v]>dist[u]+it.second){ 
                dist[v]= wt+it.second;
                pq.push({dist[v],v});
                }
               
            }
        } 
        int count =0;
            for(int i=1;i<=n;i++){
                if(dist[i]==INT_MAX) return -1 ;
               count = max(count,dist[i]);
            }

           return count ; 

    }
};
