#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T>
struct MyArray {
	//vector thisone;
	T *arrayValue = NULL;
	int theSize;
	using reference = T&;

	MyArray(int size) {
		arrayValue = new T[size];
		theSize = size;
		for (int i = 0; i < theSize; i++) {
			arrayValue[i] = i;
			/*arrayValue[i] = "Hello ";
			arrayValue[i] += to_string(i);*/
		}
	}

	const reference operator[](int n) {
		return arrayValue[n];
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
};

void main() {
	//vector<int> yesir = { 1,2,3 };
	//yesir[1] = 5;

	int arraySize;
	do {
		cout << "What size: ";
		cin >> arraySize;
		MyArray<int> testThisArray(arraySize);
		cout << "Value to add: ";
		int addV;
		cin >> addV;
		/*string addV;
		cin.ignore();
		getline(cin, addV);*/

		testThisArray.addValue(addV);

		for (int i = 0; i < testThisArray.theSize; i++) {
			cout << "Index: " << i << ", Value: " << testThisArray[i] << endl;
		}
		int index;
		do {
			
			cout << "Index #: ";
			cin >> index;
			if (index < testThisArray.theSize && index >= 0) {
				cout << "New Value: ";
				int newValue;
				cin >> newValue;
				/*string newValue;
				cin.ignore();
				getline(cin, newValue);*/
				testThisArray[index] = newValue;
				cout << "Index: " << index << ", Value: " << testThisArray[index] << endl;
			}
		} while (index != -1);

		for (int i = 0; i < testThisArray.theSize; i++) {
			cout << "Index: " << i << ", Value: " << testThisArray[i] << endl;
		}

	} while (true);

}

