class CfgPatches
{
	class DiscordWebhookManager
	{
		units[] = {};
		weapons[] = {};
		requiredVersion=0.1;
		requiredAddons[]={
			"DZ_Data"
		};
	};
	
	class DiscordWebhookManagerDefine {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {};
    };
};
class CfgMods
{
	class DiscordWebhookManager
	{
		dir = "DiscordWebhookManager";
	    picture = "";
	    action = "";
	    hideName = 0;
	    hidePicture = 1;
	    name = "DiscordWebhookManager";
	    credits = "76561198360529113";
	    author = "DiscordManager by Midnight-DayZ";
	    authorID = "76561198360529113";
	    version = "1.0";
	    extra = 0;
	    type = "mod";
		
		dependencies[] = {"Game", "World", "Mission"};
		
		defines[] = {
            "DiscordWebhookManager",
			"DiscordWebhookManagerDefine"
        };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"DiscordWebhookManager/scripts/3_Game"};
			};
			class worldScriptModule
			{
				files[] = {"DiscordWebhookManager/scripts/4_World"};
			};
			class missionScriptModule {
				value = "";
				files[] = {"DiscordWebhookManager/scripts/5_Mission"};
			};
		};
	};
};
