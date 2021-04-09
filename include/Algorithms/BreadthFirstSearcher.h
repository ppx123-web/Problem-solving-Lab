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

template<typename TGraph>
void BreadthFirstSearcher<TGraph>::VisitAllVertices(const TGraph *graph, int start, const function<void(int)> &action) {
    unordered_map<int,int> vis;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        vis[cur] = 1;
        action(cur);
        for(int u : graph->GetNeighbors(cur)) {
            if(vis.find(u) == vis.end()) {
                q.push(u);
            }
        }
    }
}

template<typename TGraph>
std::optional<int>
BreadthFirstSearcher<TGraph>::FindFirstVertex(const TGraph *graph, int start, const function<bool(int)> &predicate) {
    unordered_map<int,int> vis;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        vis[cur] = 1;
        if(predicate(cur)) {
            return cur;
        }
        for(int u : graph->GetNeighbors(cur)) {
            if(vis.find(u) == vis.end()) {
                q.push(u);
            }
        }
    }
    return NULL;
}

#endif
