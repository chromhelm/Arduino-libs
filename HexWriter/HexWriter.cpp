#include "HexWriter.h"

const uint8_t HexWriter::c[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F',};

void HexWriter::begin(Print* print,  mode_t mode)
{
	HexWriter::p = print;
	HexWriter::mode = mode;
}

void HexWriter::print(uint8_t* data, uint16_t length, uint16_t offset)
{
	uint16_t pos, endOfData;
	uint8_t offsetLength;
	
	pos = offset & ((mode.show16bit) ? 0xfff0 : 0xfff8);
	
	endOfData = offset + length;
	
	offsetLength = getNumberLength(endOfData);
	mode.offsetLength =  constrain(mode.offsetLength, 0, 8);;
	offsetLength = max(offsetLength, mode.offsetLength);
	
	if(mode.showHeader)printHeader(offsetLength);
	
	while(pos < endOfData)
	{
		printLine(data, pos, offset, endOfData, offsetLength);
		
		pos += ((mode.show16bit) ? 16 : 8);
	}
	
	p->println();
}

void HexWriter::printLine(uint8_t* data, uint16_t pos, uint16_t offset, uint16_t endOfData, uint8_t offsetLength)
{
	uint8_t i = 0;
	
	if(mode.showOffset)
	{
		print(pos, offsetLength);
		p->write('|');
	}
	
	while(i < 8  && (pos + i < endOfData || mode.showText))
	{
		if(pos + i < offset || pos + i >= endOfData) p->print("  ");
		else print(data[pos + i], 2);
		if(i < 7)p->write(' ');
		i++;
	}
	
	if(mode.show16bit)
	{
		if(pos + i < endOfData) p->write(':');
		else if(mode.showText)  p->write(' ');
		
		while(i < 16  && (pos + i < endOfData || mode.showText))
		{
			if(pos + i < offset || pos + i >= endOfData)p->print("  ");
			else print(data[pos + i], 2);
			if(i < 15)p->write(' ');
			i++;
		}
	}
	
	if(mode.showText)
	{
		i = 0;
		p->print("| ");
		
		while(i < 8 && pos + i < endOfData)
		{
			if(pos + i < offset)p->write(' ');
			else putChar(data[pos + i]);
			i++;
		}
		
		if(mode.show16bit)
		{
			p->write(' ');
			while(i < 16 && pos + i < endOfData)
			{
				if(pos + i < offset)p->write(' ');
				else putChar(data[pos + i]);
				i++;
			}
		}
	}
	p->println();
}

void HexWriter::printHeader(uint8_t offsetLength)
{
	uint8_t i = 0;

	if(mode.showOffset)
	{
		while(i++ < offsetLength)
		{
			p->write(' ');
		}
		p->write('|');
	}
	
	p->print(" 0  1  2  3  4  5  6  7");
	
	if(mode.show16bit)
	{
		p->print(": 8  9  A  B  C  D  E  F");
	}
	
	if(mode.showText)
	{
		p->print("| 01234567");
		if(mode.show16bit)
		{
			p->print(" 89ABCDEF");
		}
	}
	
	p->println();
	
	if(mode.showOffset)
	{
		i = 0;
		while(i++ < offsetLength)
		{
			p->write('-');
		}
		p->write('+');
	}
	p->print("-----------------------");
	if(mode.show16bit)
	{
		p->print("+-----------------------");
	}
	
	if(mode.showText)
	{
		p->print("+---------");
		if(mode.show16bit)
		{
			p->print("---------");
		}
	}
	p->println();
	
}

uint8_t HexWriter::getNumberLength(uint16_t number)
{
		 if(number & 0xf000) return 4;
	else if(number & 0x0f00) return 3;
	else if(number & 0x00f0) return 2;
	else					 return 1;
}

uint8_t HexWriter::getNumberLength(uint8_t number)
{
		 if(number & 0xf0) return 2;
	else				   return 1;
}

void HexWriter::putChar(uint8_t data)
{
	if(data <= 0x20 || data >= 0x7f)p->write('.');
	else p->write((char)data);
}

void HexWriter::print(uint8_t value, uint8_t decimals)
{
	if(decimals >= 2 || value &0xf0) p->write(c[value >> 4]);
	p->write(c[value & 0xf]);
}

void HexWriter::print(uint16_t value, uint8_t decimals)
{
	if(decimals >= 4 || value & 0xf000) p->write(c[ (value >> 3*4) & 0xf]);
	if(decimals >= 3 || value & 0xff00) p->write(c[ (value >> 2*4) & 0xf]);
	if(decimals >= 2 || value & 0xfff0) p->write(c[ (value >> 1*4) & 0xf]);
	p->write(c[ value & 0xf]);
}
