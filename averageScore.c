void averageScore(void) {
    printf("average score\n");

    int how;
    double result = 0.0;

    printf("Number of data : ");
    scanf("%d", &how);

    double* data = (double*)calloc(how, sizeof(double));

    for (int i = 0; i < how; i++) {
        printf("%d data : ", i + 1);
        scanf("%lf", &data[i]);

        result += data[i];
    }

    result /= how;

    printf("inputs :\n");
    printf("[");
    for (int i = 0; i < how; i++) {
        printf(" %.3f ", data[i]);
    }
    printf("]");

    printf("\naverage : %.3f", result);

    free(data);
}
