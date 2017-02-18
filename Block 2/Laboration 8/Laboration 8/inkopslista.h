//
//  inkopslista.h
//  Laboration 8
//
//  Created by Staffan Brickman on 2016-05-17.
//  Copyright © 2016 Mälardalens Högskola. All rights reserved.
//

#ifndef inkopslista_h
#define inkopslista_h

typedef struct{

    int id;

    char name[20];

    int quantity;

    float weight;

}item;

typedef item* List;

typedef struct{

    int noPosts;

    List list;

}listHead;

typedef listHead* Head;

void menu();
void createList(Head *head);
void loadList(Head *head);
void saveList(Head head);
void printList(Head head);
void addItem(Head *head);
void editPost(Head *head);
void removePost(Head *head);
void removeList(Head* head);

#endif /* inkopslista_h */