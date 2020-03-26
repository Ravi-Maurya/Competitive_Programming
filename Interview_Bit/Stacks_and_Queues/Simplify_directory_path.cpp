string Solution::simplifyPath(string A) {
    deque<string> directory;
    int n = A.size();
    int i=0;
    string tmp = "";
    while(i<n){
        if(A[i]=='/'){
            if(tmp==".."){
                if (directory.size()!=0)
                    directory.pop_back();
            }
            else{
                if(tmp!="." && tmp.size()!=0)
                    directory.push_back(tmp);
            }
            tmp = "";
        }
        else{
            tmp += A[i];
        }
        i++;
    }
    if(tmp==".."){
        if (directory.size()!=0)
            directory.pop_back();
    }
    else{
        if(tmp!="." && tmp.size()!=0)
        directory.push_back(tmp);
    }
    tmp = "";
    string res = "";
    while(directory.size()!=0){
        res += "/";
        res += directory.front();
        directory.pop_front();
    }
    if (res.size()==0){
        return "/";
    }
    return res;
}
