#ifndef EDGE_H
#define EDGE_H

//#define NONE_VERTEX 0x7fffffff

class Edge {
private:
    int from, to;

public:
    Edge(int source, int destination);

    ~Edge();

public:
    virtual int GetSource() const;

    virtual int GetDestination() const;


    bool operator == (const Edge& e) const {
        return (from == e.from && to == e.to);
    }
};




#endif
