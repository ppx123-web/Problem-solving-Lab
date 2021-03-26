#ifndef WEIGHTEDGE_H
#define WEIGHTEDGE_H

#include<DataStructures/Edge.h>

template <typename Weight_t>

class WeightedEdge : public Edge {
private:
    Weight_t w;
public:
    WeightedEdge(int source, int destination, Weight_t weight): Edge(source,destination) {
        Edge(source,destination);
        w = weight;
    }

    ~WeightedEdge();

    int GetSource() const override {
        return Edge::GetSource();
    }

    int GetDestination() const override {
        return Edge::GetDestination();
    }

    Weight_t GetWeight() const {
        return w;
    }

};



#endif