/**
* @file B171210007_1A_FinalÖdevi
* @description Dugum sınıfı kaynak dosyası
* @course 1. Öğretim A Grubu
* @assignment Final Ödevi
* @date 1.09.2020
* @author Davud Samed Tombul
*/
#include "Dugum.hpp"
#include <iostream>

Dugum::Dugum(Kisi *kisi, Dugum *_right, Dugum *_left)
{
	//dugum kurucusu
	this->kisi = kisi;
	this->_left = nullptr;
	this->_right = nullptr;
	this->stack = new Stack();
	this->stack->Push("O");
	yukseklik = 0; //Düğüm yüksekliği kurucu fonksiyonda başlangıç değeri olarak 0 alıyor.
}

Dugum::~Dugum()//Çöp oluşmasını engellemek amacıyla yıkıcı fonksiyonda çöpler temizleniyor.
{
	this->stack->Clear();
	delete (this->stack);
	delete (this->kisi);
}
