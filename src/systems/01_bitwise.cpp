#include <iostream>
#include <cstdint>
#include <bitset>

/*
    Objective: Master bitwise operations (AND, OR, XOR, NOT, Shifts).
    Simulate an 8-bit hardware register. You need to write the logic 
    to set, clear, toggle, and read specific bits without affecting 
    the other bits in the register.

    * << Shift left
    * | OR
    * & AND
    * ^ XOR
    * ~ NOT
*/
int main(){
    uint8_t hardwareReg = 0b00000000;

    //set bit 3 and bit 7
    hardwareReg |= (1 << 3) | (1 << 7);
    std::cout << "After Setting:   " << std::bitset<8>(hardwareReg) << "\n";

    //clear bit 3
    hardwareReg &= ~(1 << 3);
    std::cout << "After Clearing:   " << std::bitset<8>(hardwareReg) << "\n";

    //toggle bit 0 and 7
    hardwareReg ^= (1 << 0);
    hardwareReg ^= (1 << 7);
    std::cout << "After Toggling:   " << std::bitset<8>(hardwareReg) << "\n";

    //check state of bit 0
    if (hardwareReg & (1 << 0)){
        std::cout << "Bit 0 is ON\n";
    } else {
        std::cout << "Bit 0 is OFF\n";
    }

}