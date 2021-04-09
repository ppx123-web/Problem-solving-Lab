#ifndef DEPTH_FIRST_SEARCHER
#define DEPTH_FIRST_SEARCHER

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
class DepthFirstSearcher {
 public:
    static void VisitAllVertices(const TGraph *graph, int start, const std::function<void(int)> &action) {
        unordered_map<int,int> vis;
        vis[start] = 1;
        for(const int u:graph->GetNeighbors(cur)) {
            if()
        }
    }


    static std::optional<int> FindFirstVertex(const TGraph *graph, int start, const std::function<bool(int)> &predicate);
};

#endif
