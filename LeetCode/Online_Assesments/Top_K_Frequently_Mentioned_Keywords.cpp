#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
// https://leetcode.com/discuss/interview-question/542597/
vector <string> topBuzzwords (vector <string> reviews, vector <string> buzzwords, int k)
{
    unordered_set <string> buzzwords2 (buzzwords.begin (), buzzwords.end ());
    regex rgx("\\w+");

    unordered_map <string, int> word_cnts;
    for (auto& review : reviews)
    {
        for (sregex_iterator rgx_it (review.begin (), review.end (), rgx), rgx_it_end; rgx_it != rgx_it_end; rgx_it++)
        {
            string word = (*rgx_it) [0];
            //string word = (*rgx_it).str ();
            transform (word.begin (), word.end (), word.begin (), ::tolower);
            if (buzzwords2.count (word))
                word_cnts [word]++;
        }
    }
    
    const auto my_greater = [&word_cnts] (const string &a, const string &b)
    {
        return (word_cnts [a] > word_cnts [b]) || (word_cnts [a] == word_cnts [b] && a.compare (b) > 0); 
    };
    priority_queue <string, vector <string>, decltype (my_greater)> minq (my_greater);
    
    for (const auto word_cnt_pair : word_cnts)
    {
        minq.push (word_cnt_pair.first);
        if (minq.size () > k)
            minq.pop ();
    }
    
    vector <string> ret;
    while (!minq.empty ())
    {
        ret.push_back (minq.top ());
        minq.pop ();
    }
    
    reverse (ret.begin (), ret.end ());
    return ret;
}

int main() 
{
    vector <string> reviews, buzzwords, ret;
    reviews = {
                "Anacell provides the best services in the city",
                "betacellular has awesome services",
                "Best services provided by anacell, everyone should use anacell"
              };
    buzzwords = {"anacell", "cetracular", "betacellular"};
    
    printf ("input 1:\n");
    ret = topBuzzwords (reviews, buzzwords, 2);
    for (auto ret_word : ret)
        printf ("%s\n", ret_word.c_str ());
    printf ("\n");
    
    reviews = {
                  "I love anacell Best services; Best services provided by anacell",
                  "betacellular has great services",
                  "deltacellular provides much better services than betacellular",
                  "cetracular is worse than anacell",
                  "Betacellular is better than deltacellular."
              };
    buzzwords = {"anacell", "betacellular", "cetracular", "deltacellular", "eurocell"};
    
    printf ("input 2:\n");
    ret = topBuzzwords (reviews, buzzwords, 2);
    for (auto ret_word : ret)
        printf ("%s\n", ret_word.c_str ());
    printf ("\n");
}