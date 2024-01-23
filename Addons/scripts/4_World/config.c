class JSON_CFG_D_MANAGER
{
	string WebHookLink							= "WebHookLink this";
	//for Adding your own Webhooks, specify here
}
class DiscordWebhookManagerConfig
{
	ref JSON_CFG_D_MANAGER DataCfg;
	FileHandle		m_LogFile;
	
	string cfgPath = "$profile:DiscordWebhookManager/config.json";
	string dirPath = "$profile:DiscordWebhookManager";
	
	void DiscordWebhookManagerConfig()
	{
		DataCfg = new JSON_CFG_D_MANAGER();
		CheckCfg();
	}
	
	void CheckCfg()
	{		
		if(!FileExist(dirPath))
		{
			CreateCfg(true);
		}
		else if(!FileExist(cfgPath)) 
		{
			CreateCfg(false);
		}
		else
		{
			ref JSON_CFG_D_MANAGER LoadDataCfg = new JSON_CFG_D_MANAGER();
			JsonFileLoader<JSON_CFG_D_MANAGER>.JsonLoadFile(cfgPath, LoadDataCfg);
			DataCfg = LoadDataCfg;
		}
	}
	
	void CreateCfg(bool MakeMainDirectory)
	{
		if(MakeMainDirectory)
			MakeDirectory(dirPath);
		ref JSON_CFG_D_MANAGER NewDataCfg = new JSON_CFG_D_MANAGER();
		JsonFileLoader<JSON_CFG_D_MANAGER>.JsonSaveFile(cfgPath, NewDataCfg);
		DataCfg = NewDataCfg;
	}
}
static ref DiscordWebhookManagerConfig g_DiscordWebhookManagerConfig;
static ref DiscordWebhookManagerConfig GetDiscordManagerConfig()
{
    if(!g_DiscordWebhookManagerConfig) g_DiscordWebhookManagerConfig = new DiscordWebhookManagerConfig();
    return g_DiscordWebhookManagerConfig;
}