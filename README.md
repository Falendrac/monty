# Monty - 0x19 - C. Stacks, Queues - LIFO, FIFO

## General

For this project, we have created an interpreter for Monty ByteCodes files. 

***

## Learning Objectives

* What do LIFO and FIFO mean
* What is a stack, and when to use it
* What is a queue, and when to use it
* What are the common implementations of stacks and queues
* What are the most common use cases of stacks and queues
* What is the proper way to use global variables


## Requirements
```
To compile : 

gcc -Wall -Werror -Wextra -pedantic -std=c90 *.c -o monty
```
***

## Description

As a reminder, Monty 0.98 is a scripting language which is first compiled into Monty byte codes (just like Python). It relies on a single stack, with specific instructions for handling it.
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

````
julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty
````


The command to run the program is as follows:
```
./monty ./00.m
```


### Description of the different commands :

* __push__ : pushes an element to the stack
* __pall__ : prints all the values on the stack, starting from the top of the stack.
* __pint__ : prints the value at the top of the stack, followed by a new line.
* __pop__ : removes the top element of the stack.
* __swap__ : swaps the top two elements of the stack.
* __add__ : adds the top two elements of the stack.
* __nop__ : doesn’t do anything.
* __sub__ : subtracts the top element of the stack from the second top element of the stack.
* __div__ : ivides the second top element of the stack by the top element of the stack.
* __mul__ : multiplies the second top element of the stack with the top element of the stack
* __mod__ : computes the rest of the division of the second top element of the stack by the top element of the stack.
* __pchar__ : prints the char at the top of the stack, followed by a new line.
* __pstr__ : prints the string starting at the top of the stack, followed by a new line.
* __rotl__ : rotates the stack to the top, The top element of the stack becomes the last one, and the second top element of the stack becomes the first one.
* __rotr__ : rotates the stack to the bottom, the last element of the stack becomes the top element of the stack.
* __stack__ : sets the format of the data to a stack (LIFO). This is the default behavior of the program.
* __queue__ : sets the format of the data to a queue (FIFO).

***

## Example : 


### Contents of file 00.m : 

```push 0
push 0
push 1
push 2
push 3
pint
pall
swap
pall
add
pall
nop
push 72
pchar
push 0
push 108
push 111
push 111
push 104
push 99
push 83
pstr
````
### Output : 

```
vagrant@ubuntu-focal:~/monty$ ./monty 00.m 
3
3
2
1
0
2
3
1
0
5
1
0
H
School
```

***

## Authors: 
Franck LEGER : [GitHub](https://github.com/Falendrac)

Joel DUMORTIER : [GitHub](https://github.com/jodt/)
