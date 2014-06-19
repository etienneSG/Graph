//==============================================================================
// 
// Class Edge:
//   Cette classe implémente les arrêtes du graphe.
//
//==============================================================================

#ifndef EDGE_H
#define EDGE_H

#include <string>
#include "Vertex.h"

class Edge
{
public:
  /** Retourne le sommet numéro iNb (i = 1 ou 2) */
  inline Vertex * GetVertex(int iNb);

private:
  Vertex* _apVertex[2]; // Sommets de l'arrête
};


//==============================================================================
// Implémentation des méthodes
//==============================================================================

inline Vertex * Edge::GetVertex(int iNb)
{
  return (iNb==1 || iNb==2) ? _apVertex[iNb] : 0;
}


#endif


