#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

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
    void insert(string word) {
        transform(word.begin(), word.end(), word.begin(), ::toupper);
        word.erase(remove(word.begin(), word.end(), ' '), word.end());
        TrieNode* node = head;
        for (char iter : word) {
            int ind = iter - 65;
            if (node->children[ind] == nullptr)
                node->children[ind] = new TrieNode();
            node = node->children[ind];
        }
        node->end = true;
    }
    bool search(string word, bool& complete) {
        TrieNode* node = head;
        for (char iter : word) {
            int ind = iter - 65;
            if (node->children[ind] == nullptr)
                return false;
            node = node->children[ind];
        }
        complete = node->end;
        return true;
    }
    vector<string> prefix(string word) {
        transform(word.begin(), word.end(), word.begin(), ::toupper);
        word.erase(remove(word.begin(), word.end(), ' '), word.end());
        TrieNode* node = head;
        vector<string> ans;
        for (char iter : word) {
            int ind = iter - 65;
            if (node->children[ind] == nullptr)
                return ans;
            node = node->children[ind];
        }
        dfs(word, node, ans);
        return ans;
    }
    void dfs (string word, TrieNode* node, vector<string>& ans) {
        if (node->end) {
            ans.push_back(word);
        }
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                dfs(word + (char)(i+65), node->children[i], ans);
            }
        }
    }
};