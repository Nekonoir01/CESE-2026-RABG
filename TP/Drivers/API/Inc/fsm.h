/*
 * fsm.h
 *
 *  Created on: Apr 18, 2026
 *      Author: rberr
 */

#ifndef API_INC_FSM_H_
#define API_INC_FSM_H_

typedef enum {
    INITIALIZATION,
    verify_sensors,
    Read_start,
    Read_wait,
    read_done,
    process_data,
    control_data,
    update_display,
    STATE_IDLE,
    STATE_ERRORI2C,
} FSM_State_t;


#endif /* API_INC_FSM_H_ */
