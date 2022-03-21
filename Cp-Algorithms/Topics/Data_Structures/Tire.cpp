#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("-O3")

#define ll long long int
#define pll pair<ll, ll>
#define pls pair<ll, string>
#define psl pair<string, ll>
#define plc pair<ll, char>
#define pcl pair<char, ll>
#define pss pair<string, string>
#define maxheap(type) priority_queue<type>
#define minheap(type) priority_queue<type, vector<type>, greater<type> >
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define precise(x, y) fixed << setprecision(y) << x
#define tol(s) transform(s.begin(), s.end(), s.begin(), ::tolower);
#define tou(s) transform(s.begin(), s.end(), s.begin(), ::toupper);
#define ALPHABET_SIZE 26;

struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool is_end;
    TrieNode()
    {
        is_end = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            children[i] = nullptr;
    }
}

class Trie
{
public:
    TrieNode *root;
    Trie(vector<string> words)
    {
        root = new TrieNode();
        for (auto word : words)
            insert(word);
    }

    void insert(string key)
    {
        struct TrieNode *curr = root;
        for (int i = 0; i < key.size(); i++)
        {
            int idx = key[i] - 'a';
            if (!curr->children[idx])
                curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->is_end = true;
        return;
    }

    bool search(string key)
    {
        struct TrieNode *curr = root;
        for (int i = 0; i < key.size(); i++)
        {
            int idx = key[i] - 'a';
            if (!curr->children[idx])
                return false;
            curr = curr->children[idx];
        }
        return curr->is_end;
    }
}

int
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}