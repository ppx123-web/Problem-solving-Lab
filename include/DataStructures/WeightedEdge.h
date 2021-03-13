#ifndef WEIGHTEDGE_H
#define WEIGHTEDGE_H

#include<DataStructures/Edge.h>

class WeightedEdge : public Edge {
private:
    int w;
public:
    WeightedEdge(int source, int destination, int weight);

    ~WeightedEdge();

    int GetSource() const;

    int GetDestination() const;

    int GetWeight() const;

};

#endif