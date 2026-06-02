#include <stdio.h>

int main(){
    int block[3]={100,500,200};
    int process[3]={212,417,112};

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(block[j]>=process[i]){
                printf("Process %d allocated to block %d\n",i+1,j+1);
                block[j]-=process[i];
                break;
            }
        }
    }
    return 0;
}
