#include "main.h"
#include "CScripts.h"

SQInteger sq_createText(SQVM * pVM);
SQInteger sq_destroyText(SQVM * pVM);
SQInteger sq_toggleTextForPlayer(SQVM * pVM);
SQInteger sq_toggleTextForAll(SQVM * pVM);
SQInteger sq_setTextForAll(SQVM * pVM);
SQInteger sq_setTextForPlayer(SQVM * pVM);
SQInteger sq_setTextColorForAll(SQVM * pVM);
SQInteger sq_setTextColorForPlayer(SQVM * pVM);
SQInteger sq_setTextPositionForAll(SQVM * pVM);
SQInteger sq_setTextPositionForPlayer(SQVM * pVM);