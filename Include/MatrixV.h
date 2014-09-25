//==============================================================================
// 
// Class MatrixV:
//   Cette classe implémente un template de matrice par valeurs.
// Les coefficients des lignes et des colonnes comment à 1.
// Les coefficient de la matrice sont des valeurs.
//
//==============================================================================

#ifndef MATRIXV_H
#define MATRIXV_H

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <assert.h>

template <class T>
class MatrixV
{

public:
  /** Constructeur par défaut*/
  MatrixV();

  /**
   * Constructeur à partir de la taille de la matrice
   * @param iNbRow    : nombre de lignes de la matrice
   * @param iNbColumn : nombre de colonne de la matrice
   */
  MatrixV(int iNbRow, int iNbColumn);

  /** Constructeur à partir d'un fichier texte */
  MatrixV(std::string iFile);
  
  /** Constructeur par copie */
  MatrixV(MatrixV* iMatrixV);

  /** Destructeur */
  ~MatrixV();
  
  /**
   * Redimensionne la matrice en conservant les coefficients.
   * @param iNbRow    : Nouveau nombre de lignes de la matrice
   * @param iNbColumn : Nouveau nombre de colonnes de la matrice
   */
  void ReSize(int iNbRow, int iNbColumn);

  /**
   * Supprime une ligne et une colonne de la matrice.
   * @param iRow    : numéro de la ligne à supprimer
   * @param iColumn : numéro de la colonne à supprimer
   */
  void ExtractMineur(int iRow, int iColumn);
  
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

  /** Affichage de la matrice en console */
  void Print();


private:
  int _NbRow;     // Nombre de lignes de la matrice
  int _NbColumn;  // Nombre de colonnes de la matrice
  T *_aTab;       // Tableau des coefficient de la matrice

};


//==============================================================================
// Implémentation des méthodes
//==============================================================================
template <class T>
MatrixV<T>::MatrixV()
: _NbRow(0),
  _NbColumn(0),
  _aTab(0)
{
}


template <class T>
MatrixV<T>::MatrixV(int iNbRow, int iNbColumn)
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
MatrixV<T>::MatrixV(std::string iFile)
: _NbRow(0),
  _NbColumn(0),
  _aTab(0)
{
  std::ifstream fichier(iFile.c_str(), std::ios::in);
  if(fichier)
  {
    fichier >> _NbRow >> _NbColumn;
    int SizeOfTab = _NbRow*_NbColumn;
    if (SizeOfTab)
    {
      _aTab=new T[SizeOfTab];
      memset(_aTab, 0, SizeOfTab*sizeof(T));
      for(int i=0; i<SizeOfTab; i++)
      {
        T coef;
        fichier >> coef;
        _aTab[i]=coef;
      }
    }
    fichier.close();  // on ferme le fichier
  }
  else
    std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
}


template <class T>
MatrixV<T>::MatrixV(MatrixV* iMatrixV)
: _NbRow(0),
  _NbColumn(0),
  _aTab(0)
{
  if (iMatrixV)
  {
    _NbRow = iMatrixV->_NbRow;
    _NbColumn = iMatrixV->_NbColumn;
    
    int SizeOfTab = _NbRow*_NbColumn;
    if (SizeOfTab) {
      _aTab=new T[SizeOfTab];
      memcpy(_aTab, iMatrixV->_aTab, SizeOfTab*sizeof(T));
    }
  }
}


template <class T>
MatrixV<T>::~MatrixV()
{
  _NbRow = 0;
  _NbColumn = 0;
  if (_aTab)
    delete [] _aTab; _aTab = 0;
}


template <class T>
void MatrixV<T>::ReSize(int iNbRow, int iNbColumn)
{
  int SizeOfTab = iNbRow*iNbColumn;
  if (SizeOfTab) {
    T * aNewTab=new T[SizeOfTab];
    memset(aNewTab, 0, SizeOfTab*sizeof(T));
    
    int minColumn = iNbColumn < _NbColumn ? iNbColumn : _NbColumn;
    for (int i=1; i<=iNbRow && i<=_NbRow; i++) {
      memcpy(aNewTab+iNbColumn*(i-1), _aTab+_NbColumn*(i-1), minColumn*sizeof(T));
    }
    if (_aTab)
      delete [] _aTab;
    _aTab = aNewTab;
    _NbRow = iNbRow;
    _NbColumn = iNbColumn;
  }
  else
  {
    _NbRow = 0;
    _NbColumn = 0;
    if (_aTab)
      delete [] _aTab; _aTab = 0;
  }
}


template <class T>
void MatrixV<T>::ExtractMineur(int iRow, int iColumn)
{
  if ( !(1<=iRow && iRow<=_NbRow && 1<=iColumn && iColumn<=_NbColumn) )
    return;

  // Pour éviter une erreur du au recouvrement lors de la copie
  for(int j=iColumn; j<_NbColumn; j++)
    memcpy(_aTab+j-1, _aTab+j, sizeof(T));
  for (int i=2; i<iRow; i++) {
    for(int j=0; j<iColumn; j++)
      memcpy(_aTab+(_NbColumn-1)*(i-1)+j, _aTab+_NbColumn*(i-1)+j, sizeof(T));
    for(int j=iColumn; j<_NbColumn; j++)
      memcpy(_aTab+(_NbColumn-1)*(i-1)+j-1, _aTab+_NbColumn*(i-1)+j, sizeof(T));
  }
  for (int i=iRow+1; i<=_NbRow; i++) {
    memcpy(_aTab+(_NbColumn-1)*(i-2), _aTab+_NbColumn*(i-1), (iColumn-1)*sizeof(T));
    memcpy(_aTab+(_NbColumn-1)*(i-2)+iColumn-1, _aTab+_NbColumn*(i-1)+iColumn, (_NbColumn-iColumn)*sizeof(T));
  }
  _NbColumn = _NbColumn - 1;
  _NbRow = _NbRow - 1;
  
}


template <class T>
inline int MatrixV<T>::GetNbOfRow()
{
  return _NbRow;
}

template <class T>
inline int MatrixV<T>::GetNbOfColumn()
{
  return _NbColumn;
}

template <class T>
inline T& MatrixV<T>::operator()(int i, int j)
{
  assert(0<i && i<=_NbRow && 0<j && j<=_NbColumn);
  return _aTab[_NbColumn*(i-1)+(j-1)];
}

template <class T>
inline const T& MatrixV<T>::operator()(int i, int j)const
{
  assert(0<i && i<=_NbRow && 0<j && j<=_NbColumn);
  return _aTab[_NbColumn*(i-1)+(j-1)];
}


template <class T>
void MatrixV<T>::Print()
{
  for(int i=0; i<_NbRow; i++)
  {
    for(int j=0; j<_NbColumn; j++)
      std::cout << _aTab[_NbColumn*i+j] << "\t";
    std::cout << std::endl;
  }
}


#endif

