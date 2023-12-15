// managerthread.cpp
#include "managerthread.h"
#include <iostream>

ManagerThread::ManagerThread(Bookshop* bookshop, int numManagers)
    : bookshop(bookshop), numManagers(numManagers)
{
}

    void ManagerThread::operator()() {
        
            bookshop->restockBooks(numManagers);
            std::this_thread::sleep_for(std::chrono::seconds(2));
    }

//void ManagerThread::run()
//{
//    for (int i = 0; i < numRestocksPerManager; ++i) {
//        bookshop->restockBooks(numManagers); // Assuming manager IDs start from 1
//    }
//}



//#include <iostream>
//#include <thread>
//#include <vector>
//
//class Bookshop;  // Forward declaration
//
//class ManagerThread {
//public:
//    ManagerThread(Bookshop* bookshop, int managerID, int numRestocksPerManager)
//        : bookshop(bookshop), managerID(managerID), numRestocksPerManager(numRestocksPerManager) {}
//
//    void operator()() {
//        for (int i = 0; i < numRestocksPerManager; ++i) {
//            bookshop->restockBooks(managerID);
//        }
//    }
//
//private:
//    Bookshop* bookshop;
//    int managerID;
//    int numRestocksPerManager;
//};
//
//class Bookshop {
//public:
//    void restockBooks(int managerID) {
//        // Simulated restockBooks function
//        std::cout << "Manager " << managerID << " restocked books." << std::endl;
//    }
//};
//
//int main() {
//    const int numManagers = 3;
//    const int numRestocksPerManager = 2;
//
//    // Create Bookshop instance
//    Bookshop bookshop;
//
//    // Create and start multiple ManagerThread instances
//    std::vector<std::thread> managerThreads;
//    for (int i = 1; i <= numManagers; ++i) {
//        ManagerThread managerThread(&bookshop, i, numRestocksPerManager);
//        managerThreads.emplace_back(managerThread);
//    }
//
//    // Wait for all threads to finish
//    for (auto& thread : managerThreads) {
//        thread.join();
//    }
//
//    return 0;
//}
