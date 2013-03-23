/*
Given an array containing only 0s and 1s, find the minimum 
size of subarray containing exactly k-zeros.

http://www.geeksforgeeks.org/forums/topic/amazon-phone-screen/

Ex. 11010100011

result = 5(01000)
*/

#include <iostream>

using namespace std;

// O(n^2)
void findMinSubarray(bool array[], int size, int k){
	int i;
	int minIndex = 0;
	int minChar = 100;
	int zeroCount = 0;
	int charCount = 0;
	for (i = 0; i < size; i++){
		for (int j = i; j < size; j++){
			if (array[j] == 0){
				zeroCount += 1;
				if (zeroCount == k && charCount < minChar){
					minChar = charCount; 
					minIndex = i;
					break;
				}
			}
			charCount += 1;
		}
		charCount = 0;
		zeroCount = 0;
	}
	cout << "starting from index " << minIndex << endl;
	cout << minChar + 1 << "(";
	for (i = minIndex; i <= minIndex + minChar; i++){
		cout << array[i];
		if (i < minIndex + minChar)
			cout << ",";
	}
	cout << ")";
}


void findMinSubarray2(bool arr[], int size, int k){
	int i;
	int indexOne = 0;
	int indexTwo = 0;
	int zeroCount = 0;
	for (i = 0; i < size; i++){
		if (arr[i] == 0){
			zeroCount++;
			if (zeroCount == 1){
				indexOne = i;
				indexTwo = i;
			}
			if (zeroCount == k){
				indexTwo = i;
			}
			if (zeroCount > k)
			{
				indexTwo = i;
				do{
					indexOne++;
				} while(arr[indexOne] != 0);
			}
		}
	} 
	cout << "starting from " << indexOne << " to " << indexTwo << endl;
	cout << "(";
	for (i = indexOne; i <= indexTwo; i++){
		cout << arr[i];
		if (i < indexTwo)
			cout << ",";
	}
	cout << ")";
}

int main(){
	int k;
	//bool arr[] = {1, 0 , 0, 0, 1, 1, 0, 1};
	bool arr[] = {1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1};
	/*
	* k = 1
	* starting from index 2
	* 1(0)
	*
	* k = 3
	* starting from index 6
	* 3(0,0,0)
	*/ 
	cout << "insert k: " << endl;
	cin >> k;
	if (k > 0 && k < sizeof(arr))
		//findMinSubarray(arr, sizeof(arr), k);
		findMinSubarray2(arr, sizeof(arr), k);

	return 0;
}