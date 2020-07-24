# 8085-Emulator
<p align="center">
  <img src="https://github.com/akbloodadarsh/None-of-your-concern/blob/master/8085-Emulator/8085_working.png">
</p>

#### How to use (For Linux)
1. **git clone https://github.com/akbloodadarsh/8085-Emulator**
2. **cd 8085-Emulator**
3. **sudo apt install g++**
4. **sudo apt install build-essential**
5. **g++ main.cpp**


## Arithmetic
- <a href="https://github.com/akbloodadarsh/8085-Emulator/blob/master/Arithmetic.cpp">Arithmetic.cpp</a>:This file contains all the arithmetic operations:

-  <a href="https://www.tutorialspoint.com/instruction-type-add-r-in-8085-microprocessor">ADD</a> :During the addition, we will check from which register we are performing the addition & after that, we will pass the accumulator and the register as a reference to flag_on_off_8bit_ADD and perform the addition,& set the flags depending on the results of the operations & return the resultant value.

-  <a href="https://www.tutorialspoint.com/instruction-type-adi-d8-in-8085-microprocessor#:~:text=In%208085%20Instruction%20set%2C%20ADI,immediate%20data%20to%20the%20Accumulator.&text=It%20occupies%202%2DBytes%20in,affected%20based%20on%20the%20result.">ADI</a>: During the ADI we will extract the hexadecimal number and convert it to decimal & pass the accumulator & the hexadecimal value & pass it to flag_on_off_8bit_ADD & it will return the result & set the flags & return the result and store the results in the accumulator.

-  <a href="https://www.tutorialspoint.com/instruction-type-sui-d8-in-8085-microprocessor">SUI</a>:During the SUI we will extract the hexadecimal number and convert it to decimal & pass the accumulator & the hexadecimal value & pass it to flag_on_off_8bit_SUB & it will return the result & set the flags & return the result and store the result in accumulator.

-  <a href="https://www.tutorialspoint.com/instruction-type-sub-r-in-8085-microprocessor">SUB</a>: During the subtraction, we will check from which register we are performing the subtraction & after that we will pass the accumulator and the register as a reference to flag_on_off_8bit_SUB and perform the subtraction,& set the flags depending on the results of the operations & return the resultant value.

- <a href="https://www.tutorialspoint.com/instruction-type-dcr-r-in-8085-microprocessor">DCR</a>: We will check which from which register we have to perform DCR and after that, we will decrease the value of the register with 1 by using flag_on_off_8bit_SUB & passing the register and value 1 to decrease the content of the register.

- <a href="https://www.tutorialspoint.com/instruction-type-inr-r-in-8085-microprocessor#:~:text=In%208085%20Instruction%20set%2C%20INR,M%20pointed%20by%20HL%20pair.&text=This%20instruction%20is%20used%20to,increased%20by%20amount%201%20only.">INR</a>: We will check which from which register we have to perform INR and after that, we will increase the value of the register with 1 by using flag_on_off_8bit_ADD & passing the register and value 1 to increase the content of the register.

- <a href="https://www.tutorialspoint.com/instruction-type-inx-rp-in-8085-microprocessor#:~:text=In%208085%20Instruction%20set%2C%20INX,of%20the%20following%20register%20pairs.&text=A%20register%20pair%20is%20generally,store%2016%2Dbit%20memory%20address.">INX</a>: We will check which register pair value we have to increase & because we are storing the value in 2 registers we have to combine them to create the actual number & after that we simply increment the number by 1 & again break the number and update the values of the registers by the incremented number.

- <a href="https://www.tutorialspoint.com/instruction-type-dcx-sp-in-8085-microprocessor#:~:text=In%208085%20Instruction%20set%2C%20DCX,only%201%2DByte%20in%20memory.">DCX</a>: We will check which register pair value we have to decrease & because we are storing the value in 2 registers we have to combine them to create the actual number & after that we simply decrement the number by 1 & again break the number and update the values of the registers by the incremented number.

- <a href="https://www.tutorialspoint.com/instruction-type-dad-rp-in-8085-microprocessor">DAD</a>: We have to combine the values stored in HL register pair to create the actual number & after that we have to check from which register pair we have to perform addition operation then, we have to combine the content of the registers pairs to create the actual number and perform addition and then we have to update the content of HL register pair with the resultant value.

## LOGICAL
<p align="center">
  <img src="https://github.com/akbloodadarsh/None-of-your-concern/blob/master/8085-Emulator/logical.png">
</p>

- <a href="https://github.com/akbloodadarsh/8085-Emulator/blob/master/Logical.cpp">Logical.cpp</a>: This file contains all the logical operations:
- <a href="https://www.tutorialspoint.com/instruction-to-complement-accumulator-in-8085-microprocessor">CMA</a>: One's compliment the content of accumulator.
- <a href="#">CMP</a>: Check from which register we have to compare the content of the accumulator & output the difference of the given register and accumulator.

