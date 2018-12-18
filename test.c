#include "types.h"
#include "user.h"
#include "data.h"

int main(int argc, char **argv) {

    // create object of struct and test it
    struct table table;
    int n = counts(&table);
    // if error
    if (n < 0) {
        return -1;
    }
    printf(1,"sjjjjjjjjjjjjjjjjjjj");

    // int pid = fork();
    // if (pid > 0) {
    //     nice(2);
    //     sleep(1);
    //     getpri();
    // 	wait();
    // } else {
    // 	nice(0);
    //     sleep(1);
    //     getpri();
    // }
    // exit();


    // 1 means stdout not std error
    // printf(1, "sys_fork : %d \n", table.counts[0]);
    // printf(1, "sys_exit : %d \n", table.counts[1]);
    // printf(1, "sys_wait : %d \n", table.counts[2]);
    // printf(1, "sys_pipe : %d \n", table.counts[3]);
    // printf(1, "sys_read : %d \n", table.counts[4]);
    // printf(1, "sys_kill : %d \n", table.counts[5]);
    // printf(1, "sys_exec : %d \n", table.counts[6]);
    // printf(1, "sys_fstat : %d \n", table.counts[7]);
    // printf(1, "sys_chdir : %d \n", table.counts[8]);
    // printf(1, "sys_dup : %d \n", table.counts[9]);
    // printf(1, "sys_getpid : %d \n", table.counts[10]);
    // printf(1, "sys_sbrk : %d \n", table.counts[11]);
    // printf(1, "sys_sleep : %d \n", table.counts[12]);
    // printf(1, "sys_uptime : %d \n", table.counts[13]);
    // printf(1, "sys_open : %d \n", table.counts[14]);
    // printf(1, "sys_write : %d \n", table.counts[15]);
    // printf(1, "sys_mknod : %d \n", table.counts[16]);
    // printf(1, "sys_unlink : %d \n", table.counts[17]);
    // printf(1, "sys_link : %d \n", table.counts[18]);
    // printf(1, "sys_mkdir : %d \n", table.counts[19]);
    // printf(1, "sys_close : %d \n", table.counts[20]);
    // printf(1, "sys_counts : %d \n", table.counts[21]);
    exit();
}
