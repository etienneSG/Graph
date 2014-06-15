#include "run.h"
#include "matrix.h"
#include <iostream>
using namespace std;

void run(int argc, char *argv[])
{
  for (int i=1; i<argc; i++)
  {
    if (string(argv[i])=="-h" || string(argv[i])=="-help")
      PrintArguments();
    else if (string(argv[i])=="-test")
      RunTest();
  }

  return;
}


void PrintArguments()
{
  cout << "Arguments de l'excécutable" << endl;
  cout << "-h ou -help: Affiche l'aide" << endl;
  cout << "-test      : Lance l'ensemble des tests" << endl;
}


int RunTest()
{
  // Test de l'affichage de l'aide
  cout << "#=======================================" << endl;
  cout << "# Test de l'affichage de l'aide"          << endl;
  cout << "#=======================================" << endl;
  PrintArguments();
  
  // Test sur la classe matrice
  cout << "#=======================================" << endl;
  cout << "# Test sur la classe matrice"             << endl;
  cout << "#=======================================" << endl;
  TestMatrice();
  
  return 0;
}


int TestMatrice()
{
  cout << "# Création par ligne de code" << endl;
  Matrix<int> M1(2, 3);
  for (int i=1; i<=3; i++)
  {
    M1(1,i)=i+1;
  }
  M1(2,3)=10;
  M1.Affiche();
  cout << endl; 
  
  cout << "# Création à partir d'un fichier" << endl;
  Matrix<double> M2("Test/Input/MatriceToRead");
  M2.Affiche();
  cout << endl;
  
  return 0;
}




