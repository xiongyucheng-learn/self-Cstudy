#ifndef SAYS
#define SAYS
#define MAX_WORD 20
extern char words[MAX_WORD+1];
extern int word_len;
int read_word(void);
#endif