/************************************
*        Made by Parranoia          *
*        For Ghost-Gaming           *
*     Released By Ghostcrawler336   *
*************************************
*/
 
#include "ScriptPCH.h"
#include "Chat.h"
 
class cs_mall : public CommandScript
{
        public:
                cs_mall() : CommandScript("cs_mall"){}
 
        ChatCommand * GetCommands() const
        {
                static ChatCommand WorldChatCommandTable[] =
                {
                        {"mall",        0,                              false,          &HandleMallCommand,     "", NULL},
                        {NULL,          0,                              false,          NULL,                                           "", NULL}
                };
 
                return WorldChatCommandTable;
        }
 
        static bool HandleMallCommand(ChatHandler* handler, const char* /*args*/)
        {
                Player* player = handler->GetSession()->GetPlayer();
                if (player->isInCombat())
                {
                        player->GetSession()->SendNotification("You cannot use this in combat!");
                        return false;
                }
 
                if (player->GetTeam() == ALLIANCE)
                        player->TeleportTo(1, 9951.992188f,  2295.482910f, 1339.972534f, 1.554135f);             // Alliance mall coords (MAP, X, Y, Z, O)
                else
                        player->TeleportTo(1,  1380.092407f, -4369.104004f, 26.02462f, 3.364476f);              // Horde mall coords (MAP, X, Y, Z, O)
                return true;
        }
};
 
void AddSC_cs_mall()
{
        new cs_mall();
}