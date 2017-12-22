#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T, size_t initSize = 0>
struct MyArray {
private:
	T * arrayValue = NULL;
public:
	size_t size;

	MyArray() {
		size = initSize;
		arrayValue = new T[size];
	}

	MyArray(initializer_list<T> initList) {
		size = initList.size();
		arrayValue = new T[size];
		for (size_t i = 0; i < size; i++) {
			arrayValue[i] = *(initList.begin() + i);
		}
	}

	T& operator[](size_t i) {
		return arrayValue[i];
	}
	void addValue(T valueToAdd) {
		T *tempArray = new T[++size];

		tempArray[size - 1] = valueToAdd;

		for (size_t i = 0; i < size - 1; i++) {
			tempArray[i] = arrayValue[i];
		}

		delete[] arrayValue;
		arrayValue = tempArray;
	}

	void reSize(size_t newSize) {


		if (newSize <= 0) {
			delete[] arrayValue;
			arrayValue = NULL;
			return;
		}

		size_t oldSize = size;
		size = newSize;
		T *tempArray = new T[newSize];

		if (newSize > oldSize) {
			for (size_t i = 0; i < oldSize; i++) {

				tempArray[i] = arrayValue[i];
			}

			for (size_t i = oldSize; i < newSize; i++) {

				tempArray[i] = T{};
			}
		}
		else {
			for (size_t i = 0; i < newSize; i++) {

				tempArray[i] = arrayValue[i];
			}
		}

		delete[] arrayValue;
		arrayValue = tempArray;

	}
};

void main() {

	vector<int> testmi = { 23,56,87,12,5 };
	const int row = 10, column = 10;	
	MyArray <MyArray<string, column>, row> multiMyArray;
	for (size_t i = 0; i < row; i++) {
		for (size_t j = 0; j < column; j++) {
			multiMyArray[i][j] = to_string(i) + ":" + to_string(j) + ",";
			cout << multiMyArray[i][j];
		}
		cout << "-Column" << endl;
	}
	
	do {

		MyArray<string> testThisSizedArray;
		for (int i = 0; i < testThisSizedArray.size; i++) {
			cout << "Index: " << i << ", Value: " << testThisSizedArray[i] << endl;
		}
		MyArray<string> testThisArray = { "hello","World" };
		MyArray<int> thisIsIntArray = { 123,56,123,678,23,5,0 };
		cout << "Value to add to array of String: ";
		string addV;
		getline(cin, addV);

		testThisArray.addValue(addV);

		for (int i = 0; i < testThisArray.size; i++) {
			cout << "Index: " << i << ", Value: " << testThisArray[i] << endl;
		}
		int index;
		do {

			cout << "Choose Index # to modify: ";
			cin >> index;
			cin.ignore();
			if (index < testThisArray.size && index >= 0) {
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
		cout << "Give New Size to Array of String: ";
		cin >> resizeIt;
		testThisArray.reSize(resizeIt);

		for (int i = 0; i < testThisArray.size; i++) {
			cout << "Index: " << i << ", Value: " << testThisArray[i] << endl;
		}

		// INT
		for (int i = 0; i < thisIsIntArray.size; i++) {
			cout << "Index: " << i << ", Value: " << thisIsIntArray[i] << endl;
		}

		cout << "Give New Size to Array of INT: ";
		cin >> resizeIt;
		thisIsIntArray.reSize(resizeIt);

		for (int i = 0; i < thisIsIntArray.size; i++) {
			cout << "Index: " << i << ", Value: " << thisIsIntArray[i] << endl;
		}

	} while (true);

}

