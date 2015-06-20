/*
	Program name:
		Chatterbot Eliza

    Description:
		These program is an Eliza like chatterbot,bots like Eliza are the results
		of researchs in Artificial Intelligence (more specificly: in NLP and NLU)
		NLP: Natural Language Processing, NLU: Natural Language Understanding
		The first chatterbot was published in 1966 by Joseph Weizenbaum a professor of MIT.
		(http://i5.nyu.edu/~mm64/x52.9265/january1966.html)
		And also,most of the chatterbots that have been written this days are largely based
		on the original chatterbot Eliza that was written by Joseph Weizenbaum which means
		that they use some appropriate keywords to select the responses to generate
		when they get new inputs from the users. More generaly,the technique that are 
		in use in a "chatterbot database" or "script file" to represent the chatterbot
		knowledge is known as "Case Base Reasoning" or CBR. A very good example of an Eliza
		like chatterbot would be "Alice",these program has won the Loebner prize for most
		human chatterbot three times (www.alicebot.org). The goal of NLP and NLU is to create
		programs that are capable of understanding natural languages and also capable
		of processing it to get input from the user by "voice recognition" or to produce
		output by "text to speech". During the last decades there has been a lot of progress
		in the domains of "Voice Recognition" and "Text to Speech",however the goal of NLU
		that is to make software that are capable of showing a good level of understanding
		of "natural languages" in general seems quiet far to many A.I experts. The general
		view about this subject is that it would take at list many decades before any computer 
		can begin to really understand "natural language" just as the humans do.
		These code is Copyrighted and has limited warranty.
	
	Features of the Program:
		There are many interesting features in the current program,these chatterbot
		is capable of avoiding repetitions when selecting new responses,it can also
		follow the context of a conversation with a user. When the programs detect
		new keywords that are not part of the "script file", it saves it on the file
		"unknown.txt" and finaly it simulates a "human typist" when displaying responses
		on the screen. Actualy,there are many more features in the program,you will be
		capable of finding them by reading the "source code".

	Author:
		Gonzales Cenelia

	Website:
		www.ai-search.4t.com
*/
	
#include "eliza.h"


// gets input from the user
void Eliza::get_input() {
	std::cout << "\n\n>";
	m_sPrevInput = m_sInput;
	std::getline(std::cin, m_sInput);
}

// removes punctuation from the input
// and do some more preprocessing
void Eliza::preProcessInput() {
	if(m_sInput.length() > 0) {
		tok.cleanString(m_sInput, " ?!,;");
		trimRight(m_sInput, '.');
		UpperCase(m_sInput);
	}
}

void Eliza::start() {
	selectResponse(signOn);
	print_response();
}

// prints the bot response on the screen
void Eliza::print_response() {
	if(m_sResponse.length() > 0) {
		//std::cout << m_sResponse << std::endl << std::endl;
		print_string(m_sResponse.c_str(), time_delay, linePos);
		linePos += 3;
	}
}

inline void Eliza::dump_data() {
	if(current_data.keywords.size() > 0) {
		database.push_back(current_data);
		clear();
	}
}

// select responses randomly from a list of responses
inline void Eliza::selectResponse( vstring v ) {
	shuffle(v, v.size());
	m_sResponse = v[0];
}

inline void Eliza::extract_suffix() {
	m_sSuffix.erase();
	int pos = m_sInput.find(m_sKeyWord);
	if(pos != std::string::npos) {
		pos += m_sKeyWord.length();
		m_sSuffix = m_sInput.substr(pos, m_sInput.length() - pos);
	}
}

// helper function for the procedure "find_keyword"
inline bool Eliza::isGoodKey(const std::string key, const std::string bkey, int pos, int bestp) const{
	if(pos != std::string::npos && (key.length() > bkey.length() || 
		(pos == bestp && key.length() == bkey.length()) ||
		(pos < bestp && key.length() == bkey.length()))) {
		return 1;
	}
	return 0;
}
	
void Eliza::clear() {
	current_data.contexts.clear();
	current_data.keywords.clear();
	current_data.responses.clear();
	current_data.cmd.clear();
}

// these function finds and display a response 
// to the current input of the user.
void Eliza::respond() {
	preProcessInput();
	if(m_sResponse.length() > 0) {
		previous_responses.push(m_sResponse);
	}
	m_sPrevResponse = m_sResponse;
	if(m_sInput.length() == 0) {
		selectResponse(nullResponse);
		response_list = nullResponse;
	} else {
		if(m_sInput == m_sPrevInput) {
			selectResponse(inputRepeat);
			response_list = inputRepeat;
		} else {
			find_keyword();
			if(m_sKeyWord == "MY" || m_sKeyWord.find("MY ") != std::string::npos) {
				std::string temp = m_sInput;
				transpose_sentence(temp);
				memory.push(" " + temp);
			}
			if(response_list.size() > 0) {
				selectResponse(response_list);
				if(m_sResponse.find("*") != std::string::npos) {
					extract_suffix();
					if(m_sSuffix.length() > 0) {
						transpose_sentence(m_sSuffix);
						trimRight(m_sSuffix, ' ');
						m_sSuffix.insert(0, " ");
					}
					while(replace(m_sResponse, "*", m_sSuffix))
						;
				}
			} else {
				unknownSentences.push_back(m_sInput);
				selectResponse(noKeyWord);
				response_list = noKeyWord;
			}
		}
	}
	if(m_sResponse.find("BYE") != std::string::npos) {
		m_bQuitProgram = 1;
	}
	handle_repetition();
	//handleRepetition(response_list);
	//extendedResponseList.push_back(m_sResponse);
	print_response();
}

// function for finding the best keyword from database
// this function also handles context
void Eliza::find_keyword() {
	std::vector<data>::const_iterator iter;
	std::string bestKey = "";
	response_list.clear();

	int bestPos = -1;

	for(iter = database.begin(); iter != database.end(); ++iter) {
		verify_context((*iter).contexts);
		if(m_bGoodContext) {
			keyword_list = (*iter).keywords;
			size_t keyNum = keyword_list.size();

			for(int i = 0; i < keyNum; ++i) {
				std::string thisKey = keyword_list[i];

				bool bFrontWordsAloud = 0;
				bool bBackWordsAloud = 0;

				if(thisKey[0] != ' ') {
					bFrontWordsAloud = 1;
				} else {
					thisKey.erase(0, 1);
				}

				char lastChar = thisKey[thisKey.length()-1];
				if(lastChar != ' ') {
					bBackWordsAloud = 1;
				}

				int thisPos = (m_sInput + " ").find(thisKey);
				if(!bFrontWordsAloud && thisPos > 0) {
					continue;
				}

				if(!bBackWordsAloud && (thisPos + thisKey.length()) != m_sInput.length()+1) {
					continue;
				}

				char nextChar = m_sInput[thisPos + thisKey.length()];
				if(bBackWordsAloud && nextChar != ' ') {
					continue;
				}

				if(thisPos > 0 && bFrontWordsAloud) {
					char prevChar = m_sInput[thisPos-1];
					if(prevChar != ' ') {
						continue;
					}
				}

				if(isGoodKey(thisKey, bestKey, thisPos, bestPos)) {
					response_list = (*iter).responses;
					if((*iter).cmd.size() > 0) {
						command_list = (*iter).cmd;
					}
					bestKey = thisKey;
					bestPos = thisPos;
				}
			}
		}
	}

	m_sKeyWord = bestKey;
}

// handle the context of the conversation
// (the previous replies of the chatterbot)
void Eliza::verify_context(vstring vContext) { 

	m_bGoodContext = 1;
	
	size_t nNum = vContext.size();
	size_t nNum2 = previous_responses.size();
	
	if(!m_bLearning && (nNum == 0 || nNum2 == 0)) {
		return;
	} 

	if(m_bLearning && nNum == 0) {
		m_bGoodContext = 0;
		return;
	} 
	
	if(nNum2 < nNum) {
		nNum = nNum2;
	}

	std::stack<std::string> response_stack = previous_responses;
	
	for(int i = 0; i < nNum; ++i) {
		std::string thisResponse = response_stack.top();
		response_stack.pop();

		if(vContext[i].find("*") != std::string::npos) {
			while(replace(vContext[i], "*", m_sSuffix))
				;
		}

		if(thisResponse != vContext[i]) {
			m_bGoodContext = 0;
			return;
		}
	}
}

// this function makes sure that the bot doesn't
// repeats itself during the conversation
void Eliza::handleRepetition( vstring &vList ) {
	std::list<string>::iterator iter;
	int nListSize = vList.size();
	if(m_sPrevResponse.length() > 0) {
		for(;;) {
			if(m_sPrevResponse != m_sResponse || nListSize == 0) {
				break;
			} else if(nListSize > 0) {
				vList.erase(vList.begin());
				nListSize = vList.size();
				if(nListSize > 0) {
					m_sResponse = vList[0];
				}
			}
		}
	}
	if(nListSize == 0) {
		if(memory.size() > 0) {
			selectResponse(subjectRecall);
			replace(m_sResponse, "*", memory.top());
			memory.pop();
			nListSize = subjectRecall.size();
		} else {
			selectResponse(topicChanger);
			nListSize = topicChanger.size();
		}
	}
	if(nListSize > 0) {
		iter = std::find(extendedResponseList.begin(), 
			extendedResponseList.end(), m_sResponse);
		if(iter != extendedResponseList.end()) {
			if(vList.size() > 1) {
				vList.erase(vList.begin());
				m_sResponse = vList[0];
				handleRepetition(vList);
			}
		}
	}
}

inline void Eliza::handle_repetition() {
	while(bot_repeat()) {
		if(response_list.size() > 1) {
			response_list.erase(response_list.begin());
		} 
		else {
			break;
		}
		selectResponse(response_list);
	}
	vResponseLog.push_back(m_sResponse);
}

inline bool Eliza::bot_repeat() const {
	int pos = rfind(vResponseLog, m_sResponse);
	if(pos != -1) {
		return (pos + 1 < response_list.size());
	}
	return 0;
}

// transposes a word
bool Eliza::transpose( std::string &str ) const{
	std::string backup = str;
	std::string verbP1 = "";
	std::string verbP2 = "";
	std::string _str = " " + str + " ";
	for(int i = 0; i < m_nTransPosNum; ++i) {
		verbP1 = transpos_list[i].verbP1;
		verbP2 = transpos_list[i].verbP2;
		if(replace(_str, verbP1, verbP2)) {
			break;
		} else if(replace(_str, verbP2, verbP1)) {
			break;
		} 
	}
	str = _str.substr(1, _str.length() - 2);
	return backup != str;
}

// transpose a complete sentence
void Eliza::transpose_sentence( std::string &str ) {
	std::string thisWord = "";
	std::string tempStr = "";
	vstring stringToken;
	tok.setDelim(" !?,-");
	trimRight(str, '.');
	tok.tokenize(str, stringToken);
	int nTokNum = stringToken.size();
	for(int i = 0; i < nTokNum; ++i) {
		thisWord = stringToken[i];
		transpose(thisWord);
		tempStr += thisWord + " ";
	}
	str = tempStr;
}

void Eliza::print_current_data() {
	std::cout << "Current data:\n";
	std::cout << "Keywords,Contexts and responses:\n";
	int nKeyNum = current_data.keywords.size();
	for(int i = 0; i < nKeyNum; ++i) {
		std::cout << "   " << current_data.keywords[i] << std::endl;
		int nContextNum = current_data.contexts.size();
		for(int k = 0; k < nContextNum; ++k) {
			std::cout << "       " << current_data.contexts[k] << std::endl;
		}
		int nResponseNum = current_data.responses.size();
		for(int j = 0; j < nResponseNum; ++j) {
			std::cout << "      " << current_data.responses[j] << std::endl;
		}
	}
	std::cout << std::endl;
}

// prints database content on the screen
// for debugging purpose
void Eliza::print_database_content() {
	int nDatabaseSize = database.size();
	for(int i = 0; i < nDatabaseSize; ++i) {
		current_data = database[i];
		print_current_data();
	}
}

// loading database into memory
void Eliza::load_data() {
	std::fstream fin("script.txt", std::ios::in);
	if(fin.fail()) {
		throw string("can't open script file");
	}
	std::string buffer = "";
	std::string temp = "";
	int counter = 0, line = 0;
	transpos current_transpos;
	std::ostringstream os;
	char cSymbol = 0;
	char cPrevSymbol;
	while(std::getline(fin, buffer)) {
		line++;
		cPrevSymbol = cSymbol;
		cSymbol = buffer[0];
		if(temp.length() > 0 && cSymbol != ';' 
			&& cSymbol != cPrevSymbol) {
			temp.erase(temp.length() - 1, 1);
			comments.push_back(temp);
			temp.erase();
		}
		buffer.erase(0, 1);
		switch(cSymbol) {
		case ';':
			temp += ';';
			temp += buffer;
			temp += '\n';
			dump_data();
			break;
		case 'S':
			signOn.push_back(buffer);
			break;
		case 'T':
			++counter;
			buffer.erase(buffer.length() - 1, 1);
			if(counter % 2 == 1) {
				current_transpos.verbP1 = buffer;
			} else {
				current_transpos.verbP2 = buffer;
				transpos_list.push_back(current_transpos);
			}
			break;
		case 'K':
			buffer.erase(buffer.length() - 1, 1);
			current_data.keywords.push_back(buffer);
			break;
		case 'R':
			current_data.responses.push_back(buffer);
			break;
		case 'M':
			subjectRecall.push_back(buffer);
			break;
		case 'N':
			nullResponse.push_back(buffer);
			break;
		case 'X':
			noKeyWord.push_back(buffer);
			break;
		case 'Z':
			topicChanger.push_back(buffer);
			break;
		case 'W':
			inputRepeat.push_back(buffer);
			break;
		case 'C':
			current_data.contexts.push_back(buffer);
			break;
		case 'A':
			current_data.cmd.push_back(buffer);
			break;
		case 0:
			break;
		default:
			os << "(Script error) Unknown symbol: " << cSymbol << ", line: " << line;
			throw os.str();
		}
	}
	dump_data();
	m_nTransPosNum = transpos_list.size();
	fin.close();
}

// with these specific feature of the program,to make new updates to the
// script file,you just need to look at the "unknown.txt" file to search
// for new keyword that can be added to uptadate the chatterbot vocabulary
void Eliza::save_unknown_sentences() {
	size_t nSize = unknownSentences.size();
	if(nSize > 0) {
		std::fstream outfile("unknown.txt", std::ios::out | std::ios::app);
		for(int i = 0; i < nSize; ++i) {
			outfile << unknownSentences[i] << std::endl;
		}
		outfile.flush();
		outfile.close();
	}
}

// the functions below can be used to save
// the content of the dabase to the script file.
void Eliza::save_data() {
	scriptfile.open("script.txt", std::ios::out);
	if(scriptfile.fail()) {
		throw string("Can't save data");
	}
	saveComment(comments[0]);
	saveTopic(signOn, "S");
	
	saveComment(comments[1]);
	saveTransposTable();
	saveComment(comments[2]);
	
	saveTopic(nullResponse, "N");
	saveComment(comments[3]);
	
	saveTopic(subjectRecall, "M");
	saveComment(comments[4]);

	saveTopic(noKeyWord, "X");
	saveComment(comments[5]);

	saveTopic(topicChanger, "Z");
	saveComment(comments[6]);

	saveTopic(inputRepeat, "W");
	saveComment(comments[7]);

	saveKeyWords();

	scriptfile.flush();
	scriptfile.close();
}

void Eliza::saveTopic(const vstring vList, const std::string sSymbol) {
	int listSize = vList.size();
	for(int i = 0; i < listSize; ++i) {
		scriptfile << sSymbol << vList[i] << std::endl;
	}
}

void Eliza::saveComment(const string comment) {
	vstring vComment;
	vComment.push_back(comment);
	saveTopic(vComment, "");
}

void Eliza::saveTransposTable() {
	for(int i = 0; i < m_nTransPosNum; ++i) {
		scriptfile << "T" << transpos_list[i].verbP1 << "\"" << std::endl;
		scriptfile << "T" << transpos_list[i].verbP2 << "\"" << std::endl;
	}
}

void Eliza::saveKeyWords() {
	vstring keyWords, responses;
	vstring contexts, commands;
	int numOfKeyword, numOfResponse; 
	int numOfContext, numOfCommand;
	int nKeyWordsSize = database.size();
	for(int i = 0; i < nKeyWordsSize; ++i) {
		keyWords = database[i].keywords;
		contexts = database[i].contexts;
		responses = database[i].responses;
		commands = database[i].cmd;
		numOfKeyword = keyWords.size();
		numOfContext = contexts.size();
		numOfResponse = responses.size();
		numOfCommand = commands.size();
		for(int j = 0; j < numOfKeyword; ++j) {
			scriptfile << "K" << keyWords[j] << "\"" << std::endl;
		}
		for(int p = 0; p < numOfContext; ++p) {
			scriptfile << "C" << contexts[p] << std::endl;
		}
		for(int k = 0; k < numOfResponse; ++k) {
			scriptfile << "R" << responses[k] << std::endl;
		}
		for(int q = 0; q < numOfCommand; ++q) {
			scriptfile << "A" << commands[q] << std::endl;
		}
		scriptfile << ";" << std::endl;
	}
}

int main() {
	//std::cout << "Chatterbot - Eliza v1.0 Copyright (C) 2005 Gonzales Cenelia\n" << std::endl;
	
	try {
		Eliza eliza;
		eliza.load_data();
		eliza.start();
		while(!eliza.quit()) {
			eliza.get_input();
			eliza.respond();
		}
		if(eliza.learn()) {
			eliza.save_data();
		}
		eliza.save_unknown_sentences();
	}
	catch(std::string str) {
		std::cerr << "Exception: " << str << std::endl;
	}
	catch(...) {
		std::cout << "The program has stoped due to some unknown exception" << std::endl;
	}
	return 0;
}