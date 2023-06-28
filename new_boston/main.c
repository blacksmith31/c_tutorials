#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    printf("Hello World\n");

    // Conversion characters
    //%s: strings
    //%d: integers
    //%f: float
    printf("%s is the name of a person\n", "Juan-Diego");
    printf("%d is a number\n", 75);
    printf("%f is a number\n", 75.9284754);
    printf("%.2f is a number\n", 75.9284754);
    printf("%.4f is a number\n", 75.9284754);

    // Variables
    int age;
    int current_year, birth_year;
    // age = 27;
    current_year = 2023;
    birth_year = 1983;
    age = current_year - birth_year;
    printf("I am %d years old\n", age);

    /*
    String terminator
    add a byte for '\0'
    */ 
    char name[11] = "Juan Diego";
    printf("my name is %s\n", name);

    // reassigning a string
    // for strcpy: include string.h
    // new string must fit within original size
    strcpy(name, "Jameson");
    printf("my name is %s\n", name);
    return 0;
}