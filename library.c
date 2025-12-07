#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct
{
    int id;
    char title[100];
    char author[100];
} Book;

Book catalog[MAX_BOOKS];
int count = 0;

void trim_newline(char *s)
{
    size_t n = strlen(s);
    if (n && s[n - 1] == '\n')
        s[n - 1] = '\0';
}

void add_book(void)
{
    if (count >= MAX_BOOKS)
    {
        puts("Catalog full!");
        return;
    }
    printf("ID: ");
    scanf("%d", &catalog[count].id);
    getchar();
    printf("Title : ");
    fgets(catalog[count].title, sizeof(catalog[count].title), stdin);
    trim_newline(catalog[count].title);
    printf("Author: ");
    fgets(catalog[count].author, sizeof(catalog[count].author), stdin);
    trim_newline(catalog[count].author);
    ++count;
    puts("Book added.\n");
}

void list_books(void)
{
    if (!count)
    {
        puts("No books yet.\n");
        return;
    }
    puts("\n--- Catalog ---");
    for (int i = 0; i < count; ++i)
        printf("%d) [%d] \"%s\" by %s\n", i + 1, catalog[i].id,
               catalog[i].title, catalog[i].author);
    putchar('\n');
}

void search_book(void)
{
    int key;
    printf("Enter ID to search: ");
    if (scanf("%d", &key) != 1)
    {
        getchar();
        return;
    }
    for (int i = 0; i < count; ++i)
        if (catalog[i].id == key)
        {
            printf("Found: \"%s\" by %s\n\n",
                   catalog[i].title, catalog[i].author);
            return;
        }
    puts("Not found.\n");
}

int main(void)
{
    int choice;
    for (;;)
    {
        puts("1.Add  2.List  3.Search  4.Exit");
        printf("Choice: ");
        if (scanf("%d", &choice) != 1)
            break;
        getchar();
        switch (choice)
        {
        case 1:
            add_book();
            break;
        case 2:
            list_books();
            break;
        case 3:
            search_book();
            break;
        case 4:
            return 0;
        default:
            puts("Invalid.\n");
        }
    }
    return 0;
}
