//----------------------------------------------------------------------------------------
/* //
Table of Contents

1. Rotate 2D Image (N x N) 90 Degrees

2. Rotate 2D Image (N x N) 90 Degrees In Place

3. Traverse (NxN) array spirally


TODO:
1. Given a 2d array of integers, how do you efficiently modify the array to zero-out any rows and columns that originally contained a zero?
Looking for a algorithm run time less than O(n^2) (can sacrifice space!)

// */
//----------------------------------------------------------------------------------------
/*
// 1 Rotate 2D Image (N x N) 90 Degrees
// Rotate an image 90 degrees, allowed to create new array
// TODO: REDO THIS!!!!! TOO MUCH MISTAKES AT FIRST
// This takes O(n^2)

#include <stdlib.h>
#include <stdio.h>

void rotate90(int** image, int row, int col);

int main(void)
{
    //int image[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int** image = (int**) malloc(sizeof(int*) * 3);
    int i = 0;
    int j = 0;

    for ( i =0; i < 3; i++)
    {
        image[i] = (int*) malloc(sizeof(int) * 3);
    }

    int count = 1;

    for ( i =0; i < 3; i++)
    {
        for( j = 0; j < 3; j++)
        {
            image[i][j] = count;
            count++;
        }
    }

    for ( i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    rotate90(image, 3, 3);
    printf("after rotating\n");

    for ( i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void rotate90(int** image, int row, int col)
{
    int copyImage[row][col];
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++)
    {
            for(j = 0; j< col; j++)
            {
                copyImage[col-j-1][i] = image[i][j];
            }
    }

    for (i = 0; i < row; i++)
    {
            for(j = 0; j< col; j++)
            {
                image[i][j] = copyImage[i][j];
            }
    }
    return;
}

// */

//----------------------------------------------------------------------------------------
/* //
// 2 Rotate 2D Image (N x N) 90 Degrees In Place
// Rotate an image 90 degrees in place. Can create constant memory but not an entire array
// time->O(n^2)
// TODO: Do this again, too many mistakes
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>

void rotate90InPlace(int** image, int n);

int main(void)
{
    int counter = 1;
    int** image;
    image = (int **) malloc(sizeof(int*) * 4);
    int i = 0;
    int j = 0;
    for (i = 0; i < 4; i ++)
    {
        image[i] = (int *) malloc(sizeof(int) * 4);
        for ( j = 0; j < 4; j++)
        {
            image[i][j] = counter;
            counter++;
        }
    }

    for (i = 0; i < 4; i ++)
    {
        for ( j = 0; j < 4; j++)
        {
            printf("%d   ", image[i][j]);
        }
        printf("\n");
    }    printf("%f %f INSWAP\n", a, b);

    rotate90InPlace(image, 4);
    printf("After Rotating \n");

    for (i = 0; i < 4; i ++)
    {
        for ( j = 0; j < 4; j++)
        {
            printf("%d   ", image[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void rotate90InPlace(int** image, int n)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < floor(n/2); i++)
    {
        int end1 = n - i - 1;
        for(j = i; j < end1; j++)
        {

            int end2 = n - j - 1;
            int temp = image[j][i];
            image[j][i] = image[i][end2];
            image[i][end2] = image[end2][end1];
            image[end2][end1] = image[end1][j];
            image[end1][j] = temp;
        }
    }
    return;
}
// */
//----------------------------------------------------------------------------------------
/* //
// 3 Traverse (NxN) array spirally
// Traverse array Spirally
// Time Complexity O(n^2) , if array is size a[n][n]
// Space Complexity O(1)
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

void printValue(int a);
void traverseSpiralTopRight(int** a, int x1, int x2, int y1, int y2,void (*funcPointer)(int));
void traverseSpiralBottomLeft(int** a, int x1, int x2, int y1, int y2,void (*funcPointer)(int));
int main(void)
{
    int** a;
    int N = 5;
    a = (int**) malloc(sizeof(int*) * N);
    int i = 0;
    for(i = 0; i < N; i++)
    {
        a[i] = (int *) malloc(sizeof(int) * N);
    }
    int count = 0;

    int j = 0;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            a[i][j] = count;
            count++;
        }
    }
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            cout << a[i][j] <<" ";
        }
        cout << endl;
    }
    cout << endl;
    void (*funcPointer)(int) = &printValue;
    traverseSpiralTopRight(a,0, N-1, 0, N-1, funcPointer);
    return 0;
}


void printValue(int a)
{
    cout << a << " ";
    return;
}

void traverseSpiralTopRight(int** a, int x1, int x2, int y1, int y2,void (*funcPointer)(int) )
{
    int i = 0;
    int j = 0 ;
    double temp;
    for (i = x1; i <= x2; i++)
    {
        // Mistake, its [y][x] NOT [x][y]
        temp = a[y1][i];
        funcPointer(temp);
    }
    // Mistake: Start from y1+1, NOT y1
    for(j = y1+1; j <= y2; j++)
    {
        temp = a[j][x2];
        funcPointer(temp);
    }
    if (x2 - x1 > 0)
    {
        return traverseSpiralBottomLeft(a, x1, x2-1, y1+1, y2, funcPointer);
    }
    return;
}

void traverseSpiralBottomLeft(int** a, int x1, int x2, int y1, int y2,void (*funcPointer)(int))
{
    int i = 0;
    int j = 0 ;
    double temp;
    for (i = x2; i >= x1; i--)
    {
        temp = a[y2][i];
        funcPointer(temp);
    }
    // Mistake: Start from y2-1, NOT y2
    for(j = y2-1; j >= y1; j--)
    {
        temp = a[j][x1];
        funcPointer(temp);
    }
    if (x2 - x1 > 0)
    {
        return traverseSpiralTopRight(a, x1+1, x2, y1, y2-1, funcPointer);
    }
    return;
}
// */
//----------------------------------------------------------------------------------------
