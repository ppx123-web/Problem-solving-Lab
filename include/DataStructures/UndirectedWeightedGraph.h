#ifndef UNDIRECTEDWEIGHTEDGRAPH_H
#define UNDIRECTEDWEIGHTEDGRAPH_H

#include <DataStructures/WeightedGraph.h>


template <typename Weight_T>
class UndirectedWeightedGraph: public WeightedGraph<Weight_T> {
public:
    UndirectedWeightedGraph(): WeightedGraph<Weight_T>() {

    }

    ~UndirectedWeightedGraph() override;

    bool AddVertex(int vertex) {
        return WeightedGraph<Weight_T>::AddVertex(vertex);
    }

    bool RemoveVertex(int vertex) {
        return WeightedGraph<Weight_T>::RemoveVertex(vertex);
    }

    bool AddEdge(int vertex1, int vertex2, Weight_T weight) {
        if(WeightedGraph<Weight_T>::AddEdge(vertex1,vertex2,weight)) {
            bool temp = WeightedGraph<Weight_T>::AddEdge(vertex2,vertex1,weight);
            return true;
        } else return false;
    }


    //添加了权重参数；如果添加某条边时图中已经存在了相同起点和终点的边（无论权重是多少），则什么都不做并返回false
    bool RemoveEdge(int vertex1, int vertex2) {
        if(WeightedGraph<Weight_T>::RemoveEdge(vertex1,vertex2)) {
            bool temp = WeightedGraph<Weight_T>::RemoveEdge(vertex2,vertex1);
            return true;
        } else {
            return false;
        }
    }

    int CountVertices() const {
        return WeightedGraph<Weight_T>::CountVertices();
    }

    int CountEdges() const {
        int ans = WeightedGraph<Weight_T>::CountEdges();
        for(auto item:WeightedGraph<Weight_T>::GetVertices()) {
            if(WeightedGraph<Weight_T>::ContainsEdge(item,item)) {
                ans++;
            }
        }
        return ans/2;
    }

    bool ContainsVertex(int vertex) const {
        return WeightedGraph<Weight_T>::ContainsVertex(vertex);
    }

    bool ContainsEdge(int vertex1, int vertex2) const {
        return WeightedGraph<Weight_T>::ContainsEdge(vertex1,vertex2);
    }

    Weight_T GetWeight(int vertex1, int vertex2) const {
        return WeightedGraph<Weight_T>::GetWeight(vertex1,vertex2);
    }

    //查询v1指向v2的边的权重，如果这条边不存在则属于UB
    std::vector<int> GetVertices() const {
        return WeightedGraph<Weight_T>::GetVertices();
    }

    std::vector<WeightedEdge<Weight_T>> GetEdges() const {
        std::vector<WeightedEdge<Weight_T>> ans = WeightedGraph<Weight_T>::GetEdges();
        std::map<pair<pair<int,int>,int>,int> s;
        for(auto it = ans.begin();it != ans.end();it++) {
            pair<pair<int,int>,Weight_T> e1,e2;
            e1.first.first = it->GetSource(); e1.first.second = it->GetDestination(); e1.second = it->GetWeight();
            e2.first.first = it->GetDestination(); e2.first.second = it->GetSource(); e2.second = it->GetWeight();
            auto front = s.find(e1);
            auto back = s.find(e2);
            if(front != s.end()) {
                s.erase(front);
            } else if(back != s.end()) {
                s.erase(back);
            } else {
                s[e1] = 1;
                ans.erase(it);
            }
        }
        return ans;
    }

    std::vector<WeightedEdge<Weight_T>> GetIncomingEdges(int vertex) const {
        return WeightedGraph<Weight_T>::GetIncomingEdges(vertex);
    }


    std::vector<WeightedEdge<Weight_T>> GetOutgoingEdges(int vertex) const{
        return WeightedGraph<Weight_T>::GetOutgoingEdges(vertex);
    }

    int GetDegree(int vertex) const {
        vector<int> deg = WeightedGraph<Weight_T>::GetNeighbors(vertex);
        for(auto it:deg) {
            if(it == vertex) {
                return deg.size() + 1;
            }
        }
        return deg.size();
    }

    std::vector<int> GetNeighbors(int vertex) const{
        return WeightedGraph<Weight_T>::GetNeighbors(vertex);
    }
};

#endif
