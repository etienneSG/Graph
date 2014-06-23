//==============================================================================
// 
// Class Graph:
//   Cette classe implémente le graphe.
// Cette classe est virtuelle pure et se dérive en deux classes filles :
// - DirectedGraph (graphe orienté)
// - UndirectedGraph (graphe non-orienté)
//
//==============================================================================
//
// Note d'utilisation:
//   La taille du vecteur des sommet est N.
// La taille de la matrice des arrêtes doit doit toujours être NxN !
//
//==============================================================================

#ifndef GRAPH_H
#define GRAPH_H


#include "Vertex.h"
#include "Edge.h"
#include "MatrixP.h"
#include <vector>


class Graph
{
public:
  /** Constructeur par défaut */
  Graph();
  
  /** Destructeur */
  virtual ~Graph();

  /**
   * Retourne un pointeur sur le sommet d'indice iIdx
   * @param iIdx : Indice du sommet à retourner
   * @return un pointeur sur le sommet si le sommet existe
   *         0 sinon
   */
  inline Vertex* GetVertex(int iIdx);
  
  /**
   * Retourne l'arrête entre le sommet iRow et le sommet iColumn
   * @param iRow    : numéro du premier sommet
   * @param iColumn : numéro du second sommet
   * @return un pointeur sur l'arrête entre les deux sommets.
   *         0 sinon.
   */
  inline Edge* GetEdge(int iRow, int iColumn);

  /**
   * Ajoute une arrête entre deux sommets
   * @param iVertex1 : premier sommet de l'arrête
   * @param iVertex2 : deuxième sommet de l'arrête
   */
  virtual void AddEdge(int iVertex1, int iVertex2);
  
protected:
  std::vector<Vertex> _vVertex; // vecteur des sommets du graphe
  MatrixP<Edge> _mEdge;         // Matrices des arrêtes du graphe

};


//==============================================================================
// Implémentation des méthodes
//==============================================================================


inline Edge* Graph::GetEdge(int iRow, int iColumn)
{
  return (1<=iRow && iRow<=_mEdge.GetNbOfRow() && 1<=iColumn && iColumn<=_mEdge.GetNbOfColumn()) ? _mEdge(iRow, iColumn) : 0;
}

inline Vertex* Graph::GetVertex(int iIdx)
{
  return (1<=iIdx && iIdx<=(int)_vVertex.size()) ? &_vVertex[iIdx-1] : 0;
}


#endif

