#include "UndirectedGraph.h"


UndirectedGraph::UndirectedGraph()
{
}


UndirectedGraph::~UndirectedGraph()
{
}


void UndirectedGraph::AddEdge(int iVertex1, int iVertex2)
{
  int _nbVertex = _vVertex.size();
  if ( !(1<=iVertex1 && iVertex1<=_nbVertex && 1<=iVertex2 && iVertex2<=_nbVertex ) )
    return;
  
  Graph::AddEdge(iVertex1, iVertex2);
  _mEdge(iVertex2,iVertex1) = _mEdge(iVertex1,iVertex2);
}

