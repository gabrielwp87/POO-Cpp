//Exercicio015.cpp
//Aluno: Gabriel Wagner Piazenski
//Esse programa tem como finalidade cumprir um exercício dado pelo professor Roland Teodorowitsch,
//isto é, criar uma classe que possa conter e calcular a idade e altura de uma pessoa.
//Data: 04/04/2022


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Pessoa {
  // coloque aqui a sua implementacao...
  
	private:
		string nome;
		int idade;
		float altura;
		float taxaCrescimento;
	
	public:
		Pessoa() { //construtor sem parâmetros como pedido e um ifdef DEBUG
			nome = "";
			idade = 0;
			altura = 0;
			taxaCrescimento = 0;	
			
			
			#ifdef DEBUG
			cout << "Pessoa sem parâmetros foi criada..." << endl;
			#endif
		}
		
		Pessoa(string nomeNovo, int idadeNova, float alturaNova, float taxaCrescimentoNova) { //construtor sem parâmetros como pedido e um ifdef DEBUG
			nome = nomeNovo;
			idade = idadeNova;
			altura = alturaNova;
			taxaCrescimento = taxaCrescimentoNova;			
			
			#ifdef DEBUG
			cout << "Pessoa com parâmetros foi criada..." << endl;
			#endif
		}
		
		~Pessoa() { //destrutor sem parâmetros com um ifdef DEBUG
			#ifdef DEBUG
			cout << "Pessoa foi destruída..." << endl;
			#endif
		}
		
		
		//Série de 4 getters
		string obtemNome() {
			return nome;
		}
		
		int obtemIdade() {
			return idade;
		}
		
		float obtemAltura() {
			return altura;
		}
		
		float obtemTaxaCrescimento() {
			return taxaCrescimento;
		}
		
  		//Série de 4 setters
		void defineNome(string nomeNovo) {
			nome = nomeNovo;
		}
		
		void defineIdade(int idadeNova) {
			idade = idadeNova;
		}
		
		void defineAltura(float alturaNova) {
			altura = alturaNova;
		}
		
		void defineTaxaCrescimento(float taxaCrescimentoNova) {
			this -> taxaCrescimento = taxaCrescimentoNova;
		}
		
		void envelhece() {
			idade++;
			altura += taxaCrescimento;	
		}
  
};

void le_pessoa(Pessoa *p) {
    string s;
    getline(cin,s);
    p->defineNome(s);
    getline(cin,s);
    p->defineIdade(stoi(s));
    getline(cin,s);
    p->defineAltura(stod(s));
    getline(cin,s);
    p->defineTaxaCrescimento(stod(s));
}

void imprime_pessoa(Pessoa *p) {
    cout << p->obtemNome() << " (";
    cout << p->obtemIdade() << " anos; ";
    cout << fixed << setprecision(4);
    cout << p->obtemAltura() << " cm; ";
    cout << p->obtemTaxaCrescimento() << " cm)" << endl;
}

int main() {
    Pessoa *p1, *p2;

    // LEITURA
    p1 = new Pessoa();
    le_pessoa(p1);
    p2 = new Pessoa();
    le_pessoa(p2);
    // ENVELHECIMENTO
    for (int i=0; i<5; ++i) {
        p1->envelhece();
        p2->envelhece();
    }
    // RESULTADOS
    if (p1->obtemAltura() > p2->obtemAltura())
        imprime_pessoa(p1);
    else if (p1->obtemAltura() < p2->obtemAltura())
        imprime_pessoa(p2);
    else {
        imprime_pessoa(p1);
        imprime_pessoa(p2);
    }
    delete p2;
    delete p1;
    return 0;
}   
