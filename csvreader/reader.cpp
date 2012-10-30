#include <vector>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class student {
	 public:
	string name;
	vector <string> alias;
	string classnum;
	string class_;
	string email;
	vector <string> title; // cut vryzka
	vector <string> deadline;
	vector <string> finishdate;
	vector <string> link;
}temp;

vector <student> liststudent;
int count;


string decase(string str) {
	for(int i=0; i<str.size(); i++) {
		if((str[i]>='A') && (str[i]<='Z')) str[i]+='a'-'A';
	}
	return str;
}
 
void check() {
	if((temp.name=="") or (temp.email=="")) return; // insufficiant data, ignoring entry
	bool simi[4]={0,0,0,0};
	for(int i=0; i<liststudent.size(); i++) {
		for(int ref=0; ref<4; ref++) simi[ref]=0;
		if(liststudent[i].name==temp.name) simi[0]=1;
		if(liststudent[i].classnum==temp.classnum) simi[1]=1;
		if(liststudent[i].class_==temp.class_) simi[2]=1;
		if(liststudent[i].email==temp.email) simi[3]=1;
		if((simi[0]==1) && (simi[1]==1) && (simi[2]==1) && (simi[3]==1)) { //if full match
			if(count>liststudent[i].link.size()) {
				liststudent[i].title.push_back("TITLE");
				liststudent[i].finishdate.push_back(temp.finishdate[0]);
				liststudent[i].link.push_back(temp.link[0]);
			}
			else {
				liststudent[i].finishdate[count-1]=temp.finishdate[0];
				liststudent[i].link[count-1]=temp.link[0];
			}
			return;
		}
		else if(simi[3]==1) { // by mail sim
			if(temp.name.size()>=liststudent[i].name.size()) {
				cout << temp.name << " " << liststudent[i].name << endl;
				cout << temp.email << " " << liststudent[i].email << endl;
				bool newalias=1;
				for(int in=0; in<liststudent[i].alias.size(); in++) {
					if(liststudent[i].alias[in]==liststudent[i].name) newalias=0;
				}
				cout << "Creating new alias" << liststudent[i].name << " for " << temp.name << " with " << temp.email << endl;
				if(newalias==1) liststudent[i].alias.push_back(liststudent[i].name);
				liststudent[i].name=temp.name;
				liststudent[i].class_=temp.class_;
				if((liststudent[i].classnum=="-") && (temp.classnum!="-")) liststudent[i].classnum=temp.classnum;
				if(count>liststudent[i].link.size()) {
					liststudent[i].title.push_back("TITLE");
					liststudent[i].finishdate.push_back(temp.finishdate[0]);
					liststudent[i].link.push_back(temp.link[0]);
				}
				else {
					liststudent[i].finishdate[count-1]=temp.finishdate[0];
					liststudent[i].link[count-1]=temp.link[0];
				}
			} 
			else { // longer old name
				liststudent[i].class_=temp.class_;
				if((liststudent[i].classnum=="-") && (temp.classnum!="-")) liststudent[i].classnum=temp.classnum;
				if(count>liststudent[i].link.size()) {
					liststudent[i].title.push_back("TITLE");
					liststudent[i].finishdate.push_back(temp.finishdate[0]);
					liststudent[i].link.push_back(temp.link[0]);
				}
				else {
					liststudent[i].finishdate[count-1]=temp.finishdate[0];
					liststudent[i].link[count-1]=temp.link[0];
				}
			}
			return;
		}
		else if(simi[0]==1) { // by name sim
			liststudent[i].email=temp.email;
			liststudent[i].class_=temp.class_;
			if(temp.classnum!="-") liststudent[i].classnum=temp.classnum;
			liststudent[i].title.push_back("TITLE");
			liststudent[i].deadline.push_back("DEADLINE");
			liststudent[i].finishdate.push_back(temp.finishdate[0]);
			liststudent[i].link.push_back(temp.link[0]);
			return;
		}
		
		for(int a=0; a<liststudent[i].alias.size(); a++) { //checking aliases
			if(temp.name==liststudent[i].alias[a]) {
				cout << temp.name <<" is alias of " << liststudent[i].name << endl;
				liststudent[i].email=temp.email;
				liststudent[i].class_=temp.class_;
				if(temp.classnum!="-") liststudent[i].classnum=temp.classnum;
				liststudent[i].title.push_back("TITLE");
				liststudent[i].deadline.push_back("DEADLINE");
				liststudent[i].finishdate.push_back(temp.finishdate[0]);
				liststudent[i].link.push_back(temp.link[0]);
				return;
			}
		}
	}		
	liststudent.push_back(temp);
	for(int i=1; i<count; i++) {
		liststudent[liststudent.size()-1].title.insert(liststudent[liststudent.size()-1].title.begin(),"TITLE");
		liststudent[liststudent.size()-1].deadline.insert(liststudent[liststudent.size()-1].deadline.begin(),"няма");
		liststudent[liststudent.size()-1].finishdate.insert(liststudent[liststudent.size()-1].finishdate.begin(),"няма");
		liststudent[liststudent.size()-1].link.insert(liststudent[liststudent.size()-1].link.begin(),"няма");
	}
}

void split(string str) {
	vector <string> arrstring;
	arrstring.clear();
	temp.title.clear();
	temp.deadline.clear();
	temp.finishdate.clear();
	temp.link.clear();
	string buffer;
	int last=0;
	for(int i=0; i<str.size(); i++) if(str[i]==',') {
		buffer="";
		for(int a=last; a<i; a++) buffer+=str[a];
		arrstring.push_back(buffer);
		last=i+1;
	}
	buffer="";
	for(int a=last; a<str.size(); a++) buffer+=str[a];
	arrstring.push_back(buffer);
	string cutter="";	
	for(int cut=0; cut<arrstring[0].size(); cut++) {
		if(arrstring[0][cut]==' ') break;		
		cutter+=arrstring[0][cut];
	}
	temp.finishdate.push_back(cutter);
	cutter="";
	for(int cut=0; cut<arrstring[1].size(); cut++) {
		if((arrstring[1][cut]!='1') && (arrstring[1][cut]!='0') && (arrstring[1][cut]!=' ')) {
			cutter+=arrstring[1][cut];
		}
	}
	if((cutter=="б") || (cutter=="b")) cutter="Б";
	if((cutter=="а") || (cutter=="a")) cutter="А";
	temp.class_=cutter;
	temp.title.push_back("TITLE");
	temp.deadline.push_back("DEADLINE");		
	temp.link.push_back(arrstring[5]);
	temp.classnum=arrstring[2];
	temp.name=arrstring[3];
	temp.email=decase(arrstring[4]);
}

int main() {
	string line, filename;
	for(count=1; count<=9; count++) { // 4.csv is 9.csv!!!!
		char fnamehelp=count+'0';
		filename="x.csv";
		filename[0]=fnamehelp;
		cout << filename << endl;
		ifstream myfile;
		myfile.open(filename.c_str());
		getline(myfile, line); // first blank
		while(!myfile.eof()) {
			getline(myfile, line);
			if(line!="") split(line);			
			check();
		}
		myfile.close();
		for(int i=0; i<liststudent.size(); i++) {
			while(liststudent[i].link.size()<count) {
				liststudent[i].title.push_back("TITLE");
				liststudent[i].finishdate.push_back("няма");
				liststudent[i].link.push_back("няма");
			}
		}
	}
	//display
	ofstream myFile;
	myFile.open("finish.csv");
	string test="goshko";
	for(int i=0; i<liststudent.size(); i++) {
		myFile << i << "." << liststudent[i].name << " " << liststudent[i].email << " " << liststudent[i].classnum << " " << liststudent[i].class_ << "\n";
	}
	myFile.close();
	for(int i=0; i<liststudent.size(); i++) {
		cout << i << "." << liststudent[i].name << "::" << liststudent[i].email << "::" << liststudent[i].classnum << "::" << liststudent[i].class_ << endl;
		for(int a=0; a<liststudent[i].link.size(); a++) {
		//	cout << a << ". " << liststudent[i].link[a] << endl;
		}
	}
	cout << liststudent[44].name << endl;
	for(int a=0; a<liststudent[44].alias.size(); a++) cout << liststudent[44].alias[a] << endl;
	return 0;
}
