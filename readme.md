# Аллокатор статической памяти
Размер пула памяти и размера блока при сборке настраиваются в файле **static_mem_allocator.pro**:

```
# Set up the size of static memory pool (in bytes)
DEFINES += POOL_SIZE=10

# Set up the size of memory block that will be allocated (in bytes)
DEFINES += BLOCK_SIZE=2
```

Набор юнит-тестов написан с использованием библиотеки QtTest 5.1.1 . 
При запуске выводится результат выполнения тестов:

```
********* Start testing of TestMemAlloc *********
Config: Using QtTest library 5.1.1, Qt 5.1.1
PASS   : TestMemAlloc::initTestCase()
PASS   : TestMemAlloc::allocateDifferentBlocks()
PASS   : TestMemAlloc::outOfMemory()
PASS   : TestMemAlloc::freeTwice()
PASS   : TestMemAlloc::cleanupTestCase()
Totals: 5 passed, 0 failed, 0 skipped
********* Finished testing of TestMemAlloc *********
```
