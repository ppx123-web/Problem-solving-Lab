#include <Algorithms/DepthFirstSearcher.h>


template <typename TGraph>
static void VisitAllVertices(const TGraph *graph, int start, const std::function<void(int)> &action) {

}

template <typename TGraph>
static std::optional<int> FindFirstVertex(const TGraph *graph, int start, const std::function<bool(int)> &predicate);