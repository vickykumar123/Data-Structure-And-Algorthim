#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode *children[26]; // 26 alphabatical character
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode *root, string word)
    {
        // base Case
        if (word.length() == 0)
        {
            // last Node is true
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // absent: in Case of absent create a new node
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursion
        insertUtil(child, word.substr(1)); // if the word is "hello" the word.substr(1) returns "ello"
    }
    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    // Searching the word
    bool searchUtil(TrieNode *root, string word)
    {
        // base Case
        if (word.length() == 0)
        {
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // absent
            return false;
        }
        // Recursion
        return searchUtil(child, word.substr(1));
    }
    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    // Remove
    void removeUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = false;
            delete root;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // absent
            return;
        }
        removeUtil(child, word.substr(1));
    }
    void removeWord(string word)
    {
        removeUtil(root, word);
    }

    // prefix
    //  prefix means is any word start with "he" or not
    bool prefixUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return true;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        return prefixUtil(child, word.substr(1));
    }
    bool startsWith(string prefix)
    {
        return prefixUtil(root, prefix);
    }
};
int main()
{
    Trie *t = new Trie();
    t->insertWord("abcd");
    t->insertWord("arm");
    t->insertWord("time");
    cout << "Present or Not " << t->searchWord("arm") << endl;
    t->removeWord("arm");
    cout << "Present or Not " << t->searchWord("arm") << endl;
}
