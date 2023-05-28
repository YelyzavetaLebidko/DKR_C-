#pragma once
#include <iostream>

class BaseService
{
protected:

	int Price;

public:

	void setPrice(const int price);

	int getPrice() const;

	virtual void outputSaveInfo(std::ostream& os) const = 0;

	virtual void inputSaveInfo(std::istream& is) = 0;

};

void BaseService::setPrice(const int price)
{
	if (price >= 0)
	{
		this->Price = price;
	}
}

int BaseService::getPrice() const
{
	return this->Price;
}


