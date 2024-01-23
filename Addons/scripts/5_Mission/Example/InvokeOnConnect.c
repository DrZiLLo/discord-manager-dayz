modded class MissionServer
{
	override void OnMissionStart()
	{
		super.OnMissionStart();
		GetDiscordHook().SetAlias("example", GetDiscordManagerConfig().DataCfg.WebHookLink);//Example how to set Alias
		SendExampleWebhook();
	}
	
	void SendExampleWebhook()
	{
		ref DiscordJSON dataJSON = new DiscordJSON();
		
		ref DiscordObject_SettingsMessage msg_settings = new DiscordObject_SettingsMessage();
		msg_settings.SetField("username", "Webhook-Test"); 									//overrides the default username of the webhook
		msg_settings.SetField("avatar_url", "https://i.imgur.com/4M34hi2.png"); 			// overrides the default avatar of the webhook
		msg_settings.SetField("content", "TestContent"); 									// simple message, the message contains (up to 2000 characters)
		
		ref DiscordObject_Embed_Author m_embed_author = new DiscordObject_Embed_Author(); 	// embed author object
		m_embed_author.SetField("name", "Birdie♫"); 										//name of author
		m_embed_author.SetField("url", "https://www.reddit.com/r/cats/");					//url of author. If name was used, it becomes a hyperlink
		m_embed_author.SetField("icon_url", "https://i.imgur.com/R66g1Pe.jpg");				//url of author icon
		
		ref DiscordObject_Embed_Footer m_embed_footer = new DiscordObject_Embed_Footer();	//embed footer object
		m_embed_footer.SetField("text", "Woah! So cool! :smirk:");							//footer text, doesn't support Markdown
		m_embed_footer.SetField("icon_url", "https://i.imgur.com/fKL31aD.jpg");				//url of footer icon
		
		ref DiscordObject_Embeds m_embeds = new DiscordObject_Embeds();						//array of embed objects. That means, you can use more than one in the same body
		m_embeds.SetField("title", "Title");												// title of embed
		m_embeds.SetField("url", "https://google.com/");									// url of embed. If title was used, it becomes hyperlink
		m_embeds.SetField("description", "Text message. You can use Markdown here. *Italic* **bold** __underline__ ~~strikeout~~ [hyperlink](https://google.com) `code`"); // description text
		m_embeds.SetField("timestamp", TimeStampNow_Discord());								//time in footer. ///Example format: 2023-01-01T01:01:00.000Z/// OUTPUT: 01.01.2023 1:01
		m_embeds.SetField("color", "15258703");												// color code of the embed. You have to use Decimal numeral system, not Hexadecimal. Use color picker(https://www.spycolor.com/)
		m_embeds.SetField("thumbnail", "https://i.imgur.com/fKL31aD.jpg");					// url of thumbnail (embed thumbnail object)
		m_embeds.SetField("image", "https://i.imgur.com/fKL31aD.jpg");						//image url (embed image object)
		m_embeds.SetField("author", m_embed_author.ConvertToObject());						//embed author object
		m_embeds.SetField("footer", m_embed_footer.ConvertToObject());						//embed footer object
		m_embeds.SetEmbedField("Text", "More text", true);									// name of the field /// value of the field ///  if true, fields will be displayed in same line, but there can only be 3 max in same line or 2 max if you used thumbnail
		m_embeds.SetEmbedField("Even more text", "Yup", true);								// name of the field /// value of the field ///  if true, fields will be displayed in same line, but there can only be 3 max in same line or 2 max if you used thumbnail
		m_embeds.SetEmbedField("TESTTT", "okay...");										// name of the field /// value of the field
		m_embeds.SetEmbedField("Thanks!", "You're welcome :wink:");							// name of the field /// value of the field
		
		dataJSON.SetSettings(msg_settings);													
		dataJSON.SetEmbeds(m_embeds);
		
		GetDiscordHook().Send("example", dataJSON);
	}
}