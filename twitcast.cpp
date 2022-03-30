/*
This code is based on Niseyami's program: https://github.com/niseyami/twitcasting-dl
Author: Vivian Chantraine
*/
#include <iostream>
#include <string>
#ifdef _WIN32
#include <io.h>
#define F_OK 0
#define access _access
#else
#include <unistd.h>
#endif

int main()
{
#ifdef _WIN32
	begin:
	system("cls");
	std::string s;
	std::cout << "====================" << std::endl;
	std::cout << "TWITCASTING DOWNLOAD" << std::endl;
	std::cout << "====================" << std::endl;
	if (access("C:/Program Files (x86)/ffmpeg/ffmpeg.exe", F_OK) == 0 || access("C:/Program Files/ffmpeg/ffmpeg.exe", F_OK) == 0) {
		
		std::cout << "Paste this link in your browser's console \n\nlet a=[];for(let _ of JSON.parse(document.querySelector(\"video\")[\"dataset\"][\"moviePlaylist\"])[2])a.push(_.source?.url);console.log(a.join(\"\\n\"))\n\n";
		std::cout << "Enter the url of the video: ";
		std::cin >> s;
		std::cout << "Enter the name of the output video ('.mkv' will be added): ";
		std::string nameOut;
		std::cin >> nameOut;
		std::cin.ignore();
		std::cout << "Enter the user-agent of your browser: ";
		char input[200] = { 0 };
		std::cin.getline(input, 200);

		if (s.find("&spm=1") != std::string::npos)
		{
			
			int pos = s.find("&spm=1");
			std::string ss = "&spm=1";
			if (pos != std::string::npos)
			{
				s = s.erase(pos, ss.length());
				
			}
			
		}

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
		if (access("C:/Program Files/ffmpeg/ffmpeg.exe", F_OK) == 0) {
			std::cout << "You have to put ffmpeg.exe in Program Files x86, not Program Files..." << std::endl;
			std::cin.get();
			exit(0);
			//std::string request = "\"\"%ProgramFiles%/ffmpeg/ffmpeg.exe\" -protocol_whitelist file,http,https,tcp,tls,crypto -user_agent \"" + ressed + "\" -headers \"Origin: https://twitcasting.tv\" -i " + s + " -c copy " + nameOut + ".mkv \"";
			//system(request.c_str());
			//std::cin.get();
		}
		else if (access("C:/Program Files (x86)/ffmpeg/ffmpeg.exe", F_OK) == 0) {
			std::string request = "\"\"%ProgramFiles(x86)%/ffmpeg/ffmpeg.exe\" -protocol_whitelist file,http,https,tcp,tls,crypto -user_agent \"" + ressed + "\" -headers \"Origin: https://twitcasting.tv\" -i " + s + " -c copy " + nameOut + ".mkv \"";
			system(request.c_str());
			std::cin.get();
		}
		
		system("cls");
		std::cout << "===================\nDownload completed!\n===================\n";
		std::cout << "Do you want an mp4 version? [y/n]: ";
		std::string resp;
		std::cin >> resp;
		std::cin.ignore();
		if (resp == "y" || resp == "Y") {
			if (access("C:/Program Files/ffmpeg/ffmpeg.exe", F_OK) == 0) {
				std::string req = "\"\"%ProgramFiles%/ffmpeg/ffmpeg.exe\" -i " + nameOut + ".mkv -codec copy " + nameOut + ".mp4\"";
				system(req.c_str());
			}
			else if (access("C:/Program Files (x86)/ffmpeg/ffmpeg.exe", F_OK) == 0) {
				std::string req = "\"\"%ProgramFiles(x86)%/ffmpeg/ffmpeg.exe\" -i " + nameOut + ".mkv -codec copy " + nameOut + ".mp4\"";
				system(req.c_str());
			}
			
			std::string dest = "del " + nameOut + ".mkv";
			system(dest.c_str());
			system("cls");
			std::cout << "Do you want to download an other video? [y/n]: ";
			std::string resp2;
			std::cin >> resp2;
			std::cin.ignore();
			if (resp2 == "y" || resp2 == "Y") {
				goto begin;
			}
			else
			{
				exit(0);
			}
		}
		else
		{
			std::cout << "Do you want to download an other video? [y/n]: ";
			std::string resp2;
			std::cin >> resp2;
			std::cin.ignore();
			if (resp2 == "y" || resp2 == "Y") {
				goto begin;
			}
			else
			{
				exit(0);
			}
		}
	}
	else {
		std::cout << "!!!!ERROR!!!!\nffmpeg.exe not found!\nPlease, place it in C:/Program Files (x86)/ffmpeg/ffmpeg.exe or C:/Program Files/ffmpeg/ffmpeg.exe \n";
		std::cin.get();
		exit(0);
	}
#else
	begin:
	system("clear");
	std::string s;
	std::cout << "====================" << std::endl;
	std::cout << "TWITCASTING DOWNLOAD" << std::endl;
	std::cout << "====================" << std::endl;
	std::cout << "Paste this link in your browser's console \n\nlet a=[];for(let _ of JSON.parse(document.querySelector(\"video\")[\"dataset\"][\"moviePlaylist\"])[2])a.push(_.source?.url);console.log(a.join(\"\\n\"))\n\n";
	std::cout << "Enter the url of the video: ";
	std::cin >> s;
	std::cout << "Enter the name of the output video ('.mkv' will be added): ";
	std::string nameOut;
	std::cin >> nameOut;
	std::cin.ignore();
	std::cout << "Enter the user-agent of your browser: ";
	char input[200] = { 0 };
	std::cin.getline(input, 200);

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
	system(request.c_str());
	system("clear");
	std::cout << "===================\nDownload completed!\n===================\n";
	std::cout << "Do you want an mp4 version? [y/n]: ";
	std::string resp;
	std::cin >> resp;
	std::cin.ignore();
	if (resp == "y" ||  resp == "Y") {
		std::string req = "ffmpeg -i " + nameOut + ".mkv -codec copy " + nameOut + ".mp4";
		system(req.c_str());
		std::string dest = "rm " + nameOut + ".mkv";
		system(dest.c_str());
		system("clear");
		std::cout << "Do you want to download an other video? [y/n]: ";
		std::string resp2;
		std::cin >> resp2;
		std::cin.ignore();
		if (resp2 == "y" || resp2 == "Y") {
				goto begin;
			}
			else
			{
				exit(0);
			}
		}
		else
		{
			std::cout << "Do you want to download an other video? [y/n]: ";
			std::string resp2;
			std::cin >> resp2;
			std::cin.ignore();
			if (resp2 == "y" || resp2 == "Y") {
				goto begin;
			}
			else
			{
				exit(0);
			}
		}
#endif

	return 0;
}
