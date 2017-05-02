//
//  inkopslista.c
//  Laboration 8
//
//  Created by Staffan Brickman on 2016-05-17.
//  Copyright © 2016 Mälardalens Högskola. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "inkopslista.h"

static void flushInput(void){ //flushar input

    int ch;

    while ((ch=getchar()) != EOF && ch != '\n');

}

void menu(){

    Head head = NULL; //listhuvud pekare

    int input = -1;

    while(input != 0){ //Meny-loop START

        printf("MENU\n****\n");

        printf("1: New List\n");
        printf("2: Load List\n");

        if(head != NULL){

            printf("3: Save List\n");
            printf("4: Print List\n");
            printf("5: Add Item\n");

            if(head->list != NULL){

                printf("6: Edit Item\n");
                printf("7: Remove Item\n");

            }

            printf("8: Delete List\n");

        }

        printf("\n");

        while(scanf(" %d",&input) == 0)flushInput(); // input

        switch(input){
            case 1:createList(&head);break;
            case 2:loadList(&head);break;
        }

        if(head != NULL){

            switch(input){
                case 3:saveList(head);break;
                case 4:printList(head);break;
                case 5:addItem(&head);break;

            }

            if(head->list != NULL){
                switch(input){
                    case 6:editPost(&head);
                    case 7:removePost(&head);
                }

            }
         if(input == 8)removeList(&head); //Måste ligga sist annars blir det fel i tidigare if
        }

    };//Meny-loop END
    
};

void createList(Head *head){ //skapar ett listhuvud

    if(*head == NULL){

        *head = malloc(sizeof(listHead));

        (*head)->list = NULL;

        (*head)->noPosts = 0;

    }
    else printf("ERROR! List not created!\n");
};

void loadList(Head *head){

    printf("*LOAD FROM FILE*\n");

    char fileName[20];

    printf("Name of file? ");
    while(scanf(" %s",fileName) == 0)flushInput(); // input

    FILE *file = fopen(fileName, "r"); // öppna filen och associera pekaren file

    if(file != NULL){

        if(*head != NULL)removeList(head); //Om det finns en lista

        createList(head); //Om det inte finns en lista

        fscanf(file, "%d\n",&(*head)->noPosts); //hämta antal poster

        (*head)->list = realloc((*head)->list,sizeof(item)*(*head)->noPosts);// allokera minne för nya listan

        for(int i = 0 ; i < (*head)->noPosts ; i++){
            (*head)->list[i].id = i;
            fscanf(file, "%20s %10d %10f\n",(*head)->list[i].name,&(*head)->list[i].quantity,&(*head)->list[i].weight);
        }
        
        fclose(file);
    }
    else printf("ERROR! No such file!\n");

};

void saveList(Head head){

    printf("*SAVE TO FILE*\n");

    char fileName[20];

    printf("Name of file? ");
    while(scanf(" %s",fileName) == 0)flushInput(); // input


    FILE *file = fopen(fileName, "w+"); // öppna filen och associera pekaren file

    if(file == NULL){
        printf("ERROR! Could not write to file!");
    }

    else{

        //starta skrivning

        fprintf(file,"%d\n",head->noPosts);//skriv antal poster

        for(int i = 0 ; i < head->noPosts ; i++){
            fprintf(file,"%20s %10d %10f\n",head->list[i].name,head->list[i].quantity,head->list[i].weight);
        }

        //avsluta skrivning

        fclose(file);//stäng filen

    }
};

void printList(Head head){

    printf("*START OF LIST*\n");
    printf("id   Name                 Quantity   Weight\n");
    for(int i = 0;i < head->noPosts;i++){

        printf("%-4d %-20s %-10d %.1f kg\n",head->list[i].id,head->list[i].name,head->list[i].quantity,head->list[i].weight);

    }
    printf("Total number of items: %d\n",head->noPosts);
    printf("*END OF LIST*\n");

};
void addItem(Head *head){

    printf("*ADD ITEM*\n");

    (*head)->noPosts++;

    (*head)->list = realloc((*head)->list,sizeof(item)*(*head)->noPosts);

    (*head)->list[(*head)->noPosts - 1].id = (*head)->noPosts - 1;
    
    printf("Name? ");
    while(scanf(" %s",(*head)->list[(*head)->noPosts - 1].name) == 0)flushInput(); // input
    printf("Quantity? ");
    while(scanf(" %d",&(*head)->list[(*head)->noPosts - 1].quantity) == 0)flushInput(); // input
    printf("Weight (kg)? ");
    while(scanf(" %f",&(*head)->list[(*head)->noPosts - 1].weight) == 0)flushInput(); // input


};
void editPost(Head *head){

    printf("*EDIT ITEM*\n");

    int input;

    printf("Item-id to Edit? (-1 to exit)");
    while(scanf(" %d",&input) == 0)flushInput(); // input

    if(input > -1 && input < (*head)->noPosts){

        printf("New name? ");
        while(scanf(" %s",(*head)->list[input].name) == 0)flushInput(); // input
        printf("New quantity? ");
        while(scanf(" %d",&(*head)->list[input].quantity) == 0)flushInput(); // input
        printf("New weight (kg)? ");
        while(scanf(" %f",&(*head)->list[input].weight) == 0)flushInput(); // input

    }

    else if(input > -1)printf("ERROR! %d is not an item id!\n",input);

};
void removePost(Head *head){

    printf("*REMOVE ITEM*\n");

    int input;

    printf("Item-id to Remove? (-1 to exit)");
    while(scanf(" %d",&input) == 0)flushInput(); // input

    if(input > -1 && input < (*head)->noPosts){

        (*head)->noPosts--;

        for(int i = input;i < (*head)->noPosts;i++){ // Flytta ned resten av posterna
            for(int j = 0;j < 20;j++)(*head)->list[i].name[j] = (*head)->list[i+1].name[j]; //Kopiera namnet
            (*head)->list[i].quantity = (*head)->list[i+1].quantity;
            (*head)->list[i].weight = (*head)->list[i+1].weight;

        }
        (*head)->list = realloc((*head)->list,sizeof(item) * (*head)->noPosts);
    }

    else if(input > -1)printf("ERROR! %d is not an item id!\n",input);

};
void removeList(Head* head){

    if((*head)->list != NULL)free((*head)->list);

    if(*head != NULL)free(*head);

    *head = NULL;

};