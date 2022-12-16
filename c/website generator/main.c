#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNAMESIZE 255
#define MAXLINKSIZE 255

//database.txt
// first line = name
// second line = image link
// third line = status year month day hour minute second

struct Date{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

struct Person{
    char name[MAXNAMESIZE];
    char link[MAXLINKSIZE];
    int status; // 1-alive 0-dead
    struct Date date;
};

int main(){
    FILE *output_fp, *output_js_fp;
    struct Person person;
    int append;
    char temp=' ';
    int fileSize;
    int exit=0;
    int number_of_elements;
    char num[10];

    printf("This program creates database.txt and databasejs.txt\n");
    printf("Would you like to append(1), or overwrite(0) the database?\n");
    do{
        while((scanf("%d%c",&append,&temp)!= 2) || (temp!='\n')){
        printf("Try again: \n");
        while(getc(stdin)!= '\n');
    }
    }while((append<0 || append>1) &&  printf("Try again: \n")>0);

    if(append==1){
        output_fp = fopen("database.txt","r");
        fgets(num, 9, output_fp);
        number_of_elements = atoi(num);
        fclose(output_fp);
        output_fp = fopen("database.txt","a");
        output_js_fp = fopen("databasejs.txt","a");
    } else if(append==0){
        output_fp = fopen("database.txt","w");
        output_js_fp = fopen("databasejs.txt","w");
        number_of_elements = 0;
    }

    if(output_fp==NULL){
        printf("Couldnt open file\n");
        return 0;
    }

    fseek(output_fp, 0L, SEEK_END);
    fileSize = ftell(output_fp);
    rewind(output_fp);
    if(append==1 && fileSize!= 0){
        fputc('\n', output_fp);
    }

    while(exit==0){
        ++number_of_elements;

        printf("----------------NEW ENTRY----------------\n");

        printf("Full name: \n");
        while(fgets(person.name,MAXNAMESIZE,stdin)==NULL || ftell(stdin) > (MAXNAMESIZE-2) || ftell(stdin)==2){
            printf("Try again: \n");
            while(getc(stdin)!= '\n');
        }

        printf("Status: Alive(1) Deceased(0) \n");
        do{
            while(scanf("%d%c",&person.status,&temp)!=2 || temp != '\n'){
            printf("Try again: \n");
            while(getc(stdin)!= '\n');
        }
        }while((person.status<0 || person.status>1) && printf("Try again: \n")>0);

        printf("Birth or death date: (YEAR, MONTH, DAY, HOUR, MINUTE, SECOND)\n");
        do{

            while(scanf("%d %d %d %d %d %d%c",&person.date.year,&person.date.month,&person.date.day,&person.date.hour,&person.date.minute,&person.date.second,&temp)!=7 || temp !='\n'){
            printf("Try again: \n");
            while(getc(stdin)!= '\n');
        }
        }while((person.date.year<0 || person.date.year>9999 || person.date.month<0 || person.date.month>12 || person.date.day<0 || person.date.day>31 || person.date.hour<0 || person.date.hour>24 || person.date.second<0 || person.date.second>60) && printf("Try again: \n")>0);

        printf("Link to person image: \n");
        //printf("vieta: %d\n",ftell(stdin));
        while(fgets(person.link,MAXLINKSIZE,stdin)==NULL || ftell(stdin) > (MAXLINKSIZE-2) || ftell(stdin)==2){
            printf("Try again: \n");
            while(getc(stdin)!= '\n');
        }

        fseek(output_fp, 10, SEEK_SET);
        fputs(person.link,output_fp);
        fputs(person.name,output_fp);

        if(person.status==1){
            fputs("still alive\n",output_fp);
        } else{
            fputs("still dead\n",output_fp);
        }
        fprintf(output_fp, "%d",number_of_elements-1);

        fprintf(output_js_fp,"%d-%d-%d %d:%d:%d\n",person.date.year,person.date.month,person.date.day,person.date.hour,person.date.minute,person.date.second);

        printf("Exit(1) or continue(0) \n");
        do{
            while(scanf("%d%c",&exit,&temp)!=2 || temp != '\n'){
            printf("Try again: \n");
            while(getc(stdin)!= '\n');
        }
        }while((exit<0 || exit>1) && printf("Try again: \n")>0);

        if(exit==0){
            fclose(output_fp);
            output_fp = fopen("database.txt","a");
            fputc('\n', output_fp);
        }
    }

    fclose(output_fp);
    fclose(output_js_fp);
    output_fp = fopen("database.txt","r+");
    fprintf(output_fp, "%8d\n", number_of_elements);
    fclose(output_fp);
    return 0;
}
