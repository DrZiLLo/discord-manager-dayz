class DiscordObject_Embeds: DiscordObject
{
	protected ref map<string, ref array<string>> m_embed_fields;
	ref array<string> m_fields_json = new array<string>;
	
	override string DefaultJSONConvert()
	{
		return ConvertToJsonForEmbeds();
	}
	
	protected string ConvertToJsonForEmbeds()
	{
		string jsonData ="\"embeds\":[{";
		string fields_json = "";
		for( int i= 0; i < m_fields.GetKeyArray().Count(); i++)
		{
			jsonData+= FormatField(m_fields.GetKey(i));
		}
		for( int b= 0; b < m_fields_json.Count(); b++)
		{
			fields_json += m_fields_json.Get(b);
		}
		if(fields_json!="")
		{
			jsonData+="\"fields\":["+fields_json+"],";
		}
		jsonData+= "}],";
		return jsonData;
	}
	
	override protected string FormatField(string key)
	{
		if(key=="thumbnail" || key=="image") return DiscordHelper.GetJSONLineStringWithUrl(key, m_fields.Get(key));
		if(key=="footer"	|| key=="author") return DiscordHelper.GetJSONLineStringForOthers(key, m_fields.Get(key));
		return DiscordHelper.GetJSONLineString(key, m_fields.Get(key));
	}
	
	void SetEmbedField(string name, string value, bool inline = false)
	{
		ref DiscordObject_Fields m_field =  new DiscordObject_Fields(name, value, inline);
		m_fields_json.Insert(m_field.DefaultJSONConvert());
	}
}