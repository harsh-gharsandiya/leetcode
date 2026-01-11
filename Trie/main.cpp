#include<bits/stdc++.h>

using namespace std;

struct Node {
    Node *links[26];
    bool flag;

    Node() {
        flag = false;
        for(int i=0; i < 26; i++) {
            links[i] = nullptr;
        }
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    void setEnd() {
        flag = true;
    }
    bool isEnd() {
        return flag;
    }
};

class Trie {
    private: Node* root;

    public: 

        Trie() {
            root = new Node();
        }

        // Insert a word into trie.
        // tc -> O(len)
        void insert(string word) {
            Node* node = root;
            for(int i=0; i<word.length(); i++) {
                if(!node -> containsKey(word[i])){
                    node -> put(word[i], new Node());
                }
                //move to reference trie
                node = node->get(word[i]);
            }

            node->setEnd();
        }

        // Search word
        // O(len)
        bool search(string word) {
            Node *node = root;
            for(int i=0; i<word.length(); i++) {
                if(!node -> containsKey(word[i])) {
                    return false;
                }
                node = node->get(word[i]);
            }

            return node -> isEnd();
        }

        //Start with word
        // O(len   )
        bool startsWith(string prefix) {
            Node* node = root;
            for(int i=0; i<prefix.length(); i++) {
                if(!node->containsKey(prefix[i])) {
                    return false;
                }
                node = node -> get(prefix[i]);
            }
            return true;
        }
};