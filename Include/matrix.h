//==============================================================================
// 
// Class Matrix:
//   Cette classe implémente un template de matrice.
// Les coefficients des lignes et des colonnes comment à 1.
//
//==============================================================================

#pragma once

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>

template <class T>
class Matrix
{

public:
  /** Constructeur par défaut*/
  Matrix();

  /**
   * Constructeur à partir de la taille de la Matrix
   * @param iNbRow : nombre de lignes de la Matrix
   * @param iNbColumn : nombre de colonne de la Matrix
   */
  Matrix(int iNbRow, int iNbColumn);

  /** Constructeur à partir d'un fichier texte */
  Matrix(std::string iFile);

  /** Destructeur */
  ~Matrix();

  /** Retourne le nombre de lignes de la matrice */
  inline int GetNbOfRow();

  /** Retourne le nombre de colonnes de la matrice */
  inline int GetNbOfColumn();

  /**
   * Accès en lecture et en écriture aux coefficients
   * @param i : indice de la ligne
   * @param j : indice la colonne
   */
  inline T& operator()(int i, int j);
  inline const T& operator()(int i, int j)const;

  /** Afficahge de la matrice en console */
  void Affiche();


private:
  int _NbRow;     // Nombre de lignes de la Matrix
  int _NbColumn;  // Nombre de colonnes de la Matrix
  T *_aTab;       // Tableau des coefficient de la Matrix

};



//==============================================================================
// Implémentation des méthodes
//==============================================================================
template <class T>
Matrix<T>::Matrix()
: _NbRow(0),
  _NbColumn(0),
  _aTab(0)
{
}


template <class T>
Matrix<T>::Matrix(int iNbRow, int iNbColumn)
: _NbRow(iNbRow),
  _NbColumn(iNbColumn),
  _aTab(0)
{
  int SizeOfTab = _NbRow*_NbColumn;
  if (SizeOfTab) {
    _aTab=new T[SizeOfTab];
    memset(_aTab, 0, SizeOfTab*sizeof(T));
  }
}

template <class T>
Matrix<T>::Matrix(std::string iFile)
: _NbRow(0),
  _NbColumn(0),
  _aTab(0)
{
  /*
  std::ifstream fichier(nom.c_str(), std::ios::in);
  if(fichier)
  {
    fichier >> ligne >> colonne;
    tab=new double[ligne*colonne];
    for(int i=0; i<ligne*colonne; i++)
    {
      double coef;
      fichier >> coef;
      tab[i]=coef;
    }
    fichier.close();  // on ferme le fichier
  }
  else
    std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
  */
}

template <class T>
Matrix<T>::~Matrix()
{
  _NbRow = 0;
  _NbColumn = 0;
  if (_aTab)
    delete [] _aTab; _aTab = 0;
}

template <class T>
inline int Matrix<T>::GetNbOfRow()
{
  return _NbRow;
}

template <class T>
inline int Matrix<T>::GetNbOfColumn()
{
  return _NbColumn;
}

template <class T>
inline T& Matrix<T>::operator()(int i, int j)
{
  return _aTab[_NbColumn*(i-1)+(j-1)];
}

template <class T>
inline const T& Matrix<T>::operator()(int i, int j)const
{
  return _aTab[_NbColumn*(i-1)+(j-1)];
}

template <class T>
void Matrix<T>::Affiche()
{
  for(int i=0; i<_NbRow; i++)
  {
    for(int j=0; j<_NbColumn; j++)
      std::cout << _aTab[_NbColumn*i+j] << "\t";
    std::cout << std::endl;
  }
}


