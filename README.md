#Project 1—UNIX Shell and History Feature
##This is the second experiment code for operating system learning
This project consists of designing a C program to serve as a shell interface
that accepts user commands and then executes each command in a separate
process. This project can be completed on any Linux, UNIX, or Mac OS X system.

Part I— Creating a Child Process
The first task is to modify the main() function in Figure 3.36 so that a child
process is forked and executes the command specified by the user. This will
require parsing what the user has entered into separate tokens and storing the
tokens in an array of character strings (args in Figure 3.36). For example, if the
user enters the command ps -ael at the osh> prompt, the values stored in the
args array are:
args[0] = "ps"
args[1] = "-ael"
args[2] = NULL
This args array will be passed to the execvp() function, which has the
following prototype:
execvp(char *command, char *params[]);
Here, command represents the command to be performed and params stores the
parameters to this command. For this project, the execvp() function should
be invoked as execvp(args[0], args). Be sure to check whether the user
included an & to determine whether or not the parent process is to wait for the
child to exit.

Part II—Creating a History Feature
The next task is to modify the shell interface program so that it provides
a history feature that allows the user to access the most recently entered
commands. The user will be able to access up to 10 commands by using the
feature. The commands will be consecutively numbered starting at 1, and
the numbering will continue past 10. For example, if the user has entered 35
commands, the 10 most recent commands will be numbered 26 to 35.
The user will be able to list the command history by entering the command
history
at the osh> prompt. As an example, assume that the history consists of the
commands (from most to least recent):
ps, ls -l, top, cal, who, date
The command history will output:
6 ps
5 ls -l
4 top
3 cal
2 who
1 date
Your program should support two techniques for retrieving commands
from the command history:
1. When the user enters !!, the most recent command in the history is
executed.
2. When the user enters a single ! followed by an integer N, the Nth
command in the history is executed.
Continuing our example from above, if the user enters !!, the ps command
will be performed; if the user enters !3, the command cal will be executed.
Any command executed in this fashion should be echoed on the user’s screen.
The command should also be placed in the history buffer as the next command.
The program should also manage basic error handling. If there are
no commands in the history, entering !! should result in a message “No
commands in history.” If there is no command corresponding to the number
entered with the single !, the program should output "No such command in
history."

***We need to create circular queues to store the commands.
