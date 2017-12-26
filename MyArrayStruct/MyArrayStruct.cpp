#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T, size_t initSize = 0>
struct MyArray {
private:
	T *arrayValue = NULL;
	size_t theSize = initSize;
public:

	MyArray() {
		arrayValue = new T[theSize];
	}

	MyArray(initializer_list<T> initList) {
		theSize = initList.size();
		arrayValue = new T[theSize];
		for (size_t i = 0; i < theSize; i++) {
			arrayValue[i] = *(initList.begin() + i);
		}
	}

	~MyArray() {
		if (arrayValue) {
			delete[] arrayValue;
			arrayValue = NULL;
		}
	}

	T& operator[](size_t i) {
		return arrayValue[i];
	}
	void addValue(T valueToAdd) {
		T *tempArray = new T[++theSize];

		tempArray[theSize - 1] = valueToAdd;

		for (size_t i = 0; i < theSize - 1; i++) {
			tempArray[i] = arrayValue[i];
		}

		delete[] arrayValue;
		arrayValue = tempArray;
	}

	void reSize(size_t newSize) {
		size_t oldSize = theSize;
		theSize = newSize;
		if (newSize <= 0) {
			delete[] arrayValue;
			arrayValue = NULL;
			return;
		}
		else if (oldSize == 0 && newSize > 0) {
			arrayValue = new T[newSize];
			return;
		}

		
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

	size_t size() {
		return theSize;
	}
};

void wae() {
	MyArray<int> we;
	//we.reSize(0);
}

void main() {

	wae();

	vector<int> testmi = { 23,56,87,12,5 };
	const int i = 2, j = 2, k = 2, l = 2, m = 2;

	vector<vector<string>> multiStringV = { {"hello",",world"},{"fuck",",world2"} };
	for (size_t i = 0; i < multiStringV.size(); i++) {
		for (size_t j = 0; j < multiStringV[i].size(); j++) {
			//multiStringV[i][j] = to_string(i) + ":" + to_string(j) + ",";
			cout << multiStringV[i][j];
		}
		cout << "-Column" << endl;
	}
	//MyArray <MyArray<string, j>, i> multiMyArray;

	/*for (size_t i = 0; i < multiMyArray.size(); i++) {
		for (size_t j = 0; j < multiMyArray[i].size(); j++) {
			multiMyArray[i][j] = to_string(i) + ":" + to_string(j) + ",";
			cout << multiMyArray[i][j];
		}
		cout << "-Column" << endl;
	}*/
	/*MyArray <MyArray<MyArray<MyArray<MyArray<string, m>, l>, k>, j>, i> multiMyArray;
	for (size_t i = 0; i < multiMyArray.size(); i++) {
		for (size_t j = 0; j < multiMyArray[i].size(); j++) {
			for (size_t k = 0; k < multiMyArray[j].size(); k++) {
				for (size_t l = 0; l < multiMyArray[k].size(); l++) {
					for (size_t m = 0; m < multiMyArray[l].size(); m++) {
						multiMyArray[i][j][k][l][m] = to_string(i) + ":" + to_string(j) + ":" + to_string(k) + ":" + to_string(l) + ":" + to_string(m) + ",";
						cout << multiMyArray[i][j][k][l][m];
					}
					cout << "-l" << endl;
				}
				cout << "-k" << endl;
			}
			cout << "-j" << endl;
		}
		cout << "-i" << endl;
	}*/

	MyArray<int, 19> mulSize;
	mulSize.reSize(0);
	mulSize.reSize(10);
	//do {

		MyArray<string> testThisSizedArray;
		for (int i = 0; i < testThisSizedArray.size(); i++) {
			cout << "Index: " << i << ", Value: " << testThisSizedArray[i] << endl;
		}
		MyArray<string> testThisArray = { "hello","World" };
		MyArray<int> thisIsIntArray = { 123,56,123,678,23,5,0 };
		cout << "Value to add to array of String: ";
		string addV;
		getline(cin, addV);

		testThisArray.addValue(addV);

		for (int i = 0; i < testThisArray.size(); i++) {
			cout << "Index: " << i << ", Value: " << testThisArray[i] << endl;
		}
		int index;
		do {

			cout << "Choose Index # to modify: ";
			cin >> index;
			cin.ignore();
			if (index < testThisArray.size() && index >= 0) {
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

		for (int i = 0; i < testThisArray.size(); i++) {
			cout << "Index: " << i << ", Value: " << testThisArray[i] << endl;
		}

		// INT
		for (int i = 0; i < thisIsIntArray.size(); i++) {
			cout << "Index: " << i << ", Value: " << thisIsIntArray[i] << endl;
		}

		cout << "Give New Size to Array of INT: ";
		cin >> resizeIt;
		thisIsIntArray.reSize(resizeIt);

		for (int i = 0; i < thisIsIntArray.size(); i++) {
			cout << "Index: " << i << ", Value: " << thisIsIntArray[i] << endl;
		}

	//} while (true);

}

