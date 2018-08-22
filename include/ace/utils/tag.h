/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef _ACE_UTILS_TAG_H_
#define _ACE_UTILS_TAG_H_

/**
 * Util for handling AmigaOS tag list pattern.
 */

#include <stdarg.h>
#include <ace/types.h>

typedef ULONG tTag;
#ifndef TAG_DONE
#define TAG_DONE   0UL
#define TAG_END    0UL
#define TAG_IGNORE 1UL
#define TAG_MORE   2UL
#define TAG_SKIP   3UL
#define TAG_USER   BV(31)
#endif

/**
 *  Finds and returns value of specified tag name from tag list.
 *  Tag list may be supplied as list or va_list.
 *  TODO: 1st arg doesn't work yet
 *  @param pTagListPtr  Pointer to tag list.
 *  @param vaSrcList    va_list containing alternating tags and values.
 *  @param ulTagToFind  Tag name, of which value should be returned.
 *  @param ulOnNotFound Value to be returned if tag was not found on list.
 *  @return Zero if tag was not found, otherwise tag value.
 */
ULONG tagGet(
	void *pTagListPtr, va_list vaSrcList, tTag ulTagToFind, ULONG ulOnNotFound
);

#endif // _ACE_UTILS_TAG_H_
