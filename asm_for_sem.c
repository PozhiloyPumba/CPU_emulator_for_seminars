#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//------------------------------------------------------------------------------------------------------------

enum commands 
{
    MOV = 0,
    ADD = 1,
    SUB = 2,
    MUL = 3,
    DIV = 4,
    RET = 5,
};

double registers[4] = {};

//------------------------------------------------------------------------------------------------------------

void print_regs(double* reg);

int what_the_command(char* string);

int register_or_not(char* string);

int what_the_register(char* string);

void mov(char* string);

void addition(char* string);

void subtraction(char* string);

void multiplication(char* string);

void division(char* string);

//------------------------------------------------------------------------------------------------------------

int main()
{    
    char* str = (char*) calloc(11, sizeof(char));

    scanf("%s", str);

    while(strcmp(str, "ret"))
    {
        switch(what_the_command(str))
        {
            case MOV:
                mov(str);
                break;
            case ADD:
                addition(str);
                break;
            case SUB:
                subtraction(str);
                break;
            case MUL:
                multiplication(str);
                break;
            case DIV:
                division(str);
                break;
            default:
                printf("undefined command\n");
                if(str[strlen(str) - 1] != '\n')
			while(getchar() != '\n');
        }

        print_regs(registers);
        scanf("%s", str);
    }

    free(str);
    
    return 0;
}

//-----------------------------------------------FUNCTIONS-----------------------------------------------------

void print_regs(double* reg)
{
    printf("|");
    for (int i = 0; i < 4; i++)
    {
        printf("| %lg |", reg[i]);
    }
    printf("|\n");

    return;
}

//------------------------------------------------------------------------------------------------------------

int what_the_command(char* string)
{
    int code = -1;
    switch (string[0]) 
    {
        case 'm': 
            if(!strcmp(string, "mov"))
                code = MOV;
            if(!strcmp(string, "mul"))
                code = MUL;
            break;
        case 'a': 
            if(!strcmp(string, "add"))
                code = ADD;
            break;
        case 's':
            if(!strcmp(string, "sub")) 
                code = SUB;
            break;
        case 'd':
            if(!strcmp(string, "div")) 
                code = DIV;
            break;
        default:;
    }

    return code;
}

//------------------------------------------------------------------------------------------------------------

int register_or_not(char* string)
{
    if(isdigit(string[0]) || string[0] == '-')
        return 0;
    return 1;
}

//------------------------------------------------------------------------------------------------------------

int what_the_register(char* string)
{
    int code = -1;
    switch (string[1]) 
    {
        case 'a': 
            if(!strcmp(string, "eax,") || !strcmp(string, "eax"))
                code = 0;
            break;
        case 'b': 
            if(!strcmp(string, "ebx,") || !strcmp(string, "ebx"))
                code = 1;
            break;
        case 'c': 
            if(!strcmp(string, "ecx,") || !strcmp(string, "ecx"))
                code = 2;
            break;
        case 'd':
            if(!strcmp(string, "edx,") || !strcmp(string, "edx")) 
                code = 3;
            break;
        default:
		printf("undefined register\n");
    }
    if (code == -1)
	printf("undefined register\n");

    return code;
}

//------------------------------------------------------------------------------------------------------------

void mov(char* string)
{
    int arg1 = 0,
        arg2 = 0;

    scanf("%s", string);
    
    arg1 = what_the_register(string);
      
    scanf("%s", string);

    if (register_or_not(string))
    {
        arg2 = what_the_register(string);

        if(arg2 == -1)
        {
            printf("undefined register\n");
            return;
        }    

        registers[arg1] = registers[arg2];
    }
    else
    {
        registers[arg1] = atof(string);
    }
    return;
}

//------------------------------------------------------------------------------------------------------------

void addition(char* string)
{
    int arg1 = 0,
        arg2 = 0;

    scanf("%s", string);
    
    arg1 = what_the_register(string);
      
    scanf("%s", string);
    
    if (register_or_not(string))
    {
        arg2 = what_the_register(string);

        if(arg2 == -1)
        {
            printf("undefined register\n");
            return;
        }  

        registers[arg1] += registers[arg2];
    }
    else
    {
        registers[arg1] += atof(string);
    }

    return;
}

//------------------------------------------------------------------------------------------------------------

void subtraction(char* string)
{
    int arg1 = 0,
        arg2 = 0;

    scanf("%s", string);
    
    arg1 = what_the_register(string);
      
    scanf("%s", string);
    
    if (register_or_not(string))
    {
        arg2 = what_the_register(string);

        if(arg2 == -1)
        {
            printf("undefined register\n");
            return;
        }  

        registers[arg1] -= registers[arg2];
    }
    else
    {
        registers[arg1] -= atof(string);
    }

    return;
}

//------------------------------------------------------------------------------------------------------------

void multiplication(char* string)
{
    int arg1 = 0,
        arg2 = 0;

    scanf("%s", string);
    
    arg1 = what_the_register(string);
      
    scanf("%s", string);
    
    if (register_or_not(string))
    {
        arg2 = what_the_register(string);

        if(arg2 == -1)
        {
            printf("undefined register\n");
            return;
        }  

        registers[arg1] *= registers[arg2];
    }
    else
    {
        registers[arg1] *= atof(string);
    }

    return;
}

//------------------------------------------------------------------------------------------------------------

void division(char* string)
{
    int arg1 = 0,
        arg2 = 0;

    scanf("%s", string);
    
    arg1 = what_the_register(string);
      
    scanf("%s", string);
    
    if (register_or_not(string))
    {
        arg2 = what_the_register(string);

        if(arg2 == -1)
        {
            printf("undefined register\n");
            return;
        }  

        registers[arg1] /= registers[arg2];
    }
    else
    {
        registers[arg1] /= atof(string);
    }

    return;
}
