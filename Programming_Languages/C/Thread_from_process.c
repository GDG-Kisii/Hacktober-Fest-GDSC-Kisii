/** create a thread from a process
 *
 */
#include<pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void *threadFunc(void *arg)
{
    char *str = (char *)arg;
    printf("ThreadFunc: arguments passed are: %s, pid = (%d)\n",str,getpid());
    (void) sleep(2);
    printf("\nthreadFunc:exiting now\n");
    return 0;
}

int main(){

    //a data type used to uniquely identify a thread
    pthread_t t1;
    int s;

s = pthread_create(&t1,NULL,threadFunc,"Hello thread");
     if (s != 0) { perror("Error in thread creation"); }
    printf("Main thread:message from main(), pid = (%d)\n",getpid());
    sleep(5);
printf("\nmain thread:exiting now\n");

exit(0);




}
