//Abdalla Shaaban

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int tortoise = 1;
int hare = 1;
    
int MoveTortoise()
{
    if(((rand() % 10) + 1)>=1 && ((rand() % 10) + 1)<=5)
    {
        tortoise+=3;
    }
    else if(((rand() % 10) + 1)>=6 && ((rand() % 10) + 1)<=7)
    {
        tortoise-=6;
    }
    else if(((rand() % 10) + 1)>=8 && ((rand() % 10) + 1)<=10)
    {
        tortoise+=1;
    }
    
    if(tortoise < 1)
        tortoise = 1;
    else if(tortoise > 70)
        tortoise = 70;
        
    //return tortoise;
};

int MoveHare()
{
    if(((rand() % 10) + 1)>=1 && ((rand() % 10) + 1)<=2)
    {
        hare=hare;
    }
    else if(((rand() % 10) + 1)>=3 && ((rand() % 10) + 1)<=4)
    {
        hare+=9;
    }
    else if(((rand() % 10) + 1)==5)
    {
        hare-=12;
    }
    else if(((rand() % 10) + 1)>=6 && ((rand() % 10) + 1)<=8)
    {
        hare+=1;
    }
    else if(((rand() % 10) + 1)>=9 && ((rand() % 10) + 1)<=10)
    {
        hare-=2;
    }
    
    if(hare < 1)
        hare = 1;
    else if(hare > 70)
        hare = 70;
    
    //return hare;
};

void PrintCurrentPositions(int tortoisePosition, int harePosition)
{
    int i;
    //when both tortoise and hare are in the same spot
    if (tortoisePosition == harePosition)
    {
        for(i=1; i<tortoisePosition; i++)
            printf("%s", " ");
            
        printf("OUCH!!!");
    }else if(tortoisePosition < harePosition)
    {
        for(i=1; i<tortoisePosition; i++)
            printf("%s", " ");
        
        printf("T");
        
        for(i=1; i<(harePosition - tortoisePosition);i++)
            printf("%s", " ");
            
        printf("H");
    }else{
        for(i=1; i<harePosition; i++)
            printf("%s", " ");
            
        printf("H");
        
        for(i=1; i<(tortoisePosition - harePosition);i++)
            printf("%s", " ");
        
        printf("T");
    }
    printf("\n");
};

int main()
{
    int counter = 0;
    
    //sets the starting point for rand()
    srand(time(0));
    
    //start of race
    printf("Bang!!!!!\nAnd they're off!!!!!\n");
    
    //move until end of race
    while(tortoise != 70 && hare != 70)
    {
        MoveTortoise();
        
        MoveHare();
        
        PrintCurrentPositions(tortoise, hare);
        
        counter++;
    }
    
    //declare winner
    if(tortoise > hare)
    {
        printf("TORTOISE WIN !!! YAY !!!\n");
    }else if(tortoise < hare)
    {
        printf("HARE WIN !!! YUCH !!!\n");
    }else if( tortoise == hare)
    {
        printf("ITS'S A TIE\n");
    }
    
    return 0;
}