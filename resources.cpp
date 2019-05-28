#include "resources.h"

//Information output
void stuffReturn::outP(string file, int ac, vector<char> chr) {
	ifstream fil;
	bool def = false, rC = false, co = false, M = false, tw = false, th = false, toFil = false, w = false, pth = false;
	for(int i = 0; i < chr.size(); i++){
		switch(chr.at(i)){
			case 'A':
				def = true;
				break;
			case 'r':
				rC = true;
				tw = true;
				break;
			case 'd':
				co = true;
				th = true;
				chr.erase(chr.begin() + i);
				i--;
				break;
			case 'M':
				M = true;
				break;
			case 'w':
				w = true;
				toFil = true;
				break;
			case 'F':
				toFil = true;
				break;
			case 'P':
				pth = true;
				break;
		}
	}
	fil.open(file);
	bool isGud = true;
	isGud = GUD(file);
	fil.close();
	if(isGud){
		ofstream W;
		W.open("temp.txt");
		string temp = "";
		stuffReturn sR;
		sR.tw = tw;
		sR.th = th;
		sR.chr = chr;
		sR.setF(file, 1);
		//sR.rO"AA::outP::A::");
		sR.SeNDe(file, 0);
		if(rC){
			sR.SeNDe(file, 1);
		}
		//sR.rO"BB::outP::B::");
		vector<string> a = sR.strSz;
		vector<long> a0 = sR.intSz;
		if(!w)
			std::cout << "---------" << std::endl;
		/*
		if(rC){
			sR.strPh.clear();
			sR.intPh.clear();
		}
		*/
		if(co){
			sR.chr.push_back('d');
			sR.doCo(sR.chr);
		}
		long SET, numS;
		long LENg = 0, i = 0;
		string SP = " |--->  ";
		//sR.rO"CC::outP::C::");
		if(!M && def){
			if(w){
				for(int i = 0; i < sR.strSz.size(); i++){
					W << "STRSZ= " << sR.strSz.at(i) <<" " << sR.intSz.at(i) << endl;
				}
			}
			while (true) {
				SET = a0.at(i);
				if(!w)
					std::cout << "OUTPUT " << "=| " << a0.at(i) << " | :" << std::endl;
				while (SET == a0.at(i)) {
					if(!toFil)
						if(i % 20 == 0 && i > 0)
							sR.pauz();
					if(a0.at(i) <= 5 && !w){
						std::printf("\e[92m");
						std::cout << SP << a.at(i) << "\n" << " " << std::endl;
						std::printf("\e[0m");
					}
					if(a0.at(i) > 5 && a0.at(i) <= 10 && !w){
						std::printf("\e[93m");
						std::cout << SP << a.at(i) << "\n" << " " << std::endl;
						std::printf("\e[0m");
					}
					if(a0.at(i) > 10 && !w){
						std::printf("\e[31m");
						std::cout << SP << a.at(i) << "\n" << " " << std::endl;
						std::printf("\e[0m");
					}
					i++;
					if (a0.size() <= i)
						break;
				}
				LENg++;
				if (LENg == a.size() || i >= a0.size())
					break;
			}
		}
		if(rC){
			bool rCT = 0;
			if(w){
				for(int i = 0; i < sR.strPh.size(); i++){
					if(sR.intPh.at(i) > 1)
						W << "STRPH= " << sR.strPh.at(i) <<" " << sR.intPh.at(i) << std::endl;
				}
			}
			if(!M)
				if(!toFil)
					if(def)
						sR.pauz();
			a = sR.strPh;
			a0 = sR.intPh;
			if(!w)
				std::cout << "\n---------\n" << std::endl;
			LENg = 0, i = 0;
			if(!w){
				std::printf("\e[91m");
				std::printf("\e[4m");
				std::cout << "BEGIN::(RedCheck)" << std::endl;
				std::printf("\e[0m");
				std::printf("\e[91m");
			}
			while (true) {
				if(i >= a.size()){
					break;
				}
				SET = a0.at(i);
				if(a0.at(i) > 1){
					rCT = 1;
					if(!w){						
						std::cout << "OUTPUT " << "=| ";
						std::printf("\e[97m");
						std::cout << a0.at(i) - 1;
						std::printf("\e[91m");
						std::cout << " | :" << std::endl;
					}
					while (SET == a0.at(i)) {
						if(!toFil)
							if(i % 20 == 0 && i > 0)
								sR.pauz();
						if(!w)
							std::cout << SP << a.at(i) << "\n" << " " << std::endl;
						i++;
						if (a0.size() <= i)
							break;
					}
					LENg++;
					if (LENg == a.size() || i >= a0.size())
						break;
				}
				i++;
				if(!rCT && i >= a.size()){
					if(!w){
						std::printf("\e[4m");
						std::cout << "\nTerminal>";
						std::printf("\e[0m");
						std::printf("\e[91m");
						std::printf("\e[5m");
						std::cout << "\tNo phrases to return" << std::endl;
						std::printf("\e[0m");
						std::printf("\e[91m");
					} else {
						W << "NONE" << std::endl;
					}
				}
			}
			if(!w){
				std::printf("\e[4m");
				std::cout << "\nEND::(RedCheck)" << std::endl;
				std::printf("\e[0m");
			}
		}
		if(co){
			vector<string> nLW, nL0, pr0, pr1;
			if(w){
				W << "FILE 1: " << sR.file0 << std::endl;
				W << "FILE 2: " << sR.file1 << std::endl;
				for(int i = 0; i < sR.strS2.size(); i++){
					W << "STRS2= " << sR.strS2.at(i) <<" " << sR.intS2.at(i) << std::endl;
				}
				for(int i = 0; i < sR.strDoc.size(); i++){
					W << "STRDOC= " << sR.strDoc.at(i) <<" " << sR.intDoc.at(i) << std::endl;
				}
				for(int i = 0; i < sR.spDoc.size(); i++){
					W << "SPDOC= " << sR.spDoc.at(i) <<" " << sR.ipDoc.at(i) << std::endl;
				}
				for(int i = 0; i < sR.spD2.size(); i++){
					W << "SPD2= " << sR.spD2.at(i) <<" " << sR.ipD2.at(i) << std::endl;
				}
			}
			if(!M)
				if(!toFil)
					if(def || rC)
						sR.pauz();
			//sR.rO"EE::outP::D::");
			int ln0 = 0, ln1 = 0, sWrd = 0, s0 = 0, s1 = 0, lng0, lng1, lng2 = 0;
			string spWrd = "", sp0 = "", outpt = " +===> OUTPUT", lne = "-{", prc = "%  ", prcW;
			long chk0, chk1;
			//Set sWrd as length of longest word in strSz 
			for(long i = 0; i < sR.strSz.size(); i++){
				if(i > 0){
					if(to_string(sR.intSz.at(i)).length() > to_string(sR.intSz.at(i-1)).length()){
						sWrd = sR.strSz.at(i).length();
					}
				}
			}
			//Add presence of percentages from first document to list of prO
			for(long i = 0; i < sR.intSz.size(); i++){
				if(sR.intSz.at(i)/sR.intSz.size() > 0)
					prcW = to_string(sR.intSz.at(i)/sR.intSz.size());
				else
					prcW = "<0";
				
				while(prcW.length() < prc.length()){
					prcW += ' ';
				}
				pr0.push_back(prcW);
			}
			//Add presence of percentages from second document to list of pr1
			for(long i = 0; i < sR.intS2.size(); i++){
				if(sR.intS2.at(i)/sR.intS2.size() > 0)
					prcW = to_string(sR.intS2.at(i)/sR.intS2.size());
				else
					prcW = "<0";
				while(prcW.length() < prc.length()){
					prcW += ' ';
				}
				pr1.push_back(prcW);
			}
			//Make length of each number to equal that of the size of the longest number, plus two spaces
			for(long i = 0; i < sR.intSz.size(); i++){
				spWrd = to_string(sR.intSz.at(i));
				while(spWrd.length() < sWrd + 2){
					spWrd += " ";
				}
				nLW.push_back(spWrd);
			}
			for(long i = 0; i < sR.strS2.size(); i++){
				if(i > 0){
					if(to_string(sR.intS2.at(i)).length() > to_string(sR.intS2.at(i-1)).length()){
						sWrd = sR.strS2.at(i).length();
					}
				}
			}
			for(long i = 0; i < sR.intS2.size(); i++){
				if(i > 0){
					if(sR.strS2.at(i).length() > sR.strS2.at(i-1).length()){
						s0 = sR.strS2.at(i).length();
					}
				}
			}
			for(long i = 0; i < sR.strS2.size(); i++){
				sp0 = to_string(sR.intS2.at(i));
				while(sp0.length() < sWrd + 3){
					sp0 += " ";
				}
				nL0.push_back(sp0);
			}
			if(s0 + 2 > sR.file0.length() + 1) lng0 = s0+2; else lng0 = sR.file0.length() + 1;
			sR.file0 += " ";
			for(long i = 0; i < sR.strDoc.size(); i++){
				if(i > 0){
					if(sR.strDoc.at(i).length() > sR.strDoc.at(i-1).length()){
						s1 = sR.strDoc.at(i).length();
					}
				}
			}
			sR.file1 += ' ';
			a = sR.strDoc;
			for(int i = 0; i < a.size(); i++){
				if(i > 0){
					if(a.at(i).length() >= lng2){
						lng2 = a.at(i).length();
					}
				}
			}
			for(long i = 0; i < a.size(); i++){
				while(a.at(i).length() < lng2 + 3){
					a.at(i) += " ";
				}
			}
			while(outpt.length() < lng2 + 11){
				outpt += " ";
			}
			while(lne.length() < lng2 + lng0 + lng0 + sWrd){
				lne += "=";
			}
			lne += "}-";
			a0 = sR.intDoc;
			if(!w)
				std::cout << "\n---------\n" << std::endl;
			LENg = 0, i = 0;
			if(!w){
				std::printf("\e[96m");
				std::printf("\e[4m");
				std::cout << "BEGIN::(DoCo)" << std::endl;
				std::printf("\e[0m");
				std::printf("\e[96m");
			}			
			//sR.rO"FIN::B:");
			while (true) {
				if(i >= a.size()){
					break;
				}
				SET = a0.at(i);
				bool rCT = 0;
				rCT = 1;
				if(!w){
					std::cout << outpt << sR.file0 << prc << sR.file1 << prc << std::endl;
					std::cout << lne << std::endl;
				}
				while (SET == a0.at(i)) {
					if(!toFil)
						if(i % 30 == 0 && i > 0)
							sR.pauz();
					for(int j = 0; j < sR.strSz.size(); j++){
						if(sR.strSz.at(j) == sR.strDoc.at(i)){
							chk0 = j;
							break;
						}
					}
					for(int j = 0; j < sR.strS2.size(); j++){
						if(sR.strS2.at(j) == sR.strDoc.at(i)){
							chk1 = j;
							break;
						}
					}
					if(!w)
						std::cout << SP << a.at(i) << nLW.at(chk0) << pr0.at(chk0) << nL0.at(chk1) << pr1.at(chk1) << '\n'<< std::endl;
					i++;
					if (a0.size() <= i)
						break;
				}
				LENg++;
				if (LENg == a.size() || i >= a0.size())
					break;
				i++;
				if(!rCT && i >= a.size()){
					if(!w){
						std::printf("\e[4m");
						std::cout << "\nTerminal>";
						std::printf("\e[0m");
						std::printf("\e[91m");
						std::printf("\e[5m");
						std::cout << "\tNo phrases to return" << std::endl;
						std::printf("\e[0m");
						std::printf("\e[96m");
					} else {
						W << "NONE" << std::endl;
					}
				}
			}

			if(!toFil)
				pauz();
			
			
			vector<vector<string>> chekk = {nLW, nL0, pr0, pr1};
			for(int i = 0; i < chekk.size(); i++){
				if(!chekk.at(i).empty())
					chekk.at(i).clear();
			}
			if(!M)
				if(!toFil)
					if(def || rC)
						sR.pauz();
			//sR.rO"EE::outP::D::");
			ln0 = 0, ln1 = 0, sWrd = 0, s0 = 0, s1 = 0, lng0, lng2 = 0;
			spWrd = "", sp0 = "", outpt = " +===> OUTPUT", lne = "-{", prc = "%  ", prcW;
			chk0, chk1;
			//Set sWrd as length of longest word in strPh 
			for(long i = 0; i < sR.strPh.size(); i++){
				if(i > 0){
					if(to_string(sR.intPh.at(i)).length() > to_string(sR.intPh.at(i-1)).length()){
						sWrd = to_string(sR.intPh.at(i)).length();
					}
				}
			}
			//Add presence of percentages from first document to list of prO
			for(long i = 0; i < sR.intPh.size(); i++){
				if(sR.intPh.at(i)/sR.intPh.size() > 0)
					prcW = to_string(sR.intPh.at(i)/sR.intPh.size());
				else
					prcW = "<0";
				
				while(prcW.length() < prc.length()){
					prcW += ' ';
				}
				pr0.push_back(prcW);
			}
			//Add presence of percentages from second document to list of pr1
			for(long i = 0; i < sR.ipDoc.size(); i++){
				if(sR.ipDoc.at(i)/sR.ipDoc.size() > 0)
					prcW = to_string(sR.ipDoc.at(i)/sR.ipDoc.size());
				else
					prcW = "<0";
				while(prcW.length() < prc.length()){
					prcW += ' ';
				}
				pr1.push_back(prcW);
			}
			//Make length of each number to equal that of the size of the longest number, plus two spaces
			for(long i = 0; i < sR.intPh.size(); i++){
				spWrd = to_string(sR.intPh.at(i));
				while(spWrd.length() < sWrd + 3){
					spWrd += " ";
				}
				nLW.push_back(spWrd);
			}
			for(long i = 0; i < sR.spDoc.size(); i++){
				if(i > 0){
					if(to_string(sR.ipDoc.at(i)).length() > to_string(sR.ipDoc.at(i-1)).length()){
						sWrd = to_string(sR.ipDoc.at(i)).length();
					}
				}
			}
			for(long i = 0; i < sR.ipDoc.size(); i++){
				if(i > 0){
					if(sR.spDoc.at(i).length() > sR.spDoc.at(i-1).length()){
						s0 = sR.spDoc.at(i).length();
					}
				}
			}
			for(long i = 0; i < sR.spDoc.size(); i++){
				sp0 = to_string(sR.ipDoc.at(i));
				while(sp0.length() < sWrd + 3){
					sp0 += " ";
				}
				nL0.push_back(sp0);
			}
			if(s0 + 2 > sR.file0.length() + 1) lng0 = s0+2; else lng0 = sR.file0.length() + 1;
			sR.file0 += " ";
			for(long i = 0; i < sR.spD2.size(); i++){
				if(i > 0){
					if(sR.spD2.at(i).length() > sR.spD2.at(i-1).length()){
						s1 = sR.spD2.at(i).length();
					}
				}
			}
			sR.file1 += ' ';
			a = sR.spD2;
			for(int i = 0; i < a.size(); i++){
				if(i > 0){
					if(a.at(i).length() >= lng2){
						lng2 = a.at(i).length();
					}
				}
			}
			for(long i = 0; i < a.size(); i++){
				while(a.at(i).length() < lng2 + 3){
					a.at(i) += "-";
				}
			}
			while(outpt.length() < lng2 + 11){
				outpt += " ";
			}
			while(lne.length() < lng2 + lng0 + lng0 + sWrd){
				lne += "=";
			}
			lne += "}-";
			a0 = sR.ipD2;
			if(!w)
				std::cout << "\n---------\n" << std::endl;
			LENg = 0, i = 0;
			if(!w){
				std::printf("\e[96m");
				std::printf("\e[4m");
				std::cout << "BEGIN::(DoCo)" << std::endl;
				std::printf("\e[0m");
				std::printf("\e[96m");
			}
			//sR.rO"FIN::B:");
			while (true) {
				if(i >= a.size()){
					break;
				}
				SET = a0.at(i);
				bool rCT = 0;
				rCT = 1;
				if(!w){
					std::cout << outpt << sR.file0 << prc << sR.file1 << prc << std::endl;
					std::cout << lne << std::endl;
				}
				while (SET == a0.at(i)) {
					if(w)
						W << a.at(i) <<" " << a0.at(i) << endl;
					if(!toFil)
						if(i % 30 == 0 && i > 0)
							sR.pauz();
					for(int j = 0; j < sR.strPh.size(); j++){
						if(sR.strPh.at(j) == sR.spD2.at(i)){
							chk0 = j;
							break;
						}
					}
					for(int j = 0; j < sR.spDoc.size(); j++){
						if(sR.spDoc.at(j) == sR.spD2.at(i)){
							chk1 = j;
							break;
						}
					}
					if(!w)
						std::cout << SP << a.at(i) << nLW.at(chk0) << pr0.at(chk0) << nL0.at(chk1) << pr1.at(chk1) << '\n'<< std::endl;
					i++;
					if (a0.size() <= i)
						break;
				}
				LENg++;
				if (LENg == a.size() || i >= a0.size())
					break;
				i++;
				if(!rCT && i >= a.size()){
					if(!w){
						std::printf("\e[4m");
						std::cout << "\nTerminal>";
						std::printf("\e[0m");
						std::printf("\e[91m");
						std::printf("\e[5m");
						std::cout << "\tNo phrases to return" << std::endl;
						std::printf("\e[0m");
						std::printf("\e[96m");
					} else {
						W << "NONE" << std::endl;
					}
				}
			}


			///
			if(!w){
				std::printf("\e[4m");
				std::cout << "\nEND::(DoCo)" << std::endl;
				std::printf("\e[0m");
			}

		}
		W.close();
		if(w){
			sR.data();
		}
	}
}

