class DiscordObject_Fields : DiscordObject
{
	void DiscordObject_Fields(string name, string value, bool inline)
	{
		m_fields.Set("name", name);
		m_fields.Set("value", value);
		m_fields.Set("inline", inline.ToString());
	}
	
	override string DefaultJSONConvert()
	{
		return "{"+ ConvertToJson() + "},";
	}
}