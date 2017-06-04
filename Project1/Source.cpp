#include <iostream>

using namespace std;

struct Node
{
	Node* left;
	char data;
	Node* right;
};

void init(char value, Node*& node)
{
	Node* temp = new Node;
	temp->data = value;
	temp->left = NULL;
	temp->right = NULL;
	node = temp;
}

void insert(char value, Node*& main)
{
	if (main == NULL)
		init(value, main);
	else
		if (main->data < value)
			insert(value, main->right);
		else
			insert(value, main->left);
}

void show(Node *&main, int st)
{
	if (main != NULL)
	{
		for (int i = 0; i < st; i++)
		{
			cout << "--";
		}
		st++;
		cout << main->data << endl;
		if (main->left != NULL)
			show(main->left, st);
		if (main->right != NULL)
			show(main->right, st);
	}
}

bool search(char value, Node*& main, int &st)
{
	st++;
	if (main->data == value)
	{
		cout << "'" << value << "' foi encontrado em " << st << " tentativas." << endl;
		return true;
	}
	else
	{
		if (main->left != NULL)
			if (search(value, main->left, st))
				return true;
		if (main->right != NULL)
			if (search(value, main->right, st))
				return true;
	}
	return false;
}

bool search(char value, Node*& main)
{
	int st = 1;
	if (main->data == value)
	{
		cout << "'" << value << "' foi encontrado em " << st << " tentativas." << endl;
		return true;
	}
	else
	{
		if (main->left != NULL)
			if (search(value, main->left, st))
				return true;
		if (main->right != NULL)
			if (search(value, main->right, st))
				return true;
	}
	return false;
}

int main()
{
	Node* main = NULL;
	char value;

	int opc;
	do
	{
		show(main,0);
		cout << "O que deseja fazer?" << endl;
		cout << "1 - Inserir valor na arvore" << endl;
		cout << "2 - Buscar valor na arvore" << endl;
		cout << "0 - Sair" << endl;
		cin >> opc;

		switch (opc)
		{
		case 1:
			cout << "Insira uma letra: ";
			cin >> value;
			system("cls");
			insert(value, main);
			break;
		case 2:
			cout << "Insira o valor a buscar: ";
			cin >> value;
			system("cls");
			if (!search(value, main))
				cout << "Valor nao encontrado." << endl;
			break;
		case 0:
			system("cls");
			cout << "Mais alguma coisa?" << endl;
			break;
		default:
			system("cls");
			cout << "Opcao invalida" << endl;
			break;
		}
	} while (opc != 0);

	system("pause");
	return 0;
}