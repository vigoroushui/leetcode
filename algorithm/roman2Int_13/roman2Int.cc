# ******************************************************
# Author       : Vigoroushui
# Last modified: 2019-08-12 10:35
# Email        : vigoroushui@gmail.com
# Filename     : roman2Int.cc
# Description  : watch the question in problem.md
# ******************************************************

/*整体思路：用map的hash映射罗马数字和它代表的值，
 *而后遍历字符串，若当前罗马数字大于等于其右边的值，则加上它，否则减去它。*/
class Solution {
public:
    int romanToInt(string s) 
    {
        map<char,int> a;
        a['I']=1;a['V']=5;a['X']=10;a['L']=50;
        a['C']=100;a['D']=500;a['M']=1000;
        int ans=0;
        for(int i=0;i<s.length();++i)
        {
            if(a[s[i]]>=a[s[i+1]])
            {
                ans+=a[s[i]];
            }else
            {
                ans-=a[s[i]];
            }
        }
        return ans;
    }
};