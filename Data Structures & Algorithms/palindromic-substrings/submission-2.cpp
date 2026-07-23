class Solution {
public:
    // bool isPalindrome(int st,int end,string s){
    //     if(st==end) return true ;
    //     while(end>st){
    //         if(s[end]!=s[st]) return false ;
    //         st++;
    //         end--;
    //     }
    //     return true ;
    // }


    // int countSubstrings(string s) {
    //     int n = s.size();
    //     int count =0;
    //     for(int i=0;i<n;i++){
    //         for(int j=i;j<n;j++){
    //             if(isPalindrome(i,j,s)){
    //                 count++;
    //             }
    //         }
    //     }
    //     return count ;
    // }


    int countSubstrings(string s){
        int n= s.size();
        int count= 0;
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j]){
                    if(j-i<=1) dp[i][j]= true ;
                    else dp[i][j]= dp[i+1][j-1];
                }
                if(dp[i][j])  count++;
            }
        }
        return count ;
    }
};
