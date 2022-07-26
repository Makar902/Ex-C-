#include"Header.h"

int main()
{
	setlocale(LC_ALL, "");
	FileManger test;
	for (;;)
	{
		string before_ans;
		int us_answer = NULL;
		cout << "\t Menu:\n\t\t1).Show contents of drives C:\\ and D:\\\n\t\t2).Show the contents of a specific directory"
			<< "\n\t\t3).Rename object\n\t\t4).Create directory\n\t\t5).Delete directory whith files or inly 1 file\n\t\t6).File size(test)" << endl
			<< "\t\t7).Copy" << endl << "\t\t8).Ìove object" << endl << "\t\t9).Create user report(You can make only 9 report`s)" << endl
			<< "\t\t10).DOS command"<<"\n\t\t11).Mask search"<<"\n\t\t12).Folder size"
			<< endl;
		cin >> before_ans;
		us_answer = stoi(before_ans);
		if (us_answer == 1)
		{
			test.ShowDisk();
		}
		else if (us_answer == 2)
		{
			test.ShowCat();
		}
		else if (us_answer == 3)
		{
			test.Ren();
		}
		else if (us_answer == 4)
		{
			test.CreateCat();
		}
		else if (us_answer == 5)
		{
			cout << "Enter way to object wich you want  delete...-> ";
			cin.ignore();
			string sway;
			getline(cin, sway);
			filesystem::path way = sway;
			test.Delete(way);
		}
		else if (us_answer == 6)
		{
			test.FileSize();
		}
		else if (us_answer == 7)
		{
			test.Cop();
		}
		else if (us_answer == 8)
		{
			test.ChangeLoc();
		}
		else if (us_answer == 9)
		{
			string temp_way = test.Create_custom_report_in_txt_file();
			const char* com = temp_way.c_str();
			system(com);

		}
		else if (us_answer == 10)
		{
			test.Us_command();
		}
		else if (us_answer == 11)
		{
			wstring a;
			wstring bb;
			cout << "Enter name...> ";
			wcin.ignore();
			getline(wcin, a);
			cout << "\nEnter way...> ";
			/*wcin.ignore();
			getline(wcin, bb);*/
			//wcin >> bb;
			printf("\n");
			wcin >> bb;
			filesystem::path b = bb;
			test.FindFile(a,b);
		}
		else if (us_answer==12)
		{
			
			test.FolderSize();
		}
	}
	return NULL;
}

