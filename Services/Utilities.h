/*
 * Utilities.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Ezz_A
 */

#ifndef DIO_UTILITIES_H_
#define DIO_UTILITIES_H_

/*
 * Utilities.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Ezz_A
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/* Rotate right the register value with specific number of rotates */
#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(8-num)) )

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num)) )

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )

#define READ_BIT(REG,BIT)	((REG & (1<<BIT))>>BIT)
#endif /* UTILITIES_H_ */


#endif /* DIO_UTILITIES_H_ */
