#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE 256  //Max length of a line in the text
#define WORD 30   //Max length of a word in the text


// this function uses to read a line from the text
int get_line(char s[]){
    int chars_received = 0;
    char c;
    for (int i = 0; i < LINE; i++){
        scanf("%c", &c);
        if(feof(stdin)){
            break;
        }
        chars_received++;
        s[i] = c;
        if(c == '\n'){
            break;
        }
    }
    return chars_received;  
}

// this function uses to read a one word from the text
int getword(char w[]){
    int chars_received = 0;
    char c;
    for (int i = 0; i < WORD; i++){
       scanf("%c", &c);
        if(feof(stdin)){
            break;
        }else if(c == '\n' || c == ' ' || c == '\t' || c == '\r'){
            w[i] = '\0';
            break;
        }
        w[i] = c; 
        chars_received++;      
    }
    return chars_received;
}

// this function uses to check if one string is a substring of another
int substring(char* str1, char* str2){
    char* ans = strstr(str1, str2);
    if(ans != NULL){
        return 1;
    }
    return 0;
}

// this function uses to check if one string is similiar to another- 
// if str1 is different by only one letter from str2 
int similiar(char* s, char* t){
    int slen = (int)strlen(s);
    int tlen = (int)strlen(t);
    if((slen - tlen) > 1 || slen < tlen){
        return 0;
    }
    int count = 0;
    int i = 0;
    int j = 0;
    while (i < slen && j < tlen){
        if(s[i] != t[j]){
            count++;
            i++;
            if(count > 1){
                return 0;
            }
        }else{
            i++;
            j++;
        }
    }
    return 1;
}

int main(){
    
    char str[WORD]; // buffer for the string to search 
    char operation[WORD]; // buffer for the operation to do
    char buffer[LINE]; // buffer for reading a line or a word from the text file

    getword(str);
    getword(operation);
    get_line(buffer); // skip on the second line which is empty

    // if the operation is a, we'll check for every line in text if str is a substring of it.
    if(operation[0] == 'a'){
        int chars_recevid = get_line(buffer); 
        while(chars_recevid != 0){
            if(substring(buffer, str)){
                printf("%s", buffer);
            }
            chars_recevid = get_line(buffer);
        }
    }
    // if the operation is b we'll check for every word in text if str is similiar to it.
    if(operation[0] == 'b'){
        int chars_recevid = getword(buffer);
        while(chars_recevid != 0){
            if(similiar(buffer, str)){
                printf("%s\n", buffer);
            }
            chars_recevid = getword(buffer);
        }
    }
    
    return 0;
}

