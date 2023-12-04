// managerthread.h
#ifndef MANAGERTHREAD_H
#define MANAGERTHREAD_H

#include <thread>
#include "bookshop.h"

class ManagerThread
{
public:
    explicit ManagerThread(Bookshop* bookshop, int numManagers);

    void operator()();

private:
    Bookshop* bookshop;
    int numManagers;
};

#endif // MANAGERTHREAD_H

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