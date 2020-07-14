class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hr = hour;
        hr *= 5;
        hr += minutes / 12.0;
        double res = abs(6.0 * (hr - minutes));
        return min(res,  360 - res);
    }
};