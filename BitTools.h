#ifndef BIT_TOOLS_H
#define BIT_TOOLS_H
#include <cstdint>
#include <array>

class BitTools
{
public:
	BitTools();
	~BitTools();
	static void flipBits(int position, uint64_t & valueToFlip);
	static uint64_t encode(std::array<char, 8> charArray);
	static std::array<char, 8> decode(uint64_t encodedValue);
	static uint64_t leftSplice(uint64_t valueToSplit,  int splicer);
	static uint64_t rightSplice(uint64_t valueToSplit, int splicer);
	static uint64_t spliceMerge(uint64_t leftValue, uint64_t rightValue);
};

#endif //!BIT_TOOLS_H