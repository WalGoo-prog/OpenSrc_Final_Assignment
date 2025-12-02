#include <stdio.h>
#include <ctype.h>
#include <string.h>

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void removeNewline(char* str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}

void convertToggle(char* str) {
    for (int i = 0; str[i]; i++) {
        if (islower(str[i]))      str[i] = toupper(str[i]);
        else if (isupper(str[i])) str[i] = tolower(str[i]);
    }
}

void convertUpper(char* str) {
    for (int i = 0; str[i]; i++)
        str[i] = toupper(str[i]);
}

void convertLower(char* str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

void stringCaseConverter() {
    char str[100];
    int choice;

    while (1) {
        printf("\n[문자열 대/소문자 변환기]\n");
        printf("1. 대문자로 변환\n");
        printf("2. 소문자로 변환\n");
        printf("3. 대/소문자 반전\n");
        printf("4. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);
        clearInputBuffer();

        if (choice == 4) {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        printf("문자열 입력: ");
        fgets(str, sizeof(str), stdin);
        removeNewline(str);

        if (strlen(str) == 0) {
            printf("입력이 비어있습니다. 다시 시도하세요.\n");
            continue;
        }

        switch (choice) {
        case 1:
            convertUpper(str);
            break;
        case 2:
            convertLower(str);
            break;
        case 3:
            convertToggle(str);
            break;
        default:
            printf("잘못된 선택입니다.\n");
            continue;
        }

        printf("변환 결과: %s\n", str);
    }
}
