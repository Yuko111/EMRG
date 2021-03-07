#include "EMR.h"
#include <iostream>
#include <string>
#include <time.h>
#include <iomanip>
#include <algorithm>
#include <stdexcept>
#pragma warning(disable:4996) // ASCTİME ve LOCALTİME hatası için

unsigned long EMRG::Grs = 0; //Static class veri üyesi Class dışında ilk değer verilir.

EMRG::EMRG(std::string &nam,std::string &sur,std::string &tl,std::string &knm,std::string &sbp){
	
	setName(nam), setSurname(sur), setTel(tl), setKonum(knm), setSebep(sbp);
	++Grs;

}
EMRG::EMRG(){}



EMRG& EMRG::setName(std::string &Name) {

	if (Name.length() > 15)
		throw std::invalid_argument("isim onbeş harf uzunluğunda olmalı.");
	else if (Name.empty())
		throw std::invalid_argument("İsim girilmedi.");
	else if (std::any_of(Name.begin(), Name.end(), ::isdigit))
		throw std::invalid_argument("İsim sayılardan oluşamaz.");
	
	else
		this->Name = Name;
		 
	return *this;
}

EMRG& EMRG::setSurname(std::string& Surname) {

	if (Surname.length() > 15)
		throw std::invalid_argument("Soyisim onbeş harf uzunluğunda olmalıdır.");
	else if (Surname.empty())
		throw std::invalid_argument("Soyisim bilgisi girilmedi.");
	else if (std::any_of(Surname.begin(), Surname.end(), ::isdigit))
		throw std::invalid_argument("Soyisim sayılardan oluşmamalıdır.");
	
	else if (std::any_of(Surname.begin(), Surname.end(), ::isspace))
		throw std::invalid_argument("Soyisim boşluk [space] barındırmamalıdır.");
	else
		this->Surname = Surname;

	return *this;
}

EMRG& EMRG::setTel(std::string &Tel) {

	if (Tel.empty())
		throw std::invalid_argument("Telefon bilgisi girilmedi.");
	else if (Tel.length() != 10)
		throw std::invalid_argument("Telefon numarası on haneli olmalıdır");
	
	else if (std::any_of(Tel.begin(), Tel.end(), ::isalpha))
		throw std::invalid_argument("Telefon numarası rakamlardan oluşmalıdır.");
	else if (std::any_of(Tel.begin(), Tel.end(), ::isspace))
		throw std::invalid_argument("Telefon numarası boşluk [space] barındırmamalıdır.");
	else
		this->Tel = Tel;
	 
	return *this;
}

EMRG& EMRG::setKonum(std::string& Konum) {

	if (Konum.length() > 200)
		throw std::invalid_argument("Maksimum ikiyüz karakter sınırı aşılmamalıdır.");
	else if (Konum.empty())
		throw std::invalid_argument("Konum bilgisi girilmedi.");
	else
		this->Konum = Konum;

	return *this;
}

EMRG& EMRG::setSebep(std::string& Sebep) {

	if (Sebep.length() > 250)
		throw std::invalid_argument("Maksimum ikiyüzelli karakter sınırı aşılmamalıdır.");
	else if (Sebep.empty())
		throw std::invalid_argument("Sebep bilgisi girilmedi.");
	else
		this->Sebep = Sebep;

	return *this;
}

void EMRG::getDateTime() {
	time_t timetoday;
	time(&timetoday);
	if (asctime(localtime(&timetoday)) == NULL)
		throw std::runtime_error("Tarih ve saat bilgisi alınamadı.");
	else
		DateTime = asctime(localtime(&timetoday));
}

std::string EMRG::getName()const { return Name; }
std::string EMRG::getSurname()const { return Surname; }
std::string EMRG::getTel()const { return Tel; }
std::string EMRG::getSebep()const { return Sebep; }

void EMRG::DisplayMessage()const {

	std::cerr << "\t\t\t\t\tACİL DURUM KAYIT OTOMASYONU\n\n\n";
	std::cerr << "1 - ACİL DURUM KAYİT\n2 - ACİL DURUM SİL\n3 - LİSTELE\n\n";

}

void EMRG::TakeInfos() {
	
	std::string Nme, Snm, tl, Konm,Sbp;
	
	std::cout << "İsim bilgisi giriniz:" << std::endl;
	std::cin >> Nme;
	std::cout << std::endl;
	std::cout << "Soyisim bilgisi giriniz:" << std::endl;
	std::cin >> Snm;
	std::cout << std::endl;
	std::cout << "Telefon bilgisi giriniz:" << std::endl;
	std::cin >> tl;
	std::cout << std::endl;
	std::cout << "Konum bilgisi giriniz:" << std::endl;
	std::cin >> Konm;
	std::cout << std::endl;
	std::cout << "Olay bilgisini giriniz:" << std::endl;
	std::cin >> Sbp;
	std::cout << std::endl;
	try {
		EMRG(Nme, Snm, tl, Konm, Sbp);
	}
	catch (std::invalid_argument& error)
	{
		std::cerr << "\n\nİstisna durumu yakalandı : " << error.what() << std::endl;
	}

	
}

void EMRG::listele(const std::vector<EMRG>& List) const {

	for (auto &x : List)
		std::cout << (x.Grs) + 1 << x.DateTime <<  x.Name <<
		 x.Surname <<  x.Tel <<  x.Konum 
		<< x.Sebep << std::endl;
}
