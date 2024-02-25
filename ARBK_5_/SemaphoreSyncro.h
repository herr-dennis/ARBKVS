#pragma once
#include <iostream>
#include "Semaphore.h"



    class SemaphoreSyncro {

    public:
        SemaphoreSyncro() {}

    private:
        Semaphore s(1);
        void print_numb();
        void print_alph_up_case();
        void print_alph_low_case();
        void testing();

    };

