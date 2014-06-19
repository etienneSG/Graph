//==============================================================================
//
// Lancement du programme
//
// Argument -h ou -help pour afficher les paramètres possibles
// (Modifier la fonction PrintArguments() à chaque nouvel argument ajouté.)
//
//==============================================================================


#ifndef RUN_H
#define RUN_H


/** Lance le programme pour chacun des paramètres */
void run(int argc, char *argv[]);


/** Affiche les arguments possibles de l'excécutable */
void PrintArguments();


/**
 * Lance l'ensemble des test
 * @return : 0 si les tests ont réussi
 *           1 sinon
 */
int RunTest();


/** Tests sur les méthodes de la classe MatrixV */
int TestMatriceV();


/** Tests sur les méthodes de la classe MatrixP */
int TestMatriceP();

#endif

