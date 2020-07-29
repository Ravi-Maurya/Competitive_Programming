/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int i= 1, j = n;
        while(i<j){
            int mid = i + (j-i)/2;
            int tmp = guess(mid);
            if(tmp==0)
                return mid;
            else if(tmp==1)
                i = mid+1;
            else
                j = mid;
        }
        return i;
    }
};