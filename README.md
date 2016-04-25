# OS

 Design and implementation of applications based on OS services.
 
 
## File system management 


### stat.c

Emulates the stat command.


### links.c

Recives a route as an argument. If the route is a regular file it creates a symbolic link and a hard link (with the same name but finished in .sym and .hard respectively). 


### redirection.c

Redirects the standar and the error exits to a file, whose path it is sent as first argument.


## Licence

Code published under MIT license (see [LICENSE](LICENSE)).