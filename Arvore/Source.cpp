#include <iostream>
#include <vector>

using namespace std;

struct no{
	no *SubarvoreDir;
	char Dado;
	no *SubarvoreEsc;
};

void init(no *&node)
{
	node->SubarvoreEsc = NULL;
	node->SubarvoreDir = NULL;
}

void inserir(no*& raiz, char dado)
{
	if (raiz == NULL)
	{
		init(raiz);
	}

	if (raiz->Dado == NULL)
		raiz->Dado = dado;
	else
		if (raiz->Dado > dado)
			inserir(raiz->SubarvoreEsc, dado);
		else
			inserir(raiz->SubarvoreDir, dado);
}

void mostrar(no* raiz)
{
	cout << "Mostrando a arvore:" << endl;
	static int par = 0;
	if (raiz != NULL)
	{
		for (int i = 0; i < par; i++)
		{
			cout << "	";
		}
		par++;
		cout << raiz->Dado << endl;
		mostrar(raiz->SubarvoreEsc);
		mostrar(raiz->SubarvoreDir);
	}
	else
	{
		cout << "Arvore Vazia!" << endl;
	}
}

int main()
{
	char valor;
	no* raiz = NULL;
	do
	{
		system("cls");
		mostrar(raiz);
		cout << endl << "Insira um Valor na arvore: ";
		cin >> valor;
		inserir(raiz, valor);
	} while (valor != '-1');
	system("pause");
	return 0;
}