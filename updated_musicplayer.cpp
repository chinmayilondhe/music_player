#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char temp[100];
struct node*top=NULL;
struct node*current_song=NULL;

struct node{
    char data[100];
    struct node*next;
    struct node*previous;
};
void insert_new_song(){
    printf("Enter Song Name:\n");
    while((getchar())!='\n');
    scanf("%[^\n]%*c",temp);

    struct node* new_song=(struct node*)malloc(sizeof(struct node));
    strcpy(new_song->data,temp);
    if(top==NULL){
        new_song->next=new_song->previous=new_song;
        top=current_song=new_song;
        return;
    }
    struct node*last=top->previous;
    new_song->previous=last;
    last->next=new_song;
    new_song->next=top;
    top->previous=new_song;
}

void delete_song(){
    if(top==NULL){
        printf("No Song is there to delete!\n");
        return;
    }
    printf("Enter Song Name to delete:\n");
    while((getchar())!='\n');
    scanf("%[^\n]%*c",temp);
    printf("\n");
    struct node*ptr=top;
    do{
        if(ptr->next==ptr && strcmp(ptr->data,temp)==0){
            printf("One file deleted! Playlist is Empty Now!\n");
            top=NULL;
            free(ptr);
            return;
        }
        else if(strcmp(ptr->data,temp)==0){
            struct node*previous=ptr->previous;
            struct node*next=ptr->next;
            previous->next=next;
            next->previous=previous;
            top=next;
            free(ptr);
            printf("Song deleted!\n");
            return;
        }
        ptr=ptr->next;
    }while(ptr!=top);
    printf("No Song file is there!\n");
}

void show_song(){
    if(top==NULL){
        printf("Playlist is Empty!\n");
        return;
    }
    struct node*show_ptr=top;
    printf("\n");
    int i=1;
    printf("Displaying Playlist :\n");
    do{
        printf("Song %d : %s\n",i,show_ptr->data);
        i++;
        show_ptr=show_ptr->next;
    }while(show_ptr!=top);
}

void song_of_choice(){
    if(top==NULL){
        printf("The playlist is empty!!!\n");
        return;
    }
    printf("Enter Song name you want to search:\n");
    while((getchar())!='\n');
    scanf("%[^\n]%*c",temp);
    printf("\n");
    struct node*ptr=top;
    do{
        if(strcmp(ptr->data,temp)==0){
            printf("Song Found!\n");
            printf("Playing Song : %s\n",ptr->data);
            return;
        }
        ptr=ptr->next;
    }while(ptr!=top);
    printf("There is no Song file with this name!\n");
}

int main(){
    int choice;
    menu:
    printf("\n__________WELCOME TO SPOTIFY__________\n");
    printf("1. Add Song\n");
    printf("2. Remove Song\n");
    printf("3. Show playlist\n");
    printf("4. Play next song\n");
    printf("5. Play previous song\n");
    printf("6. Play first song\n");
    printf("7. Play last song\n");
    printf("8. Play specific song\n");
    printf("9. Exit\n\n");
    scanf("%d",&choice);

    if (choice == 1)
        insert_new_song();

    else if (choice == 2)
        delete_song();

    else if (choice == 3)
        show_song();

    else if (choice == 4)
        next_song();

    else if (choice == 5)
        previous_song();

    else if (choice == 6)
        first_song();

    else if (choice == 7)
        last_song();

    else if (choice == 8)
        song_of_choice();
    else
        exit(0);

        goto menu;
return 0;
}
