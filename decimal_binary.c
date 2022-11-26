// Online C compiler to run C program online
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int string_to_int(char string[]);
void decimal_to_binary(int decimal,int binarr[4][8],int count);





int main(){
    char ip[15];
    printf("Enter the ip address decimal:\n");
    scanf("%s",ip);
    //Array of decimal ip
    int iparray[4];
    //array to store netid
    int netid[4];
    //counter to store binary values in 2d array
    int iparraycount=0;
    //finding the string length
    int len=strlen(ip);
    //variable to store fragmentd string
    char fragmentedstring[3];
    //counter to store values in iparray
    int counter=0;

    //2D array to store binary values of IP address  and intiializing with all zeros to avoid garbage values
    int binarr[4][8]={{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
    //binary decleration of subnet mask and ip address;
    int subnetA[4]={0b11111111,0b00000000,0b00000000,0b00000000};
    int subnetB[4]={0b11111111,0b11111111,0b00000000,0b00000000};
    int subnetC[4]={0b11111111,0b11111111,0b11111111,0b00000000};
    
    //2D array to store binary values of Net Id address  and intiializing with all zeros to avoid garbage values
    int binaryNetId[4][8]={{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
    int bincounter=0;
    

//fragmenting string with '.' as identifier
    for(int i=0;i<len;i++){
        if(ip[i]=='.'){
            /*here we are converting fragemnted string into decimal
             and storing in iparray and increasing counter
            */
            int decimal=string_to_int(fragmentedstring);
            iparray[counter]=decimal;
            fragmentedstring[0]='\0';
            counter+=1;
            continue;
        }
        char formatedstring[2];
        int ascii=(int)ip[i];
        int num=(ascii-48);
        sprintf(formatedstring,"%d",num);
        strcat(fragmentedstring,formatedstring);
    }
    
    //converting the last part of ip after third dot
    int lastdecimal=string_to_int(fragmentedstring);
    iparray[counter]=lastdecimal;



    //checking the ip 
    if(iparray[1] > 255||iparray[2] > 255||iparray[3] > 255){
        printf("This is invalid ip address");
    }else{
        if(iparray[0] >= 0 && iparray[0] <=127){


            //printing the ip address
            printf("THis is class A ip address\n");
            printf("Binary Ip:");
            //printing the binary ip;
            for(int i=0;i<4;i++){
                decimal_to_binary(iparray[i],binarr,iparraycount);
                iparraycount+=1;
                for(int j=0;j<8;j++){
                    printf("%d",binarr[i][j]);
                }
                printf(" ");
            }
            printf("\n");
            //finding out the network id  ;
            for(int i=0;i<4;i++){
                int curnetid=subnetA[i]&iparray[i];
                netid[i]=curnetid;
            }
            printf("Net id:- %d %d %d %d\n",netid[0],netid[1],netid[2],netid[3]);
        
            //binary netid:
            //converting netid into binary format;
            for (int i = 0; i < 4; i++){
                decimal_to_binary(netid[i],binaryNetId,bincounter);
                bincounter++;
            }
            printf("Binary Net Id:");
            for(int i=0;i<4;i++){
                for(int j=0;j<8;j++){
                    printf("%d",binaryNetId[i][j]);
                }
                printf(" ");
            }

            
        }else if(iparray[0] >=128 && iparray[0] <=191){


            printf("THis is class B ip address\n");
            // printing the binary ip;
            printf("Binary Ip:");
            for(int i=0;i<4;i++){
                decimal_to_binary(iparray[i],binarr,iparraycount);
                iparraycount+=1;
                
                for(int j=0;j<8;j++){
                    printf("%d",binarr[i][j]);
                }
                printf(" ");
            }
            printf("\n");
            //finding out the network id  ;
            for(int i=0;i<4;i++){
                int curnetid=subnetB[i]&iparray[i];
                netid[i]=curnetid;
            }
            printf("Net id:- %d %d %d %d\n",netid[0],netid[1],netid[2],netid[3]);
            //binary netid:
            //converting nedid into binary format;
            for (int i = 0; i < 4; i++){
                decimal_to_binary(netid[i],binaryNetId,bincounter);
                bincounter++;
            }
            printf("Binary Net Id:");
            for(int i=0;i<4;i++){
                for(int j=0;j<8;j++){
                    printf("%d",binaryNetId[i][j]);
                }
                printf(" ");
            }


        }else if(iparray[0] >=192 && iparray[0] <=223){


            printf("THis is class C ip address\n");
            // printing the binary ip;
            printf("Binary Ip:");
            for(int i=0;i<4;i++){
                decimal_to_binary(iparray[i],binarr,iparraycount);
                iparraycount+=1;
                
                for(int j=0;j<8;j++){
                    printf("%d",binarr[i][j]);
                }
                printf(" ");
            }
            printf("\n");
            //finding out the network id  ;
            for(int i=0;i<4;i++){
                int curnetid=subnetC[i]&iparray[i];
                netid[i]=curnetid;
            }
            printf("Net id:- %d %d %d %d\n",netid[0],netid[1],netid[2],netid[3]);

            //binary netid:
            //converting nedid into binary format;
            for (int i = 0; i < 4; i++){
                decimal_to_binary(netid[i],binaryNetId,bincounter);
                bincounter++;
            }
            printf("Binary Net Id:");
            for(int i=0;i<4;i++){
                for(int j=0;j<8;j++){
                    printf("%d",binaryNetId[i][j]);
                }
                printf(" ");
            }
            
            
            
        }else if(iparray[0] >=224 && iparray[0] <=239){
            printf("THis is class D ip address\n");
            printf("There is no host Id  and net Id in d class");


        }else if(iparray[0] >=240 && iparray[0] <=255){
            printf("THis is class E ip address");
            printf("There is no host Id  and net Id in d class");


        }else{
            printf("This is invalid ip address");

        }

    }

    return 0;
}

//converting the string into decimal function 
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


//converting decimal into binary accepts argument as decimal;
void decimal_to_binary(int decimal,int binarr[4][8],int count){
    int decimalvalue=decimal;
    int incount=7;
    while(decimalvalue >0)
    {
        int bin=decimalvalue%2;
        decimalvalue=decimalvalue/2;
        binarr[count][incount]=bin;
        --incount;
    }


}


//to assign decimal to variable we assign directly 
//to assing octal to variable we use 0(zero)and value eg:- 0144;
//to assign hexadecimal value to var we use 0xvalue eg:- 0x64;
//to assing binary value to var we use 0bvalue eg:- 0b101010;