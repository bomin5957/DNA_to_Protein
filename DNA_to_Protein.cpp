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
		cout << "1. ������ DNA ���� �� RNA�� ���� �� ����\n2. DNA �Է� �� RNA�� ���� �� ����\n3. ����";
		cout << "\n\n�߸��� �� �Է� �� ���� ���";
		cout << "\n���� : ";
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
			cout << "���α׷��� �����մϴ�.\n";
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
		cout << "DNA ���� �Է� (���ڿ� ���̴� 3�� ����� �Է�)";
		cout << "\n\n3�� ����� �ƴϸ� ���� ���\n";
		cout << "�߸��� �Է����� �Ǵ� �� ���� ��� ex) ���ڷ� �Է�\n";
		cout << "\n�Է� : ";
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
		cout << "������� DNA : " << makedna << "\n";
		string transcription;

		for (int i = 0; i < makedna.size(); i++) {
			transcription += table[makedna[i]];
		}
		cout << "����Ǿ� ������� RNA : " << transcription << "\n";

		cout << "�����Ǿ� ������� �ܹ��� : ";
		int cnt = 1;
		string s;
		for (int i = 0; i < transcription.size(); i += 3) {
			s = "";
			s += transcription[i];
			s += transcription[i + 1];
			s += transcription[i + 2];
			cout << cnt++ << ". " << t_table[s] << " ";
		}
		cout << "\n���α׷��� �����մϴ�\n";
		return;
	}
}

void SelectDNA() {
	while (1) {
		cout << "DNA ���ڿ� �Է�\n";
		cout << "\n���ڿ��� ���̰� 3�� ����� �ƴϸ� ���� ���\n";
		cout << "DNA�� ���Ե��� ���� ���� �Է� �� ���� ���\n";
		cout << "��� �빮�ڷ� �Է�\n";
		cout << "�Է� : ";
		string in;
		cin >> in;
		cout << "\n\n";
		if (in.size() % 3)continue;
		cout << "\n�Է¹��� DNA : " << in << "\n";

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
		cout << "����Ǿ� ������� RNA : " << transcription << "\n";

		cout << "�����Ǿ� ������� �ܹ��� : ";
		int cnt = 1;
		string s;
		for (int i = 0; i < transcription.size(); i += 3) {
			s = "";
			s += transcription[i];
			s += transcription[i + 1];
			s += transcription[i + 2];
			cout << cnt++ << ". " << t_table[s] << " ";
		}
		cout << "\n���α׷��� �����մϴ�\n";
		return;
	}
}

void init() {
	table['A'] = 'U';
	table['G'] = 'C';
	table['T'] = 'A';
	table['C'] = 'G';

	t_table["UUU"] = "���";
	t_table["UUC"] = "�˶��";
	t_table["UUA"] = "����";
	t_table["UUG"] = "����";
	t_table["UCU"] = "����";
	t_table["UCC"] = "����";
	t_table["UCA"] = "����";
	t_table["UCG"] = "����";
	t_table["UAU"] = "Ÿ�̷ν�";
	t_table["UAC"] = "Ÿ�̷ν�";
	t_table["UAA"] = "���� �ڵ�";
	t_table["UAG"] = "���� �ڵ�";
	t_table["UGU"] = "�ý�����";
	t_table["UGC"] = "�ý�����";
	t_table["UGA"] = "���� �ڵ�";
	t_table["UGG"] = "Ʈ������";
	t_table["CUU"] = "����";
	t_table["CUC"] = "����";
	t_table["CUA"] = "����";
	t_table["CUG"] = "����";
	t_table["CCU"] = "���Ѹ�";
	t_table["CCC"] = "���Ѹ�";
	t_table["CCA"] = "���Ѹ�";
	t_table["CCG"] = "���Ѹ�";
	t_table["CAU"] = "����Ƽ��";
	t_table["CAC"] = "����Ƽ��";
	t_table["CAA"] = "�۷�Ÿ��";
	t_table["CAG"] = "�۷�Ÿ��";
	t_table["CGU"] = "�Ƹ�����";
	t_table["CGC"] = "�Ƹ�����";
	t_table["CGA"] = "�Ƹ�����";
	t_table["CGG"] = "�Ƹ�����";
	t_table["AUU"] = "���̼ҷ���";
	t_table["AUC"] = "���̼ҷ���";
	t_table["AUA"] = "�޽��̿��� : ���� �ڵ�";
	t_table["AUG"] = "�޽��̿��� : ���� �ڵ�";
	t_table["ACU"] = "Ʈ������";
	t_table["ACC"] = "Ʈ������";
	t_table["ACA"] = "Ʈ������";
	t_table["ACG"] = "Ʈ������";
	t_table["AAU"] = "�ƽ��Ķ��";
	t_table["AAC"] = "�ƽ��Ķ��";
	t_table["AAA"] = "���̽�";
	t_table["AAG"] = "���̽�";
	t_table["AGU"] = "����";
	t_table["AGC"] = "����";
	t_table["AGA"] = "�Ƹ�����";
	t_table["AGG"] = "�Ƹ�����";
	t_table["GUU"] = "�߸�";
	t_table["GUC"] = "�߸�";
	t_table["GUA"] = "�߸�";
	t_table["GUG"] = "�߸�";
	t_table["GCU"] = "�˶��";
	t_table["GCC"] = "�˶��";
	t_table["GCA"] = "�˶��";
	t_table["GCG"] = "�˶��";
	t_table["GAU"] = "�ƽ���Ʈ��";
	t_table["GAC"] = "�ƽ���Ʈ��";
	t_table["GAA"] = "�۷�Ž��";
	t_table["GAG"] = "�۷�Ž��";
	t_table["GGU"] = "�۶��̽�";
	t_table["GGC"] = "�۶��̽�";
	t_table["GGA"] = "�۶��̽�";
	t_table["GGG"] = "�۶��̽�";
}