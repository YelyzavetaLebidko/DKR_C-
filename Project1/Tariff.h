#pragma once
#include <string>
#include "InternetService.h"
#include "CallsService.h"

class Tariff
{
private:

	std::string Name;
	CallsService Calls;
	InternetService Internet;

public:

	Tariff();

	Tariff(const std::string name, const int priceC, const int minutes, const int priceI, const double gb);

	Tariff(const std::string name, const CallsService calls, const InternetService internet);


	void init(const std::string name, const CallsService calls, const InternetService internet);


	std::string getName() const;

	CallsService getCalls() const;

	InternetService getInternet() const;

	int getTotalPrice() const;


	void outputSaveInfo(std::ostream& os) const;

	void inputSaveInfo(std::istream& is);

};

Tariff::Tariff()
{
}

Tariff::Tariff(const std::string name, const int priceC, const int minutes, const int priceI, const double gb)
{
	this->Name = name;

	this->Calls.setPrice(priceC);
	this->Calls.setMinutes(minutes);

	this->Internet.setPrice(priceI);
	this->Internet.setGB(gb);
}

Tariff::Tariff(const std::string name, const CallsService calls, const InternetService internet)
{
	this->Name = name;

	this->Calls = calls;
	this->Internet = internet;
}

void Tariff::init(const std::string name, const CallsService calls, const InternetService internet)
{
	this->Name = name;

	this->Calls = calls;
	this->Internet = internet;
}


std::string Tariff::getName() const
{
	return this->Name;
}

CallsService Tariff::getCalls() const
{
	return this->Calls;
}

InternetService Tariff::getInternet() const
{
	return this->Internet;
}

int Tariff::getTotalPrice() const
{
	return this->Calls.getPrice() + this->Internet.getPrice();
}


std::ostream& operator << (std::ostream& os, const Tariff& obj)
{
	os << "Tariff name:   " << obj.getName() << std::endl;
	os << "Internet:      " << obj.getInternet().getGB() << "Gb" << std::endl;
	os << "Calls:         " << obj.getCalls().getMinutes() << "min" << std::endl;
	os << "Total price:   " << obj.getTotalPrice()  << std::endl;
	return os;
}


void Tariff::outputSaveInfo(std::ostream& os) const
{
	os << this->Name << std::endl;
	this->Calls.outputSaveInfo(os);
	os << " ";
	this->Internet.outputSaveInfo(os);
}

void Tariff::inputSaveInfo(std::istream& is)
{
	std::getline(is, this->Name);
	this->Calls.inputSaveInfo(is);
	this->Internet.inputSaveInfo(is);
}