#include <DataStructures/WeightedGraph.h>
#include <Algorithms/DijkstraShortestPaths.h>

int main() {
    WeightedGraph<int> *g = new WeightedGraph<int>();
    g->AddVertex(1);
    g->AddVertex(2);
    g->AddVertex(3);
    g->AddVertex(4);
    g->AddEdge(1, 2, 100);
    g->AddEdge(1, 3, 100);
    g->AddEdge(3, 4, 100);

    ShortestPaths<WeightedGraph, int>
            *p = new DijkstraShortestPaths<WeightedGraph, int>(g, 1);
    cout << p->HasPathTo(5) << endl;
    delete p;
    return 0;
}