#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 128

char* generate_password(int length) {
    char* password = new char[length + 1];
    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        int random_char = rand() % 94 + 33; // ASCII range: 33 to 126
        password[i] = (char)random_char;
    }

    password[length] = '\0'; // null-terminate the string
    return password;
}

int main() {
    int password_length;
    printf("Enter the desired password length (max %d): ", MAX_PASSWORD_LENGTH);
    scanf("%d", &password_length);

    if (password_length > MAX_PASSWORD_LENGTH) {
        printf("Password length too long. Maximum allowed is %d.\n", MAX_PASSWORD_LENGTH);
        return 1;
    }

    char* password = generate_password(password_length);
    printf("Generated password: %s\n", password);

    FILE* file = fopen("password.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fprintf(file, "%s", password);
    fclose(file);
    printf("Password saved to password.txt.\n");

    delete[] password;
    return 0;
}
