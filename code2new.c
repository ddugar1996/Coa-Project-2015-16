#include<stdio.h>
#include<stdlib.h>
struct registers
{
   unsigned int value;
};
struct registers reg[20]; //Array of registers . //19th for the sign bit. Set 1 when negative.
void status_reg()
{
    printf("\n****Displaying the status of registers****\n\n");
    printf("R00=%d\n",reg[0].value);
    printf("R01=%d\n",reg[1].value);
    printf("R02=%d\n",reg[2].value);
    printf("R03=%d\n",reg[3].value);
    printf("R04=%d\n",reg[4].value);
    printf("R05=%d\n",reg[5].value);
    printf("R06=%d\n",reg[6].value);
    printf("R07=%d\n",reg[7].value);
    printf("R08=%d\n",reg[8].value);
    printf("R09=%d\n",reg[9].value);
    printf("R10=%d\n",reg[10].value);
    printf("R11=%d\n",reg[11].value);
    printf("R12=%d\n",reg[12].value);
    printf("R13=%d\n",reg[13].value);
    printf("R14=%d\n",reg[14].value);
    printf("R15=%d\n",reg[15].value);
    printf("SIGNBIT=%d\n",reg[19].value);
    printf("\n \n");

}
bitmask_17(unsigned int instruction)
{
    unsigned int masked;
    int i ;
    char *a;
        a="11111111111111111000000000000000";
    masked = to_int(a) & instruction;
    for(i=0;i<15;i++)
        {
            masked=masked>>1;
        }
        return masked;
    //printf("%u\n",masked);
}

bitmask_19(unsigned int instruction)
{
        unsigned int masked;
        int i;
        char *a;
        a="11111111111111111110000000000000";
        masked = to_int(a) & instruction;
        for(i=0;i<13;i++)
            {
                masked=masked>>1;
            }
        return masked;
}

bitmask_22(unsigned int instruction)
{
        unsigned int masked;
        int i;
        char *a;
        a="11111111111111111111110000000000";
        masked = to_int(a) & instruction;
        for(i=0;i<10;i++)
            {
                masked=masked>>1;
            }
        return masked;
}

bitmask_25(unsigned int instruction)
{
        unsigned int masked;
        int i;
        char *a;
        a="11111111111111111111111110000000";
        masked = to_int(a) & instruction;
        for(i=0;i<7;i++)
            {
                masked=masked>>1;
            }
        return masked;
}

bitmask_27(unsigned int instruction)
{
        unsigned int masked;
        int i;
        char *a;
        a="11111111111111111111111111100000";
        masked = to_int(a) & instruction;
        for(i=0;i<5;i++)
            {
                masked=masked>>1;
            }
        return masked;
}

bitmask_32(unsigned int instruction)
{
        unsigned int masked;
        int i;
        char *a;
        a="11111111111111111111111111111111";
        masked = to_int(a) & instruction;
        return masked;
}

to_int(char *b)//Converts the 32 bit long instruction to integer format.
{
    int i,j=0;
    unsigned int converted=0;
   for(i=strlen(b)-1;i>=0;i--)
    {
        converted=((b[i]-'0')*(1<<j))+ converted;
        j++;
    }

    return converted;//printf("%u\n",converted);
}

void ADD(unsigned int instruction)
{
    int i;
    int operand1 , operand2, destination ;
    char *op1 , *op2 , *dest ;
    op1 = "00000000000000000000001111100000";
    op2 = "00000000000000000000000000011111";
    dest= "00000000000000000111110000000000";
    operand1 = instruction & to_int(op1);
    for(i=0;i<5;i++)
    {
        operand1 = operand1>>1;
    }
    operand2 = instruction & to_int(op2);
    destination = instruction & to_int(dest);
    for(i=0;i<10;i++)
    {
        destination = destination>>1;
    }

    reg[destination].value = reg[operand1].value + reg[operand2].value ;
    if(reg[destination].value >=0 )
    {
        reg[19].value =0;
    }
    else
    {
        reg[19].value =1; //Setting sign bit one.
    }
    printf("\n The value in register %d is added to value in register %d\n",operand1,operand2);
    printf("\n The output is stored in register number %d \n",destination);
   // printf("%d\n %d\n %d\n",destination,operand1,operand2);
}

void MUL(unsigned int instruction)
{
    int i;
    int operand1 , operand2, destination ;
    char *op1 , *op2 , *dest ;
    op1 = "00000000000000000000001111100000";
    op2 = "00000000000000000000000000011111";
    dest= "00000000000000000111110000000000";
    operand1 = instruction & to_int(op1);
    for(i=0;i<5;i++)
    {
        operand1 = operand1>>1;
    }
    operand2 = instruction & to_int(op2);
    destination = instruction & to_int(dest);
    for(i=0;i<10;i++)
    {
        destination = destination>>1;
    }
    reg[destination].value = reg[operand1].value * reg[operand2].value ;
    if(reg[destination].value >=0 )
    {
        reg[19].value =0;
    }
    else
    {
        reg[19].value =1; // Setting sign bit one.
    }
     printf("\n The value in register %d is multiplied with value in register %d\n",operand1,operand2);
     printf("\n The output is stored in register number %d \n",destination);
    //printf("%d\n %d\n %d\n",destination,operand1,operand2);
}

void SUB(unsigned int instruction)
{
    int i;
    int operand1 , operand2, destination ;
    char *op1 , *op2 , *dest ;
    op1 = "00000000000000000000001111100000";
    op2 = "00000000000000000000000000011111";
    dest= "00000000000000000111110000000000";
    operand1 = instruction & to_int(op1);
    for(i=0;i<5;i++)
    {
        operand1 = operand1>>1;
    }
    operand2 = instruction & to_int(op2);
    destination = instruction & to_int(dest);
    for(i=0;i<10;i++)
    {
        destination = destination>>1;
    }

    reg[destination].value = reg[operand1].value - reg[operand2].value ;
    if(reg[operand1].value >= reg[operand2].value)
    {
        reg[19].value =0; // Setting sign bit zero, positive numbers.
    }
    else
    {
        reg[19].value =1; // Setting sign bit one, negative numbers.
    }
     printf("\n The value in register %d is subtracted from value in register %d\n",operand2,operand1);
     printf("\n The output is stored in register number %d \n",destination);
}

void MOV(unsigned int instruction)
{
     int data,i;
     int destination;
     char *val = "00000000000000000000000011111111";
     char *dest ="00000000000000000001111100000000";
     data = to_int(val) & instruction ;
     destination  = to_int(dest) & instruction ;
     for(i=0;i<8;i++)
     {
         destination = destination>>1;
     }//Right shifting by 8 bits.
     reg[destination].value = data ;
     printf("\n %d Stored in register number %d \n",data,destination);
}

void CMP(unsigned int instruction)
{
    int data , i,source ;
    char *val = "00000000000000000000000011111111" ;
    char *sour= "00000000000000000001111100000000" ;
    data = to_int(val) & instruction ;
    source = to_int(sour) & instruction ;
    for(i=0;i<8;i++)
    {
        source = source>>1;
    }
    if(reg[source].value > data)
    {
        reg[16].value = 1 ; //Setting flag one.
    }
    else
    {
        if(reg[source].value < data)
        {
            reg[16].value = -1 ; // Setting flag minus one.
        }
        else
        {
            reg[16].value = 0; // Setting flag zero if values are equal.
        }
    }
   // printf("%d",reg[16].value);
}

void CMPI(unsigned int instruction)
{
        int reg1 , i,reg2 ;
        char *r1 = "00000000000000000000000000011111";
        char *r2 = "00000000000000000000001111100000";
        reg1 = to_int(r1) & instruction ;
        reg2 = to_int(r2) & instruction ;
        for(i=0;i<5;i++)
        {
            reg2 = reg2 >> 1 ;
        }
        if(reg[reg2].value > reg[reg1].value)
        {
            reg[16].value = 1 ; //Setting flag one if first value is greater than second value.
        }
        else
        {
            if(reg[reg1].value > reg[reg2].value)
            {
                reg[16].value = -1 ; // Setting flag minus one if first value is smaller than first value.
            }
            else
            {
                reg[16].value = 0; // Setting flag zero if both values values are equal.
            }
        }
}

void OUT(unsigned int instruction)
{
        char * output = "00000000000000000000000001111100" ;
        unsigned int out ;
        out = to_int(output) & instruction ;
        out>>=1;out>>=1;
        printf("%u\n",reg[out].value);

}

void IN(unsigned int instruction)
{
        char input[]  = "00000000000000000000000001111100" ;
        unsigned int in ;
        in = (to_int(input) & instruction) ;
        in>>=1;in>>=1;
        scanf("%u",&reg[in].value);
}

void INC(unsigned int instruction)
{
        int index;
        char *format = "00000000000000000000000000011111" ;
        index = to_int(format) & instruction ;
        reg[index].value = reg[index].value + 1;
        if(reg[index].value >= 0)
        {
            reg[19].value =0;// Setting sign bit 0, if the result turns out to be positive or zero.
        }
        else
        {
            reg[19].value =1; // Setting sign bit one, if the result turns out to be negative.
        }
}

int JUMP(unsigned int instruction)
{
        int lineno ;
        char *line = "00000000000000000000000000011111";
        lineno = to_int(line) & instruction;
        return lineno;
}

int JGT(unsigned int instruction)
{
        int lineno ;
        char *line = "00000000000000000000000000011111" ;
        lineno = to_int(line) & instruction ;
        return lineno;
}

int JE(unsigned int instruction)
{
        int lineno ;
        char *line = "00000000000000000000000000011111" ;
        lineno = to_int(line) & instruction ;
        return lineno;
}
print_status()
{
    //reg[16] is flag. reg[19] is for signs.
    if(reg[19].value==0)
    {
        printf("The sign bit is set to 0.\n");
    }

    if(reg[19].value==1)
    {
        printf("The sign bit is set to 1.\n");
    }
}
int main()
{
    char c;
    FILE *bin;
    int intconverted ;
    char binary[50][50];
    int i;
    int row , column ;
    bin  = fopen("binary.txt","r");
    row =0;column=0;
    while(fscanf(bin,"%s",binary[row])!=EOF){row++;}

    // Printing all the binary values stored in the array binary.
    //for(i=0;i<row;i++){printf("%s\n",binary[i]);}
    unsigned int instruction;
    unsigned int bit17 , bit19 , bit22 , bit25 , bit27 , bit32 ;
    printf("Number of lines of code = %d\n",row);
    printf("****The values of all the registers is initially set to 0****\n");
    printf("");
    i=0;
    while(i<row)
    {

        instruction = to_int(binary[i]); // Integer value of the instruction.
        bit17 = bitmask_17(instruction);// Converting first 17 bits to integer.
        bit19 = bitmask_19(instruction);// Converting first 19 bits to integer.
        bit22 = bitmask_22(instruction);// Converting first 22 bits to integer.
        bit25 = bitmask_25(instruction);// Converting first 25 bits to integer.
        bit27 = bitmask_27(instruction);// Converting first 27 bits to integer.
        bit32 = bitmask_32(instruction);// Converting first 32 bits to integer.
        if(bit17 ==0 || bit17 ==1 || bit17 ==2) // Checking for ADD, SUB, MUL .
        {
            if(bit17==0) // ADD = "00000000000000000"
            {

                ADD(instruction);// Executing add opcode and passing the instruction as integer.
                status_reg();

            }
            if(bit17==1) // MUL = "00000000000000001"
            {

                MUL(instruction);// Executing mul opcode and passing the instruction as integer.
                status_reg();
                print_status();

            }
            if(bit17==2) // SUB = "00000000000000010"
            {

                SUB(instruction);// Executing sub opcode and passing the instruction as integer.
                status_reg();
                print_status();
            }
        }

        if(bit19 == 12||bit19 == 13)// Checking for MOV, CMP
        {
            if(bit19==12)// MOV opcode execution and passing instruction as integer.
            {
                printf("Moving\n");
                MOV(instruction);
                status_reg();
                print_status();
            }
            if(bit19==13)// CMP opcode execution and passing instruction as integer.
            {
                CMP(instruction);
                status_reg();

            }
        }
        if(bit22 == 112)// Checking for CMPI.
        {
            CMPI(instruction);// CMPI opcode execution and passing instruction as integer.
            status_reg();

        }
        if(bit25==904 || bit25==905)// Checking for OUT and IN .
        {
            if(bit25==904)//Executing OUT and passing instruction as integer.
            {
                printf("Showing output\n");
                OUT(instruction);
                status_reg();

            }
            if(bit25==905)//Executing IN and passing instruction as integer.
            {
                printf("Taking input\n");
                IN(instruction);
                status_reg();

            }
        }
        if(bit27==3624 || bit27==3625 || bit27==3626 || bit27 ==3627)// Checking for JUMP, JE, JGT, INC
        {
            if(bit27 == 3624)//Executing increment .
            {
                printf("Incrementing\n");
                INC(instruction);
                status_reg();
                print_status();
            }
            if(bit27 == 3625) // Executing JUMP statement.
            {
                i = JUMP(instruction);// Reseting the value of line number where the label to be jumped on is.
                continue;
            }
            if(bit27 == 3626)//Executing Jump Equal Statement.
            {
                if(reg[16].value == 0) // Checking flag ,zero if above compared numbers are equal.
                {
                    i = JE(instruction);// Reseting the value of line number where the label to be jumped on is.
                    continue;
                }

            }
            if(bit27 == 3627)//Executing Jump if Greater than equal to instruction.
            {
                if(reg[16].value == 1 || reg[16].value ==0)
                {
                    i = JGT(instruction); // Reseting the vlaaue of line number where the label to be jumped on is.
                    continue;
                }

            }
        }
        if(bit32 ==116096)//HLT
        {
            printf("Hault occured and program ended.\n"); //On encountering a Hault (HLT).
            return ;
        }
        i++;//Incrementing the counter of while loop.
    }
    return 0;//End of code.
}
