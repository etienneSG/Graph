//==============================================================================
// 
// Class Vertex:
//   Cette classe implémente les sommets du graphe.
//
//==============================================================================

#ifndef VERTEX_H
#define VERTEX_H

#include <string>

class Vertex
{
public:
  /** Retourne le nom du sommet */
  inline std::string GetName();

private:
  std::string _name; // Nom du sommet
};


//==============================================================================
// Implémentation des méthodes
//==============================================================================

inline std::string Vertex::GetName()
{
  return _name;
}


#endif

