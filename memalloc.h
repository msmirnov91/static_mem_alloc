#ifndef MEMALLOC_H
#define MEMALLOC_H

#include <vector>

class MemAlloc
{
private:
    static unsigned char pool[POOL_SIZE];

    // to control memory operations and make them as fast as possible
    std::vector<int> _freeBlockOffsets;

    // make sure that there is only one allocator (and, therefore, one pool)
    MemAlloc();
    ~MemAlloc();
    MemAlloc(MemAlloc const&);
    MemAlloc& operator= (MemAlloc const&);

public:
    static MemAlloc* getInstance();
    void freeAll();

    void* bl_alloc(void);
    void bl_free(void*);
};

#endif // MEMALLOC_H
