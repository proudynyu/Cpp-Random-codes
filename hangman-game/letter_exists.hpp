#ifndef LETTER_EXISTS_H
#define LETTER_EXISTS_H

#include <string>

namespace Hangman {
	bool letter_exists(const char& letter, const std::string& secret);
}

#endif
