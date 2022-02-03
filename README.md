Developed a generalized string class template that can contain characters of any type (String <T>).  
Provided for the ability to store a string of any length.  
In the general case, the string may include zero characters (the value of T ()).  
  
  Construction:  
-> default (blank line);  
-> copy;  
-> move;  
-> initialization by repeating the symbol a specified number of times;  
-> initialization by a pointer to an array of characters (in this case, the line size is not transmitted, and the end of the line is the first inclusion of a zero character (value T ());  
-> initialization with pointers to the beginning (first element) and end (next after the last element) of the array of characters  
-> Convert from a string with a different character type  
  
  Methods:  
-> Assign copy and move.  
-> Obtaining the length of the line.  
-> Check if the line is empty.  
-> Clear line (makes it empty).  
-> Access to the index character (both for reading and writing).  
   Implemented using the [] operator.  
-> Obtaining a "substring": the initial index and length are given and a new string containing the corresponding part of the output string is returned.  
-> Concatenate strings and add one character to a string (as left and right).   
   Implemented by operator overload.  
-> Repeat the line a specified number of times.   
   Implemented both the operation of multiplying a string by an integer (both left and right)  
   Provided for the possibility of multiplication by 0 (returns empty line).   
   For example, multiplying the string “ABC” by 3 has be “ABCABCABC”.  
-> Comparison of lines (==,! =,> =, <=,>, <)  
   The end of a line is considered "smaller" than any character.  
-> String transformations using a functional object:   
   Copy;  
   Move;  
-> Added a keyboard input and display operation for the regular character string (char).  
