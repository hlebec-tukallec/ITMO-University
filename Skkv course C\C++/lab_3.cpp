#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double EPS = 1e-12;

void swap(double *a, double *b) {
    double tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

double *gauss(double **a, int n, int *flag) {
    int *spot;
    spot = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        spot[i] = -1;
    }

    double *ans;
    ans = malloc(sizeof(double) * n);


    for (int col = 0, row = 0; col < n && row < n; col++) {
        int cell = row;
        for (int i = row; i < n; i++) {
            if (fabs(a[i][col]) > fabs(a[cell][col])) {
                cell = i;
            }
        }
    
        if (fabs(a[cell][col]) < EPS) {
            continue;
        }
        for (int i = col; i < n + 1; i++) {
            swap(&a[cell][i], &a[row][i]);
        }
        spot[col] = row;

        for (int i = 0; i < n; i++) {
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j = col; j < n + 1; j++) {
                    a[i][j] -= a[row][j] * c;
                }
            }
        }
        row++;
    }


    for (int i = 0; i < n; i++) {
        if (spot[i] != -1) {
            ans[i] = a[spot[i]][n] / a[spot[i]][i];
        }
    }
    for (int i = 0; i < n; i++) {
        double s = 0;
        for (int j = 0; j < n; j++) {
            s += ans[j] * a[i][j];
        }
      
        if (fabs(s - a[i][n]) > EPS) {
            *flag = -1;
            free(spot);
            return ans;
        }
    }
    for (int i = 0; i < n; i++) {
        if (spot[i] == -1) {
            *flag = 1;
            free(spot);
            return ans;
        }
    }
    free(spot);
    return ans;
}

int main(int argc, char **argv) {
    //lab3 input.txt output.txt

    if (argc < 3) {
        printf("Wrong arguments! Try again.");
        return 1;
    }

    FILE *r;
    if ((r = fopen(argv[1], "r")) == NULL) {
        printf("Can't open the input file");
        return 2;
    }

    FILE *w;
    if ((w = fopen(argv[2], "w")) == NULL) {
        printf("Can't open the output file");
        return 3;
    }

    int n;
    if (fscanf(r, "%d", &n) == EOF) {
        printf("Empty input file");
        return 4;
    }


    double **matrix;
    matrix = malloc(sizeof(double *) * n);

    for (int i = 0; i < n; i++) {
        matrix[i] = malloc(sizeof(double) * (n + 1));
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            if (!(fscanf(r, "%lg", &matrix[i][j]))) {
                printf("Allocation error");
                return 5;
            }
        }
    }
    fclose(r);

    double *ans;
    int flag = 0;
    ans = gauss(matrix, n, &flag);

    if (flag == 0) {
        for (int i = 0; i < n; i++) {
            fprintf(w, "%lg\n", ans[i]);
        }
    } else if (flag == -1) {
        fprintf(w, "%s", "no solution");
    } else {
        fprintf(w, "%s", "many solutions");

    }

    fclose(w);

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(ans);

    return 0;
}

