/*
Author: Luka Rajcevic
Language: C++
Date: 25.11. 2012.

http://poj.org/problem?id=1504

The Antique Comedians of Malidinesia prefer comedies to tragedies. 
Unfortunately, most of the ancient plays are tragedies. Therefore the 
dramatic advisor of ACM has decided to transfigure some tragedies into 
comedies. Obviously, this work is very hard because the basic sense of 
the play must be kept intact, although all the things change to their 
opposites. For example the numbers: if any number appears in the tragedy, 
it must be converted to its reversed form before being accepted into the 
comedy play.

Reversed number is a number written in arabic numerals but the order of 
digits is reversed. The first digit becomes last and vice versa. For example,
 if the main hero had 1245 strawberries in the tragedy, he has 5421 of 
 them now. Note that all the leading zeros are omitted. That means if the 
 number ends with a zero, the zero is lost by reversing (e.g. 1200 gives 21). 
 Also note that the reversed number never has any trailing zeros.

ACM needs to calculate with reversed numbers. Your task is to add two reversed 
numbers and output their reversed sum. Of course, the result is not unique because 
any particular number is a reversed form of several numbers (e.g. 21 could be 12, 
120 or 1200 before reversing). Thus we must assume that no zeros were lost by 
reversing (e.g. assume that the original number was 12).

Input
The input consists of N cases. The first line of the input contains only positive 
integer N. Then follow the cases. Each case consists of exactly one line with two 
positive integers separated by space. These are the reversed numbers you are to add.

Output
For each case, print exactly one line containing only one integer - the reversed 
sum of two reversed numbers. Omit any leading zeros in the output.

Sample Input

3
24 1
4358 754
305 794

Sample Output

34
1998
1
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
using namespace std;

int main()
{
	int N;
	int a_num, b_num, sum, sum_new;
	string a, b, sum_str;
	string a_rev, b_rev;
	string sum_str_rev;
	cin >> N;
	int *s2 =  new int[N];
	for(int i = 0; i < N; i++)
	{
		cin >> a >> b;
		a_rev = string ( a.rbegin(), a.rend() );
		b_rev = string ( b.rbegin(), b.rend() );
		//int one
		istringstream buf(a_rev);
   		buf >> a_num;
   		//int two
   		istringstream buf2(b_rev);
   		buf2 >> b_num;
   		//sum
		sum = a_num + b_num;
		//sum string
		stringstream ss;
   		ss << sum;
  		sum_str = ss.str();
  		//sum_reversed
  		sum_str_rev = string ( sum_str.rbegin(), sum_str.rend() );
  		
  		//int sum_reversed
  		istringstream buf3(sum_str_rev);
   		buf3 >> sum_new;
   		s2[i] = sum_new;
	}
	for (int i = 0; i < N; i++)
		cout << s2[i] << endl;
	return 0;
}