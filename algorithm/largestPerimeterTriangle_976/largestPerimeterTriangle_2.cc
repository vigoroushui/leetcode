# ******************************************************
# Author       : Vigoroushui
# Last modified: 2019-08-11 17:23
# Email        : vigoroushui@gmail.com
# Filename     : largestPerimeterTriangle_2.cc
# Description  : watch the question in problem.md
# ******************************************************

class Solution {
public:
    string intToString(int num)
    {
        if(0==num)
           return "0";
        string s="";
        char cTmp;
        while(num)
        {
            cTmp=num%10+'0';
            num/=10;
            s=cTmp+s;
        }
        return s;
    }
    bool cmp(int a, int b)
    {
        string aStr=intToString(a);
        string bStr=intToString(b);
        return aStr+bStr>bStr+aStr;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        string s="";
        for(int i=nums.size()-1;i>=0;--i)
        {
            s+=intToString(nums);
        }
        return s;
    }
};
