//==============================================================================
// 
// Class UndirectedGraph:
//   Cette classe impl�mente un graphe non-orient� et d�rive de la classe Graph.
//
//==============================================================================

#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include "Graph.h"

class UndirectedGraph : public Graph
{
public:
  /** Constructeur par d�faut */
  UndirectedGraph();
  
  /** Destructeur */
  ~UndirectedGraph();
  
  /**
   * Ajoute une arr�te non orient�e entre deux sommets
   * @param iVertex1 : premier sommet de l'arr�te
   * @param iVertex2 : deuxi�me sommet de l'arr�te
   */
  void AddEdge(int iVertex1, int iVertex2);
  
};


#endif

