#include "types.h"
#include "defs.h"
#define CONSTANT 1000000


int main(){
  int op_array[CONSTANT];

  for (int i=0 ; i<6;i++){
    int pid = fork();
    if (pid==0){
      // CPU intesnsive operations
      for (int i=0 ; i<CONSTANT; i++){
        op_array[i] = i;
      }
      for (int i=0 ; i<CONSTANT; i++){
        op_array[i] = (op_array[CONSTANT-i] + op_array[i])* op_array[i];
      }

    }
  }
  // struct *proc p ;
  //call sys_call
  // print pid and times

}