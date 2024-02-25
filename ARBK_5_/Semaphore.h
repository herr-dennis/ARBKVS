
#pragma once
#include <mutex>
#include <condition_variable>


    class Semaphore {
    private:
        std::mutex mutex;
        std::condition_variable cv;
        //Anzahl der zu verwaltenden Resscourcen. 
        int count;

    public:
        Semaphore(int count); // Benutzerdefinierter Konstruktor
        // Standardkonstruktor ohne Parameter für den Compiler
        void notify(); 
        void wait();
    };

    

