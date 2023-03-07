#include <stdio.h>
#include <assert.h>

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

void action1(){
    printf("\n in action 1 \n");
}

void action2(){
    printf("\n in action 2 \n");
}

void action3(){
    printf("\n in action 3 \n");
}

typedef void (*action)();

typedef struct {
  state_t nextState;
  action actionToDo;
}stateElement;

stateElement stateMatrix[3][3] = { 
    {{state1, action1 },{state1, action2 }, {state1,action3 }},
    {{state2, action1 },{state2, action2 }, {state2,action3 }},
    {{state3, action1 },{state3, action2 }, {state3,action3 }},
};

state_t currentState = state1;

void stateEval(event_t e) {
    stateElement stateEvaluation = stateMatrix[currentState][e];
    currentState = stateEvaluation.nextState;
    (*stateEvaluation.actionToDo)();
}

int main()
{    
    stateEval(e1);
    stateEval(e2);
    stateEval(e2);
    return 0;
}
