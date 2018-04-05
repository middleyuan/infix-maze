# infix-maze
Determine whether a matrix contains at least a legal infix expression which need to be from the top-left corner to the bottom-right corner.
If yes, convert it based on the postfix notation.  There are some rules to be followed.   
Each cell can be reached by four directions(up, down, right, left). Matrices are consisted of 1~9, +,-,*,/, (, ) 
Each cell can be visited at most one time. The priority directions are: down>right>left>up. 
No negative number. EX: - 5 + 3 is illegal.

# Input
First line is total number of matrices.
Second and third line are matrix width nad height.
Width and height <100.
Following lines are matrix

# Output
Repeat all inputs.
For matrix, there is a white space after every elements.
If there is a legal infix expression from the top-left corner to the bottom-right corner,  output
Yes
infix expression ( there is a white space after every elements.)
postfix expression
If No, output
No

# Sample input
3|
7|
6|
8 8 3 8 ( - 9|
) / ) / / 6 2|
1 ) ( - 8 ( -|
) / 3 3 ( 9 6|
) 7 2 2 ( / )|
) 3 * * ( ) 9|
6|
6|
9 * / 6 ( 7|
3 3 8 9 4 )|
7 9 ) - 3 1|
( * ) 3 2 /|
1 7 - ) 1 2|
* 4 ( 7 7 7|
8|
7|
9 3 5 4 - ) 9 6|
2 * ) 6 + 6 + (|
- 5 8 9 ( + 2 8|
4 2 5 6 ( 6 ( 7|
6 4 ) / ) 9 + 5|
+ 9 9 9 9 + 5 (|
8 + ( ( 6 1 / 5|

# Sample output
3|
7|
6|
8 8 3 8 ( - 9|
) / ) / / 6 2|
1 ) ( - 8 ( -|
) / 3 3 ( 9 6|
) 7 2 2 ( / )|
) 3 * * ( ) 9|
No|
6|
6|
9 * / 6 ( 7|
3 3 8 9 4 )|
7 9 ) - 3 1|
( * ) 3 2 /|
1 7 - ) 1 2|
* 4 ( 7 7 7|
Yes|
9379 * ( 1 * 47 - ( 77123 ) ) - 31 / 27|
9379 1 47 * 77123 - * 31 27 / -|
8|
7|
9 3 5 4 - ) 9 6|
2 * ) 6 + 6 + (|
- 5 8 9 ( + 2 8|
4 2 5 6 ( 6 ( 7|
6 4 ) / ) 9 + 5|
+ 9 9 9 9 + 5 (|
8 + ( ( 6 1 / 5|
Yes|
92 - 46 + 8 + ( ( 61 + 99994 ) / 65258 ) * 3546 + 6 + 69 + 5 / 5|
92 46 - 8 + 61 99994 + 65258 / 3546 * + 6 + 69 + 5 5 / +|
