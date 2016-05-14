# OS

Design and implementation of applications based on OS services. This project was developed during a university course (Advanced topics in operating systems and networks) in 2016.
 
 
 
## Pipes


### pipe-name.c

Opens the pipe with name *$HOME/tuberia* in write only mode and writes in it the first argument of the program.


## multiple-pipes.c

Creates two pipes with name and wait until there is data to read in any of them. Then it writes the name of the pipe it read from and the data read.


## two-commands-shell.c


Emulates the behaviour of a shell in th execution of *command1 argument1 | command2 argument2*. It opens a pipe without name and creates a child. The parent executes *command1 argument1* and redirects the standar output to the write end of the pipe. The child executes *command2 argument2* and redirects the standar input to the read end of the pipe.


## full-duplex.c


Full-duplex communication using two pipes without name (*p_h* and *h_p*). The parent reads from standar input and send the message to his child using *p_h* pipe and freezes until the child answers. The child reads from *p_h*, writes the message received and wait a second. After that he sends his parent an *l* using *h_p* pipe to indicate that he is ready to receive more messages. After having received ten messages he sends a *q* to his parent to order him to finish.



## Process management and signaling 


### chrt.c

Shows the scheduling policy, the scheduling priority, the priority maximum value and the priority minimum value.

 
### ps.c

Shows the ids (id, group id and session id) of the process, the maximun number of files that the process can open and the actual directory.


### demon.c

Normally a demon has its own session an group. To ensure that it is possible to create it, a fork is done. This is a demon template, where the process attributes are showed (similar to how it is done in **ps.c**) and the work directory is set to */tmp*.


### demonize.c

Executes any program as a demon and redirects the terminal outputs.


### super-shell.c

Execute a shell with a FIFO scheduler policy with the priority given as an argument. If it is not given the maximum priority is set.


### super-shell.c

Execute a shell with a FIFO scheduler policy with the priority given as an argument. If it is not given the maximum priority is set.


### block-signal.c

Blocks the SIGINT and SIGTSTP signals and then sleep for a number of seconds given by the settings variable SLEEP_SECS. When it wakes up, informs if the SIGNT or/and SIGTSTP signals where received. After that the signals are unblocked and a  good-bye message displayed (if SIGTSTP was received as it has been unblicked the message will not be displayed).


### count-signal.c

Installs a handler of SIGINT and SIGTSTP signal. The program keeps in a while until ten SIGINT or SIGTSTP signals are received. Ater that it shows the numbers of signal of each type received and finishes.


### self-destruction.c

The program self-destruct (delete its executable file) after a number of seconds given as an argument. The self-destruction can be stoped by sending the SIGUSR1 signal.


## File system management 


### stat.c

Emulates the stat command.


### links.c

Recives a route as an argument. If the route is a regular file it creates a symbolic link and a hard link (with the same name but finished in .sym and .hard respectively). 


### redirection.c

Redirects the standar and the error exits to a file, whose path it is sent as first argument.


### lock.c

Checks and prints the state of a file lock. If it is unlocked a write lock is set and the current time printed. After that it sleeps during 30 second and then frees the lock.


### ls.c

Advanced ls.



## Authors

This project was developed by Ana María Martínez Gómez.



## Licence

Code published under MIT license (see [LICENSE](LICENSE)).