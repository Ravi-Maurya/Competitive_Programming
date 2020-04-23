#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size(), m= b.size();
        int i = n-1, j = m-1;
        string res = "";
        char carry = '0';
        while(i>=0 && j>=0){
            if((a[i]=='1' && b[j]=='1') ||  (a[i]=='0' && b[j]=='0')){
                res += carry;
                if(a[i]=='1'){
                    carry = '1';
                }
                else{
                    carry = '0';
                }
            }
            else{
                if(carry == '0')
                    res += '1';
                else
                    res += '0';
            }
            i--;
            j--;
        }
        while(i>=0){
            if(carry=='0')
                res += a[i];
            else{
                if(a[i]=='1'){
                    res += '0';
                }
                else{
                    res += '1';
                    carry = '0';
                }
            }
            i--;
        }
        while(j>=0){
            if(carry=='0')
                res += b[j];
            else{
                if(b[j]=='1'){
                    res += '0';
                }
                else{
                    res += '1';
                    carry = '0';
                }
            }
            j--;
        }
        if(carry == '1')
            res += '1';
        reverse(res.begin(),res.end());
        return res;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}