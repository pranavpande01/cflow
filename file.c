#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare variables to store the read values
    int iteration;
    double theta, learning_rate, beta_1, beta_2, epsilon, m, v;

    // Open the file for reading
    FILE *file = fopen("values.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read the values from the file
    fscanf(file, "%d", &iteration);
    fscanf(file, "%lf", &theta);
    fscanf(file, "%lf", &learning_rate);
    fscanf(file, "%lf", &beta_1);
    fscanf(file, "%lf", &beta_2);
    fscanf(file, "%lf", &epsilon);
    fscanf(file, "%lf", &m);
    fscanf(file, "%lf", &v);

    // Close the file
    fclose(file);

    // Print the values
    printf("Iteration: %d\n", iteration);
    printf("Theta: %lf\n", theta);
    printf("Learning Rate: %lf\n", learning_rate);
    printf("Beta 1: %lf\n", beta_1);
    printf("Beta 2: %lf\n", beta_2);
    printf("Epsilon: %lf\n", epsilon);
    printf("m: %lf\n", m);
    printf("v: %lf\n", v);

    return 0;
}
