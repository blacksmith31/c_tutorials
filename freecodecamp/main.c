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
    // *** Note not secure
    double num1;
    double num2;

    printf("Enter first number:\n");
    scanf("%lf", &num1);

    printf("Enter second number:\n");
    scanf("%lf", &num2);

    printf("answer: %f\n", num1 + num2);
}

void madlib(){
    char color[20];
    char plural_noun[20];
    char celeb[20];

    printf("Enter a color: ");
    scanf("%s", color);


    printf("Enter a plural noun: ");
    scanf("%s", plural_noun);


    printf("Enter a celebrity: ");
    scanf("%s", celeb);

    printf("Roses are %s\n", color);
    printf("%s are blue\n", plural_noun);
    printf("I love %s\n", celeb);

}

void arrays(){
    int lucky_nums[] = {3, 5, 7, 14};
    printf("first element of array: %d\n", lucky_nums[0]);

    // int lucky_nums2[10];
}

// Return vals
// funcs with return should be defined 'above' the caller if not prototyped
double cube(double num){
    return num * num * num;
}

// Conditionals && Comparators
int max(int num1, int num2){
    int result;
    if(num1 > num2){
        result = num1;
    } 
    else {
        result = num2;
    }
    return result;
}

int max3(int num1, int num2, int num3){
    if(num1 >= num2 && num1 >= num3){
        return num1;
    }
    else if(num2 >= num1 && num2 >= num3){
        return num2;
    }
    else{
        return num3;
    }
        
}

double better_calc(){
    double num1;
    double num2;
    char op;
    
    printf("Enter a number: \n");
    scanf("%lf", &num1);
    printf("Enter an operator: ");
    // space before char format specifier in scanf
    // this skips any whitespace in buffer memory when this is not the first input
    scanf(" %c", &op);
    printf("Enter a second operand: \n");
    scanf("%lf", &num2);

    if(op == '+'){
        return num1 + num2;
    }
    else if(op == '-'){
        return num1 - num2;
    }
    else if(op == '*'){
        return num1 * num2;
    }
    else if(op == '/'){
        return num1 / num2;
    }
    else{
        printf("enter a valid operator");
        return -1;
    }
}

int main(){
    printtri();

    // story();

    // format_specs();

    // get_input();

    // calculator();

    // madlib();

    printf("cube answer: %lf\n", cube(2.3));
    printf("max num : %d\n", max(1.1, 45));
    printf("max of 3: %d\n", max3(10, 2, 3));
    return 0;
}