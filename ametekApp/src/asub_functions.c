#include <aSubRecord.h>
#include <registryFunction.h>
#include <epicsExport.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int asub_write(aSubRecord *precord){

char curent_t[80];
time_t t = time(NULL);
struct tm *tm = localtime(&t);

strftime(curent_t, sizeof(curent_t), "am%y%h%d_%H%M%s.txt\n", tm); 

char filename[256];
char path[256];
strcpy(path,     (char *)precord->a);
strcpy(filename, (char *)precord->b);

float *aTab1    = (float *)precord->c;     // tab 1
unsigned nrTab1 = precord->nec;            // nr of elements in tab 1
     
float *aTab2    = (float *)precord->d;     // tab 2
unsigned nrTab2 = precord->ned;            // nr of elements in tab 2
     

FILE * pFile;
int n;

   pFile = fopen ("myfile.txt","w");
   fprintf(pFile, "%s\n", asctime(tm));

   for (n=0 ; n<3 ; n++) {
       fprintf (pFile, "%d\n", n);
   }
   fclose (pFile);


printf("[DEBUG] writing date, time to file...\n");
printf("Path:     %s\n", path);
printf("FileName: %s\n", filename);
printf("Time:     %d-%d-%d %d:%d:%d\n", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);
printf("Filename based on time %s\n", curent_t);

return 0;
}

 
epicsRegisterFunction(asub_write);

