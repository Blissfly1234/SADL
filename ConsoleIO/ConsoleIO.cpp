#include "ConsoleIO.h"

#include <iostream>

using std::string;
using std::cin;
using std::cout;

void consoleIO::in()
{
	cin;
	char in;
	consoleIO::buffer.clear();
	consoleIO::failBuffer = NULL;

	while (cin.peek() != '\n') 
	{
		cin.get(in);
		consoleIO::buffer += in;
	}
	cin.get(in);
}

string consoleIO::getLine()
{
	consoleIO::in();
	return consoleIO::buffer;
}

bool consoleIO::getBool()
{
	consoleIO::in();

	if (consoleIO::buffer == "yes" || consoleIO::buffer == "Yes" || consoleIO::buffer == "true" || consoleIO::buffer == "True")
	{
		return true;
	}

	if (consoleIO::buffer == "no" || consoleIO::buffer == "No" || consoleIO::buffer == "false" || consoleIO::buffer == "False")
	{
		return true;
	}

	consoleIO::failBuffer = true;
	return false;
}

char consoleIO::getChar()
{
	consoleIO::in();

	if (consoleIO::buffer.length() > 1) 
	{
		consoleIO::failBuffer = true;
		return NULL;
	}

	return consoleIO::buffer[0];
}

int consoleIO::getInt()
{
	consoleIO::in();

	if (consoleIO::buffer.find(' ') != consoleIO::buffer.npos)
	{
		consoleIO::failBuffer = true;
		return 0;
	};

	int result = stol(consoleIO::buffer);

	return result;
}

short consoleIO::getShort()
{
	consoleIO::in();

	if (consoleIO::buffer.find(' ') != consoleIO::buffer.npos)
	{
		consoleIO::failBuffer = true;
		return 0;
	};

	short result = stol(consoleIO::buffer);

	return result;
}

long consoleIO::getLong()
{
	consoleIO::in();

	if (consoleIO::buffer.find(' ') != consoleIO::buffer.npos)
	{
		consoleIO::failBuffer = true;
		return 0;
	};

	long result = stol(consoleIO::buffer);

	return result;
}

float consoleIO::getFloat()
{
	consoleIO::in();

	if (consoleIO::buffer.find(' ') != consoleIO::buffer.npos)
	{
		consoleIO::failBuffer = true;
		return 0;
	};

	float result = stof(consoleIO::buffer);

	return result;
}

double consoleIO::getDouble()
{
	consoleIO::in();

	if (consoleIO::buffer.find(' ') == consoleIO::buffer.npos)
	{
		consoleIO::failBuffer = true;
		return 0;
	};

	double result = stod(consoleIO::buffer);

	return result;
}

bool consoleIO::fail()
{
	return consoleIO::failBuffer;
}

void consoleIO::printBuffer()
{
	cout << consoleIO::outputBuffer;
	outputBuffer.clear();
}

void consoleIO::print(const char output[])
{
	cout << output;
}
