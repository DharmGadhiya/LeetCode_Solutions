class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for(auto el : nums){
            if(sub.empty() || sub[sub.size() -1] < el){
                sub.push_back(el);
            }
            else{
                auto it = lower_bound(sub.begin() , sub.end() , el);
                *it = el;
            }
        }
        return sub.size();
    }
};