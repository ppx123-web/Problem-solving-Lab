#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <DataStructures/Edge.h>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <utility>
#include <algorithm>


#define MAX_VERTEX 5000

class Graph {
private:
    int vertex_cnt;
    std::vector<Edge>edges;
    std::vector<Edge>edges_in[MAX_VERTEX];
    std::vector<Edge>edges_out[MAX_VERTEX];
    std::vector<int>vertexes[MAX_VERTEX];

    std::vector<int>vertex_set;//点的集合

public:

    std::unordered_map<int,int>vertex_map;

    Graph();

    ~Graph();


    void clear();



public:
    bool AddVertex(int vertex);

    bool RemoveVertex(int vertex);

    bool AddEdge(int vertex1, int vertex2);

    bool RemoveEdge(int vertex1, int vertex2);

public:
    int CountVertices() const;

    int CountEdges() const;

    bool ContainsVertex(int vertex) const;

    bool ContainsEdge(int vertex1, int vertex2) const;

    std::vector<int> GetVertices() const;

    std::vector<Edge> GetEdges() const;

    std::vector<Edge> GetIncomingEdges(int vertex) const;

    std::vector<Edge> GetOutgoingEdges(int vertex) const;

    int GetDegree(int vertex) const;

    std::vector<int> GetNeighbors(int vertex) const;

};

#endif
