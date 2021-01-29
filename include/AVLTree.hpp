/**
* @file B171210007_1A_FinalÖdevi
* @description AVLTree sınıfı başlık dosyası
* @course 1. Öğretim A Grubu
* @assignment Final Ödevi
* @date 1.09.2020
* @author Davud Samed Tombul
*/
#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include "Dugum.hpp"
#include "Kisi.hpp"
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

class AVLTree
{
public:
	Dugum *root;
	Dugum *AraveEkle(Dugum *, Kisi *);
	Dugum *SolChildIleDegistir(Dugum *);
	Dugum *SagChildIleDegistir(Dugum *);
	void Postorder(Dugum *) const;
	void LevelYaz(Dugum *, int) const;
	int Yukseklik(Dugum *) const;
	bool DeleteDugum(Dugum *&);
	void Derinlik_Guncelle(Dugum *, int, int);
	AVLTree();
	bool Bosmu() const;
	void Ekle(Kisi *);
	void Postorder() const;
	void Levelorder() const;
	void Temizle();
	int Yukseklik() const;
	int deger;

	~AVLTree();
};
#endif