class Solution {
public:
    int arrayPairSum(vector<int>& v) {
        sort(v.begin() , v.end());
        int ans =0;
        for(int i = 0  ; i < v.size() ; i+=2){
            ans+= v[i];
        }
        return ans;
    }
};