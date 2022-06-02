#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char data[100];
    struct node*next;
    struct node*previous;
};

char temp[100];
struct node*top=NULL;
struct node*current_song=NULL;