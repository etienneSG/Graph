#include "Graph.h"
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>

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

void Graph::AddVertex(int iNbToAdd)
{
  int NbVertex = _vVertex.size();
  
  for (int i=0; i<iNbToAdd; i++) {
    NbVertex++;
    string Idx = static_cast<ostringstream*>( &(ostringstream() << NbVertex) )->str();
    Vertex V("v"+Idx);
    _vVertex.push_back(V);
  }
  
  _mEdge.ReSize(NbVertex, NbVertex);
}

