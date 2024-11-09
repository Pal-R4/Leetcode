class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
       int  subset=1<<n;
       vector<vector<int>>ans;
      
        for(int i=0;i<subset;i++)
        {
             vector<int>arr;
            for(int j=0;j<n;j++)
            {
                if((i&(1<<j))>0)
                {
                    arr.push_back(nums[j]);
                }
            }
            ans.push_back(arr);

        }
        return ans;
    }
};