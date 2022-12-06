#pragma once
#include "Graph.h"
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

int Dijktras(Graph* g, string source_, string destination_)
{
    GraphNode* source = g->nodes[source_]; //whatever source graphnode we pass in
    unordered_set<GraphNode*> alreadyVisited; //nodes that we have visited already
    vector<string> path;
    alreadyVisited.insert(source); //insert into set 
    int totalDistance = 0;
    bool found = false;
    while(found != true && alreadyVisited.size() < g.size()) //go through entire graph
    {
        GraphNode* leastEdge = SmallestEdge(source->neighbors, alreadyVisited, totalDistance);
        path.push_back(leastEdge->name);
        source = leastEdge;
        alreadyVisited.insert(leastEdge);
        if(leastEdge->name == destination_) found = true;
    }
    
    if(found == false)
    {
        cout << "No Path Exists << endl;
        return -1;
    }
    
    for(auto it : path)
    {
        cout << it <<  "-> ";
    }
    return totalDistance;
}

GraphNode* SmallestEdge(vector<pair<GraphNode*, int>> neighbors_, unordered_set<GraphNode*>& alreadyVisited, int& totalDistance)
{
    if(neighbors_.size() == 0) return nullptr;
    int smallEdge = neighbors_.at(0).second;
    GraphNode* leastEdge = neighbors_.at(0).first;
    for(int i = 1; i < neighbors_.size(); i ++)
    {
        GraphNode* current = neighbors_.at(i).first;
        if(alreadyVisited.find(neighbors_.at(i).first) == alreadyVisited.end() && neighbors_.at(i).second < smallEdge)
        {
            leastEdge = current;
            smallEdge = neighbors_.at(i).second;
        }
    }
    totalDistance += smallEdge;
    return leastEdge;
}
