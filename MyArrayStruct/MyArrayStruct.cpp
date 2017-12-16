#include <iostream>
#include <string>

using namespace std;

template <class T>
struct MyArray {
	T *arrayValue = NULL;
	int theSize;
	using reference = T&;

	MyArray(initializer_list<T> iniList) {
		int size = iniList.size();
		arrayValue = new T[size];
		theSize = size;
		for (int i = 0; i < theSize; i++) {
			arrayValue[i] = *(iniList.begin() + i);
		}
	}

	const reference operator[](int i) {
		return arrayValue[i];
	}

	void addValue(T valueToAdd) {
		theSize++;
		T *tempArray = new T[theSize];

		tempArray[theSize - 1] = valueToAdd;

		for (int i = 0; i < theSize - 1; i++) {
			tempArray[i] = arrayValue[i];
		}

		delete[] arrayValue;
		arrayValue = tempArray;
	}

	void reSize(int newSize) {
		int oldSize = theSize;
		
		T *tempArray = new T[newSize];

		if (newSize > 0) {

			if (newSize > oldSize) {
				for (int i = 0; i < oldSize; i++) {

					tempArray[i] = arrayValue[i];
				}

				for (int i = oldSize; i < newSize; i++) {

					tempArray[i] = T{};
				}
			}
			else {
				for (int i = 0; i < newSize; i++) {

					tempArray[i] = arrayValue[i];
				}
			}

			delete[] arrayValue;
			arrayValue = tempArray;

		}
		else {
			delete[] arrayValue;
		}
		theSize = newSize;

	}
};

void main() {

	int arraySize;
	do {
		cout << "What size: ";
		//cin >> arraySize;
		//MyArray<int> testThisArray(arraySize);
		MyArray<string> testThisArray = {"hello","World" };
		MyArray<int> thisIsIntArray = { 123,56,123,678,23,5,0 };
		cout << "Value to add: ";
		/*
		int addV;
		cin >> addV;
		cin.ignore();
		*/
		string addV;
		getline(cin, addV);

		testThisArray.addValue(addV);

		for (int i = 0; i < testThisArray.theSize; i++) {
			cout << "Index: " << i << ", Value: " << testThisArray[i] << endl;
		}
		int index;
		do {
			
			cout << "Index #: ";
			cin >> index;
			cin.ignore();
			if (index < testThisArray.theSize && index >= 0) {
				cout << "New Value: ";
				/*int newValue;
				cin >> newValue;*/
				string newValue;
				getline(cin, newValue);
				testThisArray[index] = newValue;
				cout << "Index: " << index << ", Value: " << testThisArray[index] << endl;
			}
		} while (index != -1);

		int resizeIt;
		cout << "Give New Size: ";
		cin >> resizeIt;
		testThisArray.reSize(resizeIt);

		for (int i = 0; i < testThisArray.theSize; i++) {
			cout << "Index: " << i << ", Value: " << testThisArray[i] << endl;
		}

		// INT
		for (int i = 0; i < thisIsIntArray.theSize; i++) {
			cout << "Index: " << i << ", Value: " << thisIsIntArray[i] << endl;
		}

		cout << "Give New Size: ";
		cin >> resizeIt;
		thisIsIntArray.reSize(resizeIt);

		for (int i = 0; i < thisIsIntArray.theSize; i++) {
			cout << "Index: " << i << ", Value: " << thisIsIntArray[i] << endl;
		}

	} while (true);

}

