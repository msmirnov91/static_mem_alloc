#include <exception>
#include <qtest.h>
#include "testmemalloc.h"
#include "memalloc.h"


TestMemAlloc::TestMemAlloc(){

}

void TestMemAlloc::allocateDifferentBlocks(){
    MemAlloc *allocator = MemAlloc::getInstance();
    void* blk_1 = allocator->bl_alloc();
    void* blk_2 = allocator->bl_alloc();

    QVERIFY(blk_1 != blk_2);

    allocator->bl_free(blk_1);
    allocator->bl_free(blk_2);
}

// Qt 5.1 does not provide QVERIFY_EXCEPTION_THROWN macro

void TestMemAlloc::outOfMemory(){
    MemAlloc *allocator = MemAlloc::getInstance();
    int occupiedMemory = 0;

    while (occupiedMemory + BLOCK_SIZE <= POOL_SIZE){
        allocator->bl_alloc();
        occupiedMemory += BLOCK_SIZE;
    }

    try{
        allocator->bl_alloc();
        QFAIL("Size of allocated memory is greater than pool size");
    }
    catch (std::bad_alloc){
        //for the next tests
        allocator->freeAll();
    }
}

void TestMemAlloc::freeTwice(){
    MemAlloc *allocator = MemAlloc::getInstance();

    void* blk_1 = allocator->bl_alloc();
    allocator->bl_free(blk_1);

    try{
        allocator->bl_free(blk_1);
        QFAIL("Block can be freed twice");
    }
    catch (std::bad_alloc){

    }
}
