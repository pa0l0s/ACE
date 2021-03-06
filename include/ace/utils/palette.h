/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef _ACE_UTILS_PALETTE_H
#define _ACE_UTILS_PALETTE_H

/**
 *  Palette utilities.
 */

#include <ace/types.h>
#include <ace/utils/extview.h>

/* Types */

/* Globals */

/* Functions */

/**
 *  @brief Loads palette from supplied .plt file to given address.
 *  @param szFileName  Palette source path.
 *  @param pPalette    Palette destination pointer.
 *  @param ubMaxLength Maximum number of colors in palette.
 */
void paletteLoad(char *szFileName, UWORD *pPalette, UBYTE ubMaxLength);

/**
 *  @brief Dims palette to given brightness level.
 *  @param pSource      Pointer to source palette.
 *  @param pDest        Pointer to destination palette. May be same as pSource.
 *  @param ubColorCount Number of colors in palette.
 *  @param ubLevel      Brightness level - 15 for no dim, 0 for total blackness.
 */
void paletteDim(UWORD *pSource, UWORD *pDest, UBYTE ubColorCount, UBYTE ubLevel);

void paletteDump(UWORD *pPalette, FUBYTE fubColorCnt, char *szPath);

#endif // _ACE_UTILS_PALETTE_H
