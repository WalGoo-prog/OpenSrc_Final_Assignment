//비밀번호 생성기
void shuffle(char* array, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
}

void generateRandomPassword() {
    int length;
    printf("비밀번호 길이 입력: ");
    if (scanf("%d", &length) != 1) {
        printf("잘못된 입력\n");
        return;
    }

    if (length < 4) {
        printf("비밀번호 최소 4자 이상\n");
        return;
    }

    const int MAX_LEN = 1024;
    if (length > MAX_LEN) {
        printf("너무 긺 최대 %d자로 제한.\n", MAX_LEN);
        length = MAX_LEN;
    }

    const char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char lower[] = "abcdefghijklmnopqrstuvwxyz";
    const char digit[] = "0123456789";
    const char special[] = "!@#$%^&*()-_=+";
    const char allChars[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789"
        "!@#$%^&*()-_=+";

    int upperSize = sizeof(upper) - 1;
    int lowerSize = sizeof(lower) - 1;
    int digitSize = sizeof(digit) - 1;
    int specialSize = sizeof(special) - 1;
    int allSize = sizeof(allChars) - 1;

    char* password = (char*)malloc((size_t)length + 1);
    if (!password) {
        printf("메모리 할당 실패\n");
        return;
    }

    int idx = 0;
    password[idx++] = upper[rand() % upperSize];
    password[idx++] = lower[rand() % lowerSize];
    password[idx++] = digit[rand() % digitSize];
    password[idx++] = special[rand() % specialSize];

    for (int i = idx; i < length; i++) {
        password[i] = allChars[rand() % allSize];
    }

    shuffle(password, length);
    password[length] = '\0';

    printf("생성된 비밀번호: %s\n", password);

    free(password);
}
//비밀번호 생성기

