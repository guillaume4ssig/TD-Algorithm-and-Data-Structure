char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";
    char* longest = strs[0];
    int j;
    for (j = 0; longest[j] != '\0'; j++) {
        for (int i = 1; i < strsSize; i++) {
            if (strs[i][j]!=longest[j]|| strs[i][j] == '\0'){
                char* res = malloc(j + 1);
                strncpy(res, strs[0], j);
                res[j] = '\0';
                return res;
            }
        }
    }
    char* res = malloc(j + 1);
    strncpy(res, strs[0], j);
    res[j] = '\0';
    return res;
}