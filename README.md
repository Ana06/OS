# OS

 Design and implementation of applications based on OS services.
 
 
## File system management 


### stat.c

Emulates the stat command.


### links.c

Recives a route as an argument. If the route is a regular file it creates a symbolic link and a hard link (with the same name but finished in .sym and .hard respectively). 


### redirection.c

Redirects the standar and the error exits to a file, whose path it is sent as first argument.


### lock.c

Checks and prints the state of a file lock. If it is unlocked a write lock is set and the current time printed. After that it sleeps during 30 second and then frees the lock.


## Licence

Code published under MIT license (see [LICENSE](LICENSE)).