# DESIGN-AND-ANALYSIS-ALGORITHM
This program used different sorting algorithms (Insertion, Merge, Quick,Heahp) to sort N randomly generated numbers and analyze their running time.

CODE STRUCTURE
• The program asks the user to choose a program that will generate the
elements of the array.
• You will choose between 1, 2, and 3. The first one is Generating the elements
randomly using the function rand(), the picked numbers has a range from 0
to 1000000. The second one is Generating increasing sorted Integers by
asking the user to input a positive integer X, then compute N + (i + 1) * X . i
is the incrementing loop variable. The third one is to terminate the program.
• If you choose 1 or 2, the program will ask the user to input a number that will
determine the size of the array and store it to N variable.
(10,100,1000,10000,100000)
• The program will now generate the inputs of the array and sort the inputs
into increasing order using 4 different Sorting Algorithms (Insertion Sort,
Merge Sort, Quick Sort, Heap Sort). The sorting algorithms were
implemented using functions.
• Next in the main function it calls a function named sorting which calls all
sorting algorithms function the function also measure the time taken by the
process of specific sorting algorithm.
• The start = clock(); function was declared before the calling function of
specific sorting algorithm and end = clock(); function was declared after the
call function.
• After the first sorting technique before proceeding to the next call the
program calls a function called copy that will copy the original order of the
array from the temporary array named tempArr[]; then it proceeds to the
next sorting algorithm doing the same process until all sorting algorithm is
called.
• The program will only terminate if you input number 3 when the program
asks for selection.
• The output is outputted in an output file “README.txt” that shows the List
of Array before sorting and the list of arrays after using 4 different sorting
algorithms.
• In the output file, it also displays the time take by the process of specific
sorting algorithms

PROBLEMS ENCOUNTERED
• The problem that we encountered is when we compile the program with 100k inputs. We
used dev C++. If the user selected number 2 which is generating the input in increasing
order, the program terminates after insertion sort and mergesort call function

• To solve the problem, we try to compile the program online and the program
works.
