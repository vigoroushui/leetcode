# ******************************************************
# Author       : Vigoroushui
# Last modified: 2019-08-11 17:09
# Email        : vigoroushui@gmail.com
# Filename     : validParentheses.cc
# Description  : watch the question in problem.md
# ******************************************************

/*整体思路：首先，若字符串长度不为偶数，则字符串一定不匹配。
 *接着采用map来存放三种情况的括号。若遇到左括号则入栈；
 *遇到右括号则出栈匹配。最后查看栈是否为空，非空说明还有残留的右括号，则不匹配。*/
class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2!=0)
            return false;
        map<char,char> tmp;
        tmp[')']='(';
        tmp[']']='[';
        tmp['}']='{';
        stack<char> stk;
        for(int i=0;i<s.length();++i)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
                stk.push(s[i]);
            if(s[i]==')'||s[i]==']'||s[i]=='}')
            {
                if(stk.empty())
                    return false;
                if(tmp[s[i]]==stk.top())
                {
                    stk.pop();
                }
            }
        }
        if(!stk.empty())
            return false;
        return true;
    }
};