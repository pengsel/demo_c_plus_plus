#include <iostream>
#include <pthread.h>
#include <chrono>
#include <thread>

using namespace std;

#define NUM_THREADS     5

struct thread_data {
    int thread_id;
    char *message;
};

void *PrintHello(void *threadarg) {
    struct thread_data *my_data;

    my_data = (struct thread_data *) threadarg;

    cout << "Thread ID : " << my_data->thread_id;
    cout << " Message : " << my_data->message << endl;

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    struct thread_data td[NUM_THREADS];
    int rc;
    int i;

    for (i = 0; i < NUM_THREADS; i++) {
        cout << "main() : creating thread, " << i << endl;
        td[i].thread_id = i;
        td[i].message = (char *) "This is message";
        rc = pthread_create(&threads[i], NULL,
                            PrintHello, (void *) &td[i]);
        if (rc) {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }
    // 需要延迟，否则子线程访问数据时主线程已经销毁
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    pthread_exit(NULL);
}