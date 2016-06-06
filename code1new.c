#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define number 36

struct labels
{
    char label[50];
    int lineno ;
}; // Structure for storing all the LABELS with their respective binary values.

void menu()//Displays menu and takes action according to user input.
{
    int choice ;
    FILE *opcode , *assembly , *binary ;
    printf("Enter 1 to print opcode, register and ports table\n");
    printf("Enter 2 to print the assembly code\n");
    printf("Enter 3 to print the binary file of an assembly file\n");
    scanf("%d",&choice); // Taking user input.
    switch(choice)
    {
    case 1 :
        printopcode();//Prints the opcode.
        break;
    case 2 :
        printassembly();//Prints the assembly language code.
        break;
    case 3:
        printbinary();//Prints the binary converted assembly code.
        break;
    }
}//End of menu.

void printopcode()// Prints all the opcodes.
{
    char c;
    FILE *fo ;
    fo = fopen("opcodes.txt","r");
    while(1)
    {
        c=getc(fo);//Getting character from the file.
        if(c==EOF)
        {
            return;//Return if it encounters end of file.
        }
        else
        {
            printf("%c",c);//Prints the character.
        }
    }
}//Printing opcodes ends here.

void printassembly()// Prints the assembly code specified by user.
{
    char file[50] , c;//Taking the name of the file.
    FILE *assembly;
    printf("Enter the name of the file\n");
    scanf("%s",file);//Giving the name of the assembly code to be printed.
    file[strlen(file)]='\0' ;
    assembly = fopen(file,"r");//Opening in read mode.
    while(1)
    {
        c = getc(assembly);
        if(c==EOF)
        {
            break;
        }
        else
        {
            printf("%c",c);
        }
    }
}//End of printassembly.

int checkint(char s[] )//To check if string is an integer .
{
        int i,boolean=1,converted; // Returns 1 if the string is actually an integer else 0.
        for(i=0;i<strlen(s);i++)
        {
            if((s[i]!=48)&&(s[i]!=49)&&(s[i]!=50)&&(s[i]!=51)&&(s[i]!=52)&&(s[i]!=53)&&(s[i]!=54)&&(s[i]!=55)&&(s[i]!=56)&&(s[i]!=57))
            {
                boolean = 0;
                break;
            }
        }
        return boolean ; //Value returned .
}//End of checkint .

void labelbinary(int k,char *a)//Converts the line number of label into binary number of 5 bits.
{
   int i ;
   for(i=0;i<5;i++)
   {
       a[i]=k%2 + '0';
       k=k/2;
   }
   a[i]='\0';
   strrev(a);
}//End of labelbinary.

void tobinary(int k,char *a)//Converts an integer to binary string of 8 characters.
{
   int i ;
   for(i=0;i<8;i++)
   {
       a[i]=k%2 + '0';
       k=k/2;
   }
   a[i]='\0';
   strrev(a);
}//End of tobinary.

void printbinary() // Converts assembly to binary code.
{
    //Hardcoded opcodes, registers and their corresponding binary values.
    char opc[50][50] = {"ADD","MUL" ,"SUB" ,"MOV" ,"CMP" ,"CMPI" ,"OUT","IN" ,"INC" ,"JUMP" ,"JE","JGT","HLT" ,"R00" ,"R01" ,"R02" ,"R03" ,"R04" ,"R05" ,"R06" ,"R07" ,"R08" ,"R09" ,"R10" ,"R11","R12" ,"R13" ,"R14" ,"R15" ,"FLAG" ,"SP"	,"PC" 	,"PORT0" ,"PORT1" ,"PORT2" ,"PORT3"};
    char bin[50][50] = {"00000000000000000","00000000000000001","00000000000000010","0000000000000001100","0000000000000001101","0000000000000001110000","0000000000000001110001000","0000000000000001110001001","000000000000000111000101000","000000000000000111000101001","000000000000000111000101010","000000000000000111000101011","00000000000000011100010110000000","00000","00001","00010","00011","00100","00101","00110","00111","01000","01001","01010","01011","01100","01101","01110","01111","10000","10001","10010","00","01","10","11"};
    char b[50],tester[500][50],retester[500][50],c,binary1[50],binary2[50];
    int i = 0, j= 0, counter=0 , labelcounter=0,checker,converted;
    struct labels l[50] ;
    FILE *binary , *assembly;
    printf("Enter the name of assembly code file\n");
    scanf("%s",b);//Specifying the assembly code file.
    assembly = fopen(b,"r");
    binary = fopen("binary.txt","w");
    while(1)//Finding the lineno of labels.
    {
        c=getc(assembly);
        if(c==EOF){break;}
        else
        {
            if(c==10)
            {
                j=0;
                i++;
                counter++;
            }
            else
            {
                tester[i][j] = c;
                j++;
            }
        }
    }
    //Counter + 1 = Total number of lines.
    for(i=0;i<=counter;i++)
    {
        if(tester[i][strlen(tester[i])-1]==':')
        {
            j=0;
            while(tester[i][j]!=':')
            {
                l[labelcounter].label[j] = tester[i][j];
                j++;
            }
            l[labelcounter].label[j]='\0';
            l[labelcounter].lineno=i;//Storing the line number where label occurs.
            labelcounter++;// Incrementing the number of labels.
        }
    }
   //Line numbers of all the labels stored in the structure.

    fclose(assembly);//Closing the assembly file.
    i=0;j=0;counter=0;
    assembly = fopen(b,"r");//Reopening the assembly file to convert to binary form.
    while(1)
    {

        c=getc(assembly);
        if(c==EOF){break ; }
        if(c==10)
        {
            i++;
            strcpy(retester[i],"end");
            retester[i][strlen(retester[i])]='\0';
            i++; j =0;
            counter = counter+2;
        }
        else {
                if(c==32)
                {
                    retester[i][strlen(retester[i])]='\0';
                    i++;
                    j=0;
                    counter++;
                }
                else
                {
                    retester[i][j] = c;
                    j++ ;
                }
            }
   }

    //Writing in the binary file .
      for(i=0;i<=counter;i++)
    {
        if(strcmp("end",retester[i])==0)
        {
            fprintf(binary,"\n");//Write in the new line in file .
        }
       else
        {
            if(retester[i][strlen(retester[i])-1]==':')
            {
                fputs("00000000000000011100010110000001",binary);
                continue ; // The label coming without jump statement .
            }
            else
            {
                // If it is an integer . Convert from string to integer then to binary.
                    checker = checkint( retester[i]);
                    if(checker==1)
                    {
                           converted = atoi(retester[i]);
                           tobinary(converted,binary1);
                           fputs(binary1,binary);
                    }
                    else
                    {
                         for(j=0;j<number;j++)//Checking if its opcode,register,port or not. If yes then writing the corresponding binary value to the binary file.
                            {
                                if(strcmp(retester[i],opc[j])==0)
                                {
                                    fputs(bin[j],binary);
                                }
                            }
                        for(j=0;j<labelcounter;j++)//Checking if its a label. If yes then replacing it with binary value of the line number.
                        {
                            if(strcmp(l[j].label,retester[i])==0)
                            {
                                labelbinary(l[j].lineno,binary2);
                                fputs(binary2,binary);
                            }
                        }
                    }
              }
         }
    }
    fclose(binary);//Closing the binary file.
    binary = fopen("binary.txt","r");//Reopening binary file in order to print it.
    while(1)
    {
        c = getc(binary);
        if(c==EOF){break;}else{
        printf("%c",c);}//Printing the binary file.
    }
    fclose(binary);//Closing file.
}
int main()
{
    menu();//Calling the menu function.
    return 0;
}
