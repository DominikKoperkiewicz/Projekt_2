#include "list.hh"

list::~list()
{
    
}

void list::addFront(int id, node* v)
{
    v->setNext(this->ver[id]);
    this->ver[id] = v;
}

void list::removeFirst(int id)
{
    node* tmp = this->ver[id];
    this->ver[id] = this->ver[id]->getNext();
    delete tmp;
}

void list::dijkstra()
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
        
        for(node* i = this->ver[tmp]; i != nullptr; i = i->getNext())
        {
            if( !found[i->getId()] && i->getEdge() > 0 && this->dist[i->getId()] > this->dist[tmp]+i->getEdge() )
            {
                this->dist[i->getId()] = this->dist[tmp]+i->getEdge();
                this->path[i->getId()] = tmp;
            }
        }
    }

    delete found;
}

void list::printPaths()
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

void list::random(int ver, double den, int sta)
{
    this->setSize(ver);
    this->setStart(sta);
    this->setVer( new node* [ver] );
    int e;

    for(int i = 0; i < ver; i++)
    {
        for(int j = i+1; j < ver; j++)
        {
            if(rand() % 1000 < den*1000)
            {
            e = rand() % 100;
            this->addFront(i,new node(j,e));
            this->addFront(j,new node(i,e));
            }
        }
    }
}


void list::randomFull(int ver, int sta)
{
    this->setSize(ver);
    this->setStart(sta);
    this->setVer( new node* [ver] );
    int e;

    for(int i = 0; i < ver; i++)
    {
        for(int j = i+1; j < ver; j++)
        {
            e = rand() % 100;
            this->addFront(i,new node(j,e));
            this->addFront(j,new node(i,e));
        }
    }
}