<p>Rian Delarosa<br>
rjdelaro<br>
11/12/20</p>

Assignment 5 README
---------------
<p>Optional Character Argument Inputs (@): n # (number of elements in array), r # (random seed), p # (how many elements to print).<br>
The default values for these arguments are 100, 8222022, and 100.<br>
Every random number generated is limited to less than or equal to 2^30 -1 through bit masking.<br>
There are three arrays being used: <br>
"array" the default used to keep the same random values for multiple methods.<br>
"sorted_array" the array inputted for each function and is actually sorted.<br>
"move_compare" takes the moves and comparison values returned from each function and sets the correct corresponding variables to them.<br>
A majority of the code for main() and the boolean options is based of my code from asgn3 & asgn4.<br>
There are four sorting methods: Bubble (-b), Shell (-s), Quick (-q), and Binary Insertion (-i)<br>
Each method has their own respective option, .c and .h files that connect to sorting.c<br>
If -A is inputted no sorting method will be printed twice.<br>
Quick sort indexing for its function call and print is + 1 unllike other functions because of a segmentatuion fault error by doing this I was able to avoid the error.<br>
The code within each sorting c file is based from the pseudo code given in the asgn5.pdf file on Canvas.</p>

Steps To Run sorting.c
---------------
<p>Open the Terminal<br>
Enter: ssh rjdelaro@unix.ucsc.edu<br>
Enter: PASSWORD<br>
Enter: cd rjdelaro<br>
Enter: cd asgn5<br>
Enter: ls<br>
Make sure that Makefile, sorting.c, bubble.c, quick.c, shell.c, binary.c and respective counterparts are listed.<br>
Enter: make<br>
Enter: ./sorting -@<br>

