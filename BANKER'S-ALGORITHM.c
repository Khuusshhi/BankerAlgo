#include <stdio.h>
int i, j, ind, safe = 1, exec, count = 0, p, r, x = 0, c = 0;

int Print(int allocation[p][r], int need[p][r], int available[r], int p, int r)
{
    printf("\n--------------------------------------------------\n");
    printf("\n Process No.|Allocation Matrix: \n");
    for (i = 0; i < p; i++)
    {
        printf("  P%d        |", i);
        for (j = 0; j < r; j++)
        {
            printf("  %d   ", allocation[i][j]);
        }
        printf("\n");
    }
    printf("\n Available resources:  \n");
    for (i = 0; i < r; i++)
    {
        printf("   %d ", available[i]);
    }
    printf("\n");
    printf("\nCalculated Need Matrix:(Allocation Matrix - Max Matrix) ");
    printf("\n Process No.|Need Matrix : \n");
    for (i = 0; i < p; i++)
    {
        printf("  P%d        |", i);
        for (j = 0; j < r; j++)
        {
            printf("  %d   ", need[i][j]);
        }
        printf("\n");
    }
}

int Safe_Unsafe(int running1[p], int available1[r], int need1[p][r], int allocation1[p][r], int p1, int r1, int count1)
{
    int ans[p1], tempavail[r1], tempneed[p1][r1], tempalloc[p1][r1];
    for (j = 0; j < r1; j++)
    {
        tempavail[j] = available1[j];
    }
    for (i = 0; i < p1; i++)
    {
        for (j = 0; j < r1; j++)
        {
            tempneed[i][j] = need1[i][j];
            tempalloc[i][j] = allocation1[i][j];
        }
    }
    for (int k = 0; k < p1; k++)
        ans[k] = -1;
    ind = 0;
    while (count1 != 0)
    {
        safe = 0;
        for (i = 0; i < p1; i++)
        {
            if (running1[i])
            {
                exec = 1;
                for (j = 0; j < r1; j++)
                {
                    if (need1[i][j] > available1[j])
                    {
                        exec = 0;
                    printf("\nProcess%d 's need is more than available\n", i);
                        break;
                    }
                }
                if (exec)
                {
                    printf("\nProcess%d 's need is Less than available\n", i);
                    printf("\nProcess%d is Finished\n", i);
                    ans[ind++] = i;
                    running1[i] = 0;
                    count1--;
                    safe = 1;

                    for (j = 0; j < r1; j++)
                    {
                        available1[j] += allocation1[i][j];
                        allocation1[i][j] = 0;
                        need1[i][j] = 0;
                    }

                    break;
                }
            }
        }
        if (!safe)
        {
            printf("\nThe processes are in unsafe state.\n");
            c = 1;
            return c;
            break;
        }
        else
        {
            x = 1;
            Print(allocation1, need1, available1, p1, r1);
            printf("\nsequence is: (-1 denotes blank!)");

            for (j = 0; j < p1; j++)
            {
                printf("\t%d", ans[j]);
            }

            printf("\n");
        }
    }
    if (x == 1)
    {
        printf("\nFollowing is the SAFE Sequence\n");
        for (i = 0; i < p1 - 1; i++)
        {

            printf(" P%d ->", ans[i]);
        }
        printf(" P%d", ans[p1 - 1]);
    }

    for (i = 0; i < p1; i++)
    {
        for (j = 0; j < r1; j++)
        {
            available1[j] -= allocation1[i][j];
        }
    }
    for (i = 0; i < p; i++)
    {
        running1[i] = 1;
        count1++;
    }
    for (j = 0; j < r1; j++)
    {
        available1[j] = tempavail[j];
    }
    for (i = 0; i < p1; i++)
    {
        for (j = 0; j < r1; j++)
        {
            need1[i][j] = tempneed[i][j];
            allocation1[i][j] = tempalloc[i][j];
        }
    }
}

int main()
{
    printf("\n\tBANKER'S ALGORITHM\n");
    printf("\n1st Part: Saftey Algorithm\n");
    printf("\nEnter Number of Processes: ");
    scanf("%d", &p);
    printf("\nEnter Number of Resources: ");
    scanf("%d", &r);
    int running[p], count = 0;
    for (i = 0; i < p; i++)
    {
        running[i] = 1;
        count++;
    }

    int allocation[p][r];
    printf("\nEnter Resources allocated to each Process:\n ");
    for (i = 0; i < p; i++)
    {
        printf("\nFor Process P%d ", i);
        for (j = 0; j < r; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }
    int max[p][r];
    printf("\nEnter the number of Resources a Process can maximum acquire:\n ");
    for (i = 0; i < p; i++)
    {
        printf("\nFor Process P%d ", i);
        for (j = 0; j < r; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    int available[r];
    printf("\nEnter the number of Resources available for allocation:\n");
    for (i = 0; i < r; i++)
    {
        scanf("%d", &available[i]);
    }
    int need[p][r];
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
            need[i][j] = max[i][j] - allocation[i][j];
    }

    printf("\nYour Provided Data is here: \n");
    printf("\n Process No.|Allocation Matrix: \n");
    for (i = 0; i < p; i++)
    {
        printf("  P%d        |", i);
        for (j = 0; j < r; j++)
        {
            printf("  %d   ", allocation[i][j]);
        }
        printf("\n");
    }
    printf("\n Process No.|Max Matrix: \n");
    for (i = 0; i < p; i++)
    {
        printf("  P%d        |", i);
        for (j = 0; j < r; j++)
        {
            printf("  %d   ", max[i][j]);
        }
        printf("\n");
    }

    printf("\n Available resources:  \n");
    for (i = 0; i < r; i++)
    {
        printf("   %d ", available[i]);
    }
    printf("\n");
    printf("\nCalculated Need Matrix:(Allocation Matrix - Max Matrix) ");
    printf("\n Process No.|Need Matrix : \n");
    for (i = 0; i < p; i++)
    {
        printf("  P%d        |", i);
        for (j = 0; j < r; j++)
        {
            printf("  %d   ", need[i][j]);
        }
        printf("\n");
    }
    Safe_Unsafe(running, available, need, allocation, p, r, count);

    if (c == 1)
        printf("\nUnsafe State so it will not go into Resource Request Algorithm\n");
    else
    {
        printf("\n----------------------------------------------------------------------------------\n\n");
        printf("\n 2nd Part: Resource Request Algorithm\n");
        printf("\nEnter the process number: ");
        int pr;
        scanf("%d", &pr);
        printf("\nEnter requested resources: ");
        int req[r];
        for (i = 0; i < r; i++)
        {
            scanf("%d", &req[i]);
        }
        int check = 0;
        for (i = 0; i < r; i++)
        {
            if (req[i] <= available[i])
            {
                available[i] -= req[i];
                if (need[pr][i] >= req[i])
                {
                    allocation[pr][i] += req[i];
                    need[pr][i] -= req[i];
                }
                else
                {
                    printf("\nRequest is not valid! Due to Need of P%d is Less than Request! So it will not go into Resource Request Algorithm", pr);
                    check = 1;
                    break;
                }
            }
            else
            {
                printf("\nAvailable Resources are Less than Request of P%d So it will not go into Resource Request Algorithm", pr);
                check = 1;
                break;
            }
        }
        if (check == 0)
        {
                printf("\n Request is Less than or equal to Available\n");
                    printf("\n Request is Less than or equal to Need\n");
            printf("\nRequest is Valid: ");
            Print(allocation, need, available, p, r);
            Safe_Unsafe(running, available, need, allocation, p, r, p);
        }
    }
    return 0;
}