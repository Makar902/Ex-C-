#pragma once

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <Windows.h>
#include <cstdlib>




using namespace std;


class FileManger
{
public:
	string Start;
	char for_us_rep;
	FileManger()
	{
		for_us_rep = '0';
		Start.clear();
		Start = "Strart work....";
		cout << Start << endl;
	}
	
	inline string Create_custom_report_in_txt_file()
	{
		string way;
		cout << "Enter way for new .txt file(Saving in a directory with other files may result in data loss)....> ";
		cin.ignore();
		getline(cin, way);
		for_us_rep++;

		if (for_us_rep == '9')
		{
			for (auto& p : filesystem::recursive_directory_iterator(way))
			{
				filesystem::remove(p.path());
				for_us_rep = '0';
			}
			for_us_rep = '0';
		}

		string f_way = way + "\\User_report" + for_us_rep + ".txt";
		ofstream oFile(f_way); 
		return f_way;	
	}
	inline void Us_command()
	{
		string temp;
		cout << "Enter DOS command...> ";
		cin.ignore();
		getline(cin, temp);
		printf("\n");
		const char* com = temp.c_str();
		system(com);
	}
	inline void ShowCat()
	{
		string temp;
		cout << "Enter way...> ";
		cin.ignore();
		getline(cin, temp);
		printf("\n");
		string dir = "dir " + temp;
		const char* com = dir.c_str();
		system(com);
	}
	inline int ShowDisk()
	{

		system("dir C:\\");
		system("dir D:\\");
		//system("dir A:\\");
		return NULL;

	}
	void Ren()
	{
		 string sway;
		 cout << "Enter way to object which you want rename....> ";
			cin.ignore();
			getline(cin, sway);
			string new_name;
			cout << "\nEnter new name....> ";
			getline(cin, new_name);
			filesystem::path way = sway;
			printf("\n");
			filesystem::rename(way / way, way / new_name);
	}
	void CreateCat()
	{
		string name,sway;
		cout << "Enter way.....-> ";
		cin.ignore();
		getline(cin, sway);
		printf("\n");
		cout << "Enter name of new folder.....-> ";
		//cin >> name;
		cin.ignore();
		getline(cin, name);
		filesystem::path way = sway;
		filesystem::create_directories(way / name);
	}
	filesystem::path Delete(filesystem::path way)
	{			
		filesystem::remove_all(way);
		return way;
	}
	void FileSize()
	{
		cin.ignore();
		string sway;
		cout << "Enter way to file....-> ";
		getline(cin, sway);
		filesystem::path way = sway;
		cout << "File size = " << filesystem::file_size(way) << '\n';
  
	}
	void FolderSize()
	{
		//Никаких других понятных реализаций я не смог найти
		string way;
		cout << "Enter way to folder...> ";
		printf("\n");
		cin.ignore();
		getline(cin, way);
		string dir = "dir ";
		string prev_com = dir + way;
		const char* com = prev_com.c_str();
		system(com);
	}
	filesystem::path Cop()
	{
		string ff_way, ss_way;
		cout << "Enter way to object...> ";
		cin.ignore();
		getline(cin, ff_way);
		printf("\n");
		cout << "Enter second way.....> ";
		cin.ignore();
		getline(cin, ss_way);
		filesystem::path f_way = ff_way;
		filesystem::path s_way = ss_way;

		filesystem::copy(f_way, s_way, filesystem::copy_options::recursive);
		return f_way;
	
	}
	void ChangeLoc()
	{
		Delete(Cop());
	}
	int FindFile(wstring fileName, wstring startDirectory)
	{

		filesystem::path sPath(startDirectory + L"\\");

		for (auto& var : filesystem::recursive_directory_iterator(sPath, filesystem::directory_options::skip_permission_denied))
		{
			if (wstring(var.path().filename()).find(fileName) != wstring::npos)
			{
				wcout << var.path().filename() << endl;
			}
		}
		return 0;
	}
private:

};


