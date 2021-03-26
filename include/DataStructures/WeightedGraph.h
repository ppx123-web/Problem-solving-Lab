#ifndef WEIGHTGRAPH_H
#define WEIGHTGRAPH_H

#include<DataStructures/WeightedEdge.h>
#include<DataStructures/Graph.h>
#include <map>
#include <utility>

using namespace std;

template <typename Weight_t>

class WeightedGraph : public Graph {
private:

    unordered_map<int, Weight_t> edge_weight[MAX_VERTEX];
public:
    WeightedGraph():Graph() {

    }

    ~WeightedGraph() override {
        for(int i = 0;i < MAX_VERTEX;i++) {
            edge_weight[i].clear();
        }
    }

    bool AddVertex(int vertex) override {
        return Graph::AddVertex(vertex);
    }

    bool RemoveVertex(int vertex) override {
        if(vertex_map.find(vertex) == vertex_map.end())
            return false;
        else {
            edge_weight[vertex_map[vertex]].clear();
            bool ans =  Graph::RemoveVertex(vertex);
            return ans;
        }
    }

    bool AddEdge(int vertex1, int vertex2, Weight_t weight) {
        bool ans = Graph::AddEdge(vertex1,vertex2);
        if(ans) {
            edge_weight[vertex_map[vertex1]][vertex2] = weight;
            return true;
        } else {
            return false;
        }
    }

    //添加了权重参数；如果添加某条边时图中已经存在了相同起点和终点的边（无论权重是多少），则什么都不做并返回false
    bool RemoveEdge(int vertex1, int vertex2) override {
        if(vertex_map.find(vertex1)== vertex_map.end()||vertex_map.find(vertex2)== vertex_map.end()) return false;
        if(edge_weight[vertex_map[vertex1]].find(vertex2) == edge_weight[vertex_map[vertex1]].end()) return false;
        else {
            bool ans = Graph::RemoveEdge(vertex1,vertex2);
            if(ans) {
                edge_weight[vertex_map[vertex1]].erase(vertex2);
            }
            return ans;
        }
    }

    int CountVertices() const override {
        return Graph::CountVertices();
    }

    int CountEdges() const override {
        return Graph::CountEdges();
    }

    bool ContainsVertex(int vertex) const override {
        return Graph::ContainsVertex(vertex);
    }

    bool ContainsEdge(int vertex1, int vertex2) const override {
        return Graph::ContainsEdge(vertex1,vertex2);
    }

    Weight_t GetWeight(int vertex1, int vertex2) const {
        if(!Graph::ContainsEdge(vertex1,vertex2)) return false;
        else {
            int temp = vertex_map.find(vertex1)->second;
            return edge_weight[temp].find(vertex2)->second;
        }
    }

    //查询v1指向v2的边的权重，如果这条边不存在则属于UB
    std::vector<int> GetVertices() const override {
        return Graph::GetVertices();
    }

    std::vector<WeightedEdge<Weight_t>> GetEdges() const {
        std::vector<WeightedEdge<Weight_t>> ans;
        std::vector<Edge> edges = Graph::GetEdges();
        for(const auto& item:edges) {
            auto it = edge_weight[vertex_map.find(item.GetSource())->second].find(item.GetDestination());
            WeightedEdge e(item.GetSource(),item.GetDestination(),it->second);
            ans.push_back(e);
        }
        return ans;
    }

    std::vector<WeightedEdge<Weight_t>> GetIncomingEdges(int vertex) const{
        std::vector<WeightedEdge<Weight_t>> ans;
        std::vector<Edge> edges = Graph::GetIncomingEdges(vertex);
        for(const auto& item:edges) {
            auto it = edge_weight[vertex_map.find(item.GetSource())->second].find(item.GetDestination());
            WeightedEdge<Weight_t> e(item.GetSource(),item.GetDestination(),it->second);
            ans.push_back(e);
        }
        return ans;
    }

    std::vector<WeightedEdge<Weight_t>> GetOutgoingEdges(int vertex) const {
        std::vector<WeightedEdge<Weight_t>> ans;
        std::vector<Edge> edges = Graph::GetOutgoingEdges(vertex);
        for(const auto& item:edges) {
            auto it = edge_weight[vertex_map.find(item.GetSource())->second].find(item.GetDestination());
            WeightedEdge<Weight_t> e(item.GetSource(),item.GetDestination(),it->second);
            ans.push_back(e);
        }
        return ans;
    }

    int GetDegree(int vertex) const override {
        return Graph::GetDegree(vertex);
    }

    std::vector<int> GetNeighbors(int vertex) const override {
        return Graph::GetNeighbors(vertex);
    }

};

#endif