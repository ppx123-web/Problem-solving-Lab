#ifndef WEIGHTEDGE_H
#define WEIGHTEDGE_H

#include<DataStructures/Edge.h>

class WeightEdge : public Edge {
private:
    int weight;
public:
    WeightEdge(int v1, int v2, int w);

    ~WeightEdge();

    int GetSource() const;

    int GetDestination() const;

    int GetWeight() const;

};

#endif