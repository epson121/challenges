/*
Author: Luka Rajcevic
Language: C++
Date: 24.11. 2012.

http://poj.org/problem?id=1007

One measure of ``unsortedness'' in a sequence is the number of pairs of 
entries that are out of order with respect to each other. For instance, 
in the letter sequence ``DAABEC'', this measure is 5, since D is greater 
than four letters to its right and E is greater than one letter to its 
right. This measure is called the number of inversions in the sequence. 
The sequence ``AACEDGG'' has only one inversion (E and D)---it is nearly 
sorted---while the sequence ``ZWQM'' has 6 inversions (it is as unsorted 
as can be---exactly the reverse of sorted).

You are responsible for cataloguing a sequence of DNA strings (sequences 
containing only the four letters A, C, G, and T). However, you want to 
catalog them, not in alphabetical order, but rather in order of ``sortedness'', 
from ``most sorted'' to ``least sorted''. All the strings are of the same length.

Input
The first line contains two integers: a positive integer n (0 < n <= 50) 
giving the length of the strings; and a positive integer m (0 < m <= 100) 
giving the number of strings. These are followed by m lines, each containing 
a string of length n.

Output
Output the list of input strings, arranged from ``most sorted'' to ``least
 sorted''. Since two strings can be equally sorted, then output them according 
 to the orginal order.

Sample Input

10 6
AACATGAAGG
TTTTGGCCAA
TTTGGCCAAA
GATCAGATTT
CCCGGGGGGA
ATCGATGCAT

Sample Output

CCCGGGGGGA
AACATGAAGG
GATCAGATTT
ATCGATGCAT
TTTTGGCCAA
TTTGGCCAAA
*/
#include <iostream>
#include <string>
#include <list>

using namespace std;

int checkString(string s)
{
	int counter = 0;
	int num = 0;
	for (int i = 1; i < s.size(); i++)
	{
		for (int j = i; j < s.size(); j++)
		{
			if ((int) s[counter] > (int) s[j])
			{
				num++;
			}
		}
		counter++;
	}
	return num;
}

void BubbleSort(int num[], string num2[], int l)
{
      int i, j, flag = 1;    // set flag to 1 to start first pass
      int temp;             // holding variable
      string temp2;
      int numLength = l; 
      for(i = 1; (i <= numLength) && flag; i++)
     {
          flag = 0;
          for (j=0; j < (numLength -1); j++)
         {
               if (num[j+1] > num[j])      // ascending order simply changes to <
              { 
                    temp = num[j];             // swap elements
                    temp2 = num2[j];
                    num[j] = num[j+1];
                    num2[j] = num2[j+1];
                    num[j+1] = temp;
                    num2[j+1] = temp2;
                    flag = 1;               // indicates that a swap occurred.
               }
          }
     }
     for (int i = l-1; i >= 0; i--)a
     {
     	cout << num2[i] << endl;
     }
     return ;  
}

int main()
{
	int a, b;
	string s;
	cin >> a >> b;
	string *s_arr = new string[b];
	int *i_arr = new int[b];
	int min;
	int minS = 0;
	for (int i = 0; i < b; i++)
	{
		cin >> s;
		s_arr[i] = s;
		i_arr[i] = checkString(s);
	}
    BubbleSort(i_arr, s_arr, b);

	return 0;
}