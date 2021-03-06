/*
*	npc_supporter
*	buffs, remove debuffs, CD .. etc.
*	By Dessus
*/




#include "ScriptPCH.h"


enum SupporterActions{
	SUPPORTER_ACTION_ADD_BUFF			= 1,
	SUPPORTER_ACTION_REMOVE_AURA		= 2,
	SUPPORTER_ACTION_REMOVE_COOLDOWN	= 3
};

enum SupporterBuffs{
	// paladin
	SUPPORTER_SPELL_GBLESSING_KING		= 43223,
	SUPPORTER_SPELL_GBLESSING_MIGHT		= 48934,
	SUPPORTER_SPELL_GBLESSING_WISDOM	= 48938,
	SUPPORTER_SPELL_GBLESSING_SANCTUARY	= 25899,

	// druid
	SUPPORTER_SPELL_MARK_OF_WILD		= 48469,
	SUPPORTER_SPELL_THORNS				= 53307,

	// mage
	SUPPORTER_SPELL_INTELLECT			= 42995,

	// priest
	SUPPORTER_SPELL_FORTITUDE			= 48162,
	SUPPORTER_SPELL_SPIRIT				= 48074,
	SUPPORTER_SPELL_SPROTECTION			= 48170

};

enum SupporterAuras{
	SUPPORTER_AURA_SATED				= 57724,
	SUPPORTER_AURA_EXHAUSTION			= 57723
	
};


class npc_supporter : public CreatureScript
{
public:
    npc_supporter() : CreatureScript("npc_supporter") { }

    bool OnGossipHello(Player *player, Creature *_creature)
    {
        addMainMenu(player, _creature);
        return true;
    }


    bool removeAura(Player *player, Creature *_creature, uint32 aura){        
			 player->RemoveAura(aura);   
			 return true;
    }

	void addMainMenu(Player* player, Creature* creature){
		if (player->isInCombat())
        {
            player->CLOSE_GOSSIP_MENU();
            creature->MonsterWhisper("You are in combat!", player->GetGUID());
        }
        else
        {
            player->ADD_GOSSIP_ITEM( 7, "Remove Sated & Exhaustion", GOSSIP_SENDER_MAIN, 1);
            player->ADD_GOSSIP_ITEM( 7, "Reset cooldowns", GOSSIP_SENDER_MAIN, 2);
			player->ADD_GOSSIP_ITEM( 7, "Restore Mana & HP", GOSSIP_SENDER_MAIN, 10);
        }

        player->SEND_GOSSIP_MENU(60000, creature->GetGUID());
	
	}


    bool OnGossipSelect(Player *player, Creature *_creature, uint32 sender, uint32 uiAction)
    {
		player->PlayerTalkClass->ClearMenus();
        if (sender == 1)
        {
            
            switch(uiAction)
            {   

			case 0:
				addMainMenu(player, _creature);
				break;
			
			case 10: // restore mana & hp
				player->SetPower(POWER_MANA, player->GetMaxPower(POWER_MANA));
				player->SetHealth(player->GetMaxHealth());
				 _creature->MonsterWhisper("Done!", player->GetGUID());
				 addMainMenu(player, _creature);
                 break;
            case 1: // sated exhaustion
                 removeAura(player, _creature, SUPPORTER_AURA_SATED);
				 removeAura(player, _creature, SUPPORTER_AURA_EXHAUSTION);
				 _creature->MonsterWhisper("Sated/Exhaustion has been removed!", player->GetGUID());
				 addMainMenu(player, _creature);
                 break;
			case 2: // reset cd
				 player->RemoveAllSpellCooldown();
				 _creature->MonsterWhisper("Your cooldowns has been reseted!", player->GetGUID());
				 addMainMenu(player, _creature);
                 break;


            default:
                break;
            }
        }
		else{
			if(uiAction == 2 /*buffs*/){
				removeAura(player, _creature, sender);
				_creature->AddAura(sender, player);	
				
			}
		
		}
        return true;
    }
};

void AddSC_npc_supporter()
{
    new npc_supporter();
}
