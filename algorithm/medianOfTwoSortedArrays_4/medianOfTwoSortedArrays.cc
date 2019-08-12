# ******************************************************
# Author       : Vigoroushui
# Last modified: 2019-08-12 16:42
# Email        : vigoroushui@gmail.com
# Filename     : medianOfTwoSortedArrays.cc
# Description  : watch the question in problem.md
# ******************************************************

/*整体思路：将两个有序数组拼成一个数组，对里面的数据进行快速排序，
 *随后找到其中位数，时间复杂度为O((m+n)log(m+n))（能AC但并不满足题目要求）*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        for(int i=0;i<nums2.size();++i)
        {
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
        int front=0,back=nums1.size()-1;
        double ans;
        if(nums1.size()%2!=0)
            ans=nums1[(front+back)/2];
        else{
            ans=(nums1[(front+back)/2]+nums1[(front+back)/2+1])/2.0;    
        }
        return ans;
    }
};