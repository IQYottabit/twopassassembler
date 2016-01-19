# twopassassembler

-------------------- 
Two pass assembler:
--------------------

This is free open source code.

* It accepts an assembly language program as input and produces its machine language equivalent along with the information for the loader. 
* The assembling of source program to object code requires to accomplish following functions.

-----------
Opertion :
-----------

* Simply convert the mnemonic opcodes to machine language equivalent.(e.g, LDA to 00)
* Convert symbolic operands to their equivalent machine address   (eg, LOOP to 2045)
	Allocate necessary memory.
	Convert data constants to internal machine equivalents.
	Write the object program and assembly listing.

Two pass assembler do these functions in two passes ,i.e., two times the input programs will be scanned/processed.


Pass 1 feeds into pass 2 :

-------
PASS 1
-------
After compiling the first program it generate the two files,symtab.txt and inter.txt
	* Assign addresses to all statements in the program.
	* Addresses of symbolic labels are stored.
	* Some assemble directives will be processed.

------------
Input file :
------------
Simple ARM assembly code where it add the numbers from 1 to 10.

COPY START	1000
MOV  R0 0         
MOV  R1 10        
ADD  R0 R0 R1
SUBS R1 R1 1
BNE  1
B    halt           
$	 END	START


Example : C equivalent.

  int total;
    int i;

    total = 0;
    for (i = 10; i > 0; i--) {
        total += i;
    }

Output file generated:

inter.txt

1000	COPY	START	1000
1000	MOV	R0	0
1003	MOV	R1	10
1006	ADD	R0	R0
1009	R1	SUBS	R1
100c	R1	1	BNE
100f	1	B	halt
1012	$	END	START


symtab.txt

MOV	1000
ADD	1006
R1	1009
1	100f

-------
PASS 2
-------

	* Translate opcode and symbolic operands.
	* Generate data values defined by BYTE,WORD etc.
	* Assemble directives will be processed.
	* Write the object program and assembly listing.

Final instructions generated on this below file.

Output.txt
H^COPY^001000^12
T^001000^12^Ð
E^001000
