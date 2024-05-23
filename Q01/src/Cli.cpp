#include "Cli.hpp"

Cli::Cli(void) : _userInput(""), _exitIssued(false) {
}

Cli::~Cli(void){
}

// Huge buffers will result in uncaught exceptions.
bool Cli::_parseUserInput(void){
	if (this->_userInput.empty()){
		throw ParsingException("...");
		return false;
	}
	switch (this->_userInput.front()){
		case 'A':
			return this->_validateA();
		case 'R':
			return this->_validateR();
		case 'X':
			return this->_validateX();
		case 'P':
			return this->_validateP();
		case 'Q':
			return this->_validateQ();
		default:
			throw ParsingException("Error (wrong input): Valid commands: A, R, X, P, Q");
	}
	return false;
}

std::vector<std::string> Cli::_splitString(std::string stringToSplit) const {
	std::vector<std::string> tokens;
	std::istringstream stream(stringToSplit);
	std::string token;

	while (std::getline(stream, token, '\t')) {
		std::istringstream tokenStream(token);
		std::string subToken;
		while (std::getline(tokenStream, subToken, ' ')) {
			if (!subToken.empty()) {
				tokens.push_back(subToken);
			}
		}
	}
	return tokens;
}

bool Cli::_validateCommand(std::string command) const {
	if (command.size() != 1)
		throw ParsingException("Error(wrong command): " + command);
	return true;
}

bool Cli::_validateA(void) const {
	std::vector<std::string> toParse = this->_splitString(this->_userInput);
	this->_validateCommand(toParse[0]);
	if (toParse.size() != 3)
		throw ParsingException("Error(invalid number of arguments): 'A' must be followed by <identificador> <prioridade>");
	std::istringstream iss(toParse[2]);
	int val;
	if (iss >> val) {
		if (val < 1 || val > 20){
			throw ParsingException("Error(Out of range): 'A' <prioridade> must be between(including) 1 and 20");
		}
		return true;
	}
	throw ParsingException("Error(Conversion failed): 'A' <prioridade> failed to be converted to int");
	return false;
}

bool Cli::_validateR(void) const {
	std::vector<std::string> toParse = this->_splitString(this->_userInput);
	this->_validateCommand(toParse[0]);
	if (toParse.size() != 2)
		throw ParsingException("Error(invalid number of arguments): 'R' must be followed by <identificador>");
	return true;
}

bool Cli::_validateX(void) const {
	std::vector<std::string> toParse = this->_splitString(this->_userInput);
	this->_validateCommand(toParse[0]);
	if (toParse.size() != 2)
		throw ParsingException("Error(invalid number of arguments): 'X' must be followed by <prioridade>");
	std::istringstream iss(toParse[1]);
	int val;
	if (iss >> val) {
		if (val < 0 || val > 20){
			throw ParsingException("Error(Out of range): 'X' <prioridade> must be between(including) 1 and 20");
		}
		return true;
	}
	throw ParsingException("Error(Conversion failed): 'X' <prioridade> failed to be converted to int");
	return false;
}

bool Cli::_validateP(void) const {
	return this->_validateCommand(this->_userInput);
}

bool Cli::_validateQ(void) const {
	return this->_validateCommand(this->_userInput);
}

void Cli::_procesUserInput(void) {
	try {
		this->_parseUserInput();
		this->_doAction(this->_createActionFromUserInput());
	}
	catch (const ParsingException &e) {
		std::cerr << e.what() << std::endl;
	}
}

void Cli::_doAction(Cli_Action_Obj pAction) {
	switch (pAction.E_action){
		case CLI_ACTION_A:
			this->_doAction_A(pAction.tokens);
			break;
		case CLI_ACTION_R:
			this->_doAction_R(pAction.tokens);
			break;
		case CLI_ACTION_X:
			this->_doAction_X(pAction.tokens);
			break;
		case CLI_ACTION_P:
			this->_doAction_P();
			break;
		case CLI_ACTION_Q:
			this->_doAction_Q();
			break;
		case CLI_ACTION_INVALID:
		default:
			std::cout << "Something very weird happened..." << std::endl;
			break;
	}
	this->_userInput.clear();
	return ;
}

void Cli::_doAction_A(std::vector<std::string> tokens){
	SomeObject toInsert(std::stoi(tokens[2]), tokens[1]);
	this->_pq.push(toInsert);
	std::cout << "(A)dded [" + tokens[1] + "]:[" + tokens[2] + "]" << std::endl;
}

void Cli::_doAction_R(std::vector<std::string> tokens){
	auto it = this->_pq.find(tokens[1]);
	if (it == this->_pq.end()){
		std::cout << "--- No items to remove." << std::endl;
		return ;
	}
	std::cout << "(R)emoved [" << it->getPrioprity() << "]:[" << it->getIdentifier() << "]" << std::endl;
	this->_pq.remove(it);
}

void Cli::_doAction_X(std::vector<std::string> tokens){
	auto it = this->_pq.find(std::stoi(tokens[1]));
	if (it == this->_pq.end()){
		std::cout << "--- No items to remove." << std::endl;
		return ;
	}
	std::cout << "e(X)cluded [" << it->getPrioprity() << "]:[" << it->getIdentifier() << "]" << std::endl;
	this->_pq.remove(it);
}

void Cli::_doAction_P(void){
	this->_pq.print_all();
}

void Cli::_doAction_Q(void){
	this->_pq.print_all();
	this->_exitIssued = true;
}

Cli_Action_Obj Cli::_createActionFromUserInput(void){
	Cli_Action_Obj ret;
	ret.tokens = this->_splitString(this->_userInput);
	ret.E_action = this->_actionStringToEnum(ret.tokens[0]);
	return ret;
}

	CLI_ACTION Cli::_actionStringToEnum(std::string token) {
		if (token.empty())
			return CLI_ACTION_INVALID;
	switch (token.front()){
		case 'A':
			return CLI_ACTION_A;
		case 'R':
			return CLI_ACTION_R;
		case 'X':
			return CLI_ACTION_X;
		case 'P':
			return CLI_ACTION_P;
		case 'Q':
			return CLI_ACTION_Q;
		default:
			return CLI_ACTION_INVALID;
	}
	return CLI_ACTION_INVALID;
}

bool Cli::_getUserInput(void){
	std::cout << "PriorityQueue: ";
	std::getline(std::cin, this->_userInput);
	// ctrl+d issued...
	if (std::cin.eof())
		return false;
	return true;
}

void Cli::_clearUserInput(void){
	this->_userInput.clear();
}

bool Cli::shouldExit() const {
	return this->_exitIssued;
}

int Cli::loopStart(void){
	while(!this->shouldExit() && this->_getUserInput()){
		if (this->shouldExit())
			return 0;
		this->_procesUserInput();
	}
	return 0;
}