class DiscordJSON
{
	ref DiscordObject_SettingsMessage m_settings;
	ref DiscordObject_Embeds m_Embeds;
		
	void SetSettings(DiscordObject_SettingsMessage msg_settings)
	{
		m_settings = msg_settings;
	}
	
	void SetEmbeds(DiscordObject_Embeds m_embeds_fnc)
	{
		m_Embeds = m_embeds_fnc;
	}
	
	string GetJSON()
	{
		string jsonData = "{";
		jsonData += GetModuleJSON(m_settings);
		jsonData += GetModuleJSON(m_Embeds);
		jsonData += "}";
		jsonData = DiscordHelper.RemoveExtraCommasJSON(jsonData);
		return jsonData;
	}
	
	string GetModuleJSON(ref DiscordObject module)
	{
		if (module)
		{
			return module.DefaultJSONConvert();
		}
		return "";
	}
}
static string TimeStampNow_Discord()
{
	int year, month, day, hour, minute, second;
	GetHourMinuteSecondUTC(hour, minute, second);
	GetYearMonthDayUTC(year, month, day);

	string strHour = hour.ToString(), strMin = minute.ToString();
	if (hour.ToString().Length() == 1)
		strHour = string.Format("%2%1", hour, 0);

	if (minute.ToString().Length() == 1)
		strMin = string.Format("%2%1", minute, 0);

	return(string.Format( "%3-%2-%1T%4:%5:00.000Z", day, month, year, strHour, strMin));
}