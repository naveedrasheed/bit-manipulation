#include "bit_manipulation.h"
#include <cassert>
#include <iostream>

using namespace std;
using namespace com::brompton;

// Helper function to validate set and clear bits
static void bitHelper( BitManipulation& bitManipulation, const size_t index )
{
    bool bit_status = false;

    cout << "Processing bit: " << index << ", ";

    bit_status = bitManipulation.getBit( index );
    cout << "initial value: " << bit_status << ", ";
    assert( !bit_status );

    bitManipulation.setBit( index );
    bit_status = bitManipulation.getBit( index );
    cout << "set value: " << bit_status << ", ";
    assert( bit_status );

    bitManipulation.clearBit( index );
    bit_status = bitManipulation.getBit( index );
    cout << "clear value: " << bit_status << endl;
    assert( !bit_status );
}

// Test first and last bits in a byte
static void test_FirstAndLastBitSetInAByte( void )
{
    BitManipulation bitManipulation( 256 );
    for ( int i = 0; i < 256; ++i )
    {
        bitHelper( bitManipulation, i );

        i += 7;
        bitHelper( bitManipulation, i );
    }
}

// Test a size that is less than 8
void test_LessThan8BitBoundary( void )
{
    BitManipulation bitManipulation( 2 );
    for ( int i = 0; i < 2; ++i )
    {
        bitHelper( bitManipulation, i );
    }
}

// Test a size that is less than 16
void test_LessThan16BitBoundary( void )
{
    BitManipulation bitManipulation( 12 );
    for ( int i = 0; i < 12; ++i )
    {
        bitHelper( bitManipulation, i );
    }
}

int main ( int argc, char* argv[] )
{
    ( void ) argc;
    ( void ) argv;
    cout << __cplusplus << endl;

    test_FirstAndLastBitSetInAByte();
    test_LessThan8BitBoundary();
    test_LessThan16BitBoundary();
    return 0;
}
