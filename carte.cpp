/*  INF3105 - Structures de données et algorithmes
 *  UQAM / Département d'informatique
 *  Automne 2014
 *  Squelette pour le TP3
 *  Auteurs: Lysanne Chagnon (CHAL65550003) et Oswald Essongué (ESSO16019809)
*/

#include "carte.h"
#include "monceau.h"
#include "noeud_prioritaire.h"
#include <limits>
#include <unordered_map>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;


void Carte::ajouterLieu(const string& nomlieu, const Coordonnee& c){
    noeuds[nomlieu].position = c;
}

void Carte::ajouterRoute(const string& nomroute, const list<string>& route){
    Voisin voisin;
    voisin.nom_route = nomroute;
    string noeud_precedent = route.front();
    string noeud_courant;
    for(auto it = route.begin(); it != route.end();it++){

        if(it != route.begin()){
            noeud_courant = *it;
            voisin.distance = noeuds[noeud_precedent].position.distance(noeuds[noeud_courant].position);
            noeuds[noeud_precedent].voisins[noeud_courant] = voisin;
            noeud_precedent = noeud_courant;
        }

    }

}



double Carte::calculerTrajet(const string& nomorigine, const list<string>& nomsdestinations, 
                             std::list<string>& out_cheminnoeuds, std::list<string>& out_cheminroutes) const
{
    string position = nomorigine;
    double total = 0;
    list<string> chemin_noeuds_temp;
    double total_bon = 0;

    list<string> dest = nomsdestinations;
    dest.sort();
    // Teste toutes les combinaisons possibles de chemin
    do{
        position = nomorigine;
        total = 0;
        chemin_noeuds_temp.clear();
        // Teste un chemin
        for(list<string>::const_reverse_iterator iter=dest.rbegin();iter!=dest.rend();++iter){
            total += calculerChemin(*iter, position, chemin_noeuds_temp, out_cheminroutes);
            position = *iter;
	        if(total_bon != 0 && total > total_bon)	break;
        }
        total += calculerChemin(nomorigine, position, chemin_noeuds_temp, out_cheminroutes);

        if(total_bon == 0 || total < total_bon){
            total_bon = total;
            out_cheminnoeuds = chemin_noeuds_temp;
        }

    }while(next_permutation(dest.begin(),dest.end()));
    
    out_cheminnoeuds.push_front(nomorigine);

    // fonction ajouter routes dans liste
    enregistrerCheminRoute(out_cheminnoeuds,out_cheminroutes);

   return total_bon;
}

double Carte::calculerChemin(const string& nomorigine, const string& nomdestination,
                             std::list<string>& out_cheminnoeuds, std::list<string>& out_cheminroutes) const
{
    // utilise l'algorithme A*
    Coordonnee position_destination = noeuds.at(nomdestination).position;
    unordered_map<string,double> distance_noeuds;
    unordered_map<string,string> parent_noeuds;
    distance_noeuds[nomorigine] = 0;
    parent_noeuds[nomorigine] = "";
    Noeud_Prioritaire noeud1;
    noeud1.nom_noeud = nomorigine;
    noeud1.distance = distance_noeuds[nomorigine];
    Monceau<Noeud_Prioritaire> file_prioritaire;
    file_prioritaire.inserer(noeud1);

    while(!file_prioritaire.estVide()){
        noeud1 = file_prioritaire.minimum();
        file_prioritaire.enleverMinimum();
        string nom = noeud1.nom_noeud;
        double dist_noeud1 = distance_noeuds[nom];
        if(nom.compare(nomdestination) == 0)    break;
        double d;
        for(auto n1 = noeuds.at(nom).voisins.begin(); n1 != noeuds.at(nom).voisins.end();n1++){
            // d = distance noeud dans la file prioritaire + distance entre noeud et voisins(itérateur)
            d = dist_noeud1 + n1->second.distance;

            if(!distance_noeuds.count(n1->first) || d < distance_noeuds[n1->first]){
                distance_noeuds[n1->first] = d;
                parent_noeuds[n1->first] = nom;

                // Ajout dans la file prioritaire du noeud modifié
                noeud1.nom_noeud = n1->first;
                noeud1.distance = distance_noeuds[n1->first] + (noeuds.at(n1->first).position).distance(position_destination);
                file_prioritaire.inserer(noeud1);
            }
        }
    }
    // fonction qui modifie la liste de noeuds pour le chemin
    enregistrerCheminNoeud(nomorigine,nomdestination,out_cheminnoeuds,parent_noeuds);

    return distance_noeuds[nomdestination];

}

void Carte::enregistrerCheminNoeud(const string& origine, const string& destination,
                             std::list<string>& out_cheminnoeuds, unordered_map<string,string>& parent_noeuds) const{
    string noeud_courant = destination;
    string noeud_precedent = parent_noeuds.at(noeud_courant);
    while(noeud_courant != origine){
        out_cheminnoeuds.push_front(noeud_courant);
        noeud_courant = noeud_precedent;
        noeud_precedent = parent_noeuds.at(noeud_courant);
    }
}

void Carte::enregistrerCheminRoute(std::list<string>& out_cheminnoeuds, std::list<string>& out_cheminroutes) const{
    string noeud_courant;
    string noeud_precedent;
    string nom_route; // le nom de la route courante
    string fin_route; // la dernière route ajoutée
    for(list<string>::const_iterator iter=out_cheminnoeuds.begin();iter!=out_cheminnoeuds.end();++iter){
        if(iter == out_cheminnoeuds.begin()){
            noeud_precedent = *iter;
        }else{
            noeud_courant = *iter;
            nom_route = noeuds.at(noeud_precedent).voisins.at(noeud_courant).nom_route;
            if(out_cheminroutes.empty() || fin_route.compare(nom_route)){
                out_cheminroutes.push_back(nom_route);
                fin_route = nom_route;
            }
            noeud_precedent = noeud_courant;
        }
    }
}

/* Lire une carte. */
istream& operator >> (istream& is, Carte& carte)
{
    // Lire les lieux
    while(is){
        string nomlieu;
        is >> nomlieu;
        if(nomlieu == "---") break;
        Coordonnee coor;
        is >> coor;       
        carte.ajouterLieu(nomlieu, coor);
    }

    // Lire les routes
    while(is){
        string nomroute;
        is >> nomroute;
        if(nomroute == "---" || nomroute=="" || !is) break;
        
        char deuxpoints;
        is >> deuxpoints;
        assert(deuxpoints == ':');
        
        std::list<std::string> listenomslieux;

        string nomlieu;        
        while(is){
            is>>nomlieu;
            if(nomlieu==";") break;
            assert(nomlieu!=":");
            assert(nomlieu.find(";")==string::npos);
            listenomslieux.push_back(nomlieu);
        }
        
        assert(nomlieu==";");
        carte.ajouterRoute(nomroute, listenomslieux);
    }
    
    return is;
}

ostream& operator << (ostream& os, Carte& carte){


    for(auto it = carte.noeuds.begin(); it != carte.noeuds.end(); it++){
        os << it->first + " ";
        os << it->second.position;
        os << " [";
        for(auto it1 = it->second.voisins.begin(); it1 != it->second.voisins.end(); it1++){

            os << it1->first + " " + it1->second.nom_route + " ";
            os << it1->second.distance;
            os << ", ";

        }

        os << "], \n";
    }


    return os;
}
