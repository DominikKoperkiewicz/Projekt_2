#include <iostream>
#include <chrono>
#include "matrix.hh"
#include "list.hh"


int main()
{
    int am = 100;
    int n = 100;
    double den = 0.25;

    list* graphL = new list [am];
    matrix* graphM = new matrix [am];

    for(int i = 0; i < am; i++)
    {
        list gL;
        matrix gM;
        //gM.randomFull(n,0);
        //gL.randomFull(n,0);
        gM.random(n,den,0);
        gL.random(n,den,0);
        graphL[i] = gL;
        graphM[i] = gM;
    }


    auto startM = std::chrono::steady_clock::now();
    for(int i = 0; i < am; i++)
    {
        graphL[i].dijkstra();
    }
    auto endM = std::chrono::steady_clock::now();
    auto M_us = std::chrono::duration_cast<std::chrono::microseconds>(endM - startM); 

    auto startL = std::chrono::steady_clock::now();
    for(int i = 0; i < am; i++)
    {
        graphL[i].dijkstra();
    }
    auto endL = std::chrono::steady_clock::now();
    auto L_us = std::chrono::duration_cast<std::chrono::microseconds>(endL - startL);

    std::cout << "Vertex: " << n << "  |  Graphs: " << am << "  |  Density: " << den*100 << "%" << "\n";
    std::cout << "Matrix: " << M_us.count() << " us\n";
    std::cout << "  List: " << L_us.count() << " us\n";
 
    return 0;
}