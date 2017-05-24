# CST-370-Final-Project-2
Project #2 (50 points). Find the first common ancestor of two nodes in a
binary search tree. For the following example, the common ancestor of node “30”
and “100” is node “80”, the common ancestor of node “40” and “60” is node “60”.
      80
    30 90
  20  60  100
10  50  70
  40
Avoid storing additional nodes in a data structure. Each node of the binary search
tree having two pointers: one to the left child and the other to the right child, but
there is no pointer to the parent node. This is the same data structure as defined in
the codes BST.h and BST.cpp.
a) (20 points) Design the algorithm and describe it in Pseudo code, including
necessary explanations so that the logic of your algorithm can be
understood.
b) (20 points) Implement your algorithm in C++ and test your implementation
with a tester/driver. In the tester, you can use the function “insert” in
BST.cpp to create a sample Binary Search Tree (either from user input or
hard coded). Then, run a few tests with different pairs of nodes to verify that
your implementation can generate the right ancestor. Again, your
implementation should handle special cases properly.
c) (5 points) Give the running time of your algorithm in big O notation (briefly
explain your reasoning). You may not get the credit for this part if your
program running time is very inefficient.
d) (5 points) Make a video to give an overview of your algorithm and
implementation. Include the link to the video in your written document.
Submission instruction: Zip your source programs and written document in a
single file named as ‘Final_Project2_yourlastname’. For the program, please
include only the source files needed to compile and run successfully.
