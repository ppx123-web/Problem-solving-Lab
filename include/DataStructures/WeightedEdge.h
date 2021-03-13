#ifndef WEIGHTEDGE_H
#define WEIGHTEDGE_H

#include<DataStructures/Edge.h>

class WeightedEdge : public Edge {
private:
    int weight;
public:
    WeightedEdge(int source, int destination, int w);

    ~WeightedEdge();

    int GetSource() const;

    int GetDestination() const;

    int GetWeight() const;

};

#endif