#include <iostream>

using namespace std;

class Coin{
    int number_of_coins;
    int A[50],A_not[50];
public:
    void get_number_of_coins(){
        scanf("%d",&number_of_coins);
    }
    void get_coins(){
        int i;
        for(i=0;i<number_of_coins;i++){
            scanf("%d",&A[i]);
        }
        for(i=0;i<number_of_coins;i++)
            A_not[i]=0;
    }
    int maximum(int a,int b){
        return (a>b?a:b);
    }

    int get_maxim_non_cons(){
        int i;
        while(i>-1){
            if(i+2<=number_of_coins-1)
                A[i]+=maximum(A[i+2],A_not[i+2]);
            if(i+1<=number_of_coins-1)
                A_not[i]+=maximum(A[i+1],A_not[i+1]);
            i--;
        }
        return maximum(A[0],A_not[0]);
    }
};

int main()
{
    Coin C1;
    C1.get_number_of_coins();
    C1.get_coins();
    int res=C1.get_maxim_non_cons();
    printf("%d",res);
    return 0;
}
