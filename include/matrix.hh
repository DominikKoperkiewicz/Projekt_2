#ifndef MATRIX_HH
#define MATRIX_HH

#include <iostream>
#include <fstream>

class matrix
{
    int** edges;
    int* dist;
    int* path;
    int start;
    int size;

    public:
     matrix() : edges(nullptr),dist(nullptr),path(nullptr), start(0), size(0) {}
     ~matrix();
     void setStart(int n);
     void setMatrix(int** ptr);
     void setSize(int n);
     int getSize() const;
     int getEdge(int a, int b) const;
     void dijkstra(); 
     void printPaths();
     void random(int ver, double den, int sta);
     void randomFull(int ver, int sta);
     void resultFile(std::fstream file);
};




inline std::ostream & operator << (std::ostream &out, const matrix &M)
{
    for(int i = 0; i < M.getSize(); i++)
    {
        out << "[ ";
        for(int j = 0; j < M.getSize(); j++)
        {
            out << M.getEdge(i,j) << " ";           
        }
        out << "]\n";
    }

    return out;
}

inline std::istream & operator >> (std::istream &in, matrix &M)
{
    int edgeNumber, vertexNumber, start;
    in >> edgeNumber;
    in >> vertexNumber;
    in >> start;

    M.setSize(vertexNumber);
    M.setStart(start);

    
    int **arr = new int*[vertexNumber];
    for(int i = 0; i < vertexNumber; ++i) 
    {
        arr[i] = new int[vertexNumber];
    }

    for(int i = 0; i < vertexNumber; i++)
        for(int j = 0; j < vertexNumber; j++)
            arr[i][j] = 0;
    
    for(int i = 0; i < edgeNumber; i++)
        {
            int a,b,w;
            in >> a;
            in >> b;
            in >> w;
            arr[a][b] = w;
            arr[b][a] = w;
        }
    M.setMatrix(arr);

    return in;
}

#endif