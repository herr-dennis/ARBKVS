#include <iostream>
#include<thread>
#include<mutex>


void print_alph_up_case();
void print_alph_low_case();
void print_numbs();

std::mutex mtx;

int main() {


	std::thread t1 (print_alph_low_case);
	std::thread t2 (print_alph_up_case);
	std::thread t3 (print_numbs);

	t1.join();
	t2.join();
	t3.join();
	return 0;
}

void print_numbs() {

	mtx.lock();
	for (int i = 0; i < 33; i++) {

		std::cout << i << std::endl;

	}
	mtx.unlock();

}

void print_alph_up_case() {
	mtx.lock();
	for (int i = 65; i < 91; i++) {

		char temp = char(i);
		std::cout << temp << std::endl;

	}
	mtx.unlock();

}



void print_alph_low_case() {

	mtx.lock();
	for (int i = 97; i < 123; i++) {

		char temp = char(i);
		std::cout << temp << std::endl;

	}
	mtx.unlock();

}