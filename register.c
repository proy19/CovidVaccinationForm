#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Declaring a global structure that contains the user's info
struct users
{
    char    FirstName[30];
    char    LastName[30];
    int     m1;
    int     d1;
    int     y1;
    char    sex[20];
    int     DoseNo;
    int     m2, d2, y2;
    char    type[20];
    int     zip;
};

//delaring a users array called person with max size of 10
struct users person[10];

//declarating of regist function
void regist(struct users *person);
//declaration of disp function
void disp(struct users *person, int);
//declaration of generate_code function
void generate_code(struct users *person, int);
//declaration of age function
int age(int pday, int pmon, int py, int bday, int bmon, int by);

//age function to calculate age
int age(int pday, int pmon, int py, int bday, int bmon, int by) {
    //month array
   int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
   //if birthday > presentday, pday = pday + month[bmon - 1] and pmon = pmon - 1; 
   if (bday > pday) {
      pday = pday + month[bmon - 1];
      pmon = pmon - 1;
   }
   //if birthday month > present month, py - 1 and pmon = pmon + 12;
   if (bmon > pmon) {
      py = py - 1;
      pmon = pmon + 12;
   }
   //day = pday - bday;
   int day = pday - bday;
   //mon = pmon - bmon;
   int mon = pmon - bmon;
   //year = py - by;
   int year = py - by;
   
   //return year
   return year;
}

//disp function to diplay the user information
void disp(struct users *person, int i){
    printf("First Name: %s\n", person[i].FirstName);
    printf("Last Name: %s\n", person[i].LastName);
    printf("Birth date: %d/%d/%d\n",person[i].m1, person[i].d1, person[i].y1);
    printf("Sex: %s\n", person[i].sex);
    printf("Number of Doses: %d\n", person[i].DoseNo);
    printf("Previous Dose Date: %d/%d/%d\n",person[i].m2, person[i].d2, person[i].y2);
    printf("Vaccine Type: %s\n", person[i].type);
    printf("Residential Zip Code: %d\n", person[i].zip);
}

//generate_code function to generate the code
void generate_code(struct users *person, int i){
    
    //calculating the age
    int pday = 18;
    int pmon = 4;
    int py = 2021;
    
    int bday = person[i].d1;
    int bmon = person[i].m1;
    int by = person[i].y1;
    //calculating the last three digits of zip
    int l = age(pday, pmon, py, bday, bmon, by);
    int lastThree = person[i].zip % 1000;
    
    //printing the unique code
    printf("Unique Code: %c%c%d%c%d",person[i].FirstName[i],person[i].LastName[i],l,
           person[i].type[i],lastThree);
}

//regist function to register user
void regist(struct users *person)
{
    
    //int gender number and vaccine number
    int gender;
    int vaccine;
    //int i for the for-loop
    int i = 0;
    //for-loop to register 10 users
    for (i = 0; i < 10; i++){
    //getting first and last name
    printf("Enter first name:");
    scanf("%s", person[0].FirstName);
    
    printf("Enter a last name:");
    scanf("%s", person[0].LastName);
    
    //getting birthdate
    printf("Enter birth date: mm/dd/yy: ");
    scanf("%d/%d/%d",&person[0].m1, &person[0].d1, &person[0].y1);
    
    //getting gender
    printf("Choose a gender: \n");
    printf("\t1 Female\n");
    printf("\t2 Male\n");
    printf("\t3 Do not wish to identify\n");
    scanf("%d", &gender);
    
    //assigning gender based on user given number
    if(gender == 1){
        strcpy(person[0].sex, "Female");
    }else if (gender == 2){
        strcpy(person[0].sex, "Male");
    } else {
        strcpy(person[0].sex, "Do not wish to identify");
    }
    
    //getting number of doses
    printf("Choose number of doses: \n");
    printf("\t1\n");
    printf("\t2\n");
    scanf("%d", &person[0].DoseNo);
    
    //if dose = 2, get dose date
   if(person[0].DoseNo == 2){
      printf("Enter date of previous dose mm/dd/yyyy : ");
      scanf("%d/%d/%d",&person[0].m2, &person[0].d2, &person[0].y2);  
    }
    
    //getting a vaccine type
    printf("Choose a Vaccine Type: \n");
    printf("\t1 Pfizer\n");
    printf("\t2 Moderna\n");
    printf("\t3 Johnson&Johnson\n");
    scanf("%d", &vaccine);
    
    //assigning vaccine based on user given number
    if(vaccine == 1){
        strcpy(person[0].type, "Pfizer");
    }else if (vaccine == 2){
        strcpy(person[0].type, "Moderna");
    }else if (vaccine == 3){
        strcpy(person[0].type, "Johnson&Johnson");
    }
    
    //getting zip
    printf("Enter a Zip: ");
    scanf("%d", &person[0].zip);
    printf("\n");
    //diplay user information
    disp(person, i);
    //generate and print Unique code
    generate_code(person, i);
    
    printf("\n");
    
    }
}

int main()
{
    //calling regis function
    regist(person);
	
    return 0;
}
