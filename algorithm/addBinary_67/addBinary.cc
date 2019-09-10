/*# *******************************************************
  # Author       : Vigoroushui
  # Last modified: 2019-09-10 21:01
  # Email        : vigoroushui@gmail.com
  # Filename     : addBinary.cc
  # Description  : watch the question in problem.md
  # *******************************************************/

class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.length();
        int j=b.length();
        while(i<j)
        {
            a='0'+a;
            ++i;
        }
        while(i>j)
        {
            b='0'+b;
            ++j;
        }//对齐补位
        for(i=i-1;i>0;--i)
        {
            a[i]=a[i]-'0'+b[i];
            if(a[i]>='2')
            {
                a[i]=(a[i]-'0')%2+'0';
                a[i-1]=a[i-1]+1;
            }
        }//从后往前相加进位
        a[0]=a[0]-'0'+b[0];
        if(a[0]>='2')
        {
            a[0]=(a[0]-'0')%2+'0';
            a='1'+a;
        }//若第一位相加大于等于2，则需要进位
        return a;
    }
};

