/**
 * Classe qui va servir pour les files prioritaires avec des noeuds
 * 
 *  Auteurs: Lysanne Chagnon (CHAL65550003) et Oswald Essongué (ESSO16019809)
 */

#include <string>

using namespace std;

class Noeud_Prioritaire{
  public:

    string nom_noeud;
    double distance;
    
    bool operator< (const Noeud_Prioritaire& n){
      return distance < n.distance;
    }

    bool operator> (const Noeud_Prioritaire& n){
      return distance > n.distance;
    }
    
};