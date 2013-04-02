#include "ScriptPCH.h"

class System_OnPvPKill : public PlayerScript
{
	public: System_OnPvPKill() : PlayerScript("System_OnPvPKill")
		{
		}

	struct SystemInfo
	{
		uint32 KillStreak;
		uint32 LastGUIDKill;
	};

static std::map<uint32, SystemInfo> KillingStreak;
	
void OnPvPKill(Player *pKiller, Player *pVictim)
	{
		uint32 kGUID; 
		uint32 vGUID;
		kGUID = pKiller->GetGUID();
		vGUID = pVictim->GetGUID();	
		if(kGUID == vGUID)
		{
			return;
		}
		if(KillingStreak[kGUID].LastGUIDKill == vGUID)
		{
			return;
		}

		KillingStreak[kGUID].KillStreak++;
		KillingStreak[vGUID].KillStreak = 0;
		KillingStreak[kGUID].LastGUIDKill = vGUID;
		KillingStreak[vGUID].LastGUIDKill = 0;
		
		switch(KillingStreak[kGUID].KillStreak)
		{
			char msg[500];
			case 6: 				
				pKiller->AddItem(49426, 2);
				sprintf(msg, "[PvP System]: %s is on his RAMPAGE! of %s KILLSTREAKS!", pKiller->GetName(), KillingStreak[kGUID].KillStreak);
				sWorld->SendWorldText(LANG_SYSTEMMESSAGE, msg);
				break;
			case 12:
				pKiller->AddItem(49426, 2);
				sprintf(msg, "[PvP System]: %s killed %s and is on a RaMpAgE!", pKiller->GetName(), pVictim->GetName());
				sWorld->SendWorldText(LANG_SYSTEMMESSAGE, msg);
				break;
			case 18:    
				pKiller->AddItem(49426, 2);
				sprintf(msg, "[PvP System]: %s killed %s and is DOMINATING!", pKiller->GetName(), pVictim->GetName());
				sWorld->SendWorldText(LANG_SYSTEMMESSAGE, msg);		
				break;
			case 24:
				pKiller->AddItem(49426, 2);
				sprintf(msg, "[PvP System]: %s killed %s and is Godlike!", pKiller->GetName(), pVictim->GetName());
				sWorld->SendWorldText(LANG_SYSTEMMESSAGE, msg);
				break;
			case 30:
				pKiller->AddItem(49426, 2);
				sprintf(msg, "[PvP System]: %s killed %s and is Godlike!", pKiller->GetName(), pVictim->GetName());
				sWorld->SendWorldText(LANG_SYSTEMMESSAGE, msg);
				break;
			case 36:
				pKiller->AddItem(49426, 2);
				sprintf(msg, "[PvP System]: %s killed %s and is Unstopable!", pKiller->GetName(), pVictim->GetName());
				sWorld->SendWorldText(LANG_SYSTEMMESSAGE, msg);
				break;
			case 42:
				pKiller->AddItem(49426, 2);
				sprintf(msg, "[PvP System]: %s killed %s and is Unstopable!", pKiller->GetName(), pVictim->GetName());
				sWorld->SendWorldText(LANG_SYSTEMMESSAGE, msg);
				break;
			case 48:
				pKiller->AddItem(49426, 2);
				sprintf(msg, "[PvP System]: %s is on his RAMPAGE! %s KILLSTREAKS!", pKiller->GetName(), KillingStreak[kGUID].KillStreak);
				sWorld->SendWorldText(LANG_SYSTEMMESSAGE, msg);
				break;
		}
	}
};

void AddSC_System_OnPvPkill()
{
    new System_OnPvPKill();
}