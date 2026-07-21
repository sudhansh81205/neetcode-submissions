class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<int> dist(n, INT_MAX);
        dist[src] = 0;
       vector<vector<pair<int,int>>>adjls(n);
       for(int i=0;i<flights.size();i++){
         adjls[flights[i][0]].push_back({flights[i][1],flights[i][2]});
       }
       
       int mini = INT_MAX;
       queue<pair<int,pair<int,int>>> q;
       q.push({src,{0,0}});
       while(!q.empty()){
            int u = q.front().first;
            int wt= q.front().second.first ;
            int stops= q.front().second.second ;

            q.pop();
            if(stops>k) continue ;
            for(auto it:adjls[u]){
               if(wt + it.second < dist[it.first]) {
                dist[it.first] = wt + it.second;
                q.push({it.first, {dist[it.first], stops + 1}});
}
                if(it.first==dst && stops<=k){
                    mini = min(mini,wt+it.second);
                }
            }
           
       }

        
        if(mini!=INT_MAX) return mini ;
        return -1;
    }
};
