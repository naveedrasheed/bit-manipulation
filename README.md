# Bit Manipulation
### Build instruction
1. Open vsode at the root directory that contains .devcontainer directory
2. Open the solution in docker container
3. On command line create a directory build
4. Issue the following build command
_cmake -G Ninja -S ../ && cmake --build . --target astyle && ninja -j32_

##### Task Description
Implement a thread-safe class for managing a large bitset (e.g. 256bits) that
provides some simple operations to manipulate and query individual bits.
Specifications for implementation are provided below and we encourage you to take
decisions in the areas where they are open that enable you to speed up your
development. Additionally, we recommend not spending more than 2-4 hours on the
assignment.
Requirements
1. Class Design
    The class should be thread-safe, ensuring that concurrent operations on the
        bitmap do not lead to race conditions or inconsistent states.
    The implementation should be memory efficient
2. APIs to Implement
    setBit: Sets the bit at the specified index to 1.
    clearBit(index): Clears the bit at the specified index, setting it to 0.
    bool getBit(index): Returns the value of the bit at the specified index (true if
        the bit is set to 1, false if it is 0).
3. Additional Considerations
    Portability
    Unit Tests
    Flexibility
