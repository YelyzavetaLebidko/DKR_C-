#pragma once
#include "BaseService.h"

class InternetService : public BaseService
{
protected:

	double GB; // кількість гігабайт

public:

	InternetService();

	InternetService(const int price, const double gb);


	void setGB(const double gb);

	double getGB() const;


	void outputSaveInfo(std::ostream& os) const override;
		
	void inputSaveInfo(std::istream& is) override;

};

InternetService::InternetService()
{
	this->Price = 0;
	this->GB = 0;
}

InternetService::InternetService(const int price, const double gb) : InternetService::InternetService()
{
	if (price >= 0)
	{
		this->Price = price;
	}
	if (gb >= 0)
	{
		this->GB = gb;
	}
}


void InternetService::setGB(const double gb)
{
	if (gb >= 0)
	{
		this->GB = gb;
	}
}

double InternetService::getGB() const
{
	return this->GB;
}

std::ostream& operator << (std::ostream& os, const InternetService& obj)
{
	os << "Price:   " << obj.getPrice() << std::endl;
	os << "GB:      " << obj.getGB() << std::endl;
	return os;
}\

void InternetService::outputSaveInfo(std::ostream& os) const
{
	os << this->Price << " " << this->GB;
}

void InternetService::inputSaveInfo(std::istream& is)
{
	is >> this->Price;
	is >> this->GB;
}