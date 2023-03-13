//
// Created by hila953 on 14/03/2022.
//
#include "osm.h"
#include <sys/time.h>


/* Time measurement function for a simple arithmetic operation.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_operation_time(unsigned int iterations){
    if (iterations == 0)
    {
        return -1;
    }
    int a,b,c,d,e;
    a=0;
    b=0;
    c=0;
    d=0;
    e=0;
    timeval start_time, end_time;
    gettimeofday(&start_time, 0);

    for (int i = 0; i < iterations; i+=10) {
        a = a + 4;
        b = b + 100;
        c = c + 72;
        d = d + 35;
        e = e + 200;
        a = a + 45;
        b = b + 1022;
        c = c + 7290;
        d = d + 3456;
        e = e + 211;
    }

    gettimeofday(&end_time, 0);
    double end = double((end_time.tv_sec - start_time.tv_sec) * 1000000000) /iterations;
    end += double((end_time.tv_usec - start_time.tv_usec) * 1000) /iterations;
    return end;
}

/* This function is an empty function
 */
void nothing() {}


/* Time measurement function for an empty function call.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_function_time(unsigned int iterations){
    if (iterations == 0)
    {
        return -1;
    }
    timeval start_time, end_time;
    gettimeofday(&start_time, 0);
    for (int i = 0; i < iterations; i+=10) {
        nothing();
        nothing();
        nothing();
        nothing();
        nothing();
        nothing();
        nothing();
        nothing();
        nothing();
        nothing();
    }
    gettimeofday(&end_time, 0);
    double end = double((end_time.tv_sec - start_time.tv_sec) * 1000000000) /iterations;
    end += double((end_time.tv_usec - start_time.tv_usec) * 1000) /iterations;
    return end;
}



/* Time measurement function for an empty trap into the operating system.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_syscall_time(unsigned int iterations){
    if (iterations == 0)
    {
        return -1;
    }
    timeval start_time, end_time;
    gettimeofday(&start_time, 0);
    for (int i = 0; i < iterations; i+=10) {
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
    }
    gettimeofday(&end_time, 0);
    double end = double((end_time.tv_sec - start_time.tv_sec) * 1000000000) /iterations;
    end += double((end_time.tv_usec - start_time.tv_usec) * 1000) /iterations;
    return end;
}