#include "run.h"
#include "MatrixV.h"
#include "MatrixP.h"
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
  
  // Test sur la classe MatrixV
  cout << "#=======================================" << endl;
  cout << "# Test sur la classe MatrixV"             << endl;
  cout << "#=======================================" << endl;
  TestMatriceV();

  // Test sur la classe MatrixV
  cout << "#=======================================" << endl;
  cout << "# Test sur la classe MatrixP"             << endl;
  cout << "#=======================================" << endl;
  TestMatriceP();

  return 0;
}


int TestMatriceV()
{
  cout << "# Création par ligne de code" << endl;
  MatrixV<int> M1(2, 3);
  for (int i=1; i<=3; i++)
  {
    M1(1,i)=i+1;
  }
  M1(2,3)=10;
  M1.Print();
  cout << endl; 
  
  cout << "# Création à partir d'un fichier" << endl;
  MatrixV<double> M2("Test/Input/MatriceToRead");
  M2.Print();
  cout << endl;
  
  cout << "# Redimensionnement de matrice" << endl;
  M2.ReSize(6,7);
  M2.Print();
  cout << endl;
  M2.ReSize(3,2);
  M2.Print();
  cout << endl;
  
  return 0;
}

struct Point2D
{
  int x,y;
  Point2D(): x(0), y(0) {};
  Point2D(int x0, int y0): x(x0), y(y0) {};
};

int TestMatriceP()
{ 
  cout << "# Création par ligne de code" << endl;
  MatrixP<Point2D> M1(2, 3);
  for (int i=1; i<=3; i++)
  {
    M1(1,i)=new Point2D(i+1,0);
  }
  M1(2,3)=new Point2D(10, 5);
  M1.Print();
  for (int i=1; i<=2; i++)
  {
    for (int j=1; j<=3; j++) {
      if (M1(i,j))
        cout << "(" << M1(i,j)->x << "," << M1(i,j)->y << ")\t";
      else
        cout << "NoPoint\t";
    }
    cout << endl;
  }
  cout << endl; 
  
  M1.DeleteAll();
  
  return 0;
}


