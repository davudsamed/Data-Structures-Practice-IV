/**
* @file B171210007_1A_FinalÖdevi
* @description Main'in bulunduğu, son aşamada ödevi çalıştırdığımız Test.cpp adlı dosya.
* @course 1. Öğretim A Grubu
* @assignment Final Ödevi
* @date 1.09.2020
* @author Davud Samed Tombul
*/
#include "AVLTree.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

int main()
{

	ifstream Dosya("Kisiler.txt");
	AVLTree *AVL_agaci = new AVLTree();
	string satir;
	cout << endl;
	int sayac = 0; //# işaretinden sonra gelen verileri tipine göre ayırmada kullanacağımız sayaç alanı.
	if (Dosya.is_open())//Dosya açık ise ilgili işlemlere geçiliyor.
	{
		while (getline(Dosya, satir)) // dosyayı satırlar şeklinde okur
		{
			string _kelime; // kelimeleri tutacak değişken
			Kisi *temp_kisi = new Kisi();
			stringstream sss(satir);
			
			
			while (getline(sss, _kelime, '#')) // satırı # işaretine göre ayırır
			{
				if (sayac == 0)//# işaretinden önce gelen 0. sıradaki veri için yapılacak işlemler
					temp_kisi->isim = _kelime; //kişiye isim atanır
				else if (sayac == 2)//ikinci # işaretinden sonra gelecek olan son veriyi ilgili alana atamak için kullanıdığımız kod
					temp_kisi->kilo = stoi(_kelime); //stoi fonksiyonu ile string veri inte çevrilip kişinin kilosuna atanır.
				else if (sayac == 1)//ilk # işaretinden sonra gelen veri.
					temp_kisi->dogumYili = stoi(_kelime); //stoi fonksiyonu ile string veri inte çevrilip kişinin doğum yılına atanır.
				sayac++;
			}
			sayac = 0;//değişken sıfırlanır
			temp_kisi->yas = 2020 - temp_kisi->dogumYili; //Şimdiki yıldan kişinin doğum yılı çıkartılarak kişi yaşı hesaplanır ve kişi nesnesinin ilgili alanına atanır.
			AVL_agaci->Ekle(temp_kisi);//Heap bellek bölgesinde oluşturulan AVL ağacına yukarıdaki veriler ile doldurulmuş kişi nesnesi atanıyor.
		}
		AVL_agaci->Postorder();//Oluşturulan Avl ağacı postorder sıralaması ile okunuyor.
	}
	cout << endl;
	return 0;
}