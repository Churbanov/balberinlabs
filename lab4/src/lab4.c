/* Пример создания нового
   процесса с разной работой процессов
   ребенка и родителя */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

#include "lab4.h"

int main()
{
    pid_t pid, ppid;
    int a =  0;
    int b =  100; 

    int children = fork();
    if(children == -1){
        return 1;
    }
    
        pid = getpid();
        ppid = getppid();
    if(children == 0){
           b = pr_b(b);
    } else {
        a = pr_a(a);
    }
    printf("My pid = %d, my ppid = %d,result a = %d,result b = %d\n",(int)pid,(int)ppid,a,b);
    return 0;
}
