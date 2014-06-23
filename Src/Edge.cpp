#include "Edge.h"

Edge::Edge()
{
  for (int i=0; i<2; i++)
    _apVertex[i] = 0;
}

Edge::Edge(Vertex* iVertex1, Vertex* iVertex2)
{
  _apVertex[0] = iVertex1;
  _apVertex[1] = iVertex2;
}

Edge::~Edge()
{
  for (int i=0; i<2; i++)
    _apVertex[i] = 0;
}

