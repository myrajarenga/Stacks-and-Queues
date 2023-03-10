# Stacks-and-Queues
The goal of this project is to create an interpreter for Monty ByteCodes files


0x18. C - Stacks, Queues - LIFO, FIFO
The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

Monty byte code files
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$
The monty program
Usage: monty file
where file is the path to the file containing Monty byte code
If the user does not give any file or more than one argument to the program, the error message USAGE: monty file will print, followed by a new line, and exit with the status EXIT_FAILURE
If, for any reason, it’s not possible to open the file, the error message Error: Can't open file <file> will print, followed by a new line, and exit with the status EXIT_FAILURE
where <file> is the name of the file
If the file contains an invalid instruction, print the error message L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE
where is the line number where the instruction appears.
Line numbers always start at 1
The monty program runs the bytecodes line by line and stop if either:
it executed properly every line of the file
it finds an error in the file
an error occured
If you can’t malloc anymore, the error message Error: malloc failed will print, followed by a new line, and exit with status EXIT_FAILURE.
Compilation
This code can be compiled this way:
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
Output is printed to stdout
Error messages are printed on stderr
Operations
The push opcode pushes an element to the stack.
The pall opcode prints all values on the stack, starting from the top.
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ ./monty bytecodes/00.m
3
2
1
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$
The pint opcode prints the value at the top of the stack.
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ cat bytecodes/06.m 
push 1
pint
push 2
pint
push 3
pint
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ ./monty bytecodes/06.m 
1
2
3
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ 
The pop opcode removes the top element of the stack.
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ cat bytecodes/07.m 
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ ./monty bytecodes/07.m 
3
2
1
2
1
1
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ 
The swap opcode swaps the top two elements of the stack.
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ cat bytecodes/09.m 
push 1
push 2
push 3
pall
swap
pall
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ ./monty bytecodes/09.m 
3
2
1
2
3
1
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ 
The add opcode adds the top two elements of the stack.
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ cat bytecodes/12.m 
push 1
push 2
push 3
pall
add
pall

julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$ ./monty bytecodes/12.m 
3
2
1
5
1
julien@ubuntu:~/0x18-stacks_queues_lifo_fifo$
The nop opcode doesn't do anything.
