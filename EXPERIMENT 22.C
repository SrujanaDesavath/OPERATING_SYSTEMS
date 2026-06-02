#include <stdio.h>

int main(){
    int block[3]={100,500,200};
    int process[3]={212,417,112};

    for(int i=0;i<3;i++){
        int best=10000,index=-1;
        for(int j=0;j<3;j++){
            if(block[j]>=process[i] && block[j]<best){
                best=block[j];
                index=j;
            }
        }
        if(index!=-1){
            printf("Process %d allocated to block %d\n",i+1,index+1);
            block[index]-=process[i];
        }
    }
    return 0;
}
