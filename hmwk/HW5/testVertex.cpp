#include "vertex.h"


int main()
{
    Vertex  *tmp;

    tmp = new Vertex('A',10);

    tmp->addEdge('B');
    tmp->addEdge('C');
    tmp->removeEdge('D');
    tmp->addEdge('D');
    tmp->addEdge('A');
    tmp->addEdge('B');

    tmp->printVertex();
}
