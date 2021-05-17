#ifndef LIST_HH
#define LIST_HH

#include <iostream>
#include "node.hh"

class list
{
    node** ver;
    int* dist;
    int* path;
    int start;
    int size;

    public:
     list() : ver(nullptr),dist(nullptr),path(nullptr), start(0), size(0) {}
     ~list();
     bool empty() const { return this->ver == nullptr ? true : false; }
     node* front(int id) const { return this->ver[id]; }
     void addFront(int id, node* v);
     void removeFirst(int id);
     void setSize(int n) { this->size = n; }
     void setStart(int s) { this->start = s; }
     void setVer(node** n) { this->ver = n; }
     int getSize() const { return this->size; }
     void dijkstra(); 
     void printPaths();
     void random(int ver, double den, int sta);
     void randomFull(int ver, int sta);
};




inline std::ostream & operator << (std::ostream &out, const list &L)
{
    for(int i = 0; i < L.getSize(); i++)
    {
        out << i << ": ";
        node* tmp = L.front(i);
        while( tmp != nullptr )
        {
            out << " " << tmp->getId();
            tmp = tmp->getNext();
        }
        out << "\n";
    }
    return out;
}

inline std::istream & operator >> (std::istream &in, list &L)
{

    int edgeNumber, vertexNumber, start;
    in >> edgeNumber;
    in >> vertexNumber;
    in >> start;

    L.setSize(vertexNumber);
    L.setStart(start);
    L.setVer( new node* [vertexNumber] );

    for(int i = 0; i < edgeNumber; i++)
    {
            int a,b,w;
            in >> a;
            in >> b;
            in >> w;
            L.addFront(a, new node(b,w) );
            L.addFront(b, new node(a,w) );
    }
    return in;
}

#endif