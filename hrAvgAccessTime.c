/*  A program to figure out average memory level access time 
    Inputs
       Hit Ratio
       Time to Access Level 1
       Time to Access Level 2
    Outputs
       Average access Time
*/

#include <stdio.h>

/* inputs 2 accessTimes & one hitRatio and returns avgAccessTime */
double avgTimeMather(double levelOneTime, double levelTwoTime, double hitRatio);

/* grabs the hitRatio from std input */
double getHitRatio();

/* grabs accessTimeOne & accessTimeTwo and assigns them to pointers*/
int getAccessTimes(double *accessTimeOnePtr, double *accessTimeTwoPtr);

/* testing pointers */
void testFunction(double *hitRatioPtr)
{
  printf("hitRatioPtr inside testFunction = %fl\n", *hitRatioPtr);
}

int
main (void)
{
  double timeOne, timeTwo, hitRatio; // inputs for avgTimeMather
  double avgTime; // for output of avgTimeMather
        
  hitRatio = getHitRatio();
  getAccessTimes(&timeOne, &timeTwo);
  
  printf("hitRatio = %fl\n", hitRatio);
  printf("timeOne = %fl\n", timeOne);
  printf("timeTWo = %fl\n", timeTwo);
  avgTime = avgTimeMather(timeOne, timeTwo, hitRatio);

  printf("The average access time equals: %.2lf", avgTime);
  
  printf("\n");

  return (0);
}


/* function definitions */

double
avgTimeMather(double levelOneTime, double levelTwoTime, double hitRatio)
/* inputs 2 accessTimes & one hitRatio and returns avgAccessTime */
{  
  double avgTime;  
  avgTime = hitRatio * levelOneTime + (1 - hitRatio) * (levelTwoTime + levelOneTime);
  return (avgTime);
}


double
getHitRatio()
/* grabs the hitRatio from std input */
{
  double hitRatio;
  printf("Enter hit ratio: ");
  scanf("%lf", &hitRatio);  
    
  return (hitRatio);
}


int getAccessTimes(double *accessTimeOnePtr, double *accessTimeTwoPtr)
/* grabs accessTimeOne & accessTimeTwo and assigns them to pointers*/
{
  double inputAccessTimeOne, inputAccessTimeTwo;  
  printf("Enter access time one: ");
  scanf("%lf", &inputAccessTimeOne);  
  printf("Enter access time two: ");
  scanf("%lf", &inputAccessTimeTwo);
  *accessTimeOnePtr = inputAccessTimeOne;
  *accessTimeTwoPtr = inputAccessTimeTwo;
  
  return (0);
}