/*
FUNCTIONS FOR outP
*/

//SearchNDestroy
void stuffReturn::SeNDe(string file, bool rC){
	//cout << "\n\n\tSeNDe\n\n" << endl;
	bool c = false, def = false, dc = false;
	int prg;
	for(int i = 0; i < chr.size(); i++){
		switch(chr.at(i)){
			case 'A':
				def = true;
				break;
			case 'd':
				c = true;
				break;
			case 'O':
				dc = true;
				break;
		}
	}
	if(!tw && !th)
		prg = 20.0;
	if(tw)
		prg = 10.0;
	if(th)
		prg = 6.67;
	if(rC)
		def = false;
	//rO"FF::SeNDe::A::");
	ifstream fil;
	string inpt, inpt0;
	fil.open(file);
	while (!fil.eof()) {
		getline(fil, inpt0);
		inpt += inpt0 + " \n";
	}
	fil.close();
	vector<string> a = wordReturn(inpt);
	vector<long> a0;
	inpt = "";
	inpt0 = "";
	if(def && !c)
		nuMake(0, a);
	if(rC && !c && !dc){
		redCheck(a, 0);
	}
	if(dc)
		redCheck(a, 1);
	if(c && !dc)
		nuMake(2, a);
	a = strSz;
	progressBar(prg);
	a0 = intSz;
	progressBar(prg);
	if(rC){
		a = strPh;
		if(dc){
			a = spDoc;
		}
		if(!dc){
			nuMake(1, a);
		}
		if(dc){
			nuMake(4, a);
		}
		a0 = intPh;
		if(dc){
			a0 = ipDoc;
		}
	}
	if(def && !dc){
		a = strSz;
		a0 = intSz;
	}
	if(c && !dc){
		a = strS2;
		a0 = intS2;
	}
	long COUNT = 0;
	while (COUNT < a.size()) {
		progressBar(float(1.0/a.size()*prg));
		for (long i = 0; i < a.size(); i++) {
			if (i < a.size()) {
				if ((i + 1) >= a0.size())
					break;
				if (a0.at(i) > a0.at(i + 1)) {
					iter_swap(a.begin() + i, a.begin() + i + 1);
					iter_swap(a0.begin() + i, a0.begin() + i + 1);
				}
			}
		}
		COUNT++;
	}
	//rO"GG::SeNDe::B::");
	COUNT = 0;
	int w0 = 0, w1 = 0;
	while (a.size() - 1 > w0) {
		w1 = w0 + 1;
		while (w1 < a.size()) {
			if (a.at(w0) == a.at(w1) || a.at(w1) == "\\\\+==PERIOD==+//") {
				a.erase(a.begin() + w1);
				a0.erase(a0.begin() + w1);
				w1--;
			}
			w1++;
		}
		w0++;
	}
	//rO"HH::SeNDe::C::");
	if(c && !dc){
		strS2 = a;
		intS2 = a0;
	}
	if (def && !c){
		strSz = a;
		intSz = a0;
	}
	if (rC && !dc){
		for(int i = 0; i < chr.size(); i++){
			if(chr.at(i) == 'r'){
				chr.erase(chr.begin() + i);
				break;
			}
		}
		strPh = a;
		intPh = a0;
	}
	if(dc){
		spDoc = a;
		ipDoc = a0;
	}
	//std::cout << "\n\n\t\\SeNDe\n\n" << std::endl;
}

