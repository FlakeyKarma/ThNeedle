#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

class stuffReturn {
	private:
		vector<string>strSz, strPh, strS2, strDoc, spDoc;
		vector<long> intSz, intPh, intS2, intDoc, ipDoc;
		float progress = 0;
		int chk = 0, numCheck = 0;
		string loadBar, file0, file1;
		string verz = "v1.2.3";
	public:
		void setF(string s, bool b);
		vector<string> wordReturn(string s);
		void SeNDe(string s, vector<char> c, bool t);
		void nuMake(char c, vector<string> s);
		void outP(string file, int ac, vector<char> c);
		void redCheck(vector<string> s);
		bool GT1(string s);
		bool GUD(string f);
		void doCo(vector<char> c);
		void clr();
		void pauz();
		void progressBar(float x);
		string ver();
};