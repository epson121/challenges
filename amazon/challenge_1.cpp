/*
Given an array of size n. It contains numbers in the range 1 to n. 
Each number is present at least once except for 2 numbers. Find the missing numbers 

found at:
http://www.geeksforgeeks.org/forums/topic/amazon-interview-question-for-software-engineerdeveloper-about-algorithms-arrays-16/
*/

#include <iostream>

using namespace std;

int * getMissing(int arr[], int size){
	int * a = new int[size + 1];
	int * missing = new int[2];
	int i, count = 0;
	for (i = 0; i < size; i++){
		a[arr[i]] += 1;
	}
	for (i = 1; i <= size; i++){
		if (a[i] == 0){
			missing[count] = i;
			count += 1;
		}
	}
	return missing;
}


int main(){

	//int arr[] = {1, 2, 9, 7, 8, 1, 3, 2, 6, 4};
	// 5 and 10
	//int arr[] = {1, 2, 2, 1};
	// 3 and 4
	int arr[] = {1, 3, 5, 5, 5, 4};
	//2 and 6
	int * result = getMissing(arr, sizeof(arr)/4);
	cout << result[0] << " and " << result[1] << endl;
	delete[] result;
	return 0;
}


