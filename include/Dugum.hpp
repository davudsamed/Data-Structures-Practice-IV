/**
* @file B171210007_1A_FinalÖdevi
* @description Dugum sınıfı başlık dosyası
* @course 1. Öğretim A Grubu
* @assignment Final Ödevi
* @date 1.09.2020
* @author Davud Samed Tombul
*/
#ifndef DUGUM_HPP
#define DUGUM_HPP

#include "Kisi.hpp"
#include "Stack.hpp"

#include <iostream>

class Dugum
{
public:
	Stack *stack;
	Kisi *kisi;
	Dugum *_left;
	Dugum *_right;
	int yukseklik;

	int derinlik = 0;

	Dugum(Kisi *kisi, Dugum *_right = nullptr, Dugum *_left = nullptr);
	~Dugum();
};
#endif