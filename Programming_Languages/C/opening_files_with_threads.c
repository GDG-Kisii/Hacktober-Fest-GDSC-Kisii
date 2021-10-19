#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <fcntl.h>

/** create a thread
 ** open 2 files through threads
 */
static void *ThreadFunc(){ //opens 1st file as single thread
    int fd;
    sleep(1);
    printf("\nPrinting 1st Thread & open file 1\n");
    //open file
    fd = open("threadFile1.txt", O_RDONLY | O_WRONLY | O_CREAT);
    if (fd != 0){ perror("\nError in opening 1st threadFile\n");} //error checker

    close(fd);
    return NULL;
}

//2nd thread function
static void *ThreadFunc1(){  //opens 2nd file as single thread
    int fd1;
    sleep(1);
    printf("\nSecond thread\n");
    fd1 = open("threadFile2.txt", O_RDONLY | O_WRONLY | O_CREAT);
    if (fd1 != 0){ perror("\nError in opening 2nd threadFile\n");} //error checker

    close(fd1);
    return NULL;

}
int main(){

    pthread_t thread_id;
    pthread_t thread_id1;

    printf("\nBefore thread\n");

    /**ThreadFunc(),printing 1st threaded file
     *
     */
    pthread_create(&thread_id,NULL,ThreadFunc,NULL);
    pthread_join(thread_id,NULL);

    /**ThreadFunc1(),printing 2nd threaded file
     *
     */
    pthread_create(&thread_id1,NULL,ThreadFunc1,NULL);
    pthread_join(thread_id1,NULL);

    printf("\nAfter Thread\n");
    exit(0);

}
}
