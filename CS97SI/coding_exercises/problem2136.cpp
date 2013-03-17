/*
Author: Luka Rajcevic
Language: C++
Date: 25.11. 2012.

http://poj.org/problem?id=2136

Write a program to read four lines of upper case (i.e., all CAPITAL LETTERS) 
text input (no more than 72 characters per line) from the input file and print 
a vertical histogram that shows how many times each letter (but not blanks, digits, 
or punctuation) appears in the all-upper-case input. Format your output exactly as shown.

Input
* Lines 1..4: Four lines of upper case text, no more than 72 characters per line.

Output
* Lines 1..??: Several lines with asterisks and spaces followed by one line with 
the upper-case alphabet separated by spaces. Do not print unneeded blanks at the 
end of any line. Do not print any leading blank lines.

Sample Input

THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG.
THIS IS AN EXAMPLE TO TEST FOR YOUR
HISTOGRAM PROGRAM.
HELLO!

Sample Output

                            *
                            *
        *                   *
        *                   *     *   *
        *                   *     *   *
*       *     *             *     *   *
*       *     * *     * *   *     * * *
*       *   * * *     * *   * *   * * * *
*     * * * * * *     * * * * *   * * * *     * *
* * * * * * * * * * * * * * * * * * * * * * * * * *
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z


*/
#include <iostream>
#include <string>

using namespace std;

void createAlphabet()
{
	for (int i = 65; i < 90; i++)
	{
		cout << (char) i << " " ;
	}
	cout << "Z";
}

int main()
{
	int i_arr[26] = {0};
	char s[72] = {};	
	int counter = 0;
	for (int i = 0; i < 4; i++)
	{
		cin.getline (s,72);
		for (int j = 0; j < 72; j++)
		{
			int k = (int) s[j];
			if (k >= 65 && k < 91)
				i_arr[k - 65] += 1;
		}
		for (int l = 0; l < 72; l++)
			s[l] = '0';
	}
	int max = i_arr[0];
	for (int i = 1; i < 26; i++)
	{
		if (i_arr[i] > max)
			max = i_arr[i];
	}
	while (max > 0)
	{
		for (int j = 0; j < 26; j++)
		{
			if (i_arr[j] == max)
			{
				cout << "* ";
				i_arr[j] -= 1;
			}
			else
				cout << "  ";
		}
		cout << endl;
		max--;
	}
	createAlphabet();
	return 0;
}