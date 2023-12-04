// customerthread.cpp
#include "customerthread.h"
#include <chrono>

CustomerThread::CustomerThread(Bookshop* bookshop, int numCustomers)
    : bookshop(bookshop), numCustomers(numCustomers)
{
}

void CustomerThread::operator()() {
    
        bookshop->purchaseBooks(numCustomers); // Assuming customer IDs start from 1
        std::this_thread::sleep_for(std::chrono::seconds(1));
 
    
}

//void CustomerThread::run()
//{
//    for (int i = 0; i < numPurchasesPerCustomer; ++i) {
//        bookshop->purchaseBooks(numCustomers); // Assuming customer IDs start from 1
//    }
//}
