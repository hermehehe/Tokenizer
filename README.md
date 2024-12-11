**Description**

This project tackles tokenization (converting input text to tokens) by using hashtables to store these tokens. This program reads input text, breaks it up into words and stores each unique word into a directionary as well a hashtable that keeps track of each word and its corresponding index in the dictionary (its "token"). Tokenizing in this way allows for faster search and retrieval of words without needing to search the entire array in most cases. This is useful as tokenization is commonly used in AI Natural Language Processing tasks. This project was a way for me to apply my knowledge of hashtables and continue practice desiging my own data stucture classes. 

I wrote this project in 5 days. Some ways I could have improved this project was to use a growable array for the dictionary instead of a fixed size, I also could have ensured that the user can only use the M command to create a hashtable only once per session.

Each class, as well as its functions are declared in their own .hpp files. All definitions for all classes are in one .cpp file. A main.cpp file handles all user input.

![image](https://github.com/hermehehe/Tokenizer/assets/166939272/c3382994-c54c-4f49-a100-bee8ccb0e6e0)

**Important Classes** 

**Tokenizer Class**

- Created a tokenizer class to easily access, search through and sync, the dictionary and the hashtable in the same functions, which is why the constructor creates a hashtable and dictionary pointers, then deletes them in the destructor

**Hashtable Class**

- Constructor creates a an array of linked lists which is the data structure of our hashtable
- Also have a hashArraySize integer to remember the size of the hashtable (taken in from user input) to use in calculations like k mod m

**Dictionary Class**

- Dictionary is an array of strings. There is a pointer to the array, and integer for the size for the size of the array and an index counter that keeps track of the index of the last word added, increases by 1 (using add_index())every time a word is added to the dictionary


*COMMANDS* 

In the terminal type the commands in all caps followed by their appropriate parameters:

* *M* m - creates a new hash table with size of integer m. Outputs "success".
* *INSERT* word - inserts a word into the tokenizer updating the dictionary and hashtable. Outputs "success" if word doesn't already exist in dictionary and doesn't use non-alphabetical characters, otherwise outputs "failure".
* *READ* filename - Read words from the file named “filename”, adds words to tokenizer. Output conditions same as INSERT command ^^.
* *TOKENIZE* word - Return the token (index in the dictionary) associated with this word. If word is found in the hashtable output is its token. Otherwise output 0.
* *RETRIEVE* t - Retrieves the word with token t (an integer). Outputs the word if token exists other
* *STOK* string of words - Tokenize all words in the provided string, the input string should end with "_DONE_" and should not appear elsewhere into the string. Outputs each words' token in order and 0 if the word is not apart of the dictionary. 
* *TOKS* string of tokens - turns a string of tokens into a string of words. Outputs string of words and UNKOWN for any tokens not associated with a word.


This code has been throughly tested for errors and memory leaks using valgrind.




