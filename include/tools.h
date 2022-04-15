/**	@file tools.h
 *  @brief Various basic functions that can be useful
 *
 *	@author AECX
 *	@bug No known bugs.
 *  @todo At some point we might want to seperate functions into different namespaces
 * i.e. tools::array, tools::hashing, etc.; for now there aren't enough functions for this to make sense
 */
#pragma once
#include <cstdint>

#include "tp/dzx.h"

namespace libtp::tools
{
    /**
     *  @brief Fletcher16 checksum
     *
     *  @param data Data to calculate the checksum from
     *  @param length How many bytes of data should be considered
     *  @return Checksum in 2 bytes
     */
    uint16_t fletcher16( uint8_t* data, int32_t length );

    /**
     *  @brief Savely loads a given stage-room-spawnpoint-state and event combination
     *
     *  @param stage 8 char stage ID
     *  @param room Room ID
     *  @param spawn Spawnpoint
     *  @param state Current State (Link)
     *  @param event EventID to trigger
     */
    void TriggerSaveLoad( const char* stage, uint8_t room, uint8_t spawn, uint8_t state = 0xFF, uint8_t event = 0xFF );

    /**
     *  @brief Spawns an actor
     *
     *  @param roomID Room id to spawn the actor
     *  @param actor The actor object to be spawned
     */
    void SpawnActor( uint8_t roomID, tp::dzx::ACTR& actor );

    /**
     *  @brief Reads GCI data from offset to offset + length into buffer
     *
     *  @param chan Slot to check for the file
     *  @param fileName GCI Filename to load
     *  @param length Maximum length to read
     *  @param offset GCI fileOffset to read
     *  @param[out] buffer Buffer to save the data
     *
     *  @return One of the CARD_RESULT Constants (CARD_RESULT_READY, ...)
     */
    int32_t ReadGCI( int32_t chan, const char* fileName, int32_t length, int32_t offset, void* buffer );

#ifdef PLATFORM_WII
    /**
     *  @brief Reads NAND data from offset to offset + length into buffer
     *
     *  @param fileName NAND Filename to load
     *  @param length Maximum length to read
     *  @param offset NAND fileOffset to read
     *  @param[out] buffer Buffer to save the data
     *
     *  @return One of the NAND_RESULT Constants (NAND_RESULT_READY, ...)
     */
    int32_t ReadNAND( const char* fileName, int32_t length, int32_t offset, void* buffer );
#endif  // PLATFORM_WII

    /**
     * @brief Generates a random number based on a seed and a maximum number
     *
     * @param seed A reference to the seed that's being used
     * @param max The maximum number to be generated by the function
     */
    uint32_t getRandom( uint64_t* seed, uint32_t max );
}     // namespace libtp::tools