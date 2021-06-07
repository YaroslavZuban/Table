#include <iostream>
#include<stdio.h>
#include <fstream>
using namespace std;

const size_t N = 10;
const size_t arrayMax = 20;
const size_t sizeNumber = 7;
const size_t sizeMarka = 10;

struct T1_elem // ��������� �������� ������� 1
{
	char number[sizeNumber] = "",
		mark[sizeMarka] = "",
		owner_name[arrayMax] = "",
		owner_lastname[arrayMax] = "", 
		owner_patronymic[arrayMax] = "";
};

struct table // ��������� ������� 1
{
	T1_elem elem[N]; size_t n=0; 
};

struct T2_elem // ��������
{
	char owner_name[arrayMax]="", owner_lastname[arrayMax] = "", owner_patronymic[arrayMax] = "";
};

struct T3_elem // ����� ��� "������"
{
	char number[sizeNumber] = ""; char mark[sizeMarka] = "";
};

int main()
{
	setlocale(LC_ALL, "Russian");
	table table_1;
	FILE* fp, *file;

	fopen_s(&fp, "�����1.txt", "r");
	fopen_s(&file, "�����1.txt", "r");
	char array[sizeNumber] = "";

	if (fp != nullptr && file != nullptr)
	{
		if (fscanf_s(file, "%s", array, sizeNumber)==EOF) {
			cout << "������ � ��� ����� <<����>> ��� ���������� � �����������!" << endl;
		}
		else {
			char buf[arrayMax] = "";
			char bufMARKA[sizeMarka] = "";
			char bufNUMBER[sizeNumber] = "";

			while (!feof(fp) && table_1.n < N) // ���� �� ����� ����� ��� �� ����� �� ����� �������
			{
				fscanf_s(fp, "%s", bufNUMBER, sizeNumber); // ����� �����
				strcpy_s(table_1.elem[table_1.n].number, bufNUMBER);// ��������� ����� � �������

				fscanf_s(fp, "%s", bufMARKA, sizeMarka); // ����� �����
				strcpy_s(table_1.elem[table_1.n].mark, bufMARKA); // ��������� ����� � �������

				fscanf_s(fp, "%s", buf, arrayMax); // ����� ���
				strcpy_s(table_1.elem[table_1.n].owner_name, buf); // ��������� ��� � �������

				fscanf_s(fp, "%s", buf, arrayMax); // ����� �������
				strcpy_s(table_1.elem[table_1.n].owner_lastname, buf); // ��������� ������� � �������

				fscanf_s(fp, "%s", buf, arrayMax); // ����� ��������
				strcpy_s(table_1.elem[table_1.n].owner_patronymic, buf); // ��������� �������� � �������

				table_1.n++;
			}


			for (int i = 0; i < table_1.n; i++) // ����� �������
			{
				printf("%s|%-10s|%-10s|%-10s|%-10s\n",
					table_1.elem[i].number,
					table_1.elem[i].mark,
					table_1.elem[i].owner_name,
					table_1.elem[i].owner_lastname,
					table_1.elem[i].owner_patronymic);
			}

			cout << endl;
			
			// ������� ��������
			fopen_s(&fp, "�����.txt", "r");
			fopen_s(&file, "�����.txt", "r");

			if (fp != nullptr&&file!=nullptr)
			{

				if (fscanf_s(file, "%s", array, sizeNumber) == EOF)
					cout << "� ���� ���� ������ �� ����! ��� ������������!" << endl;
				else {
					table table_2; // ������������� ������� ��������
					T3_elem buf_1; // ����� ��� ������� ������
					fscanf_s(fp, "%s", bufNUMBER, sizeNumber); // ����� �����, ���� �� ����� ��� ����, ����� ����� ���� � ����� ����� ����������� �� ����� ������ � fp

					while (!feof(fp))
					{
						strcpy_s(buf_1.number, bufNUMBER); // ��������� � �����
						fscanf_s(fp, "%s", bufMARKA, sizeMarka); // ����� �����
						strcpy_s(buf_1.mark, bufMARKA); // ��������� � �����
						int n = 0;

						for (int i = n; i < table_1.n; i++)
							if (strcmp(buf_1.number, table_1.elem[i].number) == 0)
							{
								strcpy_s(table_2.elem[table_2.n].owner_name, table_1.elem[i].owner_name);
								strcpy_s(table_2.elem[table_2.n].owner_lastname, table_1.elem[i].owner_lastname);
								strcpy_s(table_2.elem[table_2.n].owner_patronymic, table_1.elem[i].owner_patronymic);
								table_2.n++;
								n = i;
							}

						fscanf_s(fp, "%s", bufNUMBER, sizeNumber); // ����� �����
					}

					cout << "������� ��������" << endl;

					for (int i = 0; i < table_2.n; i++) // ����� �������
					{
						printf("%s|%-10s|%-10s\n",
							table_2.elem[i].owner_name,
							table_2.elem[i].owner_lastname,
							table_2.elem[i].owner_patronymic);
					}
				}
			}
		}
	
	}

	return 0;
}