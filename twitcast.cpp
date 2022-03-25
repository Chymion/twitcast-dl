/*
This code is based on Niseyami's program: https://github.com/niseyami/twitcasting-dl
Author: Vivian Chantraine
*/
#include <iostream>
#include <string>

int main()
{

	std::string s;
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
	std::cout << "====================" << std::endl;
	std::cout << "TWITCASTING DOWNLOAD" << std::endl;
	std::cout << "====================" << std::endl;
	std::cout <<"Paste this link in your browser's console \n\nlet a=[];for(let _ of JSON.parse(document.querySelector(\"video\")[\"dataset\"][\"moviePlaylist\"])[2])a.push(_.source?.url);console.log(a.join(\"\\n\"))\n\n";
	std::cout <<"Enter the url of the video: ";
	std::cin >> s;
	std::cout << "Name of the output video: ";
	std::string nameOut;
	std::cin >> nameOut;
	std::cin.ignore();
	std::cout << "Enter the user-agent of your browser:";
	char input[200] = {0};
	std::cin.getline(input,200);

	std::string g;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != '\\')
		{
			g += s[i];
		}
		else
		{
			
		}
	}
	
	std::string ressed;
	
	std::cout << input << std::endl;
	
	for (int i = 0; i < sizeof(input); i++)
	{
		if (input[i] == '\0') break;
		ressed.push_back(input[i]);
	}

	std::string request = "ffmpeg -protocol_whitelist file,http,https,tcp,tls,crypto -user_agent \"" + ressed + "\" -headers \"Origin: https://twitcasting.tv\" -i " + s + " -c copy " + nameOut + ".mkv ";

	std::cout << request << std::endl;

	system(request.c_str());


	return 0;
}