// n this homework, you’ll measure the costs of a system call and context
// switch. Measuring the cost of a system call is relatively easy. For example,
// you could repeatedly call a simple system call (e.g., performing a 0-byte
// read), and time how long it takes; dividing the time by the number of
// iterations gives you an estimate of the cost of a system call.
// One thing you’ll have to take into account is the precision and accu-
// racy of your timer. A typical timer that you can use is gettimeofday();
// read the man page for details. What you’ll see there is that gettimeofday()
// returns the time in microseconds since 1970; however, this does not mean
// that the timer is precise to the microsecond. Measure back-to-back calls
// to gettimeofday()to learn something about how precise the timer re-
// ally is; this will tell you how many iterations of your null system-call
// test you’ll have to run in order to get a good measurement result. If
// gettimeofday() is not precise enough for you, you might look into
// using the rdtscinstruction available on x86 machines.

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

int main(){
    int n = 1000000;
    struct timeval start, end;

    gettimeofday(&start, NULL);

    for(int i = 0; i<n; i++){
        getpid();
    }

    gettimeofday(&end, NULL);

    long seconds = end.tv_sec - start.tv_sec;
    long useconds = end.tv_usec - start.tv_usec;
    //convert seconds to microsenconds and add useconds(which is already in microseconds)
    long total_time = seconds * 1000000 + useconds;

    double avg_time = (double) total_time / n;

    printf("Total time is %ld\n", total_time);
    printf("Average time for a sys call is %f\n", avg_time);

    return 0;
}