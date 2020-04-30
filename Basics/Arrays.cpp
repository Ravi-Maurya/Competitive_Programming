#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
class Sorting{
    public:
    // Merge Sort  + Inversion Count in NLogN.
    int merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right){
        int i,j,k;
        int inv_count = 0;
        i = left, j = mid, k = left;
        while((i<=mid-1) && (j<=right)){
            if(arr[i]<=arr[j])
                temp[k++] = arr[i++];
            else{
                temp[k++] = arr[j++];
                inv_count += (mid-i);
            }
        }
        while(i<=mid-1)
            temp[k++] = arr[i++];
        while(j<=right)
            temp[k++] = arr[j++];
        for(i = left; i<=right; i++)
            arr[i] = temp[i];
        return inv_count;
    }
    int helper(vector<int>& arr, vector<int>& temp, int left, int right){
        int mid, inv_count = 0;
        if(right>left){
            mid = (left+right)>>1;
            inv_count += helper(arr,temp,left,mid);
            inv_count += helper(arr,temp,mid+1,right);
            inv_count += merge(arr,temp,left,mid+1,right);
        }
        return inv_count;
    }
    int mergeSort(vector<int>& arr, int n){
        vector<int> temp(n);
        return helper(arr,temp,0,n-1);
    }

    // Quick Sort Recursive NLogN with O(1) extra space.
    int partition(vector<int>& arr, int l, int h){
        int piviot = arr[h];
        int i = l-1;
        for(int j=l; j<h; j++)
            if(arr[j]<piviot)
                i++, swap(arr[i],arr[j]);
        swap(arr[i+1],arr[h]);
        return i+1;
    }
    void quickSort(vector<int>& arr, int l, int h){
        if(l<h){
            int piv = partition(arr,l,h);
            quickSort(arr,l,piv-1);
            quickSort(arr,piv+1,h);
        }
    }
    void quickSortIter(vector<int>& arr, int l, int h){
        stack<int> s;
        s.push(l);
        s.push(h);
        while (!s.empty()){
            h = s.top();s.pop();
            l = s.top();s.pop();
            int p = partition(arr,l,h);
            if(p-1>l){
                s.push(l);
                s.push(p-1);
            }
            if(p+1<h){
                s.push(p+1);
                s.push(h);
            }
        }
    }

    // Insertion Sort N**2 and O(1) space
    void insertionSort(vector<int>& arr){
        int n = arr.size();
        int i, key, j;
        for(i=1; i<n; i++){
            key = arr[i];
            j = i-1;
            while(j>=0 && arr[j]>key){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }

    // Selection Sort
    void selectionSort(vector<int>& arr){
        int n =arr.size();
        int i,j,mn_idx;
        for(i=0;i<n-1;i++){
            mn_idx = i;
            for(j=i+1; j<n; j++)
                if(arr[j]<arr[mn_idx])
                    mn_idx = j;
            swap(arr[mn_idx], arr[i]);
        }
    }

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}