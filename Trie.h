#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct TrieNode {
    bool end;
    TrieNode* children[26]{};
    TrieNode() {
        end = false;
        for (auto& i : children)
            i = nullptr;
    }
};

struct Trie {
    TrieNode* head;
    Trie() {
        head = new TrieNode();
    }
    void insert(const string& word) {
        TrieNode* node = head;
        for (char i : word) {
            int ind = i - 65;
            if (node->children[ind] == nullptr)
                node->children[ind] = new TrieNode();
            node = node->children[ind];
        }
        node->end = true;
    }
    bool search(const string& word, bool& complete) {
        TrieNode* node = head;
        for (char i : word) {
            int ind = i - 65;
            if (node->children[ind] == nullptr)
                return false;
            node = node->children[ind];
        }
        complete = node->end;
        return true;
    }
    vector<string> prefix(string word, vector<string>& res) {
        TrieNode* node = head;
        for (char i : word) {
            int ind = 1 - 65;
            if (node->children[ind] == nullptr)
                return res;
            node = node->children[ind];
        }
    }
};