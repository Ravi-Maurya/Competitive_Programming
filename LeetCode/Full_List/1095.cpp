/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l = 0, h = mountainArr.length()-1;
        int m , maxidx;
        while(l<h){
            m = l + (h-l)/2;
            if(mountainArr.get(m)<mountainArr.get(m+1))
                l = m + 1;
            else
                h = m;
        }
        maxidx = l;
        // first half
        l = 0;
        h = maxidx;
        while(l<h){
            m = l + (h-l)/2;
            if(target<=mountainArr.get(m))
                h = m ;
            else
                l = m + 1;
        }
        if(mountainArr.get(l)==target)
            return l;
        //second half
        l = maxidx+1;
        h = mountainArr.length()-1;
        while(l<h){
            m = l + (h-l)/2;
            if(target<mountainArr.get(m))
                l = m + 1;
            else
                h = m;
        }
        if(mountainArr.get(l)==target)
            return l;
        //not found
        return -1;
    }
};