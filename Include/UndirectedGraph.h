//==============================================================================
// 
// Class UndirectedGraph:
//   Cette classe implémente un graphe non-orienté et dérive de la classe Graph.
//
//==============================================================================

#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include "Graph.h"

class UndirectedGraph : public Graph
{
public:
  /** Constructeur par défaut */
  UndirectedGraph();
  
  /** Destructeur */
  ~UndirectedGraph();
  
  /**
   * Ajoute une arrête non orientée entre deux sommets
   * @param iVertex1 : premier sommet de l'arrête
   * @param iVertex2 : deuxième sommet de l'arrête
   */
  void AddEdge(int iVertex1, int iVertex2);
  
};


#endif

