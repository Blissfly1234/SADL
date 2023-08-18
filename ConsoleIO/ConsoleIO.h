#pragma once

#include <string>

class consoleIO
{
private:
	std::string buffer;
	bool failBuffer;

	void in();
public:
	std::string outputBuffer;

	std::string getLine();

	bool getBool();
	char getChar();
	int getInt();
	short getShort();
	long getLong();
	float getFloat();
	double getDouble();

	bool fail();

	void printBuffer();
	void print(const char output[]);
};

static consoleIO console;