/*
Author: Luka Rajcevic
Language: C++
Date: 25.11. 2012.

The cows in farmer John's herd are numbered and branded with consecutive integers from 
1 to N (1 <= N <= 10,000,000). When the cows come to the barn for milking, they always 
come in sequential order from 1 to N.

Farmer John, who majored in mathematics in college and loves numbers, often looks for 
patterns. He has noticed that when he has exactly 15 cows in his herd, there are precisely 
four ways that the numbers on any set of one or more consecutive cows can add up to 15 
(the same as the total number of cows). They are: 15, 7+8, 4+5+6, and 1+2+3+4+5.

When the number of cows in the herd is 10, the number of ways he can sum consecutive cows 
and get 10 drops to 2: namely 1+2+3+4 and 10.

Write a program that will compute the number of ways farmer John can sum the numbers on 
consecutive cows to equal N. Do not use precomputation to solve this problem.

Input
* Line 1: A single integer: N

Output
* Line 1: A single integer that is the number of ways consecutive cow brands can sum to N.

Sample Input

15

Sample Output

4


*/
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int limit = N/2;
	int sum = 0;
	int times = 0;
	for (int i = 1; i <= limit + 1; i++)
	{
		for (int j = i; j <= limit + 1; j++)
		{
			sum += j;
			if (sum == N)
			{
				times += 1;
				sum = 0;
				break;
			}
			if (sum > N)
				break;
		}
		sum = 0;
	}
	cout << times + 1 << endl;
	return 0;
}