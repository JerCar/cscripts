#include <stdio.h>
#include <stdlib.h>

/* a script to convert fahrenheit to celsius and vice versa */

double celsToFahr (double cels);
double farhToCelse (double fahr);
void getUserData (char *type, double *temperature);


int
main(int argc, char *argv[])
{
  double result;
  double temperature;
  char type;  
  
  if (argc < 2)
    {
      fprintf(stdout, "Command Line Usage: %s <f or c> <temp>\n", argv[0]);
      getUserData(&type, &temperature);
      //fprintf(stdout, "\nType: %c\n", type);   junk
      //fprintf(stdout, "Temperature: %lf\n", temperature);    junk

      if (type == 'f')
      {
        result = farhToCelse(temperature);
        fprintf(stdout, "%.1lf Fahrenheit is equal to %.1lf Celsius\n", temperature, result);
      }

      else
      {
        result = celsToFahr(temperature);
        fprintf(stdout, "%.1fl Celsius is equal to %.1fl Fahrenheit\n", temperature, result); 
      }
      return(0);
    }
  else
  {
    temperature = atof(argv[2]);
    
    if (*argv[1] == 'f')
      {
        result = farhToCelse(temperature);
        fprintf(stdout, "%.1lf Fahrenheit is equal to %.1lf Celsius\n", temperature, result);
      }
    
      if (*argv[1] == 'c')
      {
        result = celsToFahr(temperature);
        fprintf(stdout, "%.1fl Celsius is equal to %.1fl Fahrenheit\n", temperature, result);
      }
  }
  
  return (0);
}

double celsToFahr (double cels)
{
  // formula: (cels * 9 / 5) + 32
  double result;

  result = (cels * 9 / 5) + 32;

  return result;  
}

double farhToCelse (double fahr)
{
  // forumla: (fahr - 32) * 5 / 9
  double result;

  result = (fahr - 32) * 5 / 9;
  
  return result;  
}

void getUserData (char *type, double *temperature)
{
  char tempType;
  double tempTemperature;
  fprintf(stdout, "Enter f for Fahrenheith to Celsius or c for Celsius to Fahrenheit (f/c): ");
  fscanf(stdin, "%c", &tempType);
  fprintf(stdout, "Enter the temperature: ");
  fscanf(stdin, "%lf", &tempTemperature);

  *type = tempType;
  *temperature = tempTemperature;  
}




