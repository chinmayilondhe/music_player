#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

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
    scanf("%s", &a);
    strcpy(first->song, a);
    // tofile(a);
    first->next = NULL;
}



main()
{
    int choice, loc;
    char song[100];
    struct node *start, *hold;
    start = (struct node *)malloc(sizeof(struct node));
    cout<< ""
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
        // case 2:deletemenu(start);
        // break;
        // case 3:printlist(start);
        // break;
        // case 4:count_nodes(hold);
        // break;
        // case 5:search1(start);
        // break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Invalid choice";
        }
    } while (choice != 6);
}