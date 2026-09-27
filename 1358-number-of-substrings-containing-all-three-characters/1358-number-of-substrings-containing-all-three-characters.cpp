class Solution {
public:
    int numberOfSubstrings(string s) {
          int c1 =0 , c2 = 0, c3 =0 ,ans =0 , m = INT_MAX;
         int i = 1;
         for(auto el : s){
            if(el == 'a'){
                c1=i; 
            }
            else if(el == 'b'){
                c2 = i;
            }
            else {
                c3 = i;
            }
            i++;
            m = min({c1,c2,c3});
            ans+=m;
         }
         return ans;
    }
};