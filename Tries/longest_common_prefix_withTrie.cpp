// it doesn't work great, without trie solution is best.....
#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};
class Trie
{
public:
    TrieNode *root;
    Trie(char ch)
    {
        root = new TrieNode(ch);
    }
    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }
    void insert(string word)
    {
        insertUtil(root, word);
    }
    // longest common prefix
    void lcp(string first, string &ans)
    {
        for (int i = 0; i < first.length(); i++)
        {
            char ch = first[i];
            if (root->childCount == 1)
            {
                ans.push_back(ch);
                // move forward
                int index = ch - 'a';
                root = root->children[index];
            }
            else
            {
                return;
            }
            if (root->isTerminal)
                return;
        }
    }
};
string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie *t = new Trie('\0');
    for (int i = 0; i < n; i++)
    {
        t->insert(arr[i]);
    }
    string first = arr[0];
    string ans = "";
    t->lcp(first, ans);
    return ans;
}
int main()
{
}