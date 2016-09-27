#include <iostream>
#include <string>
using namespace std;

int main()
{
  cout << "Combien vaut pi ?" << endl;
  double piUtilisateur(-1.); //On crée une case mémoire pour stocker un nombre réel
  cin >> piUtilisateur; //Et on remplit cette case avec ce qu'écritl'utilisateur
  cin.ignore();

  cout << "Quel est votre prenom ?" << endl;
  string nomUtilisateur("Sans nom"); //On crée une case mémoire pour contenirune chaine de caractères
  getline(cin, nomUtilisateur);

  cout << "Vous vous appelez " << nomUtilisateur << " et vous pensez que pivaut " << piUtilisateur << "." << endl;

  return 0;
}
