#ifndef BREADTH_FIRST_SEARCHER
#define BREADTH_FIRST_SEARCHER

#include <functional>
#include <optional>
#include <DataStructures/Graph.h>
#include <DataStructures/WeightedGraph.h>
#include <DataStructures/UndirectedGraph.h>
#include <DataStructures/UndirectedWeightedGraph.h>
#include <queue>
#include <unordered_map>
using namespace std;

template <typename TGraph>
class BreadthFirstSearcher {
 public:
    static void VisitAllVertices(const TGraph *graph, int start, const std::function<void(int)> &action);
    static std::optional<int> FindFirstVertex(const TGraph *graph, int start, const std::function<bool(int)> &predicate);
};

#endif
