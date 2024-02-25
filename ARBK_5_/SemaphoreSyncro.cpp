
#include"SemaphoreSyncro.h"

	

	void SemaphoreSyncro::testing() {

		print_alph_low_case();

	}
	
	void SemaphoreSyncro::print_numb() {
		s.wait();
		for (int i = 0; i < 33; i++) {

			std::cout << i << std::endl;

		}
		s.notify();
	}

	void SemaphoreSyncro::print_alph_up_case() {
		s.wait();
		for (int i = 65; i < 91; i++) {

			char temp = char(i);
			std::cout << temp << std::endl;

		}

		s.notify();
	}


	void SemaphoreSyncro::print_alph_low_case() {

		s.wait();
		for (int i = 97; i < 123; i++) {

			char temp = char(i);
			std::cout << temp << std::endl;

		}

		s.notify();
	
}