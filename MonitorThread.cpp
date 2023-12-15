// monitorthread.cpp
#include "monitorthread.h"
#include <iostream>

MonitorThread::MonitorThread(Bookshop* bookshop)
    : bookshop(bookshop)
{
}

void MonitorThread::run()
{
    if (true) {
        std::cout << "Stock is replenished. Current stock: " << bookshop->getStock() << std::endl;
        // Additional actions related to stock replenishment can be performed here
    }
}
