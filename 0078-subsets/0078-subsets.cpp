class Solution {
public:

    vector<vector<int>> ans;

    void dh(int i , vector<int> &v , vector<int> tt){
        if(i == v.size()){
            ans.push_back(tt);
            return;
        }
        dh(i+1,v,tt);
        tt.push_back(v[i]);
        dh(i+1,v,tt);
    }
    vector<vector<int>> subsets(vector<int>& v) {
        dh(0,v,{});
        return ans;
    }
};