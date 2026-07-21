class Solution {
public:
    int helper(int idx1,int idx2,string s1,string s2,vector<vector<int>>&dp){
        if(idx1<0) return idx2+1;
        if(idx2<0) return idx1+1;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(s1[idx1]==s2[idx2]) return dp[idx1][idx2]= helper(idx1-1,idx2-1,s1,s2,dp);
        return dp[idx1][idx2]=min(1+helper(idx1-1,idx2,s1,s2,dp),
        min(1+helper(idx1,idx2-1,s1,s2,dp),1+helper(idx1-1,idx2-1,s1,s2,dp)));
    }
    int minDistance(string word1, string word2) {
        int n= word1.size();
        int m= word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(n-1,m-1,word1,word2,dp);
    }
};
