#include "dictionary.h"

namespace seneca
{

	Dictionary::~Dictionary()
	{
		delete[] m_words; // Free allocated memory
	}

	// Constructor that loads words from a file
    Dictionary::Dictionary(const char* filename) {
        std::ifstream file(filename);
        if (!file) {
            std::cerr << "Failed to open file: " << filename << std::endl;
            return;
        }

        // First count the number of words in the file
        std::string line;
        while (std::getline(file, line)) {
            m_size++;
        }

        file.clear();       // Clear EOF flag
        file.seekg(0);     // Rewind to the beginning of the file

        m_words = new Word[m_size]; // Allocate memory for the words

        // Read the words into the array
        size_t index = 0;
        while (std::getline(file, line) && index < m_size) {
            std::istringstream ss(line);
            std::string pos_str;
            std::getline(ss, m_words[index].m_word, ',');
            std::getline(ss, pos_str, ',');
            std::getline(ss, m_words[index].m_definition);

            // Determine the part of speech
            if (pos_str == "n.") {
                m_words[index].m_pos = PartOfSpeech::Noun;
            }
            else if (pos_str == "n. pl.") {
                m_words[index].m_pos = PartOfSpeech::Noun;
            }
            else if (pos_str == "adv.") {
                m_words[index].m_pos = PartOfSpeech::Adverb;
            }
            else if (pos_str == "a.") {
                m_words[index].m_pos = PartOfSpeech::Adjective;
            }
            else if (pos_str == "v.") {
                m_words[index].m_pos = PartOfSpeech::Verb;
            }
            else if (pos_str == "v. i.") {
                m_words[index].m_pos = PartOfSpeech::Verb;
            }
            else if (pos_str == "v. t.") {
                m_words[index].m_pos = PartOfSpeech::Verb;
            }
            else if (pos_str == "v. t. & i.") {
                m_words[index].m_pos = PartOfSpeech::Verb;
            }
            else if (pos_str == "prep.") {
                m_words[index].m_pos = PartOfSpeech::Preposition;
            }
            else if (pos_str == "pron.") {
                m_words[index].m_pos = PartOfSpeech::Pronoun;
            }
            else if (pos_str == "conj.") {
                m_words[index].m_pos = PartOfSpeech::Conjunction;
            }
            else if (pos_str == "interj.") {
                m_words[index].m_pos = PartOfSpeech::Interjection;
            }
            else {
                m_words[index].m_pos = PartOfSpeech::Unknown;
            }

            index++;
        }

        file.close();
    }

    void Dictionary::searchWord(const char* word) {
        bool foundFirstOccurrence = false;

        // Search for the word in the array
        for (size_t i = 0; i < m_size; i++) {
            // If the word is found
            if (m_words[i].m_word == word) {
                // If it is the first occurrence
                if (!foundFirstOccurrence) {
                    std::cout << m_words[i].m_word << " - "; // Print first occurrence without indentation
                    if (m_words[i].m_pos != PartOfSpeech::Unknown && g_settings.m_verbose) {
                        std::cout << "(";
                        switch (m_words[i].m_pos) {
                        case PartOfSpeech::Noun: std::cout << "Noun"; break;
                        case PartOfSpeech::Pronoun: std::cout << "Pronoun"; break;
                        case PartOfSpeech::Adjective: std::cout << "Adjective"; break;
                        case PartOfSpeech::Adverb: std::cout << "Adverb"; break;
                        case PartOfSpeech::Verb: std::cout << "Verb"; break;
                        case PartOfSpeech::Preposition: std::cout << "Preposition"; break;
                        case PartOfSpeech::Conjunction: std::cout << "Conjunction"; break;
                        case PartOfSpeech::Interjection: std::cout << "Interjection"; break;
                        }
                        std::cout << ") ";
                    }
                    std::cout << m_words[i].m_definition; // Print the definition of the first occurrence
                    std::cout << std::endl; // New line after the first occurrence
                    foundFirstOccurrence = true; // Mark the first occurrence as found
                }

                // Print all occurrences if `g_settings.m_show_all` is true
                if (g_settings.m_show_all) {
                    std::cout << "      - " << m_words[i].m_definition << std::endl; // Print with indentation for subsequent occurrences
                }
            }
        }

        // If no occurrences were found
        if (!foundFirstOccurrence) {
            std::cout << "Word '" << word << "' was not found in the dictionary." << std::endl;
        }
    }




	// Copy assignment
	Dictionary& Dictionary::operator=(const Dictionary& src)
	{
		if (this != &src)
		{
			delete[] m_words;
			m_words = new Word[src.m_size];
			m_size = src.m_size;
			m_capacity = src.m_size;
			for (size_t i = 0; i < m_size; i++)
			{
				m_words[i] = src.m_words[i];
			}
		}
		return *this;
	}
	// Copy constructor
	Dictionary::Dictionary(const Dictionary& src)
	{
		m_words = new Word[src.m_size];
		m_size = src.m_size;
		m_capacity = src.m_size;
		for (size_t i = 0; i < m_size; i++)
		{
			m_words[i] = src.m_words[i];
		}
	}
	// Move assignment
	Dictionary& Dictionary::operator=(Dictionary&& src) noexcept
	{
		if (this != &src)
		{
			delete[] m_words;
			m_words = src.m_words;
			m_size = src.m_size;
			m_capacity = src.m_capacity;
			src.m_words = nullptr;
			src.m_size = 0;
			src.m_capacity = 0;
		}
		return *this;
	}
	// Move constructor
	Dictionary::Dictionary(Dictionary&& src) noexcept
	{
		m_words = src.m_words;
		m_size = src.m_size;
		m_capacity = src.m_capacity;
		src.m_words = nullptr;
		src.m_size = 0;
		src.m_capacity = 0;
	}


}
