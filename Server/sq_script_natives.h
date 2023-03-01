#pragma once

#include "main.h"
#include "CScripts.h"

SQInteger sq_setScriptAuthor(SQVM * pVM); // done
SQInteger sq_setScriptVersion(SQVM * pVM); // done
SQInteger sq_loadClientScript(SQVM * pVM); // done
SQInteger sq__call(SQVM * pVM); // done
SQInteger sq_clientCall(SQVM * pVM); // undone