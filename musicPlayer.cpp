#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


using namespace std;

struct node
{
    char song[100];
    struct node *next;
    struct node *prev;
} * top, *temp, *top1;

void add_node(struct node *first)
{
    char a[100];
    while (first->next != NULL)
    {
        first = first->next;
    }
    first->next = (struct node *)malloc(sizeof(struct node));
    first->prev = first;
    first = first->next;
    cout << "\n\a\a\a\aEnter Song name-  ";
    cin>>a;
    strcpy(first->song, a);

    first->next = NULL;
}

void display()
{
    top1 = top;
    if (top1 == NULL)
    {
        cout<<"\n\a\a\a\a=>NO recently played tracks.\n";
        return;
    }
   cout<<"\n\a\a\a\a#Recently played tracks-\n";
    while (top1 != NULL)
    {
        cout<< top1->song << endl;
        
        top1 = top1->next;
    }
}
void printlist(struct node *first)
{
    cout << "\nPlaylist Name- ";
    while (first->next != NULL)
    {
        cout << first->song << endl;
        first = first->next;
    }
    cout << first->song << endl;
}

void del_node(struct node *first)
{
    while((first->next)->next!=NULL)
    {
        first=first->next;
    }
    struct node *temp;
    temp=(first->next)->next;
    first->next=NULL;
    free(temp);
   cout<<"Deleted"<<endl;
}

void del_search(struct node *start)
{
    char song[100];
    printlist(start);
    cout << "\n\a\a\a\aChoose song you wish to delete- ";
    cin>>song;
    int flag = 0;
    while (start != NULL)
    {
        if (strcmp(start->song, song) == 0)
        {
            cout << "\n\a\a\a\a#Song Found" << endl;
            struct node *temp;
            temp = (struct node *)malloc(sizeof(node));
            temp = start;

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            flag++;
            cout << "\n\a\a\a\a#Song deleted" << endl;
            break;
        }
        else
        {
            start = start->next;
        }
    }
    if (flag == 0)
    {
        cout << "\n\a\a\a\a#Song Not found" << endl;
    }
}

void search1(struct node *first)
{
    char song[100];
    cout << "\n\a\a\a\aEnter song To be Searched- ";
    cin>>song;
    int flag = 0;

    while (first != NULL)
    {
        if (strcmp(first->song, song) == 0)
        {
            cout << "\n\a\a\a\a#Song Found" << endl;
            flag++;
            break;
        }
        else
        {
            first = first->next;
        }
    }
    if (flag == 0)
    {
        cout << "\n\a\a\a\a#Song Not found" << endl;
    }
}

void count_nodes(struct node *first)
{
    int i = 0;
    while (first->next != NULL)
    {
        first = first->next;
        i++;
    }
    i++;
    cout << "\nTotal songs-  " << i - 1 << endl;
}

struct node *del_pos(struct node *pointer, int pos)
{

    struct node *n1, *prev1, *temp;
    prev1 = (struct node *)malloc(sizeof(node));
    temp = (struct node *)malloc(sizeof(node));
    int i = 0;

    if (pos == 1)
    {
        temp = pointer;

        pointer = pointer->next;
        pointer->prev = NULL;
        free(temp);
        cout<<"\nThe list is updated\nUse the display function to check\n";
        return pointer;
    }
    while (i < pos - 1)
    {
        prev1 = pointer;
        pointer = pointer->next;
        i++;
    }

    if (pointer->next == NULL)
    {

        temp = pointer;

        prev1->next->prev = NULL;
        prev1->next = NULL;

        free(temp);
        cout<<"\nThe list is updated\nUse the display function to check\n";
    }

    else
    {
        temp = pointer;

        prev1->next = temp->next;
        temp->next->prev = prev1;
        free(temp);
        cout<<"\nThe list is updated\nUse the display function to check\n";
    }
}
void deletemenu(struct node *start)
{
    int c;
    cout << "Which type of delete do you want?\n1.By Search\n2.By Position" << endl;
    cin >> c;
    switch (c)
    {
    case 1:
        del_search(start);
        break;
    case 2:
        int pos;
        printf("\nEnter the pos of the song : ");
      cin>>pos;
        del_pos(start, pos - 1);
        break;
    }
}

main()
{
    int choice, loc;
    char song[100];
    struct node *start, *hold;
    start = (struct node *)malloc(sizeof(struct node));
    cout << "";
    cout << "\t\t\t\a\a\a\a**WELCOME**" << endl;
    cout << "\n**please use '_' for space." << endl;
    cout << "\n\n\a\a\a\aEnter your playlist name-  ";
    cin.getline(start->song, 100);
    start->next = NULL;
    hold = start;

    do
    {
        cout << "\n1.Add  New Song\n2.Delete Song\n3.Display Entered Playlist\n4.Total Songs\n5.Search Song\n6.Exit" << endl;
        cout << ("\n\a\a\a\aEnter your choice- ");
        cin >> choice;

        switch (choice)
        {
        case 1:
            add_node(start);
            break;
        case 2:
            deletemenu(start);
            break;
        case 3:
            printlist(start);
            break;
        case 4:
            count_nodes(hold);
            break;
        case 5:
            search1(start);
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Invalid choice";
            break;
        }
    } while (choice != 6);
}
