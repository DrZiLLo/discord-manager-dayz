modded class MissionServer
{
	override void OnInit()
	{
		super.OnInit();
		GetDiscordManagerConfig();
		GetDiscordHook();
	}
}