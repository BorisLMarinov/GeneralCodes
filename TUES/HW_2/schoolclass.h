#ifndef SCHOOLCLASS_H
#define SCHOOLCLASS_H
#include "person.h"

	struct SchoolClass {
		struct Person students[26];
		char paralelka;
		int NomerNaKlasa;
		struct Person teacher;
	};

#endif