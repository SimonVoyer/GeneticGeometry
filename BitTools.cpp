#include "BitTools.h"
#include <bitset>
#include <iostream>

BitTools::BitTools(){
}


BitTools::~BitTools(){
}


void BitTools::flipBits(int position, uint64_t & valueToFlip) {
	uint64_t masqueMin = 1;
	for (int i{ 0 }; i < position -1; ++i) {
		masqueMin <<= 1;
	}
	//std::cout << "valeur avant flip: " << valueToFlip << "\nen bits: " << std::bitset<64>(valueToFlip);
	//std::cout << "\nmasque: " << std::bitset<64>(masqueMin);
	valueToFlip ^= masqueMin;
	//std::cout << "\nvaleur apres flip: " << valueToFlip << "\nen bits: " << std::bitset<64>(valueToFlip);
}

uint64_t BitTools::encode(std::array<char, 8> charArray) {
	uint64_t encodedValue{0};
	//std::cout << "\nstarting encoded value: " << std::bitset<64>(encodedValue);
	for (int i{ 0 }; i < charArray.size(); ++i) {
		encodedValue <<= 8;
		//std::cout << "\nvalue du char en bits: " << std::bitset<8>(charArray.at(i));
		//std::cout << "\nencoded value avant: " << std::bitset<64>(encodedValue);
		encodedValue |= charArray.at(i);
		

		//std::cout << "\n encoded value apres: " << std::bitset<64>(encodedValue);
		
	}
	//std::cout << "\nvalue encodee fin : " << encodedValue;
//	std::cout << "\nvalue encodee en bits fin: " << std::bitset<64>(encodedValue);

	return encodedValue;
}
std::array<char, 8> BitTools::decode(uint64_t encodedValue) {
	//std::cout << "\nencoded bits: " << std::bitset<64>(encodedValue) << "\n\n";
	std::array<char, 8>charArray{ 0,0,0,0,0,0,0,0 };
	for (int i{ 7 }; i >= 0; --i) {
		charArray.at(i) |= encodedValue;
		encodedValue >>= 8;
		//std::cout << "\nvaleurs du char: " << (int)charArray.at(i) << "bits du char: " << std::bitset<8>(charArray.at(i));
	}
	
	/*for (auto & value : charArray) {
		value |= encodedValue;
		encodedValue >>= 8;
		std::cout << "\nvaleurs du char: " << (int) value << "bits du char: " << std::bitset<8>(value);
	}*/
	return charArray;
}

uint64_t BitTools::leftSplice(uint64_t valueToSplit,int splicer) {
	valueToSplit >>= splicer;
	return valueToSplit <<= splicer;
}

uint64_t  BitTools::rightSplice(uint64_t valueToSplit, int splicer) {
	valueToSplit <<= 64 - splicer;
	return valueToSplit >>= 64 - splicer;
}

uint64_t  BitTools::spliceMerge(uint64_t leftValue, uint64_t rightValue) {
	return leftValue |= rightValue;
}