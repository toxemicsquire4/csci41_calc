=============================================================================
						Software Project Management
						  In The Crowded Kitchen
=============================================================================

This group project will introduce you to the complexities of writing software
in larger teams than the groups of 2s or 3s you are used to. You will be
formed into groups of 5 or 6 for this one, and will use a source code
management system like Git or Mercurial. 

First, I will assign a project leader. The project leader is expressly
forbidden from writing any source code, but is free to help the other
programmers if they have any questions. The project leader will split the
tasks below into subtasks and assign the subtasks to students in the team to
complete. He or she will document which students did which subtasks. If a
student fails to do a subtask assigned, he or she will document it as well,
and reassign it to another student.

The project will be to create a program that can do algebra, with one special
twist: every time you use a variable, it will update its value afterwards. So
if x equals 3, then x+x would return 7, since x was 3 the first time, and then
4 the next time, and would be 5 afterwards.

You will read one line of input at a time. The input will be in one of three
forms:
1) Create a variable. All variables are single letters, like x or y. They can
hold values only between 0 and 255.
Valid Example: LET x = 7
Error: LET x = 9 (you can't redeclare a variable - x is already declared to be 7.)
Error: LET bob = 27 (bob is 3 letters)
Error: LET y = 300 (300 is out of range)
Error: z = 2 (forgot the LET)

On an error, print "BAD INPUT" and quit. You should probably make a die()
function.

2) Input an algebraic equation. The code will output the result (or BAD INPUT
if the user types in something bad) of the algebra. Note THERE IS NO ORDER OF
OPERATIONS, just parse the equation from left to right.
So if x = 2 and y = 10, x + y * 2 will output 24, not 22.

x will then be equal to 3, and y will be equal to 11, since every time you
access the value of a variable, it will postincrement the value after returning
it. So if the next line is x + y * 2 again, it will output 28.

You must support the following algebraic operations:
+ (addition)
- (subtraction)
* (multiplication)
/ (division)
^ (exponentiation) 
% (modulus)

Precodition: Every operand and operator will have a space before it, you don't
have to check for this.

3) If the line contains "quit" (or "QUIT") or is just an end of file, then the
program terminates.

========
Grading
========

Each one of these bullet points is worth one letter grade:
1) Use github (or equivalent source code control system) to coordinate the
source code updates across your project. You must have a rich versioning
history in your github (or equivalent) or you will lose half a grade.
2) Document your code. You'll need a 2-page report describing how you broke
the program down, the roles each person took, any problems you encountered,
and how you solved them. Your code will also need to be commented, with each
function having a comments section above it describing the pre-conditions and
post-conditions, as well as what each input variable does and any invariants.
3) You must create a class for holding monotoniclly increasing 8-bit integers.
The class must throw an exception on overflow (varable value exceeding 255),
but the results of the algebraic expressions themselves can be 32-bit ints.
When an exception is thrown, you must catch it in main and die with BAD INPUT.
4) You must create a data structure for tracking all of the variables that
have been created and what values they currently hold. Looking up a variable
must be O(1).
5) Your code must be correct. (Pass 80%+ of the test cases.) 

Tips:
Before you begin coding, you'll need to break the project down to certain
people, and get your files created, a Makefile ready, and get your project set
up on github. If nobody on your team knows how to do this, then that sounds
like a good task to assign one of your teammates.

Almost all tasks rely on another task to be done first. Prioritize critical
tasks that will hold up all other tasks if they are not done.

All grades for this project are individual grades. A student who fails to
complete their task will be penalized. It's possible for half a team to get As
and half the team to get Fs. If you haven't done anything on the project, then
request more work to be done, or you will get an F.


Extra Credit:
Allow for a new command called LOOP x, where x is a positive integer. The code
will run the following algebraic expression x times, printing the results for each.
For example:
LET x = 2
LET y = 5
LOOP 5
2 * x + y ^ 2 - 6
This will print out:
75
138
219
318
435
(This was computed like this: (2*2+5)^2 - 6 = 75, then (2*3+6)^2-6 = 138, then
(2*4+7)^2-6 = 219, etc. Remember, there are no order of operations, you're
welcome.)
6) Write pre- and post-conditions for each variable, and document the contract
7) One student is the project manager and must set a timeline and break tasks
down by student. Figure out which tasks rely on other tasks. Must record when
the tasks are completed, and by whom. If a student fails to deliver, must
reassign task to another student. CANNOT do any coding, but can advise another
student.
