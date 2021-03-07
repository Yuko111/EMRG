#ifndef _EMR_H_
#define _EMR_H_
#include <string>
#include <vector>


class EMRG {
	static unsigned long Grs;
	std::string DateTime;
	std::string Name;
	std::string Surname;
	std::string Tel;
	std::string Konum;
	std::string Sebep;
	
public:
	EMRG();
	EMRG(std::string&, std::string&, std::string&, std::string&, std::string&);
	EMRG& setName(std::string&);
	EMRG& setSurname(std::string&);
	EMRG& setTel(std::string&);
	EMRG& setKonum(std::string&);
	EMRG& setSebep(std::string&);

	std::string getName()const;
	std::string getSurname()const;
	std::string getTel()const;
	std::string getKonum()const;
	std::string getSebep()const;

	void getDateTime();
	void listele(const std::vector<EMRG>&)const;
	void TakeInfos();
	void cikar();
	
	void DisplayMessage()const;

}; 






#endif // !_EMR_H_
