#pragma once
#include <string>
#include "Tariff.h"

class Client
{
private:

	std::string Name;
	Tariff m_Tariff;

public:

	Client();

	Client(const std::string name, const Tariff& tariff);

	
	void init(const std::string name, const Tariff& tariff);


	std::string getName() const;

	Tariff getTariff() const;


	void outputSaveInfo(std::ostream& os) const;

	void inputSaveInfo(std::istream& is);

};

Client::Client()
{
}

Client::Client(const std::string name, const Tariff& tariff)
{
	this->Name = name;
	this->m_Tariff = tariff;
}

void Client::init(const std::string name, const Tariff& tariff)
{
	this->Name = name;
	this->m_Tariff = tariff;
}

std::string Client::getName() const
{
	return this->Name;
}

Tariff Client::getTariff() const
{
	return this->m_Tariff;
}


std::ostream& operator << (std::ostream& os, const Client& obj)
{
	os << "Client name:   " << obj.getName() << std::endl;
	os << obj.getTariff();
	return os;
}


void Client::outputSaveInfo(std::ostream& os) const
{
	os << this->Name << std::endl;
	this->m_Tariff.outputSaveInfo(os);
}

void Client::inputSaveInfo(std::istream& is)
{
	std::getline(is, this->Name);
	this->m_Tariff.inputSaveInfo(is);
}