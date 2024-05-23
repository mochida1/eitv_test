#pragma once
#ifndef CLI_HPP
# define CLIP_HPP

#include <string>
#include <vector>
#include <exception>
#include <sstream>
#include "PriorityQueue.tpp"

typedef enum E_CLI_ACTION {
	CLI_ACTION_A = 0,
	CLI_ACTION_R = 1,
	CLI_ACTION_X = 2,
	CLI_ACTION_P = 3,
	CLI_ACTION_Q = 4,
	CLI_ACTION_INVALID = 5
} CLI_ACTION;

struct Cli_Action_Obj {
	CLI_ACTION E_action;
	std::vector<std::string> tokens; 
};

class Cli {
private:
	SpecPriorityQueue<SomeObject, std::vector<SomeObject>, cmp> _pq;
	std::string _userInput;
	bool _parseUserInput(void);
	void _procesUserInput(void);
	bool _getUserInput(void);
	void _clearUserInput(void);
	void _doAction(Cli_Action_Obj pAction);
	Cli_Action_Obj _createActionFromUserInput(void);
	bool _validateCommand(std::string command) const;
	bool _validateA(void) const;
	bool _validateR(void) const;
	bool _validateX(void) const;
	bool _validateP(void) const;
	bool _validateQ(void) const;
	void _doAction_A(std::vector<std::string> tokens);
	void _doAction_R(std::vector<std::string> tokens);
	void _doAction_X(std::vector<std::string> tokens);
	void _doAction_P(void);
	void _doAction_Q(void);
	bool _exitIssued;

	std::vector<std::string> _splitString(std::string stringToSplit) const;
	CLI_ACTION _actionStringToEnum(std::string token);
public:
	Cli(void);
	virtual ~Cli(void);
	bool shouldExit() const;
	int loopStart(void);
	class ParsingException : public std::exception {
		private:
		std::string _msg;
		public:
		ParsingException(const std::string & msg) : _msg(msg) {}
		const char* what() const noexcept override {
			return this->_msg.c_str();
		}
	};
};




#endif // CLI_HPP