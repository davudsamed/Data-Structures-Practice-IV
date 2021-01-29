/**
* @file B171210007_1A_FinalÖdevi
* @description AVLTree kaynak dosyası
* @course 1. Öğretim A Grubu
* @assignment Final Ödevi
* @date 1.09.2020
* @author Davud Samed Tombul
*/
#include "AVLTree.hpp"
#include "Kisi.hpp"
#include <iostream>

using namespace std;

Dugum *AVLTree::AraveEkle(Dugum *altNode, Kisi *yeniKisi)
{
	if (altNode == NULL) //root'un boş olduğu durumda yeni kök ekler
	{
		altNode = new Dugum(yeniKisi);
	}
	else if (yeniKisi->yas < altNode->kisi->yas) //Eklenecek yeni yaş küçükse _lefta eklenir.
	{
		altNode->_left = AraveEkle(altNode->_left, yeniKisi); //_left alt çocuk yerine yeni bir ağaç oluşturur

		if (Yukseklik(altNode->_left) - Yukseklik(altNode->_right) == 2)//yükseklik farkı ikiye eşitse dengeler
		{ 
			// _left _left Durumu
			if (yeniKisi->yas < altNode->_left->kisi->yas)
				altNode = SolChildIleDegistir(altNode); //tek dönüş
			else //_left Sağ Durumunda yapılması gerekenler.
			{ 
				altNode->_left = SagChildIleDegistir(altNode->_left); //çift dönüş
				altNode = SolChildIleDegistir(altNode);
			}
		}
	}
	else if (yeniKisi->yas > altNode->kisi->yas)
	{ //büyükse sağa ekler, sağ durumu
		altNode->_right = AraveEkle(altNode->_right, yeniKisi);

		if (Yukseklik(altNode->_right) - Yukseklik(altNode->_left) == 2)
		{
			if (yeniKisi->yas > altNode->_right->kisi->yas)	// Sağ Sağ Durumu
				altNode = SagChildIleDegistir(altNode); //Tek dönüş
			else
			{// Sağ _left Durumunda uygulanması gereken adımlar.
				altNode->_right = SolChildIleDegistir(altNode->_right); //çift dönüş
				altNode = SagChildIleDegistir(altNode);
			}
		}
	}
	else; 

	//Yüksekliği güncelle
	altNode->yukseklik = Yukseklik(altNode);
	return altNode;
}
Dugum *AVLTree::SolChildIleDegistir(Dugum *altNode) //AVL ağacındaki sağa dönüş gereken durumda kullanacağımız fonksiyon.
{
	Dugum *tmp = altNode->_left;
	altNode->_left = tmp->_right;
	tmp->_right = altNode;

	// Yükseklikleri Güncelle
	altNode->yukseklik = Yukseklik(altNode);
	tmp->yukseklik = max(Yukseklik(tmp->_left), altNode->yukseklik) + 1;

	return tmp;
}
Dugum *AVLTree::SagChildIleDegistir(Dugum *altNode) //Dengeleme gereken durumda _lefta dönüş yaptıracak fonksiyon.
{
	Dugum *tmp = altNode->_right;
	altNode->_right = tmp->_left;
	tmp->_left = altNode;

	// Yükseklik Güncellenir
	altNode->yukseklik = Yukseklik(altNode);
	tmp->yukseklik = max(Yukseklik(tmp->_right), altNode->yukseklik) + 1;

	return tmp;
}

void AVLTree::Postorder(Dugum *altNode) const
{
	if (altNode != NULL)
	{
		Postorder(altNode->_left);	//_left
		Postorder(altNode->_right);	//SAĞ
		cout << altNode->kisi->isim << ", " << altNode->kisi->dogumYili << ", " << altNode->kisi->kilo << "    "; //KÖK

		altNode->stack->StackYazdir(altNode->stack);
	}
}
void AVLTree::LevelYaz(Dugum *altNode, int seviye) const
{
	if (altNode == NULL)
		return;
	if (seviye == 0)
		cout << altNode->kisi->yas << " ";
	else
	{
		LevelYaz(altNode->_left, seviye - 1);
		LevelYaz(altNode->_right, seviye - 1);
	}
}
int AVLTree::Yukseklik(Dugum *altNode) const
{
	if (altNode == NULL)
		return -1; // Ortada düğüm yoksa yükseklik anlamsızdır. Kodun çalışması adına -1 verilmektedir.
	return 1 + max(Yukseklik(altNode->_left), Yukseklik(altNode->_right));
}

bool AVLTree::DeleteDugum(Dugum *&altNode)
{
	Dugum *silinecekDugum = altNode;

	if (altNode->_right == NULL) // Düğümün sağ çocuğu yoksa _left çocuğu yerine geçer
		altNode = altNode->_left;
	else if (altNode->_left == NULL) //_left çocuğu yoksa sağ çocuğu yerine geçer
		altNode = altNode->_right;
	else
	{ //iki çocuğu da varsa _leftun en sağı yerine geçsin
		silinecekDugum = altNode->_left;
		Dugum *ebeveynDugum = altNode;
		while (silinecekDugum->_right != NULL)
		{
			ebeveynDugum = silinecekDugum;
			silinecekDugum = silinecekDugum->_right;
		}
		altNode->kisi->yas = silinecekDugum->kisi->yas;
		if (ebeveynDugum == altNode)
			altNode->_left = silinecekDugum->_left;
		else
			ebeveynDugum->_right = silinecekDugum->_left;
	}
	delete silinecekDugum;
	return true;
}

void AVLTree::Derinlik_Guncelle(Dugum *_dugum, int derinlik, int yeniDerinlik)///
{
	if (_dugum == NULL)
		return;
	if (derinlik != 1)
	{
		Derinlik_Guncelle(_dugum->_left, derinlik - 1, yeniDerinlik);

		Derinlik_Guncelle(_dugum->_right, derinlik - 1, yeniDerinlik);
	}
	else
	{
		int old_Height = _dugum->derinlik;
		_dugum->derinlik = yeniDerinlik;
		if (old_Height > _dugum->derinlik)
		{
			if (old_Height != 0)
				_dugum->stack->Push("Y");
		}
		else if (old_Height < _dugum->derinlik)
		{
			if (old_Height != 0)
				_dugum->stack->Push("A");
		}

		if (old_Height == _dugum->derinlik)
			_dugum->stack->Push("D");
	}
}

AVLTree::AVLTree()
{
	root = NULL;
}
bool AVLTree::Bosmu() const
{
	return root == NULL;
}
void AVLTree::Ekle(Kisi *yeni)
{
	root = AraveEkle(root, yeni);
	int yukseklik = Yukseklik() + 1;
	for (int i = yukseklik; i >= 0; i--)
	{
		Derinlik_Guncelle(root, i, i);
	}
}

void AVLTree::Postorder() const
{
	Postorder(root);
}
void AVLTree::Levelorder() const
{
	int h = Yukseklik();
	for (int level = 0; level <= h; level++)
		LevelYaz(root, level);
}

void AVLTree::Temizle()
{
	while (!Bosmu())
		DeleteDugum(root);
}
int AVLTree::Yukseklik() const // Parametreiz Yukseklik fonksiyonu int türünden veri return ediyor.
{
	return Yukseklik(root); //Ağaç yüksekliğini bulmak için root parametre olarak gönderilir.
}

AVLTree::~AVLTree()//Çöp oluşumunu engellemek için yıkıcı fonksiyonda Temizle() fonksiyonumuzu çağırıyoruz.
{
	Temizle();
}