class DiscordHook
{
	ref map<string, string> m_alias;
	
	void DiscordHook()
	{
		m_alias = new map<string, string>;
	}
	
	bool Send(string alias, ref DiscordJSON data)
	{
		RestCallback cbx = new DiscordCallBack;
		RestApi clCore = GetRestApi();
		
		if (m_alias.Contains(alias))
		{
			if (!clCore)
			{
				clCore = CreateRestApi();
			}
			RestContext ctx = clCore.GetRestContext(m_alias.Get(alias));
			ctx.SetHeader("application/json");
			ctx.POST(cbx, "", data.GetJSON());
			return true;
		}
		return false;
	}
	
	void SetAlias(string alias, string url)//Set webhook path by name
	{
		if (!m_alias.Contains(alias))
		{
			m_alias.Set(alias, url);
		}
	}
	
	void RemoveAlias(string alias)//Remove webhook path by name
	{
		if (m_alias.Contains(alias))
		{
			m_alias.Remove(alias);
		}
	}
}

class DiscordCallBack : RestCallback
{
	override void OnError(int errorCode) {};
	override void OnTimeout() {};
	override void OnSuccess(string data, int dataSize) {};
};
static ref DiscordHook g_discordHook;
static ref DiscordHook GetDiscordHook()
{
	if (!g_discordHook) g_discordHook = new DiscordHook();
	return g_discordHook;
}