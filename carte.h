/*  INF3105 - Structures de données et algorithmes
 *  UQAM / Département d'informatique
 *  Automne 2014
 *  Squelette pour le TP3
 *  Auteurs: Lysanne Chagnon (CHAL65550003) et Oswald Essongué (ESSO16019809)
*/

#ifndef CARTE_HEADER
#define CARTE_HEADER
#include <assert.h>
#include <istream>
#include <list>
#include <string>
#include <unordered_map>
#include "coordonnee.h"
using namespace std;

class Carte{
  public:
    void ajouterLieu(const string& nom, const Coordonnee& c);
    void ajouterRoute(const string& nom, const list<string>& noms);

    double calculerTrajet(const string& origine, const list<string>& destination, 
                          std::list<string>& out_cheminnoeuds, std::list<string>& out_cheminroutes) const;
    double calculerChemin(const string& origine, const string& destination,
                             std::list<string>& out_cheminnoeuds, std::list<string>& out_cheminroutes) const;

    /**
     * Il s'agit de mettre les noeuds dans le cheminnoeuds
     * @param origine le noeud d'origine
     * @param destination le noeud de destination
     * @param out_cheminnoeuds la liste ou chemin des noeuds
     * @param parent_noeuds l'arbremap contenant les parents des noeuds
     */
    void enregistrerCheminNoeud(const string& origine, const string& destination,
                             std::list<string>& out_cheminnoeuds, unordered_map<string,string>& parent_noeuds) const;

    /**
     * Il s'agit de mettre les routes dans le cheminroutes
     * @param out_cheminroutes la liste ou chemin des routes
     * @param out_cheminnoeuds la liste ou chemin des noeuds
     */                     
    void enregistrerCheminRoute(std::list<string>& out_cheminnoeuds, std::list<string>& out_cheminroutes) const;

    
  private:
    struct Voisin{
      double distance;
      string nom_route;
    };
    struct Noeud{
      Coordonnee position;
      unordered_map<string,Voisin> voisins;
    };
    unordered_map<string,Noeud> noeuds;

  friend istream& operator >> (istream& is, Carte& carte);
  friend ostream& operator << (ostream& os, Carte& carte);
};

#endif

