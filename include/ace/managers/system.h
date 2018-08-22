/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef _ACE_MANAGERS_SYSTEM_H_
#define _ACE_MANAGERS_SYSTEM_H_

#include <ace/types.h>
#include <ace/utils/custom.h>

//---------------------------------------------------------------------- DEFINES

//------------------------------------------------------------------------ TYPES

typedef void (*tAceIntHandler)(
	REGARG(volatile tCustom *pCustom, "a0"), REGARG(volatile void *tData, "a1")
);

//-------------------------------------------------------------------- FUNCTIONS

void systemCreate(void);

void systemDestroy(void);

void systemKill(const char *szMsg);

void systemSetInt(
	UBYTE ubIntNumber, tAceIntHandler pHandler, volatile void *pIntData
);

void systemUse(void);

void systemUnuse(void);

void systemDump(void);

void systemSetInt(
	UBYTE ubIntNumber, tAceIntHandler pHandler, volatile void *pIntData
);

void systemSetDma(UBYTE ubDmaBit, UBYTE isEnabled);

//---------------------------------------------------------------------- GLOBALS

#endif // _ACE_MANAGERS_SYSTEM_H_
