#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <random> 

template <class T>
struct mypair {
	T values[2];
public:
	mypair(T first, T second)
	{
		values[0] = first; values[1] = second;
	}

	std::string valuesInside(int i) {
		return values[i];
	}
};

bool condition(char         first,
	char         second,
	std::string &alphabet) {
	return alphabet.find(first) < alphabet.find(second);
}

bool compare(std::string  first,
	std::string  second,
	std::string &alphabet) {
	int  length = std::min(first.length(),
		second.length());
	int  a = 0;
	int  b = 0;
	bool result;
	for (int character = 0;
		character < length;
		character++) {
		if (first[character] != second[character]) {
			return condition(first[character], second[character], alphabet);
		}
	}
	return true;
}

bool compare_sort(std::string first,
	std::string second) {
	std::string alphabet = "_ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	return compare(first, second, alphabet);
}

std::string random_string(std::string alphabet) {
	std::string result;
	for (int iterator = 0;
		iterator < 5;
		iterator++) {
		result += alphabet[rand() % alphabet.length()];
	}
	return result;

}

void bubblesort(std::vector<std::string> &strings) {
	bool done = false;
	while (done == false) {
		done = true;
		for (int iterator = 1;
			iterator < strings.size() - 1;
			iterator++) {
			if (compare_sort(strings[iterator - 1], strings[iterator])) {
				std::swap(strings[iterator - 1], strings[iterator]);
				done = false;
			}
		}
	}
	return;
}

int main(void) {
	std::vector<std::string> strings;
	srand(time(nullptr));
	std::string alphabet = "_AB";
	strings.push_back("AAA");
	strings.push_back("__A");
	strings.push_back("_BA");
	strings.push_back("_A_");
	strings.push_back("___");
	
	

	mypair<std::string> myfloats("Hello", " World!");

	std::cout << myfloats.valuesInside(0) + myfloats.valuesInside(1) << std::endl;

	std::system("pause");

	std::random_device rando;
	std::string test[] = { " ","A","B" };
	for (int i = 0; i < 10; i++) {
		std::string namerandom;
		for (int i = 0; i < 5; i++) {
			namerandom += test[rand() % 3];
		} 
		strings.push_back(namerandom);
	}

	for (auto string : strings) {
		std::cout << string << std::endl;
	}
	std::cout << std::endl << "Before:" << std::endl;
	for (auto string : strings) {
		std::cout << string << std::endl;
	}
	bubblesort(strings);
	std::cout << std::endl << "After:" << std::endl;
	for (auto string : strings) {
		std::cout << string << std::endl;
	}
	return 0;
}
