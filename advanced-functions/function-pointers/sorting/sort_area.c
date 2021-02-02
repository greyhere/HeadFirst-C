#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int width;
    int height;
} rectangle;


int compare_area(const void *a, const void *b)
{
    // first convert pointers to the correct type
    rectangle *ra = (rectangle *)a;
    rectangle *rb = (rectangle *)b;

    // then, calculate the area
    int area_a = (ra->width * ra->height);
    int area_b = (rb->width * rb->height);

    // then, use the substraction trick
    return (area_a > area_b) - (area_a < area_b);
}


int main()
{
    // create rectangles
    rectangle r1 = {10, 5};
    rectangle r2 = {5, 8};
    rectangle r3 = {20, 8};
    rectangle r4 = {5, 6};

    // add rectangles to an array
    rectangle rectangles[] = {r1, r2, r3, r4};

    // sort rectangles in area order
    qsort(rectangles, 4, sizeof(rectangle), compare_area);
    
    puts("These are the areas in order:");
    for (int i = 0; i < 4; i++)
        printf("Area = %i (width: %i, height: %i)\n",
                (rectangles[i].width * rectangles[i].height), rectangles[i].width, rectangles[i].height);

    return 0;
}
