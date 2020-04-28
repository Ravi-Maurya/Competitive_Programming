int binary_search_inf(vector<int> arr, int l, int r, int key){
    if(r<l)
        return -1;
    int mid = l + (r-l)/2;
    if(arr[mid]==key)
        return mid;
    else if(arr[mid]>key)
        return binary_search_inf(arr,l,mid-1,key);
    return binary_search_inf(arr,mid+1,r,key);
}
int findPos(vector<int> arr, int key){
    int l =0, h = 1;
    int val = arr[0];
    while(val<key){
        l = h;
        h = 2*h;
        val = arr[h];
    }
    return binary_search_inf(arr,l,h,key);
}