Variable-Base Expression Evaluation
You've woken up one day to find that everyone suddenly expresses numbers in different number bases. You're seeing prices in octal and phone numbers in hexadecimal. It's a numerical Tower of Babel! For your own sanity, you decide to program a simple mathematical expression evaluator that can handle numbers in different number bases. It should support addition, subtraction, and multiplication, should respect order of operations, and should handle number bases between 2 and 16.

While your language of choice may directly support expression evaluation, please create your own.

The input on stdin is a mathematical expression on a single line. Number constants are expressed like "123_4", which is "123" in base 4, which is 27 in base 10. Some digits in the higher bases will be represented with uppercase letters. Numbers within the expression will always be non-negative integers. The operators will be +, -, and *. Whitespace should be ignored.

Your program should emit to stdout a single base-10 number with no underscores.

While correctness and performance are the most important parts of this problem, a human will be reading your solution, so please make an effort to submit clean, readable code. In particular, do not write code as if you were solving a problem for a competition.

Here's an example input and output:

   Input:
1430_5 - 110_2 * 2A_12 + 10_10

   Output:
46