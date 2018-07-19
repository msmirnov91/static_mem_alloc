#include <algorithm>
#include <exception>
#include "memalloc.h"

unsigned char MemAlloc::pool[POOL_SIZE];

MemAlloc::MemAlloc(){
    // at first all blocks are free
    freeAll();
}

void MemAlloc::freeAll(){
    for (int offset=0; offset + BLOCK_SIZE <= POOL_SIZE; offset += BLOCK_SIZE){
        _freeBlockOffsets.push_back(offset);
    }
}

MemAlloc::~MemAlloc(){

}

MemAlloc *MemAlloc::getInstance(){
    static MemAlloc mem;
    return &mem;
}

void* MemAlloc::bl_alloc(void){
    if (_freeBlockOffsets.empty()){
        // nothing to allocate
        throw std::bad_alloc();
    }

    int offset = _freeBlockOffsets.back();
    _freeBlockOffsets.pop_back();
    return static_cast<void*>(pool + offset);
}

void MemAlloc::bl_free(void* bl_ptr){
    unsigned char* ptr = static_cast<unsigned char*>(bl_ptr);
    int offset = ptr - pool;

    if (std::binary_search(_freeBlockOffsets.begin(), _freeBlockOffsets.end(), offset)){
        // block is already free
        throw std::bad_alloc();
    }

    _freeBlockOffsets.push_back(offset);
    std::sort(_freeBlockOffsets.begin(), _freeBlockOffsets.end());
}