//Breaks down full string into vector of all words
vector<string> stuffReturn::wordReturn(string inpt) {
	//cout  << "\n\n\twordReturn\n\n" << endl;
	int prg;
	if(!tw && !th)
		prg = 5.0;
	if(tw)
		prg = 2.5;
	if(th)
		prg = 0.75;
	long sz = 0;
	string s = "";
	vector<string> sS;
	vector<char> BLACKLIST = {};
	for (int i = 0; i < 255; i++) {
		progressBar(1.0/255 * prg);
		if (i < 32 || i > 123) {
			BLACKLIST.push_back((char)i);
		}
	}
	//rO"II::wordReturn::A::");
	for (long i = 0; i < inpt.length(); i++) {
		bool CHK = false;
		progressBar(float(1.0/inpt.length())* (prg * 3));
		for (int j = 0; j < BLACKLIST.size(); j++){
			if ((char)inpt[i] == (char)BLACKLIST.at(j)) {
				CHK = true;
				break;
			}
		}
		if (CHK == true)
			continue;
		if ((char)inpt[i] != ' ' && isalpha(inpt[i]) || (char)inpt[i] == '-' || (char)inpt[i] == '.' && isalpha((char)inpt[i+1]) || (char)inpt[i] == '\'') {
			if(isalpha((char)inpt[i])){
				s += tolower(inpt[i]);
			}
			else{
				s += inpt[i];
			}
		}
		if((char)inpt[i] == '.' && !isalpha((char)inpt[i+1])){
			sS.push_back("\\\\+==PERIOD==+//");
			prd = true;
		}

		if ((char)inpt[i] == '\\' || (char)inpt[i] == '/'||(char)inpt[i] == ':' && !isalpha((char)inpt[i])||(char)inpt[i] == ' ' && i != 0 && !isalpha((char)inpt[i]) && !s.empty()) {
			if(sS.size() > 0 && sS.at(sS.size()-1) == "\\\\+==PERIOD==+//"){
				sS.pop_back();
				sS.push_back(s);
				sS.push_back("\\\\+==PERIOD==+//");
			} else {
				sS.push_back(s);
			}
			s = "";
			sz++;
		}
	}
	//rO"JJ::wordReturn::B::");
	//cout << "\n\n\t\\wordReturn\n\n" << endl;
	return sS;
}

