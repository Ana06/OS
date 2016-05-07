# OS

Design and implementation of applications based on OS services. This project was developed during a university course (Advanced topics in operating systems and networks) in 2016.
 
 
 
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



## Licence

Code published under MIT license (see [LICENSE](LICENSE)).