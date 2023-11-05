/*喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水（编程实现）。*/
int main(){
    int numwater = 0;
    int money = 20;
    while(money>0){
        numwater++;
        if(numwater%2) money--;
    }
    printf("%d",numwater);
    return 0;
}