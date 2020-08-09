class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int res = 0;
        int n = s.size();
        // cout<<s<<"\n";
        for(int i=0; i<n; ){
            // cout<< i <<" ";
            if(s[i]=='('){
                if(i+1<n){
                    if(s[i+1]=='('){
                        // cout<<"1( ";
                        st.push('(');
                        i++;
                    }
                    else{
                        if(i+2<n){
                            if(s[i+2]==')'){
                                // cout<<"2()) ";
                                i += 3;
                            }
                            else{
                                // cout<<"3() ";
                                i += 2;
                                res+=1;
                            }
                        }
                        else{
                            // cout<<"4() ";
                            res += 1;
                            i+=2;
                        }
                    }
                }
                else{
                    // cout<<"5( ";
                    res+=2;
                    i++;
                }
            }
            else{
                if(i+1<n){
                    if(s[i+1]==')' && !st.empty()){
                        // cout<<"6)) ";
                        st.pop();
                        i += 2;
                    }
                    else if(s[i+1]=='(' && !st.empty()){
                        // cout<<"7) ";
                        st.pop();
                        res += 1;
                        i += 1;
                    }
                    else if(st.empty() && s[i+1]==')'){
                        // cout<<"8)) ";
                        res += 1;
                        i += 2;
                    }
                    else{
                        // cout<<"9) ";
                        res += 2;
                        i += 1;
                    }
                }
                else{
                    // cout<<"10) ";
                    if(!st.empty()){
                        st.pop();
                        res += 1;
                        i++;
                    }
                    else{
                        res += 2;
                        i++;
                    }
                }
            }
            // cout<<"\n";
        }
        if(!st.empty())
            res += 2*st.size();
        return res;
    }
};


class Solution {
public:
    int minInsertions(string s) {
        int ans=0;
        int sum=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')sum++;
            else{
                if(i==s.size()-1||s[i+1]!=')'){
                    ans++;
                    sum--;
                }
                else{
                    sum--;
                    i++;
                }
            }
            if(sum<0){
                sum++;
                ans++;
            }
        }
        ans+=sum*2;
        return ans;
    }
};