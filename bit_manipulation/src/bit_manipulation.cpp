#include "bit_manipulation.h"

using namespace std;
using namespace com::brompton;

// Default constructor
BitManipulation::BitManipulation():
    bits( nullptr ), bit_set_size( 0 )
{
}

// Overloaded constructor
BitManipulation::BitManipulation( const size_t _bit_set_size ): BitManipulation()
{
    bit_set_size = _bit_set_size;

    // If we have a valid size of bit set
    if ( bit_set_size )
    {
        // Represent 8 bits as uint8_t
        size_t size = xDiv8( bit_set_size );

        // If size is not divided by 8 than increment the size by 1 to accommodate
        // remaining bits
        if ( xMod8( bit_set_size ) )
        {
            ++size;
        }

        // Allocate memory for given bits as words to use memory efficiently
        bits = new uint8_t[size];
        std::memset( bits, 0, size );
    }
}

BitManipulation::~BitManipulation()
{
    // Ensure bits are not in use by any thread
    std::lock_guard<std::mutex> lock( mtx );

    // Deallocate the memory
    delete[] bits;
}

// Operations
void BitManipulation::setBit( const size_t index )
{
    if ( index < bit_set_size )
    {
        // Acquire lock to make the API threadsafe
        std::lock_guard<std::mutex> lock( mtx );

        // Identify the byte first and then set the corresponding bit
        bits[xDiv8( index )] |= ( 1u << xMod8( index ) );
    }
    else
    {
        throw std::out_of_range( "Index out of range" );
    }
}

void BitManipulation::clearBit( const size_t index )
{
    if ( index < bit_set_size )
    {
        // Acquire lock to make the API threadsafe
        std::lock_guard<std::mutex> lock( mtx );

        // Identify the byte first and then clear the corresponding bit
        bits[xDiv8( index )] &= ~( 1u << xMod8( index ) );
    }
    else
    {
        throw std::out_of_range( "Index out of range" );
    }
}

bool BitManipulation::getBit( const size_t index ) const
{
    if ( index >= bit_set_size )
    {
        throw std::out_of_range( "Index out of range" );
    }

    // Acquire lock to make the API threadsafe
    std::lock_guard<std::mutex> lock( mtx );

    // Identify the byte first and then get the corresponding bit
    return bits[xDiv8( index )] & ( 1u << xMod8( index ) );
}
