#include <semaphore.h>

class FooBar {
private:
    int n;
    sem_t sem_Foo;
    sem_t sem_Bar;
    
public:
    FooBar(int n) {
        this->n = n;
        
        sem_init(&sem_Foo,0,1);
        sem_init(&sem_Bar,0,0);
            
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
            
            sem_wait(&sem_Foo);
        	printFoo();
            sem_post(&sem_Bar);
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            
        	// printBar() outputs "bar". Do not change or remove this line.
            sem_wait(&sem_Bar);
        	printBar();
            sem_post(&sem_Foo);
        }
    }
};