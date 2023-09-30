#include<stdio.h>

int main(){
    int murderer = 0;
    for (murderer = 'a'; murderer <= 'd'; murderer++){
        if ((murderer != 'a') + (murderer == 'c') + (murderer == 'd') + (murderer != 'd') == 3)
            printf("%c", murderer);
    }
    return 0;
}