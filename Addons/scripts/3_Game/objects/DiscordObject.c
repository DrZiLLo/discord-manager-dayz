class DiscordObject
{
	protected ref map<string, string> m_fields;
	
	void DiscordObject()
	{
		m_fields = new map<string, string>;
	}
	
	string DefaultJSONConvert()
	{
		return ConvertToJson();
	}
	
	string ConvertToObject()
	{
		string jsonData = "{";
		
		array<string> keys =  m_fields.GetKeyArray();
		
		for (int keyIndex = 0; keyIndex < keys.Count(); keyIndex++)
		{
			jsonData += FormatField(keys.Get(keyIndex));
		}
		jsonData+="},";
		return jsonData;
	}
	
	protected string ConvertToJson()
	{
		string jsonData = "";
		array<string> keys =  m_fields.GetKeyArray();
		
		for (int keyIndex = 0; keyIndex < keys.Count(); keyIndex++)
		{
			jsonData += FormatField(keys.Get(keyIndex));
		}
		jsonData += ConvertSpecialFields();
		return jsonData;
	}
	
	protected string ConvertSpecialFields() {return "";}
	
	protected string FormatField(string key)
	{
		return DiscordHelper.GetJSONLineString(key, m_fields.Get(key));
	}
	
	protected bool CanSetKey(string key)
	{
		return true;
	}
	
	void SetField(string field, string value)
	{
		if (CanSetKey(field))
		{
			m_fields.Set(field, value);
		}
	}
}
class DiscordObject_SettingsMessage : DiscordObject{}
class DiscordObject_Embed_Author: DiscordObject{}
class DiscordObject_Embed_Footer: DiscordObject{}