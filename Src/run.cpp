#include "run.h"
#include "Constantes.h"
#include "MatrixV.h"
#include "MatrixP.h"
#include <iostream>
#include <math.h>
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
  cout << "Arguments de l'excecutable" << endl;
  cout << "-h ou -help: Affiche l'aide" << endl;
  cout << "-test      : Lance l'ensemble des tests" << endl;
}


int RunTest()
{
  int ToReturn = 0;
  int TestResult = 0;

  // Test de l'affichage de l'aide
  cout << "#=======================================" << endl;
  cout << "# Test de l'affichage de l'aide"          << endl;
  cout << "#=======================================" << endl;
  PrintArguments();
  cout << endl;
  
  
  // Test sur la classe MatrixV
  cout << "#=======================================" << endl;
  cout << "# Test sur la classe MatrixV"             << endl;
  cout << "#=======================================" << endl;
  ToReturn=TestMatriceV();
 
  
  // Test sur la classe MatrixV
  cout << "#=======================================" << endl;
  cout << "# Test sur la classe MatrixP"             << endl;
  cout << "#=======================================" << endl;
  TestResult=TestMatriceP();
  ToReturn+=TestResult;

  
  cout << "#=======================================" << endl;
  if (ToReturn)
    cout << "# Il y a " << ToReturn << " tests KO."    << endl;
  else
    cout << "# Tous les tests sont OK."                << endl;
  cout << "#=======================================" << endl;
  
  return ToReturn;
}


int TestMatriceV()
{
  int ToReturn = 0;
  
  cout << "# Creation par ligne de code" << endl;
  MatrixV<int> M1(2, 3);
  for (int i=1; i<=3; i++)
  {
    M1(1,i)=i+1;
  }
  M1(2,3)=10;
  M1.Print();
  cout << endl; 
  
  cout << "# Creation a partir d'un fichier" << endl;
  MatrixV<double> M2("Test/Input/MatriceToRead");
  M2.Print();
  cout << endl;
  
  cout << "# Constructeur par copie et extraction" << endl;
  MatrixV<double> M3(&M2);
  cout << "# Suppression ligne 3 colonne 2" << endl;
  M3.ExtractMineur(3,2);
  if ( fabs(M3(1,1)-1.5)>DoubleTol || fabs(M3(1,2)-6) >DoubleTol || fabs(M3(1,3)-18)>DoubleTol ||
       fabs(M3(2,1)-5)  >DoubleTol || fabs(M3(2,2)-7) >DoubleTol || fabs(M3(2,3)-8) >DoubleTol ||
       fabs(M3(3,1)-2)  >DoubleTol || fabs(M3(3,2)-19)>DoubleTol || fabs(M3(3,3)-17)>DoubleTol ||
       fabs(M3(4,1)-19) >DoubleTol || fabs(M3(4,2)-4) >DoubleTol || fabs(M3(4,3)-8) >DoubleTol   )
    ToReturn++;
  M3.Print();
  cout << endl;
  
  cout << "# Suppression ligne 1 colonne 1" << endl;
  M3.ExtractMineur(1,1);
  if ( fabs(M3(1,1)-7) >DoubleTol || fabs(M3(1,2)-8) >DoubleTol ||
       fabs(M3(2,1)-19)>DoubleTol || fabs(M3(2,2)-17)>DoubleTol ||
       fabs(M3(3,1)-4) >DoubleTol || fabs(M3(3,2)-8) >DoubleTol   )
    ToReturn++;
  M3.Print();
  cout << endl;
  
  cout << "# Redimensionnement de matrice" << endl;
  M2.ReSize(6,7);
  M2.Print();
  cout << endl;
  M2.ReSize(3,2);
  if ( fabs(M2(1,1)-1.5)>DoubleTol || fabs(M2(1,2)-7) >DoubleTol ||
       fabs(M2(2,1)-5)  >DoubleTol || fabs(M2(2,2)-6) >DoubleTol ||
       fabs(M2(3,1)-8)  >DoubleTol || fabs(M2(3,2)-15)>DoubleTol   )
    ToReturn++;
  M2.Print();
  cout << endl;
  
  cout << "# Test sur la classe MatrixV : " << ToReturn << " KO" << endl;
  cout << "#=======================================" << endl;
  cout << endl;
  
  return ToReturn ? 1 : 0;
}

struct Point2D
{
  int x,y;
  Point2D(): x(0), y(0) {};
  Point2D(int x0, int y0): x(x0), y(y0) {};
};

int TestMatriceP()
{  
  int ToReturn = 0;

  cout << "# Creation par ligne de code" << endl;
  MatrixP<Point2D> M1(2, 3);
  for (int i=1; i<=3; i++)
  {
    M1(1,i)=new Point2D(i+1,0);
  }
  M1(2,3)=new Point2D(10, 5);
  M1.Print();
  cout << endl;
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

  if (M1(1,1)==0 || M1(1,2)==0 || M1(1,3)==0 ||
      M1(2,1)!=0 || M1(2,2)!=0 || M1(2,3)==0  )
    ToReturn++;
  else if( M1(1,1)->x!=2  || M1(1,1)->y!=0 ||
           M1(1,2)->x!=3  || M1(1,2)->y!=0 ||
           M1(1,3)->x!=4  || M1(1,3)->y!=0 ||
           M1(2,3)->x!=10 || M1(2,3)->y!=5 )
    ToReturn++;

  M1.DeleteAll();
    
  cout << "# Test sur la classe MatrixP : " << ToReturn << " KO" << endl;
  cout << "#=======================================" << endl;
  cout << endl;
  
  return ToReturn;
}


