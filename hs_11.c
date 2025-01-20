#include <stdio.h>
int main()
{

    int array[3][3][3];

    int *ptr = &array[0][0][0];
    for (int i = 0; i < 27; i++)
    {
        *(ptr + i) = i + 1;
    }

    printf("3D Array Elemente:\n\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Dimension %d:\n", i + 1);
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                printf("%3d ", array[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}