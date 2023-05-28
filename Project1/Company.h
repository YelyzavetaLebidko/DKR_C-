#pragma once
#include <vector>
#include <fstream>
#include "Client.h"


class Company
{
private:

	std::vector<Tariff> Tariffs;
	std::vector<Client> Clients;

	std::string TariffsSaveFile;
	std::string ClientsSaveFile;

public:

	Company(const std::string tariffsFileName, const std::string clientsFileName);

	void saveInfo();

	void readInfo();


	void addTariff(const Tariff& tariff);

	std::vector<Tariff> getAllTariffs() const;


	void addClient(const Client& client);	

	std::vector<Client> getAllClients() const;

	std::vector<Tariff> findTariffs(const int min_price, const int max_price, const int min_minutes, const int max_minutes, const double min_gb, const double max_gb) const;

};


Company::Company(const std::string tariffsFileName = "tariffs.txt", const std::string clientsFileName = "clients.txt")
{
	this->TariffsSaveFile = tariffsFileName;
	this->ClientsSaveFile = clientsFileName;
	this->readInfo();
}

void Company::saveInfo()
{
	std::ofstream foutT(this->TariffsSaveFile, std::ios::out);
	if (foutT.good())
	{
		for (size_t i = 0; i < this->Tariffs.size(); i++)
		{
			this->Tariffs[i].outputSaveInfo(foutT);
			foutT << std::endl;
		}
	}
	std::ofstream foutC(this->ClientsSaveFile, std::ios::out);
	if (foutC.good())
	{
		for (size_t i = 0; i < this->Clients.size(); i++)
		{
			this->Clients[i].outputSaveInfo(foutC);
			foutC << std::endl;
		}
	}
}

void Company::readInfo()
{
	this->Tariffs.clear();
	this->Clients.clear();
	std::ifstream finT(this->TariffsSaveFile, std::ios::in);
	if(finT.good())
	{
		Tariff temp;
		while (finT)
		{
			temp.inputSaveInfo(finT);
			if (finT)
			{
				this->addTariff(temp);
			}
			finT.ignore();
		}
	}
	std::ifstream finC(this->ClientsSaveFile, std::ios::in);
	if (finC.good())
	{
		Client temp;
		while (finC)
		{
			temp.inputSaveInfo(finC);
			if (finC)
			{
				this->Clients.push_back(temp);
			}
			finC.ignore();
		}
	}
}


void Company::addTariff(const Tariff& tariff)
{
	int index = 0;
	while (index < this->Tariffs.size() && this->Tariffs[index].getTotalPrice() < tariff.getTotalPrice())
	{
		index++;
	}
	this->Tariffs.insert(this->Tariffs.begin() + index, tariff);
}

std::vector<Tariff> Company::getAllTariffs() const
{
	return this->Tariffs;
}

void Company::addClient(const Client& client)
{
	this->Clients.push_back(client);
}

std::vector<Client> Company::getAllClients() const
{
	return this->Clients;
}

std::vector<Tariff> Company::findTariffs(const int min_price, const int max_price, const int min_minutes, const int max_minutes, const double min_gb, const double max_gb) const
{
	std::vector<Tariff> result;
	for (size_t i = 0; i < this->Tariffs.size(); i++)
	{
		if (this->Tariffs[i].getTotalPrice() >= min_price &&
			this->Tariffs[i].getTotalPrice() <= max_price &&
			this->Tariffs[i].getCalls().getMinutes() >= min_minutes &&
			this->Tariffs[i].getCalls().getMinutes() <= max_minutes &&
			this->Tariffs[i].getInternet().getGB() >= min_gb &&
			this->Tariffs[i].getInternet().getGB() <= max_gb)
		{
			result.push_back(this->Tariffs[i]);
		}
	}
	return result;
}
