#include <HexWriter.h>

HexWriter hex;

uint8_t data[] =
{
	 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
	10,11,12,13,14,15,16,17,18,19,
	20,21,22,23,24,25,26,27,28,29,
	30,31,32,33,34,35,36,37,38,39,
	40,41,42,43,44,45,46,47,48,49,
	50,51,52,53,54,55,56,57,58,59,
	60,61,62,63,64,65,66,67,68,69,
	70,71,72,73,74,75,76,77,78,79,
	80,81,82,83,84,85,86,87,88,89,
	90,91,92,93,94,95,96,97,98,99,
};

void setup()
{
	Serial.begin(1000000);
	hex.begin(&Serial);
}

void loop()
{
	test1();
  	Serial.flush();
	delay(1000);
}

void test1()
{
	uint8_t offset = 0x20, length = 0;

	writeHex(offset, 0x0);
	writeHex(offset, 0x1);
	writeHex(offset, 0x7);
	writeHex(offset, 0x8);
	writeHex(offset, 0x9);
	writeHex(offset, 0xf);
	writeHex(offset, 0x10);
	writeHex(offset, 0x11);

	offset = 0x27;
	writeHex(offset, 0x0);
	writeHex(offset, 0x1);
	writeHex(offset, 0x7);
	writeHex(offset, 0x8);
	writeHex(offset, 0x9);
	writeHex(offset, 0xf);
	writeHex(offset, 0x10);
	writeHex(offset, 0x11);

	offset = 0x28;
	writeHex(offset, 0x0);
	writeHex(offset, 0x1);
	writeHex(offset, 0x7);
	writeHex(offset, 0x8);
	writeHex(offset, 0x9);
	writeHex(offset, 0xf);
	writeHex(offset, 0x10);
	writeHex(offset, 0x11);

	offset = 0x2F;
	writeHex(offset, 0x0);
	writeHex(offset, 0x1);
	writeHex(offset, 0x7);
	writeHex(offset, 0x8);
	writeHex(offset, 0x9);
	writeHex(offset, 0xf);
	writeHex(offset, 0x10);
	writeHex(offset, 0x11);

	offset = 0x30;
	writeHex(offset, 0x0);
	writeHex(offset, 0x1);
	writeHex(offset, 0x7);
	writeHex(offset, 0x8);
	writeHex(offset, 0x9);
	writeHex(offset, 0xf);
	writeHex(offset, 0x10);
	writeHex(offset, 0x11);

	offset = 0x31;
	writeHex(offset, 0x0);
	writeHex(offset, 0x1);
	writeHex(offset, 0x7);
	writeHex(offset, 0x8);
	writeHex(offset, 0x9);
	writeHex(offset, 0xf);
	writeHex(offset, 0x10);
	writeHex(offset, 0x11);

	delay(10000);
}

void writeHex(uint8_t offset, uint8_t length)
{
	Serial.println(F("=================================="));
	Serial.print(F("Offset = "));
	Serial.print(offset);
	Serial.print(F("   Length = "));
	Serial.println(length);
	Serial.println(F("=================================="));
	
	Serial.println(F("null"));
	hex.mode.showHeader = 0;
	hex.mode.showOffset = 0;
	hex.mode.show16bit = 0;
	hex.mode.showText = 0;
	hex.print(data, offset, length);
	delay(1);

	Serial.println(F("Header"));
	hex.mode.showHeader = 1;
	hex.mode.showOffset = 0;
	hex.mode.show16bit = 0;
	hex.mode.showText = 0;
	hex.print(data, offset, length);
	delay(1);

	Serial.println(F("Offset"));
	hex.mode.showHeader = 0;
	hex.mode.showOffset = 1;
	hex.mode.show16bit = 0;
	hex.mode.showText = 0;
	hex.print(data, offset, length);
	delay(1);

	Serial.println(F("Header + offset"));
	hex.mode.showHeader = 1;
	hex.mode.showOffset = 1;
	hex.mode.show16bit = 0;
	hex.mode.showText = 0;
	hex.print(data, offset, length);
	delay(1);

	Serial.println(F("16 bit"));
	hex.mode.showHeader = 0;
	hex.mode.showOffset = 0;
	hex.mode.show16bit = 1;
	hex.mode.showText = 0;
	hex.print(data, offset, length);
	delay(1);

	Serial.println(F("Header + 16 bit"));
	hex.mode.showHeader = 1;
	hex.mode.showOffset = 0;
	hex.mode.show16bit = 1;
	hex.mode.showText = 0;
	hex.print(data, offset, length);
	delay(1);

	Serial.println(F("Offset + 16 bit"));
	hex.mode.showHeader = 0;
	hex.mode.showOffset = 1;
	hex.mode.show16bit = 1;
	hex.mode.showText = 0;
	hex.print(data, offset, length);
	delay(1);

	Serial.println(F("Header + Offset + 16 bit"));
	hex.mode.showHeader = 1;
	hex.mode.showOffset = 1;
	hex.mode.show16bit = 1;
	hex.mode.showText = 0;
	hex.print(data, offset, length);
	//--------------------------
	Serial.println(F("Text"));
	hex.mode.showHeader = 0;
	hex.mode.showOffset = 0;
	hex.mode.show16bit = 0;
	hex.mode.showText = 1;
	hex.print(data, offset, length);
	//--------------------------
	Serial.println(F("Header + Text"));
	hex.mode.showHeader = 1;
	hex.mode.showOffset = 0;
	hex.mode.show16bit = 0;
	hex.mode.showText = 1;
	hex.print(data, offset, length);
	//--------------------------
	Serial.println(F("Offset + Text"));
	hex.mode.showHeader = 0;
	hex.mode.showOffset = 1;
	hex.mode.show16bit = 0;
	hex.mode.showText = 1;
	hex.print(data, offset, length);
	//--------------------------
	Serial.println(F("Header + offset + Text"));
	hex.mode.showHeader = 1;
	hex.mode.showOffset = 1;
	hex.mode.show16bit = 0;
	hex.mode.showText = 1;
	hex.print(data, offset, length);
	//--------------------------
	Serial.println(F("16 bit + Text"));
	hex.mode.showHeader = 0;
	hex.mode.showOffset = 0;
	hex.mode.show16bit = 1;
	hex.mode.showText = 1;
	hex.print(data, offset, length);
	//--------------------------
	Serial.println(F("Header + 16 bit + Text"));
	hex.mode.showHeader = 1;
	hex.mode.showOffset = 0;
	hex.mode.show16bit = 1;
	hex.mode.showText = 1;
	hex.print(data, offset, length);
	//--------------------------
	Serial.println(F("Offset + 16 bit + Text"));
	hex.mode.showHeader = 0;
	hex.mode.showOffset = 1;
	hex.mode.show16bit = 1;
	hex.mode.showText = 1;
	hex.print(data, offset, length);
	//--------------------------
	Serial.println(F("Header + Offset + 16 bit + Text"));
	hex.mode.showHeader = 1;
	hex.mode.showOffset = 1;
	hex.mode.show16bit = 1;
	hex.mode.showText = 1;
	hex.print(data, offset, length);
}
