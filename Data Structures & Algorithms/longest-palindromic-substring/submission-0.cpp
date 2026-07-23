class Solution {
public:
    string longestPalindrome(string s) {
       
        int n= s.size();
        int maxLen= INT_MIN;
        string ans= "" ;
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=n-1;i>=0;i--){
            
            for(int j=i;j<n;j++){
                if(s[i]==s[j]){
                    if(j-i<=1) dp[i][j]= true ;
                    else dp[i][j]= dp[i+1][j-1];
                }
                if(dp[i][j]){
                     int len = j - i + 1;

                    if (len > maxLen) {
                        maxLen = len;
                        ans = s.substr(i, len);
                    }
                    }
                }
            }
        
        return ans ;
    
}

    };
