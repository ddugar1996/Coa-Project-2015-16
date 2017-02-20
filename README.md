# Coa-Project-2015-16
********C based Assembler*************

*****Instructions for Execution*******

***code1*****
code1.c converts given assembly code into machine code 

For running code1 , following files must be present in the same directory: opcodes.txt, register.txt and the file containing the assembly code (here binary.txt, count.txt or any example code from example code folder)

code1.c generates 2 files 
1:labels.txt :contains lables and their ILC
2:machine.txt: this is the file containing the binary machine code

*****code2******
code2.c reads, interprets and executes given machine code

For running code2, machine.txt generated from code1.c must be present in the same directory along with opcodes.txt,register.txt

code2.c generates 1 file
1:status.txt: contains register status,ALU control signals, I/O status, Data Movement operations and Status of various flag registers (example status.txt generated from converting 5 to binary is included in the rar)

**************************************************************************************************************************
