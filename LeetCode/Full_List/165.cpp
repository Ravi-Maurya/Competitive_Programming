class Solution {
public:
    int comp(string a, string b){
        int i=0, j =0;
        while(i<a.size() && a[i]=='0')
            i++;
        while(j<b.size() && b[j]=='0')
            j++;
        if(a.size()-i > b.size()-j)
            return 1;
        if(a.size()-i < b.size()-j)
            return -1;
        while(i<a.size() && j<b.size()){
            if(a[i]==b[j]){
                i++;
                j++;
                continue;
            }
            if(a[i] > b[i])
                return 1;
            return -1;
        }
        return 0;
    }
    int compareVersion(string v1, string v2) {
        int i=0, j=0, n1 = v1.size(), n2 = v2.size();
        while(i<n1 && j<n2){
            string a = "";
            string b = "";
            while(i<n1 && v1[i]!='.')
                a += v1[i++];
            i++;
            while(j<n2 && v2[j]!='.')
                b += v2[j++];
            j++;
            int curr = comp(a,b);
            if(curr==0)
                continue;
            return curr;
        }
        while(i<n1){
            if(v1[i]!='0' && v1[i]!='.')
                return 1;
            i++;
        }
        while(j<n2){
            if(v2[j]!='0' && v2[j]!='.')
                return -1;
            j++;
        }
        return 0;
    }
};