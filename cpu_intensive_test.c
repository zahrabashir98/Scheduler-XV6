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
#define CONSTANT 500000


int main(int argc, char **argv){

    for(int i =0;i<5;i++){
        int pid = fork();
        
        if(pid == 0){
            // printf(1,"i am just a child , %d \n",pid);
            int a ;
            int test_array[CONSTANT];
            for(int i=0;i<CONSTANT;i++){
                test_array[i] = i;
            }
            for(int i = 0;i<CONSTANT;i++){
                for(int j =0;j<CONSTANT;j++){
                    test_array[i] += test_array[i] * test_array[j]; 
                }
            }
            for(a = 0;a<CONSTANT;a++){
                //printf(1,"a:%d \n",a);
            }
        }

        else{
            //printf(1,"i am the parent\n", pid);
            wait();
            // pinfo(getpid(),&p_info);
            // printf(1,"pid: %d ,start_time: %d, schedule: %d, finish: %d\n",p_info.pid,p_info.start_cycle,p_info.schedule_cycle,p_info.finish_cycle);
        }
    }


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
  // struct *proc p ;
  //call sys_call
  // print pid and times

}