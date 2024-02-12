#include <stdio.h>

int substitute_vowels(char *s, char ch);

int main(){
    char s[] = "This is a sentence";
    printf("%s\n", s);
    int n = substitute_vowels(s, 'o');
    printf("%s\n", s);
    printf("%d\n", n);
}

int substitute_vowels(char *s, char ch){
    int subCount = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            s[i] = ch;
            subCount++;
        }
    }
    return subCount;
}