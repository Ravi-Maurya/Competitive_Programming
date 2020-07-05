const int N = 50005;
class Solution {
public:
    bool visited[N];
    Solution(){
        memset(visited,false,sizeof(visited));
    }
    bool canReach(vector<int>& arr, int start) {
        if(start<0 || start>=arr.size())
            return false;
        if(arr[start]==0)
            return true;
        if(visited[start]==true)
            return false;
        visited[start] = 1;
        return (canReach(arr,start+arr[start]) || canReach(arr,start-arr[start]));
    }
};