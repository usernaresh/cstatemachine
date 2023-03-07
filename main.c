#include <stdio.h>

typedef enum state {
    state1 =0,
    state2 =1,
    state3 =2,
} state_t;

typedef enum event {
    e1,
    e2,
    e3,
} event_t;

void state1_actions(){
    printf("\n in state1 actions \n");
}

void state2_actions(){
    printf("\n in state2 actions \n");
}

void state3_actions(){
    printf("\n in state3 actions \n");
}

typedef struct ds_state {
    event_t event;
    state_t current_state;
    state_t next_state;
    void (*state_method)();
}ds_state_t;

ds_state_t state_mc[] = { 
    { e1, state1, state2, state1_actions},
    { e2, state2, state3, state2_actions},
    { e3, state3, state1, state3_actions},
};

void run_mc(event_t ev, state_t* st){
    if(state_mc[ev].current_state == *st){
        *st = state_mc[ev].next_state;
        state_mc[ev].state_method();
    }
}

int main()
{
    state_t st = state1;
    event_t ev = e1;
    run_mc(ev, &st); 
    ev =e2;
    run_mc(ev, &st);
    ev=e3;
    run_mc(ev, &st);
    return 0;
}
