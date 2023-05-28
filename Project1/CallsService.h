#pragma once
#include "BaseService.h"

class CallsService : public BaseService
{
protected:

	int Minutes;  // кількість хвилин

public:

	CallsService();

	CallsService(const int price, const double minutes);


	void setMinutes(const double minutes);

	double getMinutes() const;


	void outputSaveInfo(std::ostream& os) const override;

	void inputSaveInfo(std::istream& is) override;

};


CallsService::CallsService()
{
	this->Price = 0;
	this->Minutes = 0;
}

CallsService::CallsService(const int price, const double minutes) : CallsService::CallsService()
{
	if (price >= 0)
	{
		this->Price = price;
	}
	if (minutes >= 0)
	{
		this->Minutes = minutes;
	}
}


void CallsService::setMinutes(const double minutes)
{
	if (minutes >= 0)
	{
		this->Minutes = minutes;
	}
}

double CallsService::getMinutes() const
{
	return this->Minutes;
}

std::ostream& operator << (std::ostream& os, const CallsService& obj)
{
	os << "Price:    " << obj.getPrice() << std::endl;
	os << "Minutes:  " << obj.getMinutes() << "min" << std::endl;
	return os;
}
	
void CallsService::outputSaveInfo(std::ostream& os) const
{
	os << this->Price << " " << this->Minutes;
}

void CallsService::inputSaveInfo(std::istream& is)
{
	is >> this->Price;
	is >> this->Minutes;
}