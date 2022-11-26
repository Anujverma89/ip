#include <stdio.h>
#include <string.h>

int binary_to_decimal(char binaryip[]);

int main(){
    char ip[35];
    int subnetA[4]={255,0,0,0};
    int subnetB[4]={255,255,0,0};
    int subnetC[4]={255,255,255,0};
    char bin1[9];
    int netid[4];
    int decimalip[4];
    int count=0;
    printf("Enter the Ip address in binary format:\n");
    scanf("%s",ip);


    for(int i=0;i<8;i++){
        bin1[i]=ip[i];
    }

    //creating seperate strings
    char newstring[9];
    for(int i=0;i<35;i++){
        if(ip[i]=='.'){
            int decimal=binary_to_decimal(newstring);
            decimalip[count]=decimal;
            newstring[0]='\0';
            count+=1;
            continue;
        }
        char fragstr[2];
        sprintf(fragstr,"%c",ip[i]);
        strcat(newstring,fragstr);
    }


    if(bin1[0]=='0'){
        printf("This is class A Ip address:\n");
        for(int i=0;i<4;i++){
            int currnetid=subnetA[i]&decimalip[i];
            netid[i]=currnetid;
        }
        printf("Net id is %d %d %d %d\n",netid[0],netid[1],netid[2],netid[3]);
    }else if(bin1[0]=='1'&& bin1[1]=='0'){
        printf("This is class B Ip address:\n");
        //netid
        for(int i=0;i<4;i++){
            int currnetid=subnetB[i]&decimalip[i];
            netid[i]=currnetid;
        }
        printf("Net id is %d %d %d %d\n",netid[0],netid[1],netid[2],netid[3]);
    }else if(bin1[0]=='1'&& bin1[1]=='1' && bin1[2]=='0'){
        printf("This is class C Ip address:\n");
        for(int i=0;i<4;i++){
            int currnetid=subnetC[i]&decimalip[i];
            netid[i]=currnetid;
        }
        printf("Net id is %d %d %d %d\n",netid[0],netid[1],netid[2],netid[3]);
    }else if(bin1[0]=='1'&& bin1[1]=='1' && bin1[2]=='1' && bin1[3]=='0'){
        printf("This is class D Ip address:\n");
        printf("Class D has no netId");
    }else if(bin1[0]=='1'&& bin1[1]=='1' && bin1[2]=='1' && bin1[3]=='1'){
        printf("This is class E Ip address:\n");
        printf("Class E has No NetId:\n");
    }



}

//converting binary into decimal
int binary_to_decimal(char binaryip[]){
    int sum=0;
    int pow=7;
    for(int i=0;i<=7;i++){
        
        int powerproduct=1;
        int decimalvalue;
        int asciivalue=(int)binaryip[i];
        if(asciivalue==48){
            decimalvalue=0;
        }else if(asciivalue==49){
            decimalvalue=1;
        }

        if(pow==0){
            powerproduct=1;
        }else{
            for(int j=1; j<=pow; j++){
            powerproduct*=2;
            }
        }
        int calc=powerproduct*decimalvalue;
        sum+=calc;
        pow-=1;
      
    }
    return sum;
}