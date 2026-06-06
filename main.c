#include <stdio.h>

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

            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 4);

    return 0;
}