# ******************************************************
# Author       : Vigoroushui
# Last modified: 2019-08-11 16:44
# Email        : vigoroushui@gmail.com
# Filename     : LSWRC.cc
# Description  : watch the question in problem.md
# ******************************************************

/*整体思路：用无序map来存储字符串中每个字母出现的次数，遍历字符串的过程中，关键是理解处理字串中重复字母的过程。*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> a;
        int ans=0;
        for(int i=0,j=0;i<s.length();++i)
        {    
            if(++a[s[i]]>1)//处理子串中的重复字母
            {
                while(i>j)
                {
                    --a[s[j]];
                    j++;
                    if(1==a[s[i]])
                        break;
                }
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};