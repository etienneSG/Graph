#include "Graph.h"

using namespace std;

Graph::Graph()
{
}

Graph::~Graph()
{
  _mEdge.DeleteAll();
}

void Graph::AddEdge(int iVertex1, int iVertex2)
{
  int _nbVertex = _vVertex.size();
  if ( !(1<=iVertex1 && iVertex1<=_nbVertex && 1<=iVertex2 && iVertex2<=_nbVertex ) )
    return;
  
  _mEdge(iVertex1, iVertex2) = new Edge(&_vVertex[iVertex1], &_vVertex[iVertex2]);
}