//Counts instances of each word
void stuffReturn::nuMake(char t, vector<string> s) {
	//cout << "\n\n\tnuMake\n\n" << endl;
	int prg;
	if(!tw && !th)
		prg = 20.0;
	if(tw)
		prg = 10.0;
	if(th)
		prg = 3.33;
	if(t == 0){
		strSz.push_back(s.at(0));
		intSz.push_back(0);
		long SZ = 0;
		for (long i = 0; i < s.size(); i++){
			progressBar(1.0/s.size()*prg);
			for (long j = 0; j < strSz.size(); j++) {
				if (intSz.size() < strSz.size())
					intSz.push_back(0);
				if (s.at(i) == strSz.at(j)) {
					intSz.at(j)++;
					SZ++;
					break;
				}
				if (s.at(i) != strSz.at(j) && j == strSz.size() - 1) {
					strSz.push_back(s.at(i));
				}
			}
		}
	}
	else if(t >= 1){
		vector<string> a, strV;
		vector<long> a0;
		switch(t){
			case 1:
				strV = strPh;
				a = strPh;
				break;
			default:
				strV = s;
				a = s;
				break;
		}
		a0.push_back(0);
		for (long i = 0; i < a.size(); i++){
			progressBar(1.0/a.size()*prg);
			for (long j = 0; j < strV.size(); j++) {
				if (a0.size() < a.size()){
					a0.push_back(0);
				}
				if (a.at(i) == strV.at(j)) {
					a0.at(j)++;
				}
			}
		}
		switch(t){
			case 1:
				intPh = a0;
				break;
			case 2:
				strS2 = a;
				intS2 = a0;
				break;
			case 3:
				intDoc = a0;
				break;
			case 4:
				ipDoc = a0;
				break;
			case 5:
				ipD2 = a0;
				break;
		}
		if(!a0.empty())
			a0.clear();
		if(!a.empty())
			a.clear();
	}
	//cout  << "\n\n\t\\nuMake\n\n" << endl;
}

