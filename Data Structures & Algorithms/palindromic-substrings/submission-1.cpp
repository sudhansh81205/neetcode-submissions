class Solution {
public:
    bool isPalindrome(int st,int end,string s){
        if(st==end) return true ;
        while(end>st){
            if(s[end]!=s[st]) return false ;
            st++;
            end--;
        }
        return true ;
    }


    int countSubstrings(string s) {
        int n = s.size();
        int count =0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s)){
                    count++;
                }
            }
        }
        return count ;
    }
};
