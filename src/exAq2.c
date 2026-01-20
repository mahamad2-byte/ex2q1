#include <stdio.h>
#include <math.h>
int main(void) {
    float point1_x, point1_y, point2_x, point2_y, point3_x, point_3y;

    float dist_12, dist_13, dist_23;
    float min_dist;
    
    /* ----Read first distance----*/
    printf("Enter coordinates of point 1 (point1_x point1_y): ");
    if (scanf("%f %f", &point1_x, &point1_y) != 2) {
        printf("Invalid input.\n");
        return 1;
    }
    /* ----Read second distance----*/
    printf("Enter coordinates of point 2 (point2_x point2_y): ");
    if (scanf("%f %f", &point2_x, &point2_y) != 2) {
        printf("Invalid input.\n");
        return 1;
    }
    /* ----Read third distance----*/
    printf("Enter coordinates of point 3 (point3_x point3_y): ");
    if (scanf("%f %f", &point3_x, &point_3y) != 2) {
        printf("Invalid input.\n");
        return 1;
    }
    /* ----Calculate distances----*/
    dist_12 = sqrtf((point2_x - point1_x)*(point2_x - point1_y) + (point2_y - point1_y)*(point2_y - point1_y));
    dist_13 = sqrtf((point3_x - point1_x)*(point3_x - point1_x) + (point_3y - point1_y)*(point_3y - point1_y));
    dist_23 = sqrtf((point3_x - point2_x)*(point3_x - point2_x) + (point_3y - point2_y)*(point_3y - point2_y));
 
    /* ----Determine minimum distance----*/

    min_dist = dist_12;
    if (dist_13 < min_dist) 
        min_dist = dist_13;

    
    if (dist_23 < min_dist) 
        min_dist = dist_23;

    
    /*----Check if all distances ----*/
    
    if (dist_12 == dist_13 && dist_13 == dist_23) {
        printf("All distances are equal: %.2f\n", dist_12);
        return 0;

    } 
    
    /*----print only the smallest distance----*/
    if (dist_12 == min_dist) 
        printf(" p1<->p3: %.2f\n", dist_12);
    if (dist_13 == min_dist)
        printf(" p1<->p3: %.2f\n", dist_13);
    if (dist_23 == min_dist)
        printf(" p2<->p3: %.2f\n", dist_23);
    
    

    return 0;
           
}
