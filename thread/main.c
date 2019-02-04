#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <pthread.h>
#include <pthread.h>
#include "time.h"
#include "readwritefile.h"
#include "thread.h"

const static char *fileInputPath = "./input/";
const static char *fileOutputPath = "./output/output";

int main(int argc, char const *argv[])
{

    DIR *dir = opendir("./input/");
    struct dirent *entry;


    if (dir == NULL)
    {
        printf("opendir failed!");
        return -1;
    }
    else
    {
        //跳过..
        // entry = readdir(dir);
        // entry = readdir(dir);
        char *outPath = (char *)malloc(strlen(fileOutputPath) + strlen(".txt") + 2); 
        char *inputPath = (char *)malloc(strlen(fileInputPath) + strlen("input.txt") + 2);
        int Q = -1;
        for(int i = 0; entry != NULL; i++)
        {
            entry = readdir(dir);

            //判断是否entry为空
            if (entry == NULL) {

                printf("运行结束\n"); 
                closedir(dir);
                break;
            }
        
            sprintf(outPath, "%s%d%s", fileOutputPath, i, ".txt");
            sprintf(inputPath, "%s%s", fileInputPath, entry->d_name);

            if(strcmp(inputPath, "./input/.") != 0 & strcmp(inputPath, "./input/..") != 0)
            {
                run_thread(inputPath, outPath);
                printf("\n\n");
            }

        }

        return 0;
    }
}

