/*  INF3105 - Structures de données et algorithmes
    UQAM | Faculté des sciences | Département d'informatique
    Lab13 -- http://ericbeaudry.uqam.ca/INF3105/lab13/
    © Jaël Champagne Gareau (champagne_gareau.jael@uqam.ca)
 */
#ifndef MONCEAU_H
#define MONCEAU_H

#include <vector>
#include <utility>
#include <cassert>

using namespace std;

template <class T>
class Monceau {
  public:
    void inserer(const T&);
    const T& minimum() const;
    void enleverMinimum();
    bool estVide() const;

  private:
    vector<T> tab;
    int parent(int indice) const{return (indice - 1)/2;}
    int enfant1(int indice) const { return 2*indice+1; }
    int enfant2(int indice) const { return 2*indice+2; }
    void remonter(int);
    void echanger(T&, T&);
    void descendre(int);
};


template <class T>
const T& Monceau<T>::minimum() const{
  assert(!estVide()); 
  return tab[0];
}

template <class T>
bool Monceau<T>::estVide() const{
  return tab.empty();
}

template <class T>
void Monceau<T>::inserer(const T& element){
  int indice = tab.size();
  tab.push_back(element);
  remonter(indice);
}

template <class T>
void Monceau<T>::remonter(int indice){
  if(indice == 0) return;
  int p = parent(indice);
  if(tab[indice] < tab[p]){
    echanger(tab[indice], tab[p]);
    remonter(p);
  }
}

template<class T>
void Monceau<T>::echanger(T& a, T& b){
  T temp = a;
  a = b;
  b = temp;
}

template <class T>
void Monceau<T>::enleverMinimum(){
  // replace first element by last
  tab[0] = tab[tab.size() - 1];
  // delete last element
  tab.pop_back();
  descendre(0);
}

template <class T>
void Monceau<T>::descendre(int indice){
  size_t suivant = enfant1(indice);
  if(suivant >= tab.size()) return;
  size_t tmp = suivant + 1;
  if(tmp < tab.size() && tab[tmp] < tab[suivant]){
    suivant++;
  }
  if(tab[suivant] < tab[indice]){
    echanger(tab[suivant], tab[indice]);
    descendre(suivant);
  }
}

#endif
