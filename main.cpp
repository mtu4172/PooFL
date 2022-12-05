#include <iostream>
#include "Graph.h"

int main() {
    Graph g;
    g.AddNode("Pugh", 0, 0, 0, true);
    g.AddNode("Turlington", 1, 1, 1, false);
    g.AddNode("Marston", 1, 0, 1, true);
    g.AddNode("Reitz", 1, 0, 1, true);
    g.AddNode("Graham", 1, 0, 1, true);
    g.AddNode("Carleton", 1, 0, 1, true);
    g.AddNode("Fine Arts", 1, 0, 1, true);
    g.AddNode("Rolf", 1, 0, 1, true);
    g.AddNode("Smathers", 1, 0, 1, true);
    g.AddEdges(5);
    for (const auto& iter : g.nodes) {
        cout << iter.first << ": ";
        for (auto it : iter.second->neighbors)
            cout << it.first->name <<" " << it.second<< "  ";
        cout << endl;
    }
    return 0;
}
