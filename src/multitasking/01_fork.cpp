#include <iostream>
#include <unistd.h>


/*
    Demonstrate process creation using fork(). 
    Observe how the OS splits the execution path, assigns different PIDs, 
    and completely isolates the memory space of the parent and child.
*/
int main() {
    int sharedData = 100;

    std::cout << "Shared Data: " << sharedData << std::endl;

    pid_t pid = fork();

    //child process
    if (pid == 0) {
        std::cout << "Child pID: " << getpid() << std::endl;

        sharedData = 500;
        std::cout << "Shared Data: " << sharedData << std::endl;
    }
    //parent process 
    else if (pid > 0) {
        //wait for child to finish
        wait(NULL);

        std::cout << "Parent pID: " << getpid() << std::endl;
        std::cout << "Child pID: " << pid << std::endl;

        std::cout << "Shared Data: " << sharedData << std::endl;
    }
    //error state
    else {
        std::cerr << "Error trying to fork.\n";
    }
}