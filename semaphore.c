#include <stdio.h>
#include <stdlib.h>
int n, mutex = 1, x = 0, empty = 3, full = 0;
int wait(int);
int signal(int);
void producer();
void consumer();
void main()
{
    printf("1.Producer\n2.Consumer\n3.Exit\n");
    while (1)
    {
        printf("Enter your choice: \n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            if (mutex == 1 && empty != 0)
            {
                producer();
            }
            else
            {
                printf("BUFFER IS FULL\n");
            }
            break;
        case 2:
            if (mutex == 1 && full != 0)
            {
                consumer();
            }
            else
            {
                printf("BUFFER IS EMPTY\n");
            }
            break;
        case 3:
            exit(0);
        }
    }
}
int wait(int s)
{
    return (--s);
}
int signal(int s)
{
    return (++s);
}

void producer()
{
    mutex = wait(mutex);
    empty = wait(empty);
    full = signal(full);
    mutex = signal(mutex);
    x++;
    printf("Producer produces item %d \n", x);
}
void consumer()
{
    mutex = wait(mutex);
    empty = signal(empty);
    full = wait(full);
    mutex = signal(mutex);
    x--;
    printf("Consumer consumes item %d \n", x);
}