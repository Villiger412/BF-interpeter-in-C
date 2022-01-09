#include <stdio.h>
#include <stdlib.h>
#define SIZE 32768
char array[SIZE]={0};
int ptr=0; //between 0 and SIZE

int takeInput(char* input){
    int inputSize=0;
    char c;
    scanf("%c",&c);
    while(c!='\n'){
        input=realloc(input, (inputSize+1)*sizeof(char));
        if(input==NULL){ 
            printf("not enough memory :/\n");
            exit(2);
        }
        input[inputSize]=c;
        inputSize++;
        scanf("%c",&c);
    }
    input[inputSize]='\0';
    return inputSize;
}

int readLine(char* input,int inputPtr){
    switch(input[inputPtr]){
        case '+':
            array[ptr]++;
            inputPtr++;
            readLine(input,inputPtr);
            break;
        case '-':
            array[ptr]--;
            inputPtr++;
            readLine(input,inputPtr);
            break;
        case '>':
            ptr++;
            ptr=ptr%SIZE;
            inputPtr++;
            readLine(input,inputPtr);
            break;
        case '<':
            ptr--;
            ptr=ptr%SIZE;
            inputPtr++;
            readLine(input,inputPtr);
            break;
        case '.':
            printf("%d",array[ptr]);
            inputPtr++;
            readLine(input,inputPtr);
            break;
        case ',': {
            int scanInt;
            scanf("%d",&scanInt);
            array[ptr]=scanInt;
            inputPtr++;
            readLine(input, inputPtr);
            break;
        }

        case '[': {
            if(array[ptr]==NULL){//go to the matching ']'
                int bracketSymetry=-1;
                while(bracketSymetry!=0){
                    inputPtr++;

                    if(input[inputPtr]=='['){
                        bracketSymetry--;
                    }
                    if(input[inputPtr]==']'){
                        bracketSymetry++;
                    }
                }
                inputPtr++;
                readLine(input,inputPtr);
            }
            else{
                inputPtr++;
                readLine(input,inputPtr);
            }
            break;
        }

        case ']': {
            //going back to the matching '['
            int bracketSymetry=1;
            while(bracketSymetry!=0){
                inputPtr--;

                if(input[inputPtr]=='['){
                    bracketSymetry--;
                }
                if(input[inputPtr]==']'){
                    bracketSymetry++;
                }
            }
            readLine(input,inputPtr);
            break;
        }
        case '\0':
            exit(0);
        default:
            printf("Error!\n");
            exit(1);
    }
}


void main(){
    char* input=malloc(sizeof(char));
    takeInput(input);
    readLine(input,0);
}
