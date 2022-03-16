# This project aims to introduce the UNIX system - pipes and redirection.

I. Important keywords:
	* Process:
A process refers to an executing program in computer memory. <br>
In most operating systems, the execution of a process is in five different stages: start, ready, running, waiting, and terminated. To execute a process in a computer system, resources such as memory, CPU time, and input-output (I/O) devices are needed.
	* Process State:<br>
		<img width="1279" alt="Screen Shot 2022-02-26 at 4 15 40 PM" src="https://user-images.githubusercontent.com/95033881/155848544-61bec2de-62e4-494f-8fbd-d3cb1bfab274.png">
		
	* Fork():
Fork system call is used for creating a new process, which is called child process, which runs concurrently with the process that makes the fork() call (parent process). After a new child process is created, both processes will execute the next instruction following the fork() system call. A child process uses the same pc(program counter), same CPU registers, same open files which use in the parent process.


Negative Value: creation of a child process was unsuccessful.
Zero: Returned to the newly created child process.
Positive value: Returned to parent or caller. The value contains process ID of newly created child process.

	* Wait():
A call to wait() blocks the calling process until one of its child processes exits or a signal is received. After child process terminates, parent continues its execution after wait system call instruction. 
Child process may terminate due to any of these: 

+ It calls exit();
+ It returns (an int) from main
+ It receives a signal (from the OS or another process) whose default action is to terminate.

It takes no parameters and returns an integer value. Below are different values returned by fork().

2. Useful resources:
	* Understanding OS, Process, Fork() etc ... :
	   * https://youtube.com/playlist?list=PLBlnK6fEyqRiVhbXDGLXDk_OQAeuVcp2O
