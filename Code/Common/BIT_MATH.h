#ifndef BIT_MATH_H
#define BIT_MATH_H

#define     SET_BIT(Reg_Name,Bit_position)            (Reg_Name |= (1<<Bit_position))
#define     CLR_BIT(Reg_Name,Bit_position)            (Reg_Name &= (~(1<<Bit_position)))
#define     TOGGLE_BIT(Reg_Name,Bit_position)         (Reg_Name ^= (1<<Bit_position))
#define     READ_BIT(Reg_Name,Bit_position)           ((Reg_Name&(1<<Bit_position))>>Bit_position)

#endif