## BRANCHING
- <a href="https://github.com/akbloodadarsh/8085-Emulator/blob/master/Branching.cpp">Branching.cpp</a>: This file contains all the branching operations:
- <a href="#">JMP</a>: It will covert the hexadecimal address to decimal and check if the address is free or not if no then return true which signifies that there is an error else return false which means no error occurred during this operation.
- <a href="#">JC</a>: Before calling this function we will check if carry is set or not, if yes then only we will call this function, rest is same as JMP.
- <a href="#">JNC</a>: Before calling this function we will check if carry is set or not, if not then only we will call this function, rest is same as JMP
- <a href="https://www.tutorialspoint.com/jump-if-zero-jz-result-in-8085-microprocessor">JZ</a>: Before calling this function we will check if Zero Flag is set or not, if yes then only we will call this function, rest is same as JMP.
- <a href="https://www.tutorialspoint.com/jump-if-zero-jz-result-in-8085-microprocessor">JZ</a>: Before calling this function we will check if Zero Flag is set or not, if not then only we will call this function, rest is same as JMP.

## LOAD AND STORE
- <a href="https://github.com/akbloodadarsh/8085-Emulator/blob/master/Load_and_Store.cpp">Load_and_Store.cpp</a>: This file contains all the load and store operations:
- <a href="#">MOV</a>: We will check from which register we have to move the content, then we will store the content in a temporary variable and then we will check in which register we have to overwrite the content and update the content with the temporary variable value.
- <a href="#">MVI</a>: We will convert the hexadecimal content to decimal content and store the content in a temporary variable and then we will check in which register we have to overwrite the content and update the content with the temporary variable value.
- <a href="#">LDA</a>: We will convert the hexadecimal address to decimal address and use adress_data to check if there is some value stored at the address, if yes then store that value in the accumulator.
- <a href="#">STA</a>: We will convert the hexadecimal address to decimal address and use adress_data to store the data of the accumulator to that address.
- <a href="#">SHLD</a>: Store the content of register L in the given address and store the content of register H in the incremented address.
- <a href="#">LHLD</a>: Store the content of given address in register L and the content of incremented address in register H.
- <a href="#">XCHG</a>: Swap the content of register pair HL & DE.
- <a href="#">LXI</a>: Store the address in the register pair after breaking the address into two & converting it to its decimal form.
- <a href="#">STAX</a>: Extract the address from the given register pair & combine it to form the actual address and use that address to store the content of the accumulator at that address.


## DEBUGGER INSTRUCTIONS
- <a href="#">SET</a>: We will convert the hexadecimal address to decimal address & convert the hexadecimal data to decimal data and use adress_data to store the data to that address. Ex:- SET 2500H, 05H
- <a href="#">break or b</a>: It will stop the execution of the pragram when it reaches the specified address. Ex:- break 2500H or b 2500H
- <a href="#">step or s</a>: It will run program one instruction at a time and ask if you want to use debugger, if yes you enter debugger mode else it will run the next instruction.Ex:- step or s
- <a href="#">print or p</a>: It prints the value of register or value present at memory location. Ex:- print A or p B or print 2500H or p 5000H 
- <a href="#">quit or q</a>: quits the debugger. Ex:- quit or q
- <a href="#">help</a>: will show commands of the debugger. Ex:- help


# EXTRA FEATURES
- If you accidentally input some invalid starting address Ex:- 01,425544646. It will tell you to input a valid starting address.
- You can give input from a file. After asking Do you want to take input from a file press 'y' & give the location of the file. If the input file is in the same folder which contains the program just input the file name with extension Ex:- file_name.txt, if the file is not found you will be asked to input a valid file location.
- If the user input a partial correct instruction he will be given a correct suggestion Ex:- I/P ADD BLABLA  O/P Did you mean ADD B? or I/P ADD O/P Did you mean ADD valid_register_name

## EXTRA FILES DESCRIPTION
- <a href="#">mnemonics.cpp</a>: It contains unordered maps for:
<ol> 
 <li>mnemonics:- It contains opcodes as key & theirID's & their size as values.</li>
 <li>instruction_size:- It contains opcode id as key & instruction size & instruction example as value.</li>
 <li>char_to_int:- It has hexadecimal digit as key & its decimal equivalent as value.</li>
 <li>int_to_char:- It has decimal number as key & its hexadecimal equivalent as value.</li>
</ol>

- <a href="#">utility.cpp</a>: It contains utility functions for:
<ol> 
 <li>hex_to_dec:- It takes (string)hexadecmal number as input & return its decimal equivalent which is integer type.</li>
 <li>dec_to_hex:- It takes  (integer)decimal number as input & return its hexadecimal equivalent which is string type.</li>
 <li>dec_to_hex16:- It takes  (integer)decimal number as input & return its 16bit hexadecimal equivalent which is string type.</li>
</ol>

### CONTRIBUTE
Read the **<a href="https://github.com/akbloodadarsh/8085-Emulator/blob/master/contributing.md">contribution guidelines</a>** if you want to contribute.
- any other suggestions then leave an issue.
- Leave a star if you like the project :)
