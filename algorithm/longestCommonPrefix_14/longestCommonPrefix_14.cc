# ******************************************************
# Author       : Vigoroushui
# Last modified: 2019-08-13 22:58
# Email        : vigoroushui@gmail.com
# Filename     : longestCommonPrefix_14.cc
# Description  : watch the question in problem.md
# ******************************************************

/*整体思路：先找出头两个字符串的最长公共前缀，然后与后面的字符串逐一比较，时间复杂度为O（n*m）*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(0==strs.size())
            return "";//测试用例中出现了[]，故加上此句
        if(1==strs.size())
            return strs[0];
        string tmp="";
        for(int i=0,j=0;i<strs[0].length()&&j<strs[1].length();++i,++j)
        {
                if(strs[0][i]==strs[1][j])
                    tmp+=strs[0][i];
                else
                    break;
        }
        auto it=strs.begin()+2;
        while(it!=strs.end())
        {
            for(int i=0;i<tmp.length();++i)
            {
                if((*it)[i]!=tmp[i])
                {
                    tmp=tmp.substr(0,i);
                    break;
                }
            }
            if(0==tmp.length())
                return "";
            ++it;
        }
            return tmp;
    }
};
