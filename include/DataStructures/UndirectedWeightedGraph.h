#ifndef UNDIRECTEDWEIGHTEDGRAPH_H
#define UNDIRECTEDWEIGHTEDGRAPH_H

#include <DataStructures/WeightedGraph.h>

class UndirectedWeightedGraph: public WeightedGraph {
public:
    UndirectedWeightedGraph();

    ~UndirectedWeightedGraph();

    bool AddVertex(int vertex);

    bool RemoveVertex(int vertex);

    bool AddEdge(int vertex1, int vertex2, int weight);

    //添加了权重参数；如果添加某条边时图中已经存在了相同起点和终点的边（无论权重是多少），则什么都不做并返回false
    bool RemoveEdge(int vertex1, int vertex2);

    int CountVertices() const;

    int CountEdges() const;

    bool ContainsVertex(int vertex) const;

    bool ContainsEdge(int vertex1, int vertex2) const;

    int GetWeight(int vertex1, int vertex2) const;

    //查询v1指向v2的边的权重，如果这条边不存在则属于UB
    std::vector<int> GetVertices() const;

    std::vector<WeightedEdge> GetEdges() const;

    std::vector<WeightedEdge> GetIncomingEdges(int vertex) const;

    std::vector<WeightedEdge> GetOutgoingEdges(int vertex) const;

    int GetDegree(int vertex) const;

    std::vector<int> GetNeighbors(int vertex) const;
};

#endif
