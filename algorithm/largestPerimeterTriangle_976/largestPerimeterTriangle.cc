# ******************************************************
# Author       : Vigoroushui
# Last modified: 2019-08-11 17:21
# Email        : vigoroushui@gmail.com
# Filename     : largestPerimeterTriangle.cc
# Description  : watch the question in problem.md
# ******************************************************

/*整体思路：先用sort函数按升序快速排序，时间复杂度 O（n*logn），
 *再从后往前遍历动态数组，第一次访问到的满足两边之和大于第三遍的三角形，即为最大周长的三角形。*/
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(),A.end());
        for(int i=A.size()-1;i>=2;--i)
        {
            if(A[i-2]+A[i-1]>A[i])
                return A[i-2]+A[i-1]+A[i];
        }
        return 0;
    }
};
