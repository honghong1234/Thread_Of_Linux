#ifndef THREAD
#define THREAD


void *sum_work(void *arg);
int run_thread(const char *fileInput, const char *fileOutput, const char *timeOutPath);
int correct_answer();
#endif