#include <aSubRecord.h>
#include <registryFunction.h>
#include <epicsExport.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


// asub_write is not used in this wersion and never was tested.
// Saving data was moved from EPICS DB to python script in OPI
//

int asub_write(aSubRecord *precord){

char curent_t[80];
time_t t = time(NULL);
struct tm *tm = localtime(&t);

strftime(curent_t, sizeof(curent_t), "%y%h%d_%H%M%s\n", tm); 

char filename[256];
char path[256];
char sweepTime[256];
char fullPathName[256];

strcpy(path,     (char *)precord->a);
strcpy(filename, (char *)precord->b);
strcpy(sweepTime, (char *)precord->c);

float *aTab1    = (float *)precord->d;     // tab 1 (frequency)
unsigned nrTab1 = precord->ned;            // nr of elements in tab 1
     
float *aTab2    = (float *)precord->e;     // tab 2 (DC_X)
//unsigned nrTab2 = precord->nee;            // nr of elements in tab 2

float *aTab3    = (float *)precord->f;     // tab 2 (DC_Y)
//unsigned nrTab3 = precord->nef;            // nr of elements in tab 2
     
float *aTab4    = (float *)precord->g;     // tab 2 (Amplitude)
//unsigned nrTab4 = precord->neg;            // nr of elements in tab 2
     
float *aTab5    = (float *)precord->h;     // tab 2 (Phase)
//unsigned nrTab5 = precord->neh;            // nr of elements in tab 2


sprintf(fullPathName, "%s/%04d%02d%02d_%02d%02d%02d_%s.txt", "./", 
							tm->tm_year + 1900, 
							tm->tm_mon + 1, 
							tm->tm_mday, 
							tm->tm_hour, 
							tm->tm_min, 
							tm->tm_sec, 
							filename);
printf("fullPathName:%s\n", fullPathName);     
FILE * pFile;
int n = 0;


   printf("Hello 1\n");
   pFile = fopen (fullPathName,"w");
   if (pFile == NULL) {
      printf(" [ERROR] The file [%s] cannot be opened... exit\n", fullPathName);
      return 0;
   }

   fprintf(pFile, "# Data from Ametek Lock-In amplifier\n");
   printf("Hello 2\n");
   fprintf(pFile, "# Data was collected:\n");
   printf("Hello 3\n");
   fprintf(pFile, "# %s\n", sweepTime);
   printf("Hello 4\n");
   fprintf(pFile, "# Data was saved:\n");
   printf("Hello 5\n");
   fprintf(pFile, "# %s\n", asctime(tm));
   printf("Hello 6\n");
   fprintf(pFile, "\n");
   printf("Hello 7\n");
   fprintf(pFile, "Freq(Hz), DC_X(V), DC_Y(V), Magnitude(V), Phase(deg)\n");

   printf("Hello 8\n");
   //for (int n = 0 ; n < nrTab1 ; n++) {
   for (n = 0 ; n < 3 ; n++) {
       fprintf (pFile, "%f\t%f\t%f\t%f\t%f\n", aTab1[n], aTab2[n], aTab3[n], aTab4[4], aTab5[5]);
   }

   fclose (pFile);


//printf("[DEBUG] writing date, time to file...\n");
//printf("Path:     %s\n", path);
//printf("FileName: %s\n", filename);
//printf("Time:     %d-%d-%d %d:%d:%d\n", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);
//printf("Filename based on time %s\n", curent_t);

return 0;
}

 
epicsRegisterFunction(asub_write);

