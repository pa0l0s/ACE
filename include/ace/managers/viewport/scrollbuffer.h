/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef _ACE_MANAGERS_VIEWPORT_SCROLLBUFFER_H_
#define _ACE_MANAGERS_VIEWPORT_SCROLLBUFFER_H_

#ifdef AMIGA

/**
 * Scrollable buffer manager
 * Uses scrolling-trick from aminet to achieve memory-efficient scroll
 * Must be processed as last, because it calls WaitTOF
 * Author: KaiN
 * Requires viewport managers:
 * 	- camera
 * TODO: make it work without tileBuffer manager
 */

#include <ace/types.h>
#include <ace/macros.h>
#include <ace/types.h>
#include <ace/utils/custom.h>
#include <ace/utils/extview.h>
#include <ace/utils/bitmap.h>

#include <ace/managers/blit.h>
#include <ace/managers/copper.h>
#include <ace/managers/viewport/camera.h>

/* Types */

typedef struct {
	tVpManager sCommon;
	tCameraManager *pCameraManager;  /// Quick ref to camera

	tBitMap *pBuffer;          /// Ptr to buffer bitmap
	tCopBlock *pStartBlock;          /// Initial data fetch
	tCopBlock *pBreakBlock;          /// Bitplane ptr reset
	tUwCoordYX uBfrBounds;           /// Real bounds of buffer (includes height reserved for x-scroll)
	UWORD uwBmAvailHeight;           /// Avail height of buffer to blit (excludes height reserved for x-scroll)
	UWORD uwVpHeightPrev;            /// Prev height of related VPort, used to force refresh on change
	UWORD uwModulo;                  /// Bitplane modulo
	tAvg *pAvg;
} tScrollBufferManager;

/* Globals */

/* Functions */

tScrollBufferManager *scrollBufferCreate(
	tVPort *pVPort, UBYTE ubMarginWidth,
	UWORD uwBoundWidth, UWORD uwBoundHeight
);

void scrollBufferDestroy(tScrollBufferManager *pManager);

void scrollBufferProcess(tScrollBufferManager *pManager);

void scrollBufferReset(
	tScrollBufferManager *pManager, UBYTE ubMarginWidth,
	UWORD uwBoundWidth, UWORD uwBoundHeight
);

void scrollBufferBlitMask(
	tBitMap *pSrc, WORD wSrcX, WORD wSrcY,
	tScrollBufferManager *pDstManager,
	WORD wDstX, WORD wDstY,
	WORD wWidth, WORD wHeight,
	UWORD *pMsk
);

#endif // AMIGA

#endif // _ACE_MANAGERS_VIEWPORT_SCROLLBUFFER_H_
