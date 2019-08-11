# ******************************************************
# Author       : Vigoroushui
# Last modified: 2019-08-11 17:01
# Email        : vigoroushui@gmail.com
# Filename     : palindromeNumber.cc
# Description  : watch the question in problem.md
# ******************************************************

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int tmp=x;
        long a=0;
        while(tmp)
        {
            a=a*10+tmp%10;
            tmp/=10;
            if(a>INT_MAX)
                return false;
        }
        return x==static_cast<int>(a)?true:false;
    }
};