//Clears Screen
void stuffReturn::clr(){
	#ifdef _WIN32
	system("CLS");
	#else
	system("clear");
	#endif
}

//Pauses screen for user
void stuffReturn::pauz(){
	char a[0];
	#ifdef _WIN32
	system("pause");
	#else
	std::cout << "PressEnter\\" << std::endl;
	cin.ignore();
	cin.get();
	#endif
}

//Returns Version
string stuffReturn::ver(){
	return verz;
}

//Progress bar for...Progress
void stuffReturn::progressBar(float x){
	progress += x;
	char bar[] = {'\\', '|', '/', '-'};
	loadBar = "[";
	int frst = int(progress/10), second = 10-frst;
	for(int i = 0; i < frst; i++){
		loadBar += ":=:";
	}
	for(int i = 0; i < second; i++){
		loadBar += "   ";
	}
	loadBar += "]";
	if(chk % 2 == 0){
		numCheck++;
	}
	if(numCheck == 4){
		numCheck = 0;
	}
	chk++;
	
	std::cout << loadBar << bar[numCheck] << int(progress) << "\%" << std::endl;
	std::printf("%c[A", 27);
	std::printf("%c[2K", 27);
}

//Check for redundant phrases used
void stuffReturn::redCheck(vector<string> s, bool d){
	//cout  << "\n\n\tredCheck\n\n" << endl;
	vector<string> phrase;
	string nxt = "";
	long leng = 0, l = 0;
	for(int i = 0; i < s.size(); i++){
		if(prd){
			while(s.at(leng + i) != "\\\\+==PERIOD==+//"){
				phrase.push_back(s.at(leng + i));
				leng++;
				if(leng + i == s.size()){
					break;
				}
			}
		} else {
			while(leng < 10){
				phrase.push_back(s.at(leng + i));
				leng++;
				if(leng + i == s.size()){
					break;
				}
			}
		}
		leng = 0;
		for(int j = i; j < s.size(); j++){
			while(l < phrase.size()){
				if(l > 0){
					phrase.erase(phrase.begin());
					l--;
				}
				if(s.at(j) == phrase.at(l)){
					nxt += s.at(j) + " ";
					if(l == 0){
						if(nxt != "" && nxt != " " && GT1(nxt)){
							if(d)
								spDoc.push_back(nxt);
							else
								strPh.push_back(nxt);
						}
					}
					j++;
					l++;
					if(l >= phrase.size()){
						nxt = "";
						break;
					}
					continue;
				}
				if(s.at(j) != phrase.at(l)){
					nxt = "";
					break;
				}
				l++;
				j--;
			}
			l = 0;
		}
		if(!phrase.empty())
			phrase.clear();
	}
	//cout  << "\n\n\t\\redCheck\n\n" << endl;
}

//Compare documents for similarities in vocabulary and word patterns
void stuffReturn::doCo(vector<char> c){
	//cout  << "\n\n\tdoCo\n\n" << endl;
	string file;
	while(1){
		std::cout << "FK> Enter second file: ";
		cin >> file;
		if(file == "ls"){
			system("ls");
			file = "";
		}
		else if (GUD(file)){
			break;
		}
	}
	setF(file, 0);
	SeNDe(file, 0);
	for(int i = 0; i < strSz.size(); i++){
		for(int j = 0; j < strS2.size(); j++){
			if(strSz.at(i) == strS2.at(j)){
				strDoc.push_back(strSz.at(j));
				break;
			}
		}
	}
	nuMake(3, strDoc);
	chr.push_back('O');
	SeNDe(file, 1);
	chr.pop_back();
	for(int i = 0; i < strPh.size(); i++){
		for(int j = 0; j < spDoc.size(); j++){
			if(strPh.at(i) == spDoc.at(j)){
				spD2.push_back(strPh.at(i));
				break;
			}
		}
	}
	nuMake(5, spD2);
	//rO"DoCo::C");
	//cout  << "\n\n\t\\doCo\n\n" << endl;
}

//Check if the string has more than one word
bool stuffReturn::GT1(string s){
	for(int i = 0; i < s.length(); i++){
		if(s[i] == ' '){
			if(i != s.length() - 1){
				if(s[i + 1] != ' '){
					return 1;
				}
			}
			if(i == s.length() - 1){
				return 0;
			}
		}
		if(i == s.length() - 1){
			return 0;
		}
	}
}

