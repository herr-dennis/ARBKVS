
#include"Semaphore.h"



    Semaphore::Semaphore(int count) : count(count) {}

    void Semaphore::notify() {
        //unique_lock<std::mutex> ist eine Klasse zum besseren verwalten von Mutex
        std::unique_lock<std::mutex> lock(mutex);
        count++;
        //Weckt ein Thread in der internen Queue auf, Thread beeendet. 
        cv.notify_one();
    }

    //Wartet auf eine frei  Ressource
    //Wenn count > 0, dann gibt es eine frei Ressource. Beispiel Drucker vergleich. Hier aber BinäreSemaphore
    void Semaphore::wait() {
        //Hier ein Mutex Lock um zu verhindern, dass die Daten persitent bleiblben, besonders count!
        //Sonst könnten andere Threads reinschreiben.
        std::unique_lock<std::mutex> lock(mutex);
        //Wenn Resscource frei, dann nicht mehr im Wartezustand. 
        while (count == 0) {
            cv.wait(lock);
        }
        //Thread hat Ressource bekommen, dann Ressourcezähler runter. 
        count--;

    }
   
