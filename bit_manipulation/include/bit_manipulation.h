#ifndef BIT_MANIPULATION_H
#define BIT_MANIPULATION_H

#include <cstring>
#include <mutex>

namespace com
{
    namespace brompton
    {
        class BitManipulation
        {
        public:
            // Constructors and destructor
            BitManipulation();
            BitManipulation( const size_t _bit_set_size );
            ~BitManipulation();

            // Operations
            void setBit( const size_t index );
            void clearBit( const size_t index );
            bool getBit( const size_t index ) const;
        private:
            uint8_t* bits;
            size_t bit_set_size;
            mutable std::mutex mtx;

            //Helper function

            // This function divides a number by 8
            inline size_t xDiv8( const size_t number ) const
            {
                return ( number >> 3 );
            }

            // This function performs modulo operation by 8
            inline size_t xMod8( const size_t number ) const
            {
                return ( number & 0x7 );
            }
        };
    }
}

#endif // BIT_MANIPULATION_H
