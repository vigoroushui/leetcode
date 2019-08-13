# ******************************************************
# Author       : Vigoroushui
# Last modified: 2019-08-13 22:54
# Email        : vigoroushui@gmail.com
# Filename     : LPS.cc
# Description  : watch the question in problem.md
# ******************************************************


/*整体思路：暴力和动态规划先不考虑，采用中心扩展方法求解此题，private类中写了求解回文子串长度的函数对象（很好理解）。
 *中心拓展方法涉及奇数（例:"aba"）和偶数（例：“abba”）拓展。
 *遍历原字符串中过程中记录最长的回文子串起始位置和长度，最终用求子串的函数求出此回文字串。时间复杂度为O(n^2)*/
class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.length();
        if(len<2)
            return s;
        int start=0,end=0,maxLen=0;//start记录最大回文子串的起始地址
        for(int i=0;i<s.length();++i)
        {
            int lenEven=expandAroundCenter(s,i,i+1);
            int lenOdd=expandAroundCenter(s,i,i);
            maxLen=max(max(lenEven,lenOdd),maxLen);
            if(maxLen>end-start+1)
            {
                start=i-(maxLen-1)/2;
                end=i+maxLen/2;
            }
        }
        return s.substr(start,maxLen);
    }
private:
    int expandAroundCenter(string &s,int left,int right)//用引用传递的方法可以有效提高效率
    {
        while(left>=0&&right<s.length()&&s[left]==s[right])
        {
            --left;
            ++right;
        }
        return right-left-1;
    }
};