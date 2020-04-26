class Solution {
public:
    static bool compare(string a, string b){
        string ida=a.substr(0,a.find_first_of(" "));
        string idb=b.substr(0,b.find_first_of(" "));
        string aa=a.substr(a.find_first_of(" ")+1);
        string bb=b.substr(b.find_first_of(" ")+1);
        if (isalpha(bb[0])){
            if (isalpha(aa[0])){
                return (aa!=bb?aa<bb:ida<idb);
            }
            return false;
        }
        if (isalpha(aa[0])) {
            return true;
        }
        return false;
    };
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(),logs.end(),compare);
        return logs;
    }
};