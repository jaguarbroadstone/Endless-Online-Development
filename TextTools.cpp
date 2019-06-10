#include "stdafx.h"
#include "TextTools.h"


TextTools::TextTools()
{
}

int TextTools::GetTextWidth(std::string szText, ID3DXFont* pFont)
{
	RECT rcRect = { 0,0,0,0 };
	if (pFont)
	{
		// calculate required rect
		pFont->DrawText(NULL, LPCWSTR(szText.c_str()), strlen(szText.c_str()), &rcRect, DT_CALCRECT,
			D3DCOLOR_XRGB(0, 0, 0));
	}

	// return width
	return rcRect.right - rcRect.left;
}

std::vector<TextTools::ChatContainer>* TextTools::AllChat = new std::vector<ChatContainer>();
std::vector<std::string> TextTools::SnipTextToWidth(std::string szText, int width, ID3DXFont* pFont)
{
	RECT rcRect = { 0,0,0,0 };
	std::string builder;
	int strpos = 0;
	std::vector<std::string> Words;
	std::vector<std::string> Sentences;
	///Generate list of words and then build a new string based on the width.
	for (int i = 0; i < szText.length(); i++)
	{
		if (szText[i] == ' ' || szText[i] == '\n')
		{
			Words.push_back(szText.substr(i - strpos, strpos + 1));
			strpos = 0;
			continue;
		}
		if (i == szText.length() - 1 && strpos > 0)
		{
			Words.push_back(szText.substr(i - strpos, strpos + 1));
			strpos = 0;
			continue;
		}
		strpos++;
	}

	std::string returnstr;
	std::string tempreturnstr;
	for (int i = 0; i < Words.size(); i++)
	{
		if (pFont)
		{
			// calculate required rect
			tempreturnstr += Words[i];
			pFont->DrawTextA(NULL, tempreturnstr.c_str(), tempreturnstr.size(), &rcRect, DT_CALCRECT, D3DCOLOR_XRGB(0, 0, 0));
			if (returnstr.find('\n') != std::string::npos)
			{
				Sentences.push_back(returnstr);
				returnstr.clear();
				tempreturnstr.clear();
				continue;
			}
			if (rcRect.right > width)
			{
				Sentences.push_back(returnstr);
				returnstr.clear();
				tempreturnstr.clear();
			}
			returnstr += Words[i];
		}
	}
	Sentences.push_back(returnstr);
	// return width
	return Sentences;
}
void TextTools::AppendChat(int ChatIndex, int width, std::string playername, std::string m_message, ID3DXFont* pFont, D3DCOLOR message_col)
{
	RECT rcRect = { 0,0,0,0 };
	std::string builder;
	int strpos = 0;
	std::vector<std::string> Words;
	std::vector<std::string> Sentences;
	///Generate list of words and then build a new string based on the width.
	for (int i = 0; i < m_message.length(); i++)
	{
		if (m_message[i] == ' ' || m_message[i] == '\n')
		{
			Words.push_back(m_message.substr(i - strpos, strpos + 1));
			strpos = 0;
			continue;
		}
		if (i == m_message.length() - 1 && strpos > 0)
		{
			Words.push_back(m_message.substr(i - strpos, strpos + 1));
			strpos = 0;
			continue;
		}
		strpos++;
	}

	std::string returnstr;
	std::string tempreturnstr;
	for (int i = 0; i < Words.size(); i++)
	{
		if (pFont)
		{
			// calculate required rect
			tempreturnstr += Words[i];
			std::string Space = playername + "  " + tempreturnstr;
			pFont->DrawTextA(NULL, Space.c_str(), Space.size(), &rcRect, DT_CALCRECT, D3DCOLOR_XRGB(0, 0, 0));
			if (returnstr.find('\n') != std::string::npos)
			{
				Sentences.push_back(returnstr);
				returnstr.clear();
				tempreturnstr.clear();
				continue;
			}
			if (rcRect.right > width)
			{
				Sentences.push_back(returnstr);
				returnstr.clear();
				tempreturnstr.clear();
			}
			returnstr += Words[i];
		}
	}
	Sentences.push_back(returnstr);
	ChatContainer newcontainer;
	newcontainer.CharacterName += playername;
	newcontainer.ChatIndex = ChatIndex;
	newcontainer.Message = Sentences;
	newcontainer.MessageLength = Sentences.size();
	newcontainer.message_col = message_col;
	AllChat->push_back(newcontainer);
}
void TextTools::AppendChat(int ChatIndex, int width, std::string playername, std::string m_message, ID3DXFont* pFont)
{
	RECT rcRect = { 0,0,0,0 };
	std::string builder;
	int strpos = 0;
	std::vector<std::string> Words;
	std::vector<std::string> Sentences;
	///Generate list of words and then build a new string based on the width.
	for (int i = 0; i < m_message.length(); i++)
	{
		if (m_message[i] == ' ' || m_message[i] == '\n')
		{
			Words.push_back(m_message.substr(i - strpos, strpos + 1));
			strpos = 0;
			continue;
		}
		if (i == m_message.length() - 1 && strpos > 0)
		{
			Words.push_back(m_message.substr(i - strpos, strpos + 1));
			strpos = 0;
			continue;
		}
		strpos++;
	}

	std::string returnstr;
	std::string tempreturnstr;
	for (int i = 0; i < Words.size(); i++)
	{
		if (pFont)
		{
			// calculate required rect
			tempreturnstr += Words[i];
			std::string Space = playername + "  " + tempreturnstr;
			pFont->DrawTextA(NULL, Space.c_str(), Space.size(), &rcRect, DT_CALCRECT, D3DCOLOR_XRGB(0, 0, 0));
			if (returnstr.find('\n') != std::string::npos)
			{
				Sentences.push_back(returnstr);
				returnstr.clear();
				tempreturnstr.clear();
				continue;
			}
			if (rcRect.right > width)
			{
				Sentences.push_back(returnstr);
				returnstr.clear();
				tempreturnstr.clear();
			}
			returnstr += Words[i];
		}
	}
	Sentences.push_back(returnstr);
	ChatContainer newcontainer;
	newcontainer.CharacterName += playername;
	newcontainer.ChatIndex = ChatIndex;
	newcontainer.Message = Sentences;
	newcontainer.MessageLength = Sentences.size();
	AllChat->push_back(newcontainer);
}
TextTools::~TextTools()
{
}
