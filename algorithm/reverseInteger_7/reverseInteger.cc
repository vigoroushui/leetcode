# ******************************************************
# Author       : Vigoroushui
# Last modified: 2019-08-11 16:56
# Email        : vigoroushui@gmail.com
# Filename     : reverseInteger.cc
# Description  : watch the question in problem.md
# ******************************************************

class Solution {
public:
    int reverse(int x) {
        long ans=0;
        while(x)
        {
            ans+=x%10;
            x/=10;
            if(ans>INT_MAX||ans<INT_MIN)
                return 0;
            if(x!=0)
                ans*=10;
        }
        return static_cast<int>(ans);
    }
};

