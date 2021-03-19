#include <cassert>
#include <DataStructures/WeightedGraph.h>
#include <DataStructures/UndirectedWeightedGraph.h>

using namespace std;

int main() {
    WeightedGraph g;

    assert(g.AddVertex(1) == true);
    assert(g.AddVertex(2) == true);
    assert(g.AddVertex(3) == true);
    assert(g.AddVertex(3) == false);
    assert(g.AddVertex(4) == true);
    assert(g.ContainsVertex(4) == true);
    assert(g.RemoveVertex(4) == true);
    assert(g.ContainsVertex(4) == false);
    assert(g.RemoveVertex(5) == false);

    assert(g.AddEdge(1, 2, 1) == true);
    assert(g.AddEdge(1, 3, 1) == true);
    assert(g.AddEdge(2, 5, 1) == false);
    assert(g.ContainsEdge(1, 2) == true);
    assert(g.ContainsEdge(2, 5) == false);

    assert(g.GetDegree(1) == 2);
    assert(g.GetIncomingEdges(1).empty());
    assert(g.GetOutgoingEdges(1).size() == 2);
    assert(g.GetNeighbors(1).size() == 2);
    assert(g.GetNeighbors(2).empty());
    assert(g.GetWeight(1,2) == 1);
    assert(g.RemoveEdge(1121313,2) == 0);
}


