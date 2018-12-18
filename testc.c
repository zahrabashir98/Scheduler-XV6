//
// Created by qhazale on 11/20/18.
//

#include "types.h"
#include "user.h"
#include "table.h"

int main(int argc, char **argv) {
    struct table tb;
    int res = counts(&tb);
    if (res < 0) {
        return -1;
    }
//    for (int i = 0; i <22 ; ++i) {
//        printf(1, "syscall : %d\n", tb.counts[i]);
//    }
    printf(1, "sys_fork : %d \n", tb.counts[0]);
    printf(1, "sys_exit : %d \n", tb.counts[1]);
    printf(1, "sys_wait : %d \n", tb.counts[2]);
    printf(1, "sys_pipe : %d \n", tb.counts[3]);
    printf(1, "sys_read : %d \n", tb.counts[4]);
    printf(1, "sys_kill : %d \n", tb.counts[5]);
    printf(1, "sys_exec : %d \n", tb.counts[6]);
    printf(1, "sys_fstat : %d \n", tb.counts[7]);
    printf(1, "sys_chdir : %d \n", tb.counts[8]);
    printf(1, "sys_dup : %d \n", tb.counts[9]);
    printf(1, "sys_getpid : %d \n", tb.counts[10]);
    printf(1, "sys_sbrk : %d \n", tb.counts[11]);
    printf(1, "sys_sleep : %d \n", tb.counts[12]);
    printf(1, "sys_uptime : %d \n", tb.counts[13]);
    printf(1, "sys_open : %d \n", tb.counts[14]);
    printf(1, "sys_write : %d \n", tb.counts[15]);
    printf(1, "sys_mknod : %d \n", tb.counts[16]);
    printf(1, "sys_unlink : %d \n", tb.counts[17]);
    printf(1, "sys_link : %d \n", tb.counts[18]);
    printf(1, "sys_mkdir : %d \n", tb.counts[19]);
    printf(1, "sys_close : %d \n", tb.counts[20]);
    printf(1, "sys_counts : %d \n", tb.counts[21]);
    exit();
}
