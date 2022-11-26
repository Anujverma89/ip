#include<stdio.h>
#include<string.h>

int string_to_int(char string[]);
int main(){
    char ip[15];
    printf("Enter the ip address decimal:\n");
    scanf("%s",ip);
    int iparray[4];

    int len=strlen(ip);

    char fragmentedstring[3];
    int counter=0;
    for(int i=0;i<len;i++){
        if(ip[i]=='.'){
            int decimal=string_to_int(fragmentedstring);
            iparray[counter]=decimal;
            fragmentedstring[0]='\0';
            counter+=1;
            continue;
        }
        char formatedstring[10];
        int ascii=(int)ip[i];
        int num=(ascii-48);
        sprintf(formatedstring,"%d",num);
        strcat(fragmentedstring,formatedstring);
    }
    
    int lastdecimal=string_to_int(fragmentedstring);
    iparray[counter]=lastdecimal;
  

    if(iparray[1] > 255||iparray[2] > 255||iparray[3] > 255){
        printf("this is invalid ip address");
    }else{
        // printf("THis is class A ip address");
        if(iparray[0] >= 0 && iparray[0] <=127){
            printf("THis is class A ip address");
        }else if(iparray[0] >=128 && iparray[0] <=191){
            printf("THis is class B ip address");
        }else if(iparray[0] >=192 && iparray[0] <=223){
            printf("THis is class C ip address");
        }else if(iparray[0] >=224 && iparray[0] <=239){
            printf("THis is class D ip address");
        }else if(iparray[0] >=240 && iparray[0] <=255){
            printf("THis is class E ip address");
        }else{
            printf("this is invalid ip address");
        }

    }



    return 0;
}


int string_to_int(char string[]){
    int len=strlen(string);
    int decival=0;
    int power = len-1;
    for(int i=0;i<len;i++){
        int value=(int)string[i]-48;
        int placevalue=1;
        if(power==0){
            placevalue=1;
        }else{
            for(int j=power;j>0;j--){
                placevalue*=10;
            }
        }
        int multiple=placevalue*value;
        decival+=multiple;
        power-=1;
    }

    return decival;
}