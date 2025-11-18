#pragma once
namespace Utility{
	template <typename T>
	int reverse(T* a1, T* a2) {
		int lengthoperations = 0;
		if (a1 == a2 || !a1 || !a2) {
			return 3;
		}
		a2--;
		lengthoperations += 4;
		while (a1 < a2) { //Wykonuj poki a1 adres nie jest wiekszy niz a2
			std::swap(*a1, *a2); //swap == 3 operacje
			//Za kazdym razem jak swap to dodaj a1 i odejmij a2 zeby zmieniac pierszy z ostatnim potem drugi z przedostatnim
			a1++;
			a2--;
			lengthoperations += 6;
		}
		return lengthoperations;
	}
}