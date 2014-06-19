//==============================================================================
// 
// Class Graph:
//   Cette classe implémente le graphe.
//
//==============================================================================

#ifndef GRAPH_H
#define GRAPH_H


#include "Vertex.h"
#include "Edge.h"
#include "MatrixP.h"


class Graph
{
public:
  /**
   * Retourne l'arrête entre le sommet iRow et le sommet iColumn
   * @param iRow    : numéro du premier sommet
   * @param iColumn : numéro du second sommet
   * @return un pointeur sur l'arrête entre les deux sommets.
   *         0 sinon.
   */
  inline Edge* GetEdge(int iRow, int iColumn);

private:
  MatrixP<Edge> _mEdge;

};


//==============================================================================
// Implémentation des méthodes
//==============================================================================


inline Edge* Graph::GetEdge(int iRow, int iColumn)
{
  return _mEdge(iRow, iColumn);
}


#endif

