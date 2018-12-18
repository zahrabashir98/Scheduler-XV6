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
