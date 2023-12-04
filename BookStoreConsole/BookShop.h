// bookshop.h
#ifndef BOOKSHOP_H
#define BOOKSHOP_H

#include <queue>
#include <condition_variable>
#include <mutex>

class Bookshop
{
public:
    explicit Bookshop(int initialStock, int maxStock);
    void purchaseBooks(int customerID);
    void restockBooks(int managerID);
    int getStock() const;
    std::mutex stockMutex;
    std::condition_variable ReStock;

private:
    int stock;
    int maxStock;
    std::queue<int> customerqueue;
    //std::queue<std::condition_variable*> customerQueue_cv;
};

#endif // BOOKSHOP_H
