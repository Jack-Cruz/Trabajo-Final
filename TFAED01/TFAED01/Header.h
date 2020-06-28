#pragma once
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Colu
{
private:
	string titulo;
protected:
	vector<char>*ccolu;
	vector<string>*scolu;
	vector<float>*fcolu;
	vector<int>*icolu;
public:
	Colu(string titulo) :titulo(titulo) {	}
	~Colu()
	{
	}
	string getTitulo() { return titulo; }
	virtual void add(string elem) {}
	virtual string getsdato(int i) { return ""; }
};

class SColu : public Colu
{
public:
	SColu(string titulo) :Colu(titulo)
	{
		scolu = new vector<string>();
	}
	~SColu()
	{
		delete scolu;
	}
	void add(string elem) override
	{
		scolu->push_back(elem);
	}
	string getsdato(int i) override
	{
		return scolu->at(i);
	}
};

class FColu :public Colu
{
public:
	FColu(string titulo) :Colu(titulo)
	{
		fcolu = new vector<float>();
	}
	~FColu()
	{
		delete fcolu;
	}

	float getdato(int i)
	{
		return fcolu->at(i);
	}

	void add(string elem) override
	{
		fcolu->push_back(stof(elem));
	}
	string getsdato(int i)override
	{
		return to_string(fcolu->at(i));
	}
};

class IColu : public Colu
{
public:
	IColu(string titulo) :Colu(titulo)
	{
		icolu = new vector<int>();
	}
	~IColu()
	{
		delete icolu;
	}

	void add(string elem) override
	{
		icolu->push_back(stoi(elem));
	}
	string getsdato(int i)override
	{
		return to_string(icolu->at(i));
	}

	int getdato(int i)
	{
		return icolu->at(i);
	}
};

class CColu :public Colu
{
public:
	CColu(string titulo) :Colu(titulo)
	{
		ccolu = new vector<char>();
	}
	~CColu()
	{
		delete ccolu;
	}
	void add(string elem) override
	{
		ccolu->push_back((char)elem[0]);
	}
	char getdato(int i)
	{
		return ccolu->at(i);
	}
	string getsdato(int i) override
	{
		return to_string(ccolu->at(i));
	}

};

class Tabla
{
private:
	vector<Colu*>columnas;
	int colu;
	int fila;

public:
	Tabla(int n) :colu(n)
	{
		fila = 0;
	}
	~Tabla()
	{
	}

	void definir(string tipo, string titulo)
	{
		//string tipo, titulo;

			if (tipo == "string")
			{
				SColu*nuevo = new SColu(titulo);
				columnas.push_back(nuevo);
			}
			else {
				if (tipo == "char")
				{
					CColu*nuevo = new CColu(titulo);
					columnas.push_back(nuevo);
				}
				else {
					if (tipo == "int")
					{
						IColu*nuevo = new IColu(titulo);
						columnas.push_back(nuevo);
					}
					else if (tipo == "float")
					{
						FColu*nuevo = new FColu(titulo);
						columnas.push_back(nuevo);
					}
				}
			}
	}
	void agregar(string dato, int i)
	{
			columnas[i]->add(dato);
			// fila += 1;
	}
	
	string titulo(int i)
	{
		return columnas[i]->getTitulo();
	}
	string mostrar(int col, int row)
	{
		return columnas[col]->getsdato(row);
	/*	for (int i = 0; i < colu; i++)
		{
			cout << columnas[i]->getTitulo() << "\t";
		}

		cout << endl;

		for (int i = 0; i < fila; i++)
		{
			for (int j = 0; j < colu; j++)
			{
				columnas[j]->getsdato(i); cout << "\t";
			}
			cout << endl;
		}
	
	*/
	}

};






