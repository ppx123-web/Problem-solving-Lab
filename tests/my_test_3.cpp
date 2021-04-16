#include <DataStructures/WeightedGraph.h>
#include <Algorithms/DijkstraShortestPaths.h>

int main() {
    WeightedGraph<int> *g = new WeightedGraph<int>();
    g->AddVertex(1), g->AddVertex(2);
    g->AddEdge(1, 2, 100);

    ShortestPaths<WeightedGraph, int>
            *p = new DijkstraShortestPaths<WeightedGraph, int>(g, 1);
    cout << p->TryGetDistanceTo(2).value_or(114514) << endl;
    delete p;
    return 0;
}