//Chmod 777 Fix
//Fix for Cellular Data, iMessage and FaceTime
//by Pedro Adelino
//Nara Logic 2020
//www.bypedro.eu

//Version
#define VERSION_MAJOR 0
#define VERSION_MINOR 1
#define VERSION 0.1
#define VERSION_REVISION 1
//#define VERSION STRINGIZE(VERSION_MAJOR) "." STRINGIZE(VERSION_MINOR)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>      /* needed to use pid_t, etc. */
#include <sys/wait.h>       /* needed to use wait() */  
#include "naralogic.h"
//double app_version = VERSION;
const char *app_version = "0.2";
//int println;
int main(int argc, char **argv)
{
    //int ret;
	//println("Cydia Repos v." + app_version);
    colorprint("Chmod 777 Fix v", "blue");
    colorprint(app_version, "blue");
    colorprint("\n", "blue");
    colorprint("Fix for Cellular Data, iMessage and FaceTime.\n", "blue");
	colorprint("By Pedro Adelino.\n", "blue");
    colorprint("www.bypedro.eu\n", "blue");
    //The following example searches for the location of the command
    //among the directories specified by the PATH environment variable.
    //ret = execlp("ls", "ls", "-l", (char *)NULL);
    
    int commandnr;
    int errors=0;
    FILE *file;

    for(commandnr=1;commandnr<=4;commandnr++){
    pid_t pid;

    pid = fork();
  
    if (pid < 0)
    {
        colorprint("A fork error has occurred. Please try again!\n", "red");
        exit(-1);
    }
    else 
    if (pid == 0) /* We are in the child. */
    {
        if (commandnr == 1){
            //Command1
            //printf("Command1\n");
            //printf("I am the child, about to use execlp.\n");
            //char *command = ;
            execlp("chmod", "chmod", "777", "/var", NULL);
            /*  If execlp() is successful, we should not reach this next line. */
            //printf("The call to execlp() was not successful.\n");
            colorprint("Failed executing command 1.\n", "red");
            errors++;
            exit(127);
        }
        else
        if (commandnr == 2){
            //Command2
            //printf("Command2\n");
            //printf("I am the child, about to use execlp.\n");
            //char *command = ;
            execlp("chmod" , "chmod" , "777", "/var/mobile", NULL);
            /*  If execlp() is successful, we should not reach this next line. */
            //printf("The call to execlp() was not successful.\n");
            colorprint("Failed executing command 2.\n", "red");
            errors++;
            exit(127);
        }
        else
        if (commandnr == 3){
            //Command3
            //printf("Command3\n");
            //printf("I am the child, about to use execlp.\n");
            //char *command = ;
            execlp("chmod" , "chmod" , "777", "/var/mobile/Library", NULL);
            /*  If execlp() is successful, we should not reach this next line. */
            //printf("The call to execlp() was not successful.\n");
            colorprint("Failed executing command 3.\n", "red");
            errors++;
            exit(127);
        }
        else
        if (commandnr == 4){
            //Command4
            //printf("Command4\n");
            //printf("I am the child, about to use execlp.\n");
            //char *command = ;
            execlp("chmod" , "chmod" , "777", "/var/mobile/Library/Preferences", NULL);
            /*  If execlp() is successful, we should not reach this next line. */
            //printf("The call to execlp() was not successful.\n");
            colorprint("Failed executing command 4.\n", "red");
            errors++;
            exit(127);
        }
    }
    else  /* We are in the parent. */
    {
    //Command executed
    //pid = 0;
    wait(0);               /* Wait for the child to terminate. */
    //Go to the next command or exit
    }
    } //Loop
    if (errors == 0) {
        colorprint("All done. Have fun!\n", "green");
    }
    else {
        colorprint("Failed! Please try again!\n", "red");
    }
    //printf("I am the parent.  The child just ended.  I will now exit.\n");
    exit(0);
    return(0); 
}