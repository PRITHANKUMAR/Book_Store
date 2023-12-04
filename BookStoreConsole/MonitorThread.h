// monitorthread.h
#ifndef MONITORTHREAD_H
#define MONITORTHREAD_H

#include <thread>
#include "bookshop.h"

class MonitorThread
{
public:
    explicit MonitorThread(Bookshop* bookshop);
    ~MonitorThread();

    void run();

private:
    Bookshop* bookshop;
};

#endif // MONITORTHREAD_H
