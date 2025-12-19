int cmp(const void* a, const void* b) {
    return *(int *)a - *(int *)b;
}

int maximumPopulation(int** logs, int logsSize, int* logsColSize) {
    int* birth = malloc(sizeof(int)*logsSize);
    int* death = malloc(sizeof(int)*logsSize);
    for(int i = 0; i < logsSize; i++){
        birth[i] = logs[i][0];
        death[i] = logs[i][1];
    }

    qsort(birth, logsSize, sizeof(int), cmp);
    qsort(death, logsSize, sizeof(int), cmp);

    int max_pop = 0;
    int curr_pop = 0;
    int year = 1950;

    int born = 0;
    int died = 0;

    while (born < logsSize && died < logsSize) {
        int curr_birth = birth[born];
        int curr_death = death[died];

        if (curr_birth < curr_death) {
            curr_pop++;
            born++;
            if (curr_pop > max_pop) {
                year = curr_birth;
                max_pop = curr_pop;
            }
        } else {
            curr_pop--;
            died++;
        }
    }

    *logsColSize = logsSize;
    free(birth);
    free(death);
    return year;
}
