#ifndef NODE_HH
#define NODE_HH

#include <iostream>

class node
{
     node* next;
     int id;
     int edge;
    public:
     node(int i, int e) : next(nullptr), id(i), edge(e) {}
     ~node() { delete next; }
     int getId() const { return this->id; }
     int getEdge() const { return this->edge; }
     node* getNext() const { return next; }
     void setId(int i) { id = i; }
     void setEdge(int i) { edge = i; }
     void setNext(node* n) { next = n; }
};


#endif