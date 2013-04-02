/*
*Made by - Ghostcrawler336 From ac-web.org
*/
 

#include "ScriptPCH.h"
#define TOKEN_ID   988888

 
class Level_NPC : public CreatureScript
{
public:
Level_NPC() : CreatureScript("Level_NPC") {}
bool OnGossipHello(Player* pPlayer, Creature* _creature)
{

  pPlayer->ADD_GOSSIP_ITEM(10, "Level 90(50 Title Token)", GOSSIP_SENDER_MAIN, 1);
  pPlayer->ADD_GOSSIP_ITEM(10, "Level 95(100 Title Token)", GOSSIP_SENDER_MAIN, 2);
  pPlayer->ADD_GOSSIP_ITEM(10, "Level 100(150 Title Token)", GOSSIP_SENDER_MAIN, 3);
  pPlayer->ADD_GOSSIP_ITEM(10, "Level 150(200 Title Token)", GOSSIP_SENDER_MAIN, 4);
  pPlayer->ADD_GOSSIP_ITEM(10, "Level 200(250 Title Token)", GOSSIP_SENDER_MAIN, 5);
  pPlayer->ADD_GOSSIP_ITEM(10, "Level 210(200 Title Token)", GOSSIP_SENDER_MAIN, 6);
  pPlayer->ADD_GOSSIP_ITEM(10, "Level 220(300 Title Token)", GOSSIP_SENDER_MAIN, 7);
  pPlayer->ADD_GOSSIP_ITEM(10, "Level 240(400 Title Token)", GOSSIP_SENDER_MAIN, 8);
  pPlayer->ADD_GOSSIP_ITEM(10, "Level 250(450 Title Token)", GOSSIP_SENDER_MAIN, 9);
  pPlayer->ADD_GOSSIP_ITEM(10, "Level 255(500 TTitle Token)", GOSSIP_SENDER_MAIN, 10);
 
                pPlayer->PlayerTalkClass->SendGossipMenu(907, _creature->GetGUID());
                return true;
}
bool OnGossipSelect(Player* pPlayer, Creature* _creature, uint32 uiSender, uint32 uiAction)
{
                 pPlayer->PlayerTalkClass->ClearMenus();
                       
                                switch(uiAction)
                                {      
                                                           
                         case 1: // Level 10 - required 1 token
                           if (pPlayer->HasItemCount(TOKEN_ID, 50, true))
                           {
                               pPlayer->GiveLevel(90);
                          pPlayer->DestroyItemCount(TOKEN_ID, 50, true);
                                       _creature->MonsterWhisper("Your now Level 90!", pPlayer->GetGUID());
                                        pPlayer->CLOSE_GOSSIP_MENU();
                                }
                                else
                                {
                                  pPlayer->CLOSE_GOSSIP_MENU();
                                  _creature->MonsterWhisper("You don't have the required token.", pPlayer->GetGUID());
                                      return false;
                                }
                                break;

                                                               
                                                               
                     case 2: // Level 20 - required t tokens
              if (pPlayer->HasItemCount(TOKEN_ID, 100, true))
                   {
                    pPlayer->GiveLevel(95);
             pPlayer->DestroyItemCount(TOKEN_ID, 100, true);
              _creature->MonsterWhisper("Your now Level 95!", pPlayer->GetGUID());
             pPlayer->CLOSE_GOSSIP_MENU();
         }
           else
              {
             pPlayer->CLOSE_GOSSIP_MENU();
           _creature->MonsterWhisper("You don't have the required token.", pPlayer->GetGUID());
                return false;
             }
               break;
 


                                 
                         case 3: // Level 30 - required  3 tokens
        if (pPlayer->HasItemCount(TOKEN_ID, 150, true))
             {
        pPlayer->GiveLevel(100);
        pPlayer->DestroyItemCount(TOKEN_ID, 150, true);
         _creature->MonsterWhisper("Your now Level 100!", pPlayer->GetGUID());
         pPlayer->CLOSE_GOSSIP_MENU();
        }
        else
        {
         pPlayer->CLOSE_GOSSIP_MENU();
         _creature->MonsterWhisper("You don't have the required token.", pPlayer->GetGUID());
         return false;
        }
        break;
		

 
        case 4: // Level 40 - required 4 tokens
        if (pPlayer->HasItemCount(TOKEN_ID, 200, true))
        {
         pPlayer->GiveLevel(150);
         pPlayer->DestroyItemCount(TOKEN_ID, 200, true);
         _creature->MonsterWhisper("Your now Level 150!", pPlayer->GetGUID());
         pPlayer->CLOSE_GOSSIP_MENU();
        }
        else
        {
         pPlayer->CLOSE_GOSSIP_MENU();
         _creature->MonsterWhisper("You don't have the required token.", pPlayer->GetGUID());
         return false;
        }
        break;
               
               
                   case 5: // Level 50 - required  5 tokens
        if (pPlayer->HasItemCount(TOKEN_ID, 250, true))
        {
         pPlayer->GiveLevel(200);
         pPlayer->DestroyItemCount(TOKEN_ID, 250, true);
         _creature->MonsterWhisper("Your now Level 200!", pPlayer->GetGUID());
         pPlayer->CLOSE_GOSSIP_MENU();
        }
        else
        {
         pPlayer->CLOSE_GOSSIP_MENU();
         _creature->MonsterWhisper("You don't have the required token.", pPlayer->GetGUID());
         return false;
        }
        break;
               
             
               
                                   case 6: // Level 60 - required  6 tokens
        if (pPlayer->HasItemCount(TOKEN_ID, 300, true))
        {
         pPlayer->GiveLevel(210);
         pPlayer->DestroyItemCount(TOKEN_ID, 300, true);
         _creature->MonsterWhisper("Your now Level 210!", pPlayer->GetGUID());
         pPlayer->CLOSE_GOSSIP_MENU();
        }
        else
        {
         pPlayer->CLOSE_GOSSIP_MENU();
         _creature->MonsterWhisper("You don't have the required token.", pPlayer->GetGUID());
         return false;
        }
        break;
               
                
               
                case 7: // Level 70 - required  7 tokens
        if (pPlayer->HasItemCount(TOKEN_ID, 400, true))
        {
         pPlayer->GiveLevel(220);
         pPlayer->DestroyItemCount(TOKEN_ID, 400, true);
         _creature->MonsterWhisper("Your now Level 220!", pPlayer->GetGUID());
         pPlayer->CLOSE_GOSSIP_MENU();
        }
        else
        {
         pPlayer->CLOSE_GOSSIP_MENU();
         _creature->MonsterWhisper("You don't have the required token.", pPlayer->GetGUID());
         return false;
        }
        break;
            
               
                                case 8: // Level 80 - required  8 tokens
        if (pPlayer->HasItemCount(TOKEN_ID, 400, true))
        {
         pPlayer->GiveLevel(240);
         pPlayer->DestroyItemCount(TOKEN_ID, 400, true);
         _creature->MonsterWhisper("Your now Level 240!", pPlayer->GetGUID());
         pPlayer->CLOSE_GOSSIP_MENU();
        }
        else
        {
         pPlayer->CLOSE_GOSSIP_MENU();
         _creature->MonsterWhisper("You don't have the required token.", pPlayer->GetGUID());
         return false;
        }
        break;            
	               
                                case 9: // Level 255 - required  500 tokens
        if (pPlayer->HasItemCount(TOKEN_ID, 450, true))
        {
         pPlayer->GiveLevel(250);
         pPlayer->DestroyItemCount(TOKEN_ID, 450, true);
         _creature->MonsterWhisper("Your now Level 250!", pPlayer->GetGUID());
         pPlayer->CLOSE_GOSSIP_MENU();
        }
        else
        {
         pPlayer->CLOSE_GOSSIP_MENU();
         _creature->MonsterWhisper("You don't have the required token.", pPlayer->GetGUID());
         return false;
        }
        break;
		               
                                case 10: // Level 255 - required  500 tokens
        if (pPlayer->HasItemCount(TOKEN_ID, 500, true))
        {
         pPlayer->GiveLevel(255);
         pPlayer->DestroyItemCount(TOKEN_ID, 500, true);
         _creature->MonsterWhisper("Your now Level 255!", pPlayer->GetGUID());
         pPlayer->CLOSE_GOSSIP_MENU();
        }
        else
        {
         pPlayer->CLOSE_GOSSIP_MENU();
         _creature->MonsterWhisper("You don't have the required token.", pPlayer->GetGUID());
         return false;
        }
        break;
}
};
void AddSC_Level_NPC()
{
        new Level_NPC();
}