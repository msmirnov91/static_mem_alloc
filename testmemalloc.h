#ifndef TESTMEMALLOC_H
#define TESTMEMALLOC_H

#include <QObject>

class TestMemAlloc: public QObject
{

    Q_OBJECT
public:
    TestMemAlloc();

private slots:
    void allocateDifferentBlocks();
    void outOfMemory();
    void freeTwice();
};

#endif // TESTMEMALLOC_H
