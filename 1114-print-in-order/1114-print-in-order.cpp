#include <semaphore.h>

class Foo {
private:
    sem_t firstSem;
    sem_t secondSem;
    
public:
    Foo() {
        sem_init(&firstSem, 0, 0);
        sem_init(&secondSem, 0, 0);
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        
        sem_post(&firstSem);
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        sem_wait(&firstSem);
        
        printSecond();
        
        sem_post(&secondSem);
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        sem_wait(&secondSem);
        
        printThird();
    }
};