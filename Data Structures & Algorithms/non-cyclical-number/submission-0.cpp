class Solution {
public:
    bool isHappy(int n) {
        while(n!=1){
            int sqsum =0;
            while(n>0){
                int no = n%10;
                sqsum+=no*no;
                n=n/10;
            }
            n=sqsum;
           if(n!=1 && n/10==0){
            return false;
           }
        }
        return true ;

    }
};
