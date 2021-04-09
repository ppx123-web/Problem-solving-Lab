#include <Algorithms/DepthFirstSearcher.h>
#include <Algorithms/BreadthFirstSearcher.h>
#include <assert.h>
#include <iostream>
using namespace std;


int main() {
    Graph g;
    assert(g.AddVertex(1));
    for(int i = 2; i <= 5; ++i) {
        assert(g.AddVertex(i));
        assert(g.AddEdge(i - 1, i));
    }
    BreadthFirstSearcher<Graph>::FindFirstVertex(&g, 1, [] (int a) -> bool {
        cout << a << endl;
        return a == 3;
    });
}