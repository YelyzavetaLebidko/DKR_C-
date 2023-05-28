#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include "Company.h"


void outputLog(const std::string logFileName, const std::string text)
{
    time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    std::ofstream logFile(logFileName, std::ios_base::app);
    if (logFile.good())
    {
        logFile << std::put_time(localtime(&now), "%F %T") << " - " << text << std::endl;
    }
    logFile.close();
}


void outputAllTariffs(Company& company, const std::string logFileName)
{
    system("cls");
    std::vector<Tariff> temp = company.getAllTariffs();
    std::cout << "All tariffs: " << std::endl;
    for (size_t i = 0; i < temp.size(); i++)
    {
        std::cout << temp[i] << std::endl;
    }
    system("pause");
    system("cls");
}

void outputAllClients(Company& company, const std::string logFileName)
{
    system("cls");
    std::vector<Client> temp = company.getAllClients();
    std::cout << "All clients: " << std::endl;
    for (size_t i = 0; i < temp.size(); i++)
    {
        std::cout << temp[i] << std::endl;
    }
    system("pause");
    system("cls");
}

void addTariff(Company& company, const std::string logFileName)
{
    system("cls");
    std::cout << "     ADD TARIFF" << std::endl;

    std::string name;
    int minutes;
    int minutesPrice;
    double gb;
    int gbPrice;

    std::cin.ignore();
    std::cout << "Enter name:            ";
    std::getline(std::cin, name);


    std::cout << "Enter minutes:         ";
    std::cin >> minutes;
    std::cout << "Enter minutes price:   ";
    std::cin >> minutesPrice;
    std::cout << "Enter gb of internet:  ";
    std::cin >> gb;
    std::cout << "Enter gb price:        ";
    std::cin >> gbPrice;

    Tariff tariff(name, minutesPrice, minutes, gbPrice, gb);
    company.addTariff(tariff);

    std::cout << "Tariff was added" << std::endl;
    std::string text = "New tariff with name \"";
    text += name;
    text += "\" was added";
    outputLog(logFileName, text);
    company.saveInfo();
    system("pause");
    system("cls");
}

void addClient(Company& company, const std::string logFileName)
{
    system("cls");
    std::string cName;
    std::string tName;

    std::cout << "Enter client name:  ";
    std::cin.ignore();
    std::getline(std::cin, cName);

    std::vector<Tariff> temp = company.getAllTariffs();
    std::cout << "All tariffs: " << std::endl;
    for (size_t i = 0; i < temp.size(); i++)
    {
        std::cout << temp[i] << std::endl;
    }

    std::cout << "Enter tariff name: ";
    std::getline(std::cin, tName);

    for (size_t i = 0; i < temp.size(); i++)
    {
        if (tName == temp[i].getName())
        {
            company.addClient(Client(cName, temp[i]));
            std::cout << "Client was added." << std::endl;
            std::string text = "New client with name \"";
            text += cName;
            text += "\" was added";
            outputLog(logFileName, text);
            company.saveInfo();
            system("pause");
            system("cls");
            return;
        }
    }
    std::cout << "No such tariff name." << std::endl;
    system("pause");
    system("cls");
}

void findTariffByDiapazone(Company& company, const std::string logFileName)
{
    system("cls");
    int minPrice;
    int maxPrice;
    int minMinutes;
    int maxMinutes;
    int minGb;
    int maxGb;
    std::cout << "Enter min price:  ";
    std::cin >> minPrice;
    std::cout << "Enter max price:  ";
    std::cin >> maxPrice;
    std::cout << "Enter min minutes:  ";
    std::cin >> minMinutes;
    std::cout << "Enter max minutes:  ";
    std::cin >> maxMinutes;
    std::cout << "Enter min gb:  ";
    std::cin >> minGb;
    std::cout << "Enter max gb:  ";
    std::cin >> maxGb;

    std::vector<Tariff> result = company.findTariffs(minPrice, maxPrice, minMinutes, maxMinutes, minGb, maxGb);
    std::cout << "\nResult tariffs: " << std::endl;
    for (size_t i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << std::endl;
    }
    system("pause");
    system("cls");
}

void outputTotalClientsQuantity(Company& company, const std::string logFileName)
{
    system("cls");
    std::cout << "Total clients quantity:  " << company.getAllClients().size() << std::endl;    
    system("pause");
    system("cls");
}


void menu(Company& company, const std::string logFileName)
{
    while (true)
    {
        std::cout << "     Menu" << std::endl;
        std::cout << "1 - output all tariffs" << std::endl;
        std::cout << "2 - output all clients" << std::endl;
        std::cout << "3 - add tariff" << std::endl;
        std::cout << "4 - add client" << std::endl;
        std::cout << "5 - find tariff by diapazone" << std::endl;
        std::cout << "6 - output total clients quantity" << std::endl;
        std::cout << "else - exit" << std::endl;
        int choise;
        std::cout << "Your choise:  ";
        std::cin >> choise;

        if (choise == 1)
        {
            outputLog(logFileName, "Output all tariffs option call.");
            outputAllTariffs(company, logFileName);
        }
        else if (choise == 2)
        {
            outputLog(logFileName, "Output all clients option call.");
            outputAllClients(company, logFileName);
        }
        else if (choise == 3)
        {
            outputLog(logFileName, "Add tariff option call.");
            addTariff(company, logFileName);
        }
        else if (choise == 4)
        {
            outputLog(logFileName, "Add client option call.");
            addClient(company, logFileName);
        }
        else if (choise == 5)
        {
            outputLog(logFileName, "Find tariff by dipazone option call.");
            findTariffByDiapazone(company, logFileName);
        }
        else if (choise == 6)
        {
            outputLog(logFileName, "Output total clients quantity option call.");
            outputTotalClientsQuantity(company, logFileName);
        }
        else 
        {
            std::cout << "Menu exit." << std::endl;
            outputLog(logFileName, "Program exit.");
            return;
        }
    }
}


int main()
{
    std::string logFileName = "logFile.txt";
    outputLog(logFileName, "Program start.");
    

    Company company;
    menu(company, logFileName);

    return 0;   
}