//Check if file is good
bool stuffReturn::GUD(string fil){
	bool tf = 0;
	ifstream f;
	f.open(fil);
	if(!f.good()){
			std::cout << "-+=FileNotFound=+-" << std::endl;
	} else {
		tf = 1;
	}
	f.close();
	return tf;
}

//Setting file names
void stuffReturn::setF(string fil, bool b){
	string f = "";
	for(int i = 0; i < f.length() - 4; i++){
		f += fil[i];
	}
	if(b)
		file0 = f;
	else
		file1 = f;
		
}

//Data to display on web-page
void stuffReturn::data(){
	ifstream f;
	ofstream f0;
	f0.open("graphicOut.js");
	string fil, inpt = "", Wfl = "start ", Lfl = "firefox ", bse,
	sSz = " ", iSz = " ",
	sPh = " ", iPh = " ",
	sS2 = " ", iS2 = " ",
	sDc = " ", iDc = " ",
	sD2 = " ", iD2 = " ",
	jsFil = "function outP() { var ";
	vector<vector<string>> allS = {strSz, strPh, strS2, strDoc, spD2};
	vector<vector<long>> allL = {intSz, intPh, intS2, intDoc, ipD2};
	vector<string> stz = {sSz, sPh, sS2, sDc, sD2}, lnz = {iSz, iPh, iS2, iDc, iD2};
	for(int i = 0; i < allS.size(); i++){
		for(int j = i; j < allS.at(i).size(); j++){
			stz.at(i) += "\"" + allS.at(i).at(j) + "\"";
			lnz.at(i) += to_string(allL.at(i).at(j));
			cout << allL.at(i).at(j) << " :: " << i << " :: " << j << endl;
			if(j < allS.at(i).size() - 1){
				stz.at(i) += ", ";
				lnz.at(i) += ", ";
			}
		}
	}
	for(int i = 0; i < stz.size(); i++){
		cout << i << " : " << stz.at(i) << " :: " << lnz.at(i) << endl;
		if(i > 0)
			jsFil += ",";
		switch(i){
			case 0:
				jsFil += "sSz = [" + stz.at(i) + "], iSz = [" + lnz.at(i) + "] ";
				break;
			case 1:
				jsFil += "sPh = [" + stz.at(i) + "], iPh = [" + lnz.at(i) + "] ";
				break;
			case 2:
				jsFil += "sS2 = [" + stz.at(i) + "], iS2 = [" + lnz.at(i) + "] ";
				break;				
			case 3:
				jsFil += "sDc = [" + stz.at(i) + "], iDc = [" + lnz.at(i) + "] ";
				break;
			case 4:
				jsFil += "sD2 = [" + stz.at(i) + "], iD2 = [" + lnz.at(i) + "] ";
				break;
		}
	}
	jsFil += "; lst = [sSz, iSz, sPh, iPh, sS2, iS2, sDc, iDc, sD2, iD2]; for(var i = 0; i < lst.length; i++){ console.log(lst[i]); } }";
	f0 << jsFil;
	f0.close();
	f.open("path2Fil.txt");
	while(!f.eof()){
		getline(f, fil);
		Wfl += fil;
		Lfl += fil;
	}
	f.close();
	Lfl += "/index.html";
	char Lpath[]= {*Lfl.c_str()}, Wpath[] = {*Wfl.c_str()};
	#if WIN_32
		system(Wpath);
	#else
		system(Lpath);
	#endif
}

