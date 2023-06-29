#include <stdio.h>
#include <stdlib.h>

void printtri(){
    printf("    /|\n");
    printf("   / |\n");
    printf("  /  |\n");
    printf(" /___|\n");
}

void story(){
    char name[] = "John";
    int age = 35;

    printf("There once was a man named %s\n", name);
    printf("He was %d years old.\n", age);
    printf("He really liked the name %s\n", name);
    printf("But he did like being %d\n", age);
}

void format_specs(){
    printf("number %d\n", 500);
    printf("string: %s\n", "string");
    printf("float: %f\n", 500.0123);

}

/*
basic intro to data types, math, and comments
const 
user input
*/

void get_input(){
    int age;
    char name[20];
    printf("Enter your age: \n");
 
    scanf("%d", &age); //& prefix = pointer to var address
    printf("you are %d years old\n", age);

    printf("Enter your name: \n");
    // scanf only reads up to the first whitespace
    // scanf("%s", name); //array name is a pointer, '&' not needed
    // printf("your name is %s\n", name);

    fgets(name, 20, stdin);
    printf("your name is %s\n", name);

    //***? fgets does not accept input after scanf?
}

void calculator(){
    double num1;
    double num2;

    printf("Enter first number:\n");
    scanf("%lf", &num1);

    printf("Enter second number:\n");
    scanf("%lf", &num2);

    printf("answer: %f\n", num1 + num2);
}

int main(){
    printtri();

    story();

    format_specs();

    // get_input();

    calculator();

    return 0;
}