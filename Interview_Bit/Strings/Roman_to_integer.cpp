int romanCharToInt(char c)
{
    switch(c)
    {
        case 'I':
        case 'i':
            return 1;
        case 'V':
        case 'v':
            return 5;
        case 'X':
        case 'x':
            return 10;
        case 'L':
        case 'l':
            return 50;
        case 'C':
        case 'c':
            return 100;
        case 'D':
        case 'd':
            return 500;
        case 'M':
        case 'm':
            return 1000;
        default:
            return 0;
    }
}
int Solution::romanToInt(string A) {
    int result = 0;
    int n = A.length();
    
    for (auto i = 0; i<n; ++i)
    {
        if (i!=n && romanCharToInt(A[i]) < romanCharToInt(A[i+1]))
            result -= romanCharToInt(A[i]);
        else 
            result += romanCharToInt(A[i]);
    }
    return result;
}