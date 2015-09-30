#pragma once

#include <string>
#include <map>

using namespace std;
class CommandFactory
{
	enum CommandString {
		error,
		help
	};

private:
	void RunHelpCommand();
	void Error();
	map<string, CommandString> stringMap;
public:
	CommandFactory();
	~CommandFactory();
	void CreateCommand(string commandString);
};

