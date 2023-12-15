// customerthread.h
#ifndef CUSTOMERTHREAD_H
#define CUSTOMERTHREAD_H

#include <thread>
#include "bookshop.h"

class CustomerThread
{
public:
    explicit CustomerThread(Bookshop* bookshop, int numCustomers);

    void operator()();
private:
    Bookshop* bookshop;
    int numCustomers;
};

#endif // CUSTOMERTHREAD_H