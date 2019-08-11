# ******************************************************
# Author       : Vigoroushui
# Last modified: 2019-08-11 16:16
# Email        : vigoroushui@gmail.com
# Filename     : twoSum.cc
# Description  : watch the question in problem.md ~
# ******************************************************
class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        map<int,int> a;
        vector<int> ans(2,0);
        for(int i=0;i<nums.size();++i)
        {
            if(a.count(target-nums[i])!=0)
            {
                ans[0]=a[target-nums[i]];
                ans[1]=i;
                break;
            }
            a[nums[i]]=i;
        }
        return ans;
    }
};
