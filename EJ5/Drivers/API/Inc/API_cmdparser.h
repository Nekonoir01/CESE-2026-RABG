/*
 * API_cmdparser.h
 *
 *  Created on: Apr 2, 2026
 *      Author: rberr
 */

#ifndef API_INC_API_CMDPARSER_H_
#define API_INC_API_CMDPARSER_H_
#define CMD_MAX_LINE 64 	//incluye '\0'
#define CMD_MAX_TOKENS 3	// COMANDO + maximo 2 argumentos

void cmdParserInit(void);
void cmdpoll(void);


#endif /* API_INC_API_CMDPARSER_H_ */
