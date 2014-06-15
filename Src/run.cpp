#include "run.h"
#include "matrix.h"
#include <iostream>
using namespace std;

void run(int argc, char *argv[])
{
  cout << "hello !" << endl;

  for (int i=1; i<argc; i++)
  {
    if (string(argv[i])=="test")
      RunTest();
  }

  return;
}


int RunTest()
{
  // Test sur la classe matrice
  cout << "========================================" << endl;
  cout << " Test sur la classe matrice"              << endl;
  cout << "========================================" << endl;
  Matrix<int> M(2, 3);
  for (int i=1; i<=3; i++)
  {
    M(1,i)=i+1;
  }
  M(2,3)=10;
  M.Affiche();
  
  return 0;
}


