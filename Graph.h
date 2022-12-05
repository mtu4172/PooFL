#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <random>

using namespace std;

struct GraphNode {
    string name;
    int priv;
    int temp;
    int clean;
    int avgoverall;
    bool bath;
    vector<pair<GraphNode*, int>> neighbors; // lists all connected nodes and edge weight
    GraphNode (string name, int priv, int temp, int clean, int avgoverall, bool bath) {
        this->name = name;
        this->priv = priv;
        this->temp = temp;
        this-> clean = clean;
        this->bath = bath;
        this->avgoverall = avgoverall;
    }
};

struct Graph {
    unordered_map<string, GraphNode*> nodes; // map of names to nodes (easier searching)
    vector<string> names; // just a list of names

    int size;
    Graph() {
        size = 0;
    }

    void AddNode(string name, int priv, int temp, int clean, int avgoverall, bool bath) {
        if (nodes[name] != nullptr) { // no duplicate names
            return;
        }
        names.push_back(name);
        nodes[name] = new GraphNode(name, priv, temp, clean, avgoverall, bath);
        size++;
    }

    void AddEdges(int E) { // creates edges between nodes and assigns random weights
        random_device rd;
        uniform_int_distribution<int> dist(1, 100);
        for (int i = 0; i < names.size()-E; i++) {
            for (int j = 1; j <= E; j++) {
                int d = dist(rd);
                // connect A->B and B->A
                nodes[names[i]]->neighbors.push_back({nodes[names[i+j]], d});
                nodes[names[i+j]]->neighbors.push_back({nodes[names[i]], d});
            }
        }
    }
};
