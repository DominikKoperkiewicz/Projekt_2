#include "matrix.hh"

matrix::~matrix()
{
    for(int i = 0; i < this->size; i++)
    {
        delete this->edges[i];
    }
    delete this->edges;
    delete this->dist;
    delete this->path;
}

void matrix::setStart(int n)
{
    this->start = n;
}

void matrix::setMatrix(int** ptr)
{
    this->edges = ptr;
}

void matrix::setSize(int n)
{
    this->size = n;
}


int matrix::getSize() const
{
    return this->size;
}

int matrix::getEdge(int a, int b) const
{
    return this->edges[a][b];
}

void matrix::dijkstra()
{
    this->dist = new int [this->size];
    this->path = new int [this->size];
    bool* found = new bool [this->size];

    for(int i = 0; i < this->size; i++)
    {
        this->dist[i] = INT16_MAX;
        found[i] = false;
        this->path[i] = -1;
    }
    this->dist[this->start] = 0;
    int tmp = this->start;
    for(int j = 0; j < this->size; j++)
    {
        for(tmp = 0; found[tmp] == true; tmp++);

        for(int i = 0; i < this->size; i++)
        {
            if( !found[i] && this->dist[tmp] > this->dist[i] )
            {
                tmp = i;
            }
        }
        found[tmp] = true;
        
        for(int i = 0; i < this->size; i++)
        {
            if( !found[i] && this->getEdge(i,tmp) > 0 && this->dist[i] > this->dist[tmp]+this->getEdge(i,tmp) )
            {
                this->dist[i] = this->dist[tmp]+this->getEdge(i,tmp);
                this->path[i] = tmp;
            }
        }
    }

    delete found;
}

void matrix::printPaths()
{
    if(this->path == nullptr)
    {
        std::cout << "\nSciezki nie wyliczone\n";
        return;
    }

    for(int i = 0; i < this->size; i++)
    {
        std::cout << i << ": " << this->dist[i] << "  |  ";
        for(int j = i; this->path[j] != -1; j = this->path[j] )
        {
           std::cout << this->path[j] << " ";
        }
        std::cout << "\n";
    }
}


void matrix::random(int ver, double den, int sta)
{
    if(this->edges != nullptr)
    {
        for(int i = 0; i < this->size; i++)
        {
            delete this->edges[i];
        }
    }


    this->setSize(ver);
    this->setStart(sta);

    this->edges = new int*[ver];
    for(int i = 0; i < ver; ++i) 
    {
        this->edges[i] = new int[ver];
    }
    int e;

    for(int i = 0; i < ver; i++)
    {
        for(int j = i+1; j < ver; j++)
        {
            if(rand() % 1000 < den*1000)
            {
            e = rand() % 100;
            this->edges[i][j] = e;
            this->edges[j][i] = e;
            }
        }
    }
}

void matrix::randomFull(int ver, int sta)
{
    if(this->edges != nullptr)
    {
        for(int i = 0; i < this->size; i++)
        {
            delete this->edges[i];
        }
    }


    this->setSize(ver);
    this->setStart(sta);

    this->edges = new int*[ver];
    for(int i = 0; i < ver; ++i) 
    {
        this->edges[i] = new int[ver];
    }
    int e;

    for(int i = 0; i < ver; i++)
    {
        for(int j = i+1; j < ver; j++)
        {
            e = rand() % 100;
            this->edges[i][j] = e;
            this->edges[j][i] = e;
        }
    }
}

void matrix::resultFile(std::fstream file)
{
    if(this->path == nullptr)
    {
        std::cout << "\nSciezki nie wyliczone\n";
        return;
    }
    if(file.is_open())
    {
        for(int i = 0; i < this->size; i++)
        {
            file << i << ": " << this->dist[i] << "  |  ";
            for(int j = i; this->path[j] != -1; j = this->path[j] )
            {
            file << this->path[j] << " ";
            }
            file << "\n";
        }
    }
    file.close();
}