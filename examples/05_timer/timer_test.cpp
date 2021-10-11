#define ONE_MILLION 1000000
#define ONE_BILLION 1000000000

#include <time.h> // clock_nanosleep()
#include <sys/time.h> // gettimeofday() in busy wait implem
#include <pthread.h>
#include <errno.h>
#include <math.h>
#include <iostream>

using namespace std;

int nb_iters_loop = 100000;
float duration_loop;

void calibrate_busy_wait()
{
    nb_iters_loop = 100000;
    struct timeval begin;
    struct timeval end;    
    gettimeofday( & begin, 0);    
    double value;
    
    for (int ct = 0; ct < nb_iters_loop; ct++)
    {
        value += value + log(10 + value + log(10 + value + log(10 + value)));
    }
    
    gettimeofday( & end, 0);    
    duration_loop = (end.tv_sec - begin.tv_sec) + 1e-6 * (end.tv_usec - begin.tv_usec);

}

void do_busy_wait(float seconds)
{    
    int nb_iterations_to_do = nb_iters_loop * (seconds / duration_loop);
    float value;    
    for (int ct = 0; ct < nb_iterations_to_do; ct++)
    {
        value += value + log(10 + value + log(10 + value + log(10 + value)));
    }

}

void * main_thread_high(void * arg)
{
    int c = 0;
    struct timespec ts;
    int period = 10; // ms    
    int status = clock_gettime(CLOCK_REALTIME, & ts);
    if (status != 0)
    {
        perror("clock_gettime");
        exit(123);
    }
    

    const unsigned long period_ms_ulong = (unsigned long) period;
    const unsigned long one_million_ulong = (unsigned long) ONE_MILLION;
    const unsigned long period_ns_ulong = (unsigned long)(period_ms_ulong * one_million_ulong);
    const unsigned long one_billion_ulong = (unsigned long) ONE_BILLION;
    const unsigned long additional_nanoseconds = (unsigned long)(period_ns_ulong % one_billion_ulong);
    
    time_t additional_seconds = period / 1000;
    while (true)
    {
        int status = clock_nanosleep(CLOCK_REALTIME, TIMER_ABSTIME, & ts, NULL);
        if (status != 0)
        {
            switch (status)
            {
                case EINTR:
                    perror("clock_nanosleep() returned EINTR");
                    break;

                case EINVAL:
                    perror("clock_nanosleep() returned EINVAL");
                    break;

                case ENOTSUP:
                    perror("clock_nanosleep() returned ENOTSUP");
            }
            exit(1243);
        }
        
        ts.tv_nsec += additional_nanoseconds;
        ts.tv_sec += additional_seconds;
        if (ts.tv_nsec >= one_billion_ulong)
        {
            ts.tv_sec++;
            ts.tv_nsec -= one_billion_ulong;
        }
        

        do_busy_wait((float)(period / 2000));
        {
            int sched_policy;
            sched_param sp;
            pthread_getschedparam(pthread_self(), & sched_policy, & sp);            
            cerr << __FILE__ << " : " << __LINE__ << " busy wait done, prio = " << sp.sched_priority << ", " << c++ << endl;
        }

    }

}

void * main_thread_low(void * arg)
{

    int c = 0;
    struct timespec ts;
    int period = 2050; // ms
    
    int status = clock_gettime(CLOCK_REALTIME, & ts);

    if (status != 0)

    {

        perror("clock_gettime");

        exit(123);

    }
    

    const unsigned long period_ms_ulong = (unsigned long) period;
    const unsigned long one_million_ulong = (unsigned long) ONE_MILLION;
    const unsigned long period_ns_ulong = (unsigned long)(period_ms_ulong * one_million_ulong);
    const unsigned long one_billion_ulong = (unsigned long) ONE_BILLION;
    const unsigned long additional_nanoseconds = (unsigned long)(period_ns_ulong % one_billion_ulong);
    
    time_t additional_seconds = period / 1000;
    while (true)
    {        
        int status = clock_nanosleep(CLOCK_REALTIME, TIMER_ABSTIME, & ts, NULL);
        if (status != 0)
        {
            switch (status)
            {
                case EINTR:
                    perror("clock_nanosleep() returned EINTR");
                    break;

                case EINVAL:
                    perror("clock_nanosleep() returned EINVAL");
                    break;

                case ENOTSUP:
                    perror("clock_nanosleep() returned ENOTSUP");
            }

            exit(1243);
        }
        
        ts.tv_nsec += additional_nanoseconds;
        ts.tv_sec += additional_seconds;
        if (ts.tv_nsec >= one_billion_ulong)
        {
            ts.tv_sec++;
            ts.tv_nsec -= one_billion_ulong;
        }

        do_busy_wait((float)(period / 2000));
        {
            int sched_policy;
            sched_param sp;
            pthread_getschedparam(pthread_self(), & sched_policy, & sp);            
            cerr << __FILE__ << " : " << __LINE__ << " busy wait done, prio = " << sp.sched_priority << ", " << c++ << endl;

        }
    }
}

int main()
{    
    calibrate_busy_wait();    
    pthread_t periodic_thread_high;
    {
        pthread_attr_t thread_attributes;
        int status;
        
        pthread_attr_init( & thread_attributes);

        if (status != 0) perror("pthread_attr_init failed ");
        
        status = pthread_attr_setschedpolicy( & thread_attributes, SCHED_FIFO);

        if (status != 0) perror("pthread_set_schedpolicy failed ");
        
        struct sched_param sched_parameter;

        sched_parameter.sched_priority = 50;

        status = pthread_attr_setschedparam( & thread_attributes, & sched_parameter);

        if (status != 0) perror("pthread_setschedparam falied ");
        
        status = pthread_attr_setinheritsched( & thread_attributes, PTHREAD_EXPLICIT_SCHED);

        if (status != 0) perror("pthread_attr_setinheritsched failed");
        
        status = pthread_attr_setscope( & thread_attributes, PTHREAD_SCOPE_SYSTEM);

        if (status != 0) perror("pthread_attr_setscope failed ");
        
        status = pthread_create( & periodic_thread_high, & thread_attributes, main_thread_high, NULL);

        if (status != 0) perror("pthread_create failed ");

    }
    
    pthread_t periodic_thread_low;

    {

        pthread_attr_t thread_attributes;

        int status;
        
        pthread_attr_init( & thread_attributes);

        if (status != 0) perror("pthread_attr_init failed ");
        
        status = pthread_attr_setschedpolicy( & thread_attributes, SCHED_FIFO);

        if (status != 0) perror("pthread_set_schedpolicy failed ");
        
        struct sched_param sched_parameter;

        sched_parameter.sched_priority = 1;

        status = pthread_attr_setschedparam( & thread_attributes, & sched_parameter);

        if (status != 0) perror("pthread_setschedparam falied ");
        
        status = pthread_attr_setinheritsched( & thread_attributes, PTHREAD_EXPLICIT_SCHED);

        if (status != 0) perror("pthread_attr_setinheritsched failed");
        
        status = pthread_attr_setscope( & thread_attributes, PTHREAD_SCOPE_SYSTEM);

        if (status != 0) perror("pthread_attr_setscope failed ");
        
        status = pthread_create( & periodic_thread_low, & thread_attributes, main_thread_low, NULL);

        if (status != 0) perror("pthread_create failed ");
        
    }
    
    pthread_join(periodic_thread_high, NULL);

    pthread_join(periodic_thread_low, NULL);
    
    cout << "Hopefully this message will never be issued." << endl;

}