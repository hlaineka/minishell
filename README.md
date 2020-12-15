# minishell


The project is not ready, work still in progress!

This shell was coded by Helvi Lainekallio (hlaineka) as a part of Hive
Helsinki studies. 
Code and subject of the project can be found on
https://github.com/hlaineka/minishell.
Only allowed readymade functions in this project are listed below. Everything
else coded by me, including my own printf, ls-command and c-library.

Allowed readymade functions in this project:

    - malloc, free
    - access
    - open, close, read, write
    - opendir, readdir, closedir
    - getcwd, chdir
    - stat, lstat, fstat
    - fork, execve
    - wait, waitpid, wait3, wait4
    - signal, kill
    - exit

Mandatory requirements of the project:

    - You must program a miniUNIXcommand interpreter.
    - This interpreter must display a prompt (a simple "$>" for example) and wait tillyou type a command line,
    validated by pressing enter.
    - The prompt is shown again only once the command has been completely executed.
    - The command lines are simple, no pipes, no redirections or any other advancedfunctions.
    - The executable are those you can find in the paths indicated in thePATHvariable.
    - In cases where the executable cannot be found, it has to show an error message anddisplay the prompt again.
    - You must manage the errors without usingerrno, by displaying a message adaptedto the error output.
    - You must deal correctly with thePATHand the environment (copy of systemchar**environ).
    - You must implement a series of builtins:echo,cd,setenv,unsetenv,env,exit.
    - You can choose as a reference whatever shell you prefer.
    - You must manage expansions $ and ̃

Additional features:

    - Structure of the program has been planned so that it is scalable to future projects of 21sh and 42sh
    - Arrow keys up, left and right
    - Command history behind arrow up

The structure of the program is shown in the activity diagram below:

![Activity diagram](/images/activity_diagram.png)

