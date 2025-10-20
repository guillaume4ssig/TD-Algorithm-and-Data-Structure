#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"
#include "utils.h"

int main(void)
{
    // implement main here
    // create array example using malloc
    int n=200;
    int *tableau = malloc(n * sizeof(int));
    int valeurs[200]= {
        7, 22, 25, 33, 42, 43, 52, 53, 54, 55,
        56, 59, 87, 90, 93, 104, 106, 113, 114, 116,
        118, 121, 129, 131, 136, 138, 140, 149, 150, 164,
        177, 182, 185, 188, 190, 192, 199, 202, 205, 206,
        207, 211, 224, 228, 230, 231, 238, 242, 245, 252,
        262, 270, 284, 288, 290, 292, 296, 299, 315, 317,
        319, 323, 324, 329, 334, 344, 346, 362, 363, 367,
        374, 376, 383, 388, 392, 396, 399, 400, 401, 408,
        412, 413, 414, 416, 417, 436, 453, 460, 461, 468,
        472, 488, 490, 492, 495, 500, 507, 513, 522, 525,
        526, 528, 532, 539, 543, 547, 549, 552, 555, 556,
        564, 569, 572, 574, 582, 583, 585, 588, 590, 592,
        596, 597, 612, 614, 623, 628, 629, 630, 631, 632,
        633, 658, 662, 668, 669, 670, 671, 673, 677, 681,
        689, 695, 705, 706, 707, 716, 718, 731, 735, 740,
        744, 749, 753, 758, 771, 774, 775, 797, 802, 803,
        814, 816, 818, 822, 832, 841, 842, 848, 853, 855,
        864, 866, 876, 885, 886, 887, 895, 896, 901, 913,
        921, 924, 930, 933, 938, 940, 944, 954, 955, 957,
        960, 961, 973, 982, 985, 990, 993, 995, 997, 998
    };

    for (int i = 0; i<n ; i++){
        tableau[i] = valeurs[i];
    }
    // use searching algorithms and compare runtime
    int target = 716;
    clock_t debut, fin;
    double tempsExecution;
    int index;

    if (is_sorted_nondecreasing(tableau, n)) {
        // Linear search
        debut = clock();
        index = linear_search(tableau, n, target);
        fin = clock();
        tempsExecution = (double)(fin - debut) / CLOCKS_PER_SEC;
        printf("Linear search : index = %d, temps = %.6f s\n", index, tempsExecution);

        // Jump search
        debut = clock();
        index = jump_search(tableau, n, target);
        fin = clock();
        tempsExecution = (double)(fin - debut) / CLOCKS_PER_SEC;
        printf("Jump search   : index = %d, temps = %.6f s\n", index, tempsExecution);

        // Binary search
        debut = clock();
        index = binary_search(tableau, n, target);
        fin = clock();
        tempsExecution = (double)(fin - debut) / CLOCKS_PER_SEC;
        printf("Binary search : index = %d, temps = %.6f s\n", index, tempsExecution);
    }
    else {
        printf("Le tableau n'est pas trié, utilisation du linear search uniquement.\n");
        debut = clock();
        index = linear_search(tableau, n, target);
        fin = clock();
        tempsExecution = (double)(fin - debut) / CLOCKS_PER_SEC;
        printf("Linear search : index = %d, temps = %.6f s\n", index, tempsExecution);
    }


    free(tableau);
    return 0;
}