//Set path to directory
void stuffReturn::pathSet(){
	ofstream f;
	string path;
	f.open("path2Fil.txt");
	cout << "Enter path to HTML and JavaScript file: ";
	cin >> path;
	f << path;
	f.close();
}

//Dev debug variable tool
void stuffReturn::rO(string s){
	std::cout << "--LISTS--" << endl;
	std::cout << s << "::::::::::::::>Doc 1 words<< " << strSz.size() << " " << intSz.size() << endl;
	for(int i = 0; i < strSz.size(); i++){
		if(i % 30 == 0)
			pauz();
		std::cout << strSz.at(i) << " :: " << intSz.at(i) << endl;
	}
	std::cout << s << "::::::::::::::>\\Doc 1 words<< " << strSz.size() << " " << intSz.size() << endl;
	pauz();
	std::cout << s << "::::::::::::::>Doc 1 red<< " << strPh.size() << " " << intPh.size() << endl;
	for(int i = 0; i < strPh.size(); i++){
		if(i % 30 == 0)
			pauz();
		std::cout << strPh.at(i) << " :: " << intPh.at(i) << endl;
	}
	std::cout << s << "::::::::::::::>\\Doc 1 red<< " << strPh.size() << " " << intPh.size() << endl;
	pauz();
	std::cout << s << "::::::::::::::>Doc 2 words<< " << strS2.size() << " " << intS2.size() << endl;
	for(int i = 0; i < strS2.size(); i++){
		if(i % 30 == 0)
			pauz();
		std::cout << strS2.at(i) << " :: " << intS2.at(i) << endl;
	}
	std::cout << s << "::::::::::::::>\\Doc 2 words<< " << strS2.size() << " " << intS2.size() << endl;
	pauz();
	std::cout << s << "::::::::::::::>doCo:Words<< " << strDoc.size() << " " << intDoc.size() << endl;
	for(int i = 0; i < strDoc.size(); i++){
		if(i % 30 == 0)
			pauz();	
		std::cout << strDoc.at(i) << " :: " << intDoc.at(i) << endl;
	}
	std::cout << s << "::::::::::::::>\\doCo:Words<< " << strDoc.size() << " " << intDoc.size() << endl;
	pauz();
	std::cout << s << "::::::::::::::>Doc 2 red<< " << spDoc.size() << " " << ipDoc.size() << endl;
	for(int i = 0; i < spDoc.size(); i++){
		if(i % 30 == 0)
			pauz();
		std::cout << spDoc.at(i) << " :: " << ipDoc.at(i) << endl;
	}
	std::cout << s << "::::::::::::::>\\Doc 2 red<< " << spDoc.size() << " " << ipDoc.size() << endl;
	pauz();
	std::cout << s << "::::::::::::::>doCo:Red<< " << spD2.size() << " " << ipD2.size() << endl;
	for(int i = 0; i < spD2.size(); i++){
		if(i % 30 == 0)
			pauz();
		std::cout << spD2.at(i) << " :: " << ipD2.at(i) << endl;
	}
	std::cout << s << "::::::::::::::>\\doCo:Red<< " << endl;
	pauz();
}