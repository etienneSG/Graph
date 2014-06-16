//==============================================================================
// 
// Class MatrixP:
//   Cette classe implémente un template de matrice par pointeur.
// Les coefficients des lignes et des colonnes comment à 1.
// Les coefficient de la matrice sont des pointeurs.
//
//==============================================================================

#pragma once

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <assert.h> 

template <class T>
class MatrixP
{

public:
  /** Constructeur par défaut*/
  MatrixP();

  /**
   * Constructeur à partir de la taille de la matrice
   * @param iNbRow    : nombre de lignes de la matrice
   * @param iNbColumn : nombre de colonne de la matrice
   */
  MatrixP(int iNbRow, int iNbColumn);

  /** Destructeur */
  ~MatrixP();
  
  /**
   * Redimensionne la matrice en conservant les coefficients.
   * @param iNbRow    : Nouveau nombre de lignes de la matrice
   * @param iNbColumn : Nouveau nombre de colonnes de la matrice
   */
  void ReSize(int iNbRow, int iNbColumn);

  /** Retourne le nombre de lignes de la matrice */
  inline int GetNbOfRow();

  /** Retourne le nombre de colonnes de la matrice */
  inline int GetNbOfColumn();

  /**
   * Accès en lecture et en écriture aux coefficients
   * @param i : indice de la ligne
   * @param j : indice la colonne
   */
  inline T*& operator()(int i, int j);
  inline const T*& operator()(int i, int j)const;

  /** Affichage de la matrice en console */
  void Print();


private:
  int _NbRow;     // Nombre de lignes de la matrice
  int _NbColumn;  // Nombre de colonnes de la matrice
  T **_apTab;      // Tableau des coefficient de la matrice

};



//==============================================================================
// Implémentation des méthodes
//==============================================================================
template <class T>
MatrixP<T>::MatrixP()
: _NbRow(0),
  _NbColumn(0),
  _apTab(0)
{
}


template <class T>
MatrixP<T>::MatrixP(int iNbRow, int iNbColumn)
: _NbRow(iNbRow),
  _NbColumn(iNbColumn),
  _apTab(0)
{
  int SizeOfTab = _NbRow*_NbColumn;
  if (SizeOfTab) {
    _apTab=new T*[SizeOfTab];
    memset(_apTab, 0, SizeOfTab*sizeof(T*));
  }
}


template <class T>
MatrixP<T>::~MatrixP()
{
  _NbRow = 0;
  _NbColumn = 0;
  if (_apTab)
    delete [] _apTab; _apTab = 0;
}


template <class T>
void MatrixP<T>::ReSize(int iNbRow, int iNbColumn)
{
  int SizeOfTab = iNbRow*iNbColumn;
  if (SizeOfTab) {
    T ** aNewTab=new T*[SizeOfTab];
    memset(aNewTab, 0, SizeOfTab*sizeof(T*));
    
    int minColumn = iNbColumn < _NbColumn ? iNbColumn : _NbColumn;
    for (int i=1; i<=iNbRow && i<=_NbRow; i++) {
      memcpy(aNewTab+iNbColumn*(i-1), _apTab+_NbColumn*(i-1), minColumn*sizeof(T*));
    }
    if (_apTab)
      delete [] _apTab;
    _apTab = aNewTab;
    _NbRow = iNbRow;
    _NbColumn = iNbColumn;
  }
  else
  {
    _NbRow = 0;
    _NbColumn = 0;
    if (_apTab)
      delete [] _apTab; _apTab = 0;
  }
}


template <class T>
inline int MatrixP<T>::GetNbOfRow()
{
  return _NbRow;
}

template <class T>
inline int MatrixP<T>::GetNbOfColumn()
{
  return _NbColumn;
}

template <class T>
inline T*& MatrixP<T>::operator()(int i, int j)
{
  assert(0<i && i<=_NbRow && 0<j && j<=_NbColumn);
  return _apTab[_NbColumn*(i-1)+(j-1)];
}

template <class T>
inline const T*& MatrixP<T>::operator()(int i, int j)const
{
  assert(0<i && i<=_NbRow && 0<j && j<=_NbColumn);
  return _apTab[_NbColumn*(i-1)+(j-1)];
}


template <class T>
void MatrixP<T>::Print()
{
  for(int i=0; i<_NbRow; i++)
  {
    for(int j=0; j<_NbColumn; j++)
      std::cout << (_apTab[_NbColumn*i+j] ? 1 : 0) << "\t";
    std::cout << std::endl;
  }
}


