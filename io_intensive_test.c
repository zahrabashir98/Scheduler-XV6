// #include "types.h"
// #include "stdio.h"
// #include "stdlib.h"
// #include "param.h"
// #include "types.h"
// #include "stat.h"
// #include "user.h"
// #include "fs.h"
// #include "fcntl.h"
// #include "syscall.h"
// #include "traps.h"
// #include "memlayout.h"
// //  #include <bits/libc-header-start.h>

// void writetest(void)
// {
//   int fd;
//   int i;
//   int stdout = 1;
//   char buf[8192];

//   printf(stdout, "small file test\n");
//   fd = open("small", O_CREATE|O_RDWR);
//   if(fd >= 0){
//     printf(stdout, "creat small succeeded; ok\n");
//   } else {
//     printf(stdout, "error: creat small failed!\n");
//     exit();
//   }
//   for(i = 0; i < 100; i++){
//     if(write(fd, "aaaaaaaaaa", 10) != 10){
//       printf(stdout, "error: write aa %d new file failed\n", i);
//       exit();
//     }
//     if(write(fd, "bbbbbbbbbb", 10) != 10){
//       printf(stdout, "error: write bb %d new file failed\n", i);
//       exit();
//     }
//   }
//   printf(stdout, "writes ok\n");
//   close(fd);
//   fd = open("small", O_RDONLY);
//   if(fd >= 0){
//     printf(stdout, "open small succeeded ok\n");
//   } else {
//     printf(stdout, "error: open small failed!\n");
//     exit();
//   }
//   i = read(fd, buf, 2000);
//   if(i == 2000){
//     printf(stdout, "read succeeded ok\n");
//   } else {
//     printf(stdout, "read failed\n");
//     exit();
//   }
//   close(fd);

//   if(unlink("small") < 0){
//     printf(stdout, "unlink small failed\n");
//     exit();
//   }
//   printf(stdout, "small file test ok\n");
// }
// int main(int argc, char **argv){
// printf(1,"HOOOOO");
// // writetest();

//   // struct *proc p ;
//   //call sys_call
//   // print pid and times
// exit();
// }

#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"
#include "table.h"

char buf[8192];
char name[3];
char *echoargv[] = { "echo", "ALL", "TESTS", "PASSED", 0 };
int stdout = 1;

void
writetest1(void)
{
  int i, fd, n;

  printf(stdout, "big files test\n");

  fd = open("big", O_CREATE|O_RDWR);
  if(fd < 0){
    printf(stdout, "error: creat big failed!\n");
    exit();
  }

  for(i = 0; i < MAXFILE; i++){
    ((int*)buf)[0] = i;
    if(write(fd, buf, 512) != 512){
      printf(stdout, "error: write big file failed\n", i);
      exit();
    }
  }

  close(fd);

  fd = open("big", O_RDONLY);
  if(fd < 0){
    printf(stdout, "error: open big failed!\n");
    exit();
  }

  n = 0;
  for(;;){
    i = read(fd, buf, 512);
    if(i == 0){
      if(n == MAXFILE - 1){
        printf(stdout, "read only %d blocks from big", n);
        exit();
      }
      break;
    } else if(i != 512){
      printf(stdout, "read failed %d\n", i);
      exit();
    }
    if(((int*)buf)[0] != n){
      printf(stdout, "read content of block %d is %d\n",
             n, ((int*)buf)[0]);
      exit();
    }
    n++;
  }
  close(fd);
  if(unlink("big") < 0){
    printf(stdout, "unlink big failed\n");
    exit();
  }
  printf(stdout, "big files ok\n");
}

int main(){
writetest1();

    struct table table;
    int n = counts(&table);
    // if error
    if (n < 0) {
        return -1;
    }
    printf(1,"TESTTT\n");
    int ctime = table.counts[0];
    int ltime = table.counts[1];
    int first_res_time = table.counts[2];
    printf(1, "ctime : %d \n", table.counts[0]);
    printf(1, "ltime : %d \n", table.counts[1]);
    printf(1, "first_res_time : %d \n", table.counts[2]);
    printf(1, "test : %d \n", table.counts[3]);
    printf(1, "TurnAroundTime : %d\n",ltime-ctime );
    printf(1, "ResponseTime : %d\n", ltime-first_res_time);

exit();
}