class System_OnKill : public PlayerScript
{
	public:
		System_OnKill() : PlayerScript("System_OnKill") {}

	void OnPVPKill(Player * Killer, Player * Victim)
	{
		uint64 KillerGUID = Killer->GetGUID();
		uint64 VictimGUID = Victim->GetGUID();

		struct KillStreak_Info
		{
			uint32 killstreak;
			uint64 lastkill;
		};

		static std::map<uint64, KillStreak_Info> KillStreakData;

		if( KillerGUID == VictimGUID || KillStreakData[KillerGUID].lastkill == VictimGUID )
			return;

		KillStreakData[KillerGUID].killstreak++;
		KillStreakData[KillerGUID].lastkill = VictimGUID;
		KillStreakData[VictimGUID].killstreak = 0;
		KillStreakData[VictimGUID].lastkill = 0;

		if( KillStreakData[KillerGUID].killstreak % 5 == 0 ) // send killstreak message every 5 kills
		{
			char msg[250];
			snprintf(msg, 250, "[Killstreak System]: %s killed %s and is Godlike!",Killer->GetName(), Victim->GetName(), KillStreakData[KillerGUID].killstreak);
			sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
		}
	}
};

void AddSC_PvP_System()
{
    new System_OnKill;
}