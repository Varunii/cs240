//
// Created by haoyu on 9/18/2022.
//
#include <stdlib.h>
#include <stdio.h>

typedef struct string {
    char *s;
    int len, cap;
} String;


String *append_string(String *s, char c) {
    if (s->cap == s->len) {
        s->cap <<= 1;
        s->s = (char *) realloc(s->s, s->cap);
    }
    s->s[s->len++] = c;
    s->s[s->len] = 0;
    return s;
}

char *getLine(String *s) {
    s->len = 0;
    char c;
    while (1) {
        c = getchar();
        if (c == -1 || c == '\n') return s->s;
        append_string(s, c);
    }
}


int solution(char *S, char *F) {
    int solution(char *S,char *F) {
    // contains array will stores the 26
    // the size is 26 means index 0-a,1-b and so on
    int contains[26],i,res = 0;
    // making the contains[i] = 0 means first all the characters are not present
    for(i = 0;i<26;i++) {
        contains[i] = 0;
    }
    // for each character present in the F then we will make the index of the character to 1
    // for example if F is 1 then contains[0] = 1
    i = 0;
    while(F[i] != '\0') {
        contains[F[i] - 97] = 1;
        i++;
    }
    i = 0;
    // for each character in the S
    while(S[i] != '\0') {
        int curr = S[i] - 97,count1 = 0,count2 = 0,j;
        j = curr;
        // counts the number of operation takes if we consider succeding one
        do {
            if(contains[j] == 1)
                break;
            count1++;
            j++;
            if(j > 25) {
                j = 0;
            }
        }while(j != curr);
        // counts the number of operation takes if we consider preceding one
        j = curr;
        do {
            if(contains[j] == 1)
                break;
            count2++;
            j--;
            if(j < 0) {
                j = 25;
            }
        }while(j != curr);
        // adds the smallest count to the res
        if(count1 < count2) {
            res += count1;
        }
        else {
            res += count2;
        }
        i++;
    }
    // returns res
    return res;
    
    
}
}

int main(int argc, char *argv[]) {
    int t;
    String s1 = {malloc(10), 0, 10},
            s2 = {malloc(10), 0, 10};
    t = atoi(getLine(&s1));
    for (int i = 1; i <= t; ++i) {
        getLine(&s1);
        getLine(&s2);

        if (argc == 1) {
            printf("Case #%d: %d\n", i, solution(s1.s, s2.s));
        } else if (atoi(argv[1]) == i) {
            printf("s1: %s\n", s1.s);
            printf("s2: %s\n", s2.s);
        }
        s1.len = 0;
        s2.len = 0;
    }
    return 0;
}
