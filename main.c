#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 20
#define COLS 50

char canvas[ROWS][COLS];

/* Clear canvas */
void clearCanvas() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            canvas[i][j] = '_';
        }
    }
}

/* Display canvas */
void displayCanvas() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

/* Draw rectangle */
void drawRectangle(int x, int y, int width, int height) {
    for (int i = y; i < y + height && i < ROWS; i++) {
        for (int j = x; j < x + width && j < COLS; j++) {

            if (i == y || i == y + height - 1 ||
                j == x || j == x + width - 1) {
                canvas[i][j] = '*';
                
            }
            
        }
    }
}
void drawCircle(int cx, int cy, int r)
{
    for (int y = 0; y < ROWS; y++)
    {
        for (int x = 0; x < COLS; x++)
        {
            int dx = x - cx;
            int dy = y - cy;

            int dist = dx * dx + dy * dy;

            if (abs(dist - r * r) <= r)
            {
                canvas[y][x] = '*';
            }
        }
    }
}
void drawTriangle(int x, int y, int height)
{
    for(int i = 0; i < height; i++)
    {
        canvas[y + i][x - i] = '*';
        canvas[y + i][x + i] = '*';
    }

    for(int j = x - height + 1; j <= x + height - 1; j++)
    {
        canvas[y + height - 1][j] = '*';
    }
}
void drawLine(int x1, int y1, int x2, int y2) {
    int x;

    if (y1 == y2) {
        for (x = x1; x <= x2; x++) {
            canvas[y1][x] = '-';
        }
    }
}

int main() {
    int choice;
    int x, y, width, height;

    clearCanvas();

    do {
        printf("\n===== 2D Graphics Editor =====\n");
        printf("1. Draw Rectangle\n");
        printf("2. Display Canvas\n");
        printf("3. Clear Canvas\n");
        printf("4. Exit\n");
        printf("5. Draw Line\n");
        printf("6. Draw Circle\n");
        printf("7. Draw Triangle\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter x y width height: ");
                scanf("%d %d %d %d", &x, &y, &width, &height);

                drawRectangle(x, y, width, height);

                printf("Rectangle Added!\n");
                break;

            case 2:
                displayCanvas();
                break;

            case 3:
                clearCanvas();
                printf("Canvas Cleared!\n");
                break;

            case 4:
                printf("Exiting...\n");
                break;
            case 5:
{
    int x1, y1, x2, y2;

    printf("Enter x1 y1 x2 y2: ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    drawLine(x1, y1, x2, y2);

    printf("Line Added!\n");
    break;
}
case 6:
{
    int cx, cy, r;

    printf("Enter center x y and radius: ");
    scanf("%d %d %d", &cx, &cy, &r);

    drawCircle(cx, cy, r);

    printf("Circle Added!\n");
    break;
}
case 7:
{
    int tx, ty, h;

    printf("Enter x y height: ");
    scanf("%d %d %d", &tx, &ty, &h);

    drawTriangle(tx, ty, h);

    printf("Triangle Added!\n");
    break;
}
            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 4);

    return 0;
}