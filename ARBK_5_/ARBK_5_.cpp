#include <iostream>
#include<thread>
#include<mutex>
#include"SemaphoreSyncro.h"

void print_alph_up_case();
void print_alph_low_case();
void print_numbs();
void user_action();
bool mtx_on = false;
std::mutex mtx;

int main() {

	//user_action();
	std::thread t1 (print_alph_low_case);
	std::thread t2 (print_alph_up_case);
	std::thread t3 (print_numbs);

	t1.join();
	t2.join();
	t3.join();

	Semaphore s(1);

	return 0;
}

void user_action() {
	char input = ' ';
	std::cout << "Synchronisation anschalten ? (y,n)\n";
	input = std::getchar();
	if (input == 'y') {
		mtx_on = true;

	}
	else {
		mtx_on = false;
	}
}

void print_numbs() {

	if (mtx_on) {
      mtx.lock();
	}
	
	for (int i = 0; i < 33; i++) {

		std::cout << i << std::endl;

	}
	if (mtx_on) {
     mtx.unlock();
	}
	

}

void print_alph_up_case() {
	if (mtx_on) {
		mtx.lock();
	}
	for (int i = 65; i < 91; i++) {

		char temp = char(i);
		std::cout << temp << std::endl;

	}
	if (mtx_on) {
		mtx.unlock();
	}

}



void print_alph_low_case() {
	if (mtx_on) {
		mtx.lock();
	}
	for (int i = 97; i < 123; i++) {

		char temp = char(i);
		std::cout << temp << std::endl;

	}
	if (mtx_on) {
		mtx.unlock();
	}

}