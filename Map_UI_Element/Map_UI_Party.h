#pragma once
#include "..\Utilities/Button.h"
class Map_UI_Party
{
public:
	Button* UI_Element_PartyButton;

	//Map_UI_Inventory();
	Map_UI_Party(void* m_MapUI, void* m_Game);
	void Update();
	void Render();
	~Map_UI_Party();
};

