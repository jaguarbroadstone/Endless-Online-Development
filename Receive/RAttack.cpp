#include "Handler.h"


CLIENT_F_FUNC(Attack)
{	
		switch(action)
		{		
			case PACKET_PLAYER: 
				{
					int ID = reader.GetShort();
					int Dir = reader.GetChar();
					int findid = (ID);
					if (findid >= 0)
					{
						int procDirection = Dir;
						if (Dir == 1)
						{
							procDirection = 3;
						}
						if (Dir == 2)
						{
							procDirection = 1;
						}
						if (Dir == 3)
						{
							procDirection = 2;
						}

						game->map->m_Players[findid]->direction = procDirection;
						game->map->m_Players[findid]->SetStance(CharacterModel::PlayerStance::BluntAttacking);
					}
					
					break;
				}
			default:
				return false;
		}
		return true;
}