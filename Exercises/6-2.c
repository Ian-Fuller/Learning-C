#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getline(char *, int);

int groupCount = 1;

char *keywords[] = {
    "char",
    "int",
    "float",
    "double"
};

char lastSix[MAXWORD] = "______";

/*
Current Issues:
- There's something wrong with how getline ignores non-declarative lines. For example, if "int main() {" is the first line, it will cause treeprint to print the line
  count, but not the string (it shouldn't even know this line exists)
*/

int main(int argc, char *argv[]) {
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getline(word, MAXWORD) != EOF) {
        if (word[0] != '\0') {
            root = addtree(root, word);
        }
    }
    treeprint(root);
    
    return 0;
}

struct tnode *talloc(void);
char *strdup2(char *);

struct tnode *addtree(struct tnode *p, char *w) {
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = strdup2(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0) {
        p->count++;
    }
    else if (cond < 0) {
        p->left = addtree(p->left, w);
    }
    else {
        p->right = addtree(p->right, w);
    }

    return p;
}

void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        char currentSix[MAXWORD];
        int i;
        for (i = 0; i < 6; i++) {
            currentSix[i] = p->word[i];
        }
        currentSix[i] = '\0';
        if (strcmp(currentSix, lastSix) != 0) {
            printf("Group %d:\n", groupCount);
            groupCount++;
        }
        for (i = 0; i < 6; i++) {
            lastSix[i] = currentSix[i];
        }
        lastSix[i] = '\0';
        printf("\t%s\n", p->word);
        treeprint(p->right);
    }
}

struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdup2(char *s) {
    char *p;

    p = (char *) malloc(strlen(s)+1);
    if (p != NULL) {
        strcpy_s(p, MAXWORD, s);
    }

    return p;
}

int getline(char s[], int lim) {
    int c, i, j;
    char s2[MAXWORD], s3[MAXWORD];

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        if (c != '\t') {
            s2[i++] = c;
        }
    }
    s2[i] = '\0';

    // determines if the line is a variable declaration
    int match = 0;
    for (i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        for (j = 0; j < strlen(keywords[i]); j++) {
            s3[j] = s2[j];
        }
        s3[j] = '\0';

        if (strcmp(s3, keywords[i]) == 0) {
            match = 1;
        }
    }

    // if the line is a variable declaraction, get the second word in the line (the variable name)
    if (match == 1) {
        i = 0;
        j = 0;
        while (s2[i] != ' ') {
            i++;
        }
        i++;
        if (s2[i] == '*') {
            i++;
        }
        while (s2[i] != ' ' && s2[i] != ';') {
            if (s2[i] == '(') {
                s[0] = '\0';
                break;
            }
            s[j] = s2[i];
            i++;
            j++;
        }
        s[j] = '\0';
    }

    if (c == EOF) {
        return c;
    }

    return i;
}