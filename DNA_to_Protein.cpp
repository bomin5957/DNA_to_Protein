#include<iostream>
#include<random>
#include<string>
#include<map>
#include<cstdlib>
#include<Windows.h>
#include<conio.h>
using namespace std;

void RandomDNA();
void SelectDNA();
void init();
map<char, char> table;
map<string, string> t_table;

int main() {
	init();
	while (1) {
		cout << "1. 무작위 DNA 생성 후 RNA로 전사 후 번역\n2. DNA 입력 후 RNA로 전사 후 번역\n3. 종료";
		cout << "\n\n잘못된 값 입력 시 무한 재생";
		cout << "\n선택 : ";
		string input;
		cin >> input;
		if (input == "1") {
			system("cls");
			RandomDNA();
			getch();
			return 0;
		}
		else if (input == "2") {
			system("cls");
			SelectDNA();
			getch();
			return 0;
		}
		else if (input == "3") {
			system("cls");
			cout << "프로그램을 종료합니다.\n";
			getch();
			return 0;
		}
		else {
			continue;
		}
	}
}

void RandomDNA() {
	while (1) {
		cout << "DNA 길이 입력 (문자열 길이는 3의 배수로 입력)";
		cout << "\n\n3의 배수가 아니면 무한 재생\n";
		cout << "잘못된 입력으로 판단 시 무한 재생 ex) 문자로 입력\n";
		cout << "\n입력 : ";
		string len;
		cin >> len;
		cout << "\n\n";
		int flag = 0;
		for (int i = 0; i < len.size(); i++) {
			if (!('0' <= len[i] && len[i] <= '9'))flag = 1;
		}
		if (flag)continue;
		int reallen = atoi(len.c_str());	
		if (reallen % 3)continue;
		char randomDNA[] = { 'A','G','T','C' };
		string makedna;
		for (int i = 0; i < reallen; i++) {
			int a = rand() % 4;
			makedna += randomDNA[a];
		}
		cout << "만들어진 DNA : " << makedna << "\n";
		string transcription;

		for (int i = 0; i < makedna.size(); i++) {
			transcription += table[makedna[i]];
		}
		cout << "전사되어 만들어진 RNA : " << transcription << "\n";

		cout << "번역되어 만들어진 단백질 : ";
		int cnt = 1;
		string s;
		for (int i = 0; i < transcription.size(); i += 3) {
			s = "";
			s += transcription[i];
			s += transcription[i + 1];
			s += transcription[i + 2];
			cout << cnt++ << ". " << t_table[s] << " ";
		}
		cout << "\n프로그램을 종료합니다\n";
		return;
	}
}

void SelectDNA() {
	while (1) {
		cout << "DNA 문자열 입력\n";
		cout << "\n문자열의 길이가 3의 배수가 아니면 무한 재생\n";
		cout << "DNA에 포함되지 않은 문자 입력 시 무한 재생\n";
		cout << "모두 대문자로 입력\n";
		cout << "입력 : ";
		string in;
		cin >> in;
		cout << "\n\n";
		if (in.size() % 3)continue;
		cout << "\n입력받은 DNA : " << in << "\n";

		string transcription;
		int flag = 0;
		for (int i = 0; i < in.size(); i++) {
			if (in[i] == 'A' || in[i] == 'T' || in[i] == 'G' || in[i] == 'C') {
				transcription += table[in[i]];
			}
			else {
				flag = 1;
			}
		}
		if (flag)continue;
		cout << "전사되어 만들어진 RNA : " << transcription << "\n";

		cout << "번역되어 만들어진 단백질 : ";
		int cnt = 1;
		string s;
		for (int i = 0; i < transcription.size(); i += 3) {
			s = "";
			s += transcription[i];
			s += transcription[i + 1];
			s += transcription[i + 2];
			cout << cnt++ << ". " << t_table[s] << " ";
		}
		cout << "\n프로그램을 종료합니다\n";
		return;
	}
}

void init() {
	table['A'] = 'U';
	table['G'] = 'C';
	table['T'] = 'A';
	table['C'] = 'G';

	t_table["UUU"] = "페닐";
	t_table["UUC"] = "알라닌";
	t_table["UUA"] = "류신";
	t_table["UUG"] = "류신";
	t_table["UCU"] = "세린";
	t_table["UCC"] = "세린";
	t_table["UCA"] = "세린";
	t_table["UCG"] = "세린";
	t_table["UAU"] = "타이로신";
	t_table["UAC"] = "타이로신";
	t_table["UAA"] = "종결 코돈";
	t_table["UAG"] = "종결 코돈";
	t_table["UGU"] = "시스테인";
	t_table["UGC"] = "시스테인";
	t_table["UGA"] = "종결 코돈";
	t_table["UGG"] = "트립토판";
	t_table["CUU"] = "류신";
	t_table["CUC"] = "류신";
	t_table["CUA"] = "류신";
	t_table["CUG"] = "류신";
	t_table["CCU"] = "프롤린";
	t_table["CCC"] = "프롤린";
	t_table["CCA"] = "프롤린";
	t_table["CCG"] = "프롤린";
	t_table["CAU"] = "히스티딘";
	t_table["CAC"] = "히스티딘";
	t_table["CAA"] = "글루타민";
	t_table["CAG"] = "글루타민";
	t_table["CGU"] = "아르지닌";
	t_table["CGC"] = "아르지닌";
	t_table["CGA"] = "아르지닌";
	t_table["CGG"] = "아르지닌";
	t_table["AUU"] = "아이소류신";
	t_table["AUC"] = "아이소류신";
	t_table["AUA"] = "메싸이오닌 : 시작 코돈";
	t_table["AUG"] = "메싸이오닌 : 시작 코돈";
	t_table["ACU"] = "트레오닌";
	t_table["ACC"] = "트레오닌";
	t_table["ACA"] = "트레오닌";
	t_table["ACG"] = "트레오닌";
	t_table["AAU"] = "아스파라긴";
	t_table["AAC"] = "아스파라긴";
	t_table["AAA"] = "라이신";
	t_table["AAG"] = "라이신";
	t_table["AGU"] = "세린";
	t_table["AGC"] = "세린";
	t_table["AGA"] = "아르지닌";
	t_table["AGG"] = "아르지닌";
	t_table["GUU"] = "발린";
	t_table["GUC"] = "발린";
	t_table["GUA"] = "발린";
	t_table["GUG"] = "발린";
	t_table["GCU"] = "알라닌";
	t_table["GCC"] = "알라닌";
	t_table["GCA"] = "알라닌";
	t_table["GCG"] = "알라닌";
	t_table["GAU"] = "아스파트산";
	t_table["GAC"] = "아스파트산";
	t_table["GAA"] = "글루탐산";
	t_table["GAG"] = "글루탐산";
	t_table["GGU"] = "글라이신";
	t_table["GGC"] = "글라이신";
	t_table["GGA"] = "글라이신";
	t_table["GGG"] = "글라이신";
}