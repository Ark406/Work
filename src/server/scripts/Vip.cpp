/*
* Made By ???
* Error Fixed By Rochet2
* Released By Ghostcrawler
*EDITED BY yvoms
 
U got to add a Item with itemID ; 313370
If it was me i would make it soulbound, Couse u will be able to .vip activate <- gives u GM level 1 Meaning VIP.
*/
 
 
#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "MapManager.h"
#include "Chat.h"
#include "Common.h"
#include "Language.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
 
class vipcommands : public CommandScript
{
public:
    vipcommands() : CommandScript("vipcommands") { }
 
    ChatCommand* GetCommands() const
    {
        static ChatCommand vipCommandTable[] =
 
        {
            { "gm island",     0,     true, &HandleVipMallCommand,         "", NULL },
            { "vip changerace",    0,  false, &HandleChangeRaceCommand,             "", NULL },
            { "vip changefaction",  0,  false, &HandleChangeFactionCommand,                "", NULL },
            { "vip maxskills",      0,  false, &HandleMaxSkillsCommand,            "", NULL },
            { "vip customize",      0,  false, &HandleCustomizeCommand,            "", NULL },
            { "vip tele",           0,  false, &HandleTeleCommand,         "", NULL },
            { "vip morph",           0,  false, &HandleMorphCommand,               "", NULL },
                { "vip buffs",           0,  false, &HandleBuffCommand,            "", NULL },
                { "vip activate",           0,  false, &HandleActivateCommand,             "", NULL },
                { "vip getdrunk",       0,     false, &HandleGetDrunkCommand,         "", NULL },
        { "vip soberup",       0,     false, &HandleSoberUpCommand,         "", NULL },
            { "vip respawn",            0,      false, &HandleRespawnCommand,               "", NULL },
 
            { NULL,             0,                     false, NULL,                                          "", NULL }
        };
        static ChatCommand commandTable[] =
        {
            { "vip",        0,   true, NULL,      "",  vipCommandTable},
               { NULL,             0,                  false, NULL,                               "", NULL }
        };
        return commandTable;
    }
 
static bool HandleActivateCommand(ChatHandler * handler, const char * args)
{
        Player* player = handler->GetSession()->GetPlayer();
 
        if(player->GetSession()->GetSecurity() >= 1)
        {
                handler->PSendSysMessage("You already got VIP rank.");
                handler->SetSentErrorMessage(true);
                return false;
        }
 
        if(player->HasItemCount(313370, 1, false)) // Token ID, Count.
        {
                  PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_GET_ACCOUNT_BY_IP);
                  stmt->setUInt32(0, player->GetSession()->GetAccountId());
                  stmt->setUInt8(1, 1);
                  stmt->setInt32(2, -1);
                 LoginDatabase.Execute(stmt);
                player->DestroyItemCount(313370, 1, true, false); // Token ID, Count.
                handler->PSendSysMessage("Your VIP rank has been updated.Login to get it active");
                return true;
        }
        return true;
}
 
static bool HandleTeleCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;
 
        Player* me = handler->GetSession()->GetPlayer();
 
        // id, or string, or [name] Shift-click form |color|Htele:id|h[name]|h|r
        GameTele const* tele = handler->extractGameTeleFromLink((char*)args);
 
        if (!tele)
        {
            handler->SendSysMessage(LANG_COMMAND_TELE_NOTFOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }
 
        if (me->isInCombat())
        {
            handler->SendSysMessage(LANG_YOU_IN_COMBAT);
            handler->SetSentErrorMessage(true);
            return false;
        }
 
        MapEntry const* map = sMapStore.LookupEntry(tele->mapId);
        if (!map || map->IsBattlegroundOrArena())
        {
            handler->SendSysMessage(LANG_CANNOT_TELE_TO_BG);
            handler->SetSentErrorMessage(true);
            return false;
        }
 
        // stop flight if need
        if (me->isInFlight())
        {
            me->GetMotionMaster()->MovementExpired();
            me->CleanupAfterTaxiFlight();
        }
        // save only in non-flight case
        else
            me->SaveRecallPosition();
 
        me->TeleportTo(tele->mapId, tele->position_x, tele->position_y, tele->position_z, tele->orientation);
        return true;
                }
 
 
static bool HandleBuffCommand(ChatHandler * handler, const char * args)
    {
        Player * pl = handler->GetSession()->GetPlayer();
                if(pl->isInCombat())
                {
                        pl->GetSession()->SendNotification("You can't use this in combat!");
                        return false;
                }
                if(pl->InArena())
                {
                        pl->GetSession()->SendNotification("You can't use that item in an arena match!");
                        return false;
                }
                else
                pl->AddAura(48162, pl);
                pl->AddAura(48074, pl);
                pl->AddAura(48170, pl);
                pl->AddAura(43223, pl);
                pl->AddAura(36880, pl);
                pl->AddAura(467, pl);
                pl->AddAura(69994, pl);
                pl->AddAura(48469, pl);
                handler->PSendSysMessage("You have been buffed, enjoy!");
                return true;
 
    }
 
 
static bool HandlevipCommand(ChatHandler* handler, const char* args)
    {
 
        Player* me = handler->GetSession()->GetPlayer();
 
            me->Say("vip command?", LANG_UNIVERSAL);
            return true;
    }
 
static bool HandleMorphCommand(ChatHandler* handler, const char* args)
    {
        handler->GetSession()->GetPlayer()->SetDisplayId((uint32)atol((char*)args));
        return true;
    }
 
static bool HandleChangeRaceCommand(ChatHandler* handler, const char* args)
    {
 
        Player* me = handler->GetSession()->GetPlayer();
                me->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
                handler->PSendSysMessage("Relog to change race of your character.");
        return true;
    }
 
static bool HandleChangeFactionCommand(ChatHandler* handler, const char* args)
    {
 
        Player* me = handler->GetSession()->GetPlayer();
                me->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
                handler->PSendSysMessage("Relog to change faction of your character.");
        return true;
    }
 
static bool HandleMaxSkillsCommand(ChatHandler* handler, const char* args)
    {
 
        Player* me = handler->GetSession()->GetPlayer();
                me->UpdateSkillsForLevel();
                handler->PSendSysMessage("Your weapon skills are now maximized.");
        return true;
    }
 
static bool HandleCustomizeCommand(ChatHandler* handler, const char* args)
    {
 
        Player* me = handler->GetSession()->GetPlayer();
                me->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);
                handler->PSendSysMessage("Relog to customize your character.");
        return true;
    }
 
static bool HandleVipMallCommand(ChatHandler* handler, const char* args)
    {
 
        Player* me = handler->GetSession()->GetPlayer();
 
        if (me->isInCombat())
        {
            handler->SendSysMessage(LANG_YOU_IN_COMBAT);
            handler->SetSentErrorMessage(true);
            return false;
        }
 
        // stop flight if need
        if (me->isInFlight())
        {
            me->GetMotionMaster()->MovementExpired();
            me->CleanupAfterTaxiFlight();
        }
        // save only in non-flight case
        else
            me->SaveRecallPosition();
 
                me->TeleportTo(1,       16228.153320f, 16403.464844f,  -64.379883f,      3.316732f); // MapId, X, Y, Z, O
                return true;
    }
 
static bool HandleRespawnCommand(ChatHandler* handler, char const* /*args*/)
    {
        Player* player = handler->GetSession()->GetPlayer();
 
        Unit* target = handler->getSelectedUnit();
        if (player->GetSelection() && target)
        {
            if (target->GetTypeId() != TYPEID_UNIT || target->isPet())
            {
                handler->SendSysMessage(LANG_SELECT_CREATURE);
                handler->SetSentErrorMessage(true);
                return false;
            }
                        if(player->GetAreaId() == 4723)
                                return false;
 
            if (target->isDead())
                target->ToCreature()->Respawn();
            return true;
        }
 
        CellCoord p(Trinity::ComputeCellCoord(player->GetPositionX(), player->GetPositionY()));
        Cell cell(p);
        cell.SetNoCreate();
 
        Trinity::RespawnDo u_do;
        Trinity::WorldObjectWorker<Trinity::RespawnDo> worker(player, u_do);
 
        TypeContainerVisitor<Trinity::WorldObjectWorker<Trinity::RespawnDo>, GridTypeMapContainer > obj_worker(worker);
        cell.Visit(p, obj_worker, *player->GetMap(), *player, player->GetGridActivationRange());
 
        return true;
    }
 
static bool HandleGetDrunkCommand(ChatHandler* handler, const char* args)
        {
           
                        Player* me = handler->GetSession()->GetPlayer();
                                me->SetDrunkValue(100);
                                handler->PSendSysMessage("You're now drunk!");
                        return true;
        }
 
static bool HandleSoberUpCommand(ChatHandler* handler, const char* args)
        {
           
                        Player* me = handler->GetSession()->GetPlayer();
                                me->SetDrunkValue(1);
                                handler->PSendSysMessage("It's about time you sober up.");
                        return true;
}
       
};
 
void AddSC_vipcommands()
{
    new vipcommands();
}