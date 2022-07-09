#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void printREG(int hexnum){
    switch (hexnum)
        {
        case 0:
            printf("%%rax");
            break;
        case 1:
            printf("%%rcx");
            break;
        case 2:
            printf("%%rdx");
            break;
        case 3:
            printf("%%rbx");
            break;
        case 4:
            printf("%%rsp");
            break;
        case 5:
            printf("%%rbp");
            break;
        case 6:
            printf("%%rsi");
            break;
        case 7:
            printf("%%rdi");
            break;
        }
}
void disassemble(const unsigned char *raw_instr){
    printf("pushq ");
    if(raw_instr[0] == 104){
        printf("$0x");
        for(int i = 4; i > 0; i--){
            if(raw_instr[i] != 0){
                printf("%x", raw_instr[i]);
            }
        }
    }
    else if (!(((raw_instr[0] >> 3) << 3) ^ 0x50)) {
        int temp = (raw_instr[0] & 0x7);
        printREG(temp);
    }
    else{
        if (raw_instr[1] == 0x74){
            if (raw_instr[3] != 0){
                printf("%#x", raw_instr[3]);
            }
            printf("(");
            printREG((raw_instr[2] & 7));
            printf(",");
            printREG(((raw_instr[2] >> 3) & 7));
            int index = (raw_instr[2] >> 6);
            if (index == 0){printf(",1");}
            else if (index == 1){printf(",2");}
            else if (index == 2){printf(",4");}
            else if (index == 3){printf(",8");}
            printf(")");
        }
        else{
            int temp = ((raw_instr[1] >> 3) << 3);
            if (temp == 0x30) {
                printf("(");
                printREG((raw_instr[1] & 7));
                printf(")");
            }
            else if (temp == 0x70) {
                if (raw_instr[2] != 0){
                printf("%#x", raw_instr[2]);
                printf("(");
                printREG((raw_instr[1] & 7));
                printf(")");
            }
            }
        }     
    }
    printf("\n");
}

int main()
{
    // pushq $0x3f10
    unsigned char inst1[5] = {0x68,0x10,0x3f,0x00,0x00};
    // pushq %rbx
    unsigned char inst2[1] = {0x53};
    // pushq (%rdx)
    unsigned char inst3[2] = {0xff, 0x32};
    // pushq 0x8(%rax)
    unsigned char inst4[3] = {0xff, 0x70, 0x08};
    // pushq 0xff(%rbp,%rcx,4)
    unsigned char inst5[4] = {0xff, 0x74, 0x8d, 0xff};
    disassemble(inst1);
    disassemble(inst2);
    disassemble(inst3);
    disassemble(inst4);
    disassemble(inst5);
    return 0;
}
