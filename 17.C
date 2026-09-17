#include <stdio.h>

int task(FILE *, int *);

int main(void){
    FILE *in = fopen("1.txt", "r");
    int err, res;
    err = task(in, &res);
    if (err == 0) {
        printf("Not file\n");
        return -1;
    }
    fclose(in);

    if (err == -1)
        printf("Bad file\n");
    if (err == -2)
        printf("Empty file or 0 only\n");
    if (err == 1)
        printf("result=%d\n", res);
    return 0;
}

int task(FILE *in, int *res) {
    int cur, err, cnt=0, m=0;
    *res = 0;
    if (in == NULL)
        err = 0;
    else {
        while (fscanf(in, "%d", &cur) == 1) {
            (cnt)++;
            if (cur != 0 && m==0){
                *res=cnt;
                m+=1;
            }
        }
        if (!feof(in))
            err = -1;
        else {
            if (*res==0)
                err = -2;
            else
                err = 1;
        }
    }
    return err;
}
