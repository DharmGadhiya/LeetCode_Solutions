class Solution {
public:
    int maxDepth(string s) {
        int c1 =0 ,c2 =0 ;
        for(auto el : s){
            if(el == '('){
                c1++;
                c2 = max(c2,c1);
            }
            else if(el == ')'){
                c1--;
            }
        }
        return c2;
    }
};