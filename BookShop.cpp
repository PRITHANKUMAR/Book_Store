// bookshop.cpp
#include "bookshop.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Bookshop::Bookshop(int initialStock, int maxStock)
    : stock(initialStock), maxStock(maxStock)
{
}

void Bookshop::purchaseBooks(int customerID)
{
    std::unique_lock<std::mutex> lock(stockMutex);
    int booksToPurchase = rand() % 5 + 1;
    ReStock.wait(lock, [=] {return (stock < booksToPurchase) ? false:true;});
    stock -= booksToPurchase;
    std::cout << "Customer " << customerID << " purchased " << booksToPurchase << " books. Remaining stock: " << stock << std::endl;

}

void Bookshop::restockBooks(int managerID)
{
    std::unique_lock<std::mutex> lock(stockMutex);
    int booksToRestock = rand() % 6 + 5;
    if (stock < maxStock) {
        stock += booksToRestock;
        std::cout << "Manager " << managerID << " restocked " << booksToRestock << " books. New stock: " << stock << std::endl;
        ReStock.notify_one();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    else {
        std::cout << "Manager " << managerID << " stopped restocking. Maximum stock reached: " << maxStock << std::endl;
        ReStock.notify_one();
    }
}

int Bookshop::getStock() const
{
    return stock;
}

