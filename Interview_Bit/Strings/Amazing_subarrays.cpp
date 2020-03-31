int Solution::solve(string A) {
    int MOD = 10003;
    set<char> isVowel;
    isVowel.insert('a');isVowel.insert('e');isVowel.insert('i');
    isVowel.insert('o');isVowel.insert('u');
    isVowel.insert('A');isVowel.insert('E');isVowel.insert('I');
    isVowel.insert('O');isVowel.insert('U');
    
    int count = 0;
    int N = A.size();
    for (int i = 0; i < N; i++) {
        if (isVowel.find(A[i])!=isVowel.end()) {
            count += N - i;
        }
    }
    return count%MOD;
}
