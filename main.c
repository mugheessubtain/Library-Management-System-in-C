#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book
{
    int id;
    char title[100];
    char author[100];
    int year;
};
void addBook(struct Book **book, int *count)
{
    (*count)++;
    *book = (struct Book *)realloc(*book, (*count) * sizeof(struct Book));
    if (*book == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    printf("\nEnter book ID:");
    scanf("%d", &((*book)[*count - 1].id));

    printf("Enter Book Name: ");
    scanf(" %[^\n]", (*book)[*count - 1].title);

    printf("Enter author name: ");
    scanf(" %[^\n]", (*book)[*count - 1].author);

    printf("Enter year: ");
    scanf("%d", &(*book)[*count - 1].year);

    printf("Book added successfully!\n");
}

void displayBook(struct Book *book,int count)
{
    if(count==0){
        printf("No book avaliable");
    }
    for(int i=0;i<count;i++){
        printf("Book id is: %d\n",book[i].id);
        printf("Book name is: %s\n",book[i].title);
        printf("Book author is: %s\n",book[i].author);
        printf("Book year is: %d\n",book[i].year);
    }
}

void exitData(struct Book *book)
{
    free(book);
    printf("Memory freed successfully.\n");

}

int main()
{
    struct Book *book = NULL;
    int count = 0;
    int choice;

    do
    {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addBook(&book, &count);
            break;
        case 2:
            displayBook(book,count);
            break;
        case 3:
            exitData(book);
            break;
        default:
            printf("Default");
            break;
        }
    } while (choice != 3);
}