#include "types.h"

int main(){

  for (int i=0 ; i<6;i++){
    int pid = fork();
    if (pid==0){
        // CPU intesnsive operations
    }
  }
  // struct *proc p ;
  //call sys_call
  // print pid and times

}