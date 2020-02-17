/**	@file tools.h
 *  @brief Various basic functions that can be useful
 *
 *	@author AECX
 *	@bug No known bugs.
 *  @todo At some point we might want to seperate functions into different namespaces
 * i.e. tools::array, tools::hashing, etc.; for now there aren't enough functions for this to make sense
 */

#pragma once

#include "types.h"

namespace libtp::tools
{
    /**
     *  @brief Returns the index of needle in haystack, -1 if error
     *
     *  @param haystack The array for which you need the index
     *  @param needle The data to find in haystack
     *  @param length Length (in bytes) of haystack
     *  @param chunkSize Length (in bytes) of one individual element (haystack[0])
     */
    s32 indexOf(const void* haystack, void* needle, s32 length, s32 chunkSize = sizeof(char));
}  // namespace libtp::tools