/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef _ACE_UTILS_BMFRAME_H_
#define _ACE_UTILS_BMFRAME_H_

#include <ace/utils/bitmap.h>
#include <ace/managers/blit.h>

// defines for offsets of tiles in frame file

#define FRAMETILE_NW 0,0
#define FRAMETILE_N 16,0
#define FRAMETILE_NE 32,0

#define FRAMETILE_W 0,16
#define FRAMETILE_C 16,16
#define FRAMETILE_E 32,16

#define FRAMETILE_SW 0,32
#define FRAMETILE_S 16,32
#define FRAMETILE_SE 32,32

void bmFrameDraw(
	tBitMap *pFrameSet, tBitMap *pDest,
	UWORD uwX, UWORD uwY, UBYTE ubTileWidth, UBYTE ubTileHeight
);

#endif // _ACE_UTILS_BMFRAME_H_
