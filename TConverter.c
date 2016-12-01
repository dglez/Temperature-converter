/***************************************************/
#include <stdio.h>
/***************************************************/

/* Author: Daniel Gonzalez P#4926400 */
/* Assignment 1: Table temperature (Fahrenheit and Celsius) */

/* program will accept and validate input values 
 * to be one character in length in the range from 1 to 9 */
/* compilation: gcc TConverter.c -o myprogram.out */

/*   execute with ./myprogram.out */
/*   To exit execution press [ctrl + Z] */

/************************************************
    I Daniel Gonzalez #4926400 hereby certify that this collective work is 
    my own and none of it is the work of any other person or entity. 
************************************************/



/***************************************************/
/* program defines */

#define LOWER -20.0                            /* Lower limit of table */
#define UPPER 280.0                            /* Upper limit */
#define NOERRORS 0                             /* For clean return  */
#define TEMPERATURE_FORMULA_VALUE_5 5.0        /* Constant formula value 5.0 */
#define TEMPERATURE_FORMULA_VALUE_9 9.0        /* Constant formula value 9.0*/
#define TEMPERATURE_FORMULA_VALUE_32 32.0      /* Constant formula value 32.0*/
#define INPUT_LOWEST 1                         /* Minimum step value*/
#define INPUT_HIGHEST 9                        /* Maximum step value*/
#define EOL '\n'                               /* End of line character*/
#define ZERO_CHAR '0'                          /* Character 0 */
#define SPACE_CHAR ' '                         /* Space character*/





/***************************************************/
/*   Function prototypes: 
*    Funtion declarations are listed as below.
*/
float convertToCelsius(float fahrenheit);
float convertToFahrenheit(float celsius);
void tableDisplay(float, float, int);
int validateInput();
/***************************************************/






/**
 * [main program function]
 * @return [NOERRORS when program finishes ok]
 */
int main()
{
    /* Declare and initialize variables  */
    
    float fahrenheit = LOWER;
    float celsius = LOWER;
    int step = 0;

    
    /* Input values */
    printf( "Enter a value from %d to %d for the table temperature steps:\n", 
            INPUT_LOWEST, 
            INPUT_HIGHEST 
            );
    step = validateInput();    

    if (step == 0){
        return NOERRORS;
    }

    /* Main process */
    tableDisplay(fahrenheit, celsius, step);


    return NOERRORS;
}







/**
 * [convertToCelsius description] converts Fahrenheit to Celsius 
 * @param  Fahrenheit [float Fahrenheit temperature value to convert to Celsius]    
 * @return            [float Celsius converted value]
 * Conversion formula used f(x) = 5(x - 32)/9
 */
float convertToCelsius(float fahrenheit){

    return 
    TEMPERATURE_FORMULA_VALUE_5 
    * (fahrenheit - TEMPERATURE_FORMULA_VALUE_32) 
    / TEMPERATURE_FORMULA_VALUE_9;
}







/**
 * [convertToFahrenheit Converts Celsius to Fahrenheit]
 * @param  celsius [float value to be converted]
 * @return         [float Converted value to Fahrenheit]
 * Conversion formula used f(x) = 9x/5 + 32
 */
float convertToFahrenheit(float celsius){

    return 
    TEMPERATURE_FORMULA_VALUE_9 
    * celsius
    /TEMPERATURE_FORMULA_VALUE_5 
    + TEMPERATURE_FORMULA_VALUE_32;
}








/**
 * [tableDisplay prints a conversion temperature table with the specified  
 * increment]
 * @param fahrenheit [fahrenheit initial Value]
 * @param celsius    [celsius initial value]
 * @param step       [Step increment for intervals of table]
 */
void tableDisplay(float fahrenheit, float celsius, int step){

    printf(
        "-------------------------------------"
        "-----------------------------------\n"
        "\tFahrenheit\tCelsius\t\tCelsius\t\tFahrenheit\n"
        "-------------------------------------"
        "-----------------------------------\n"
        );
    
    while (fahrenheit <= UPPER)
    {
        printf(
            "\t%6.1f\t\t %6.1f\t\t %6.1f\t\t %6.1f\n", 
            fahrenheit, 
            convertToCelsius(fahrenheit), 
            celsius, 
            convertToFahrenheit(celsius) 
            );

        celsius = fahrenheit += step;
    }

}








/**
 * [validateInput validates user input to be in range]
 * @return [int validated input]
 */
int validateInput(){

    // getchar() - ZERO_CHAR : converts input char to int usable value.
    int step = getchar() - ZERO_CHAR;
    int ok = 0;
    int charCount = 0;

    if (step == (EOF - ZERO_CHAR))
    {
        return 0;
    }
    
    /*while next character is different from end of line(EOL) and EOF,
     count characters if different from space.*/
    ok = getchar();
    while( ok != EOL && ok != EOF){        

        charCount += (ok == SPACE_CHAR)? 0 : 1;
        ok = getchar();
    }
    
    printf("\n" );
    if (step < INPUT_LOWEST | step > INPUT_HIGHEST | charCount > 0){

        printf(
            "Enter a value from %d to %d for the table temperature steps:\n", 
            INPUT_LOWEST, 
            INPUT_HIGHEST 
            );
        return validateInput();    
        
    }
    else{

        return step;
    }
    
}

