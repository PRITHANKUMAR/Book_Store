// Bookshop_MultiThreading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <vector>
#include <functional>
#include "BookShop.h"
#include "CustomerThread.h"
#include "ManagerThread.h"
#include "MonitorThread.h"

int main()
{
    std::cout << "Hello World!\n";

    int numCustomers, numManagers;

    std::cout << "Enter the number of customers: ";
    std::cin >> numCustomers;

    //std::cout << "Enter the number of purchases per customer: ";
    //std::cin >> numPurchasesPerCustomer;

    std::cout << "Enter the number of managers: ";
    std::cin >> numManagers;

    //std::cout << "Enter the number of restocks per manager: ";
    //std::cin >> numRestocksPerManager;

    // Create Bookshop instance
    Bookshop bookshop(20, 30);

    std::vector<std::thread> customerThreads;
    std::vector<std::thread> managerThreads;

    for (int i = 0; i < numCustomers; ++i) {
        CustomerThread customerThread(&bookshop, i + 1);
        customerThreads.emplace_back(std::thread(customerThread));
        //customerThread->run();
    }
    for (int i = 1; i <= numManagers; ++i) {
        ManagerThread managerThread(&bookshop, i);
        managerThreads.emplace_back(managerThread);
    }
    //for (int i = 0; i < numManagers; ++i) {
    //    ManagerThread* managerThread = new ManagerThread(&bookshop, i + 1, numRestocksPerManager);
    //    managerThreads.emplace_back(std::thread(managerThread));
    //    //managerThread->run();
    //}

    MonitorThread* monitorThread = new MonitorThread(&bookshop);
    monitorThread->run();

    for (auto& thread : customerThreads) {
        thread.join();
    }

    for (auto& thread : managerThreads) {
        thread.join();
    }


}