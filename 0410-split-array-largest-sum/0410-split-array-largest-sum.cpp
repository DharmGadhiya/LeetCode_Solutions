class Solution {
public:
    int dh(vector<int>nums,int m,int k)
    {
        int n = nums.size();
        int c1 = 1;
        int sum = nums[0];

        for(int i = 1 ; i<n ; i++)
        {
            sum+=nums[i];

            if(sum>m)
            {
                c1++;
                sum = nums[i];
            }
        }

        return c1;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int l = *max_element(nums.begin(),nums.end()), h = accumulate(nums.begin(),nums.end(),0);

        while(l<=h)
        {
            int m = l + (h-l)/2;

            int c1 = dh(nums,m,k);

            if(c1>k)
            {
                l = m+1;
            }
            else
            {
                h = m-1;
            }
        }

        return l;
    }
};