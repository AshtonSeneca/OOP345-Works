#ifndef SENECA_DICTIONARY_H
#define SENECA_DICTIONARY_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <memory>
#include "settings.h"


namespace seneca 
{
	enum class PartOfSpeech
	{
		Unknown,
		Noun,
		Pronoun,
		Adjective,
		Adverb,
		Verb,
		Preposition,
		Conjunction,
		Interjection,
	};

	struct Word
	{
		std::string m_word{};
		std::string m_definition{};
		PartOfSpeech m_pos = PartOfSpeech::Unknown;
	};
	class Dictionary
	{
		Word* m_words = nullptr;
		size_t m_size = 0;
		size_t m_capacity = 0;
	public:
		// default constructor
		Dictionary(){};
		// destructor
		~Dictionary();
		// loads from the file specified as parameter the collection of words, allocate enough memory
		Dictionary(const char* filename);
		// searches in the collection of words the one specified as a parameter
		void searchWord(const char* word);
		//copy assignment
		Dictionary& operator=(const Dictionary& src);
		//copy constructor
		Dictionary(const Dictionary& src);
		//move assignment
		Dictionary& operator=(Dictionary&& src) noexcept;
		//move constructor
		Dictionary(Dictionary&& src) noexcept;



	};

}
#endif // !SENECA_DICTIONARY_H
