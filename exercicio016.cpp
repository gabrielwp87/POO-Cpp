// Exercicio016.cpp
//Aluno: Gabriel Wagner Piazenski
//Esse programa tem como finalidade cumprir um exercício dado pelo professor Roland Teodorowitsch,
//isto é, criar uma classe que possa simular o funcionamento de um elevador.
//Data: 06/04/2022


#include <iostream>
#include <vector>

using namespace std;

class Elevador {
  // coloque aqui a sua implementacao...
  
	private:
		int andarAtual;
		int totalAndares; //aqui se exclui o térreo, portanto um prédio que tem 5 andares terá do 0 ao 5º andar (inclusive), o térreo é o 0.
		int capacidade; //é a capacidade de pessoas que podem entrar no elevador.
		int numPessoas;
		
	public:
	
	Elevador() {
		andarAtual = 0;
		totalAndares = 0;
		capacidade = 0; 
		numPessoas = 0;
	}
	
	Elevador(int aa, int ta, int cap, int np) {
		andarAtual = aa;
		totalAndares = ta;
		capacidade = cap;
		numPessoas = np;
	}
	
	~Elevador()	{
		#ifdef DEBUG
		cout << "Elevador destruído..." << endl;
		#endif;
	}
	
	//método entra
	void entra() {
		++numPessoas;
		if (numPessoas > capacidade)
			numPessoas = capacidade;
	}
	
	//método sai
	void sai() {
		--numPessoas;
		if (numPessoas < 0)
			numPessoas = 0;
	}
	//método sobe
	void sobe() {
		++andarAtual;
		if (andarAtual > totalAndares)
			andarAtual = totalAndares;
	}
	
	//método desce
	void desce() {
		--andarAtual;
		if (andarAtual < 0)
			andarAtual = 0;
	}
	
	//Série de 4 getters
	int obtemAndarAtual() {
		return andarAtual;
	}
	
	int obtemTotalAndares() {
		return totalAndares;
	}
	
	int obtemCapacidade() {
		return capacidade;
	}
	
	int obtemNumPessoas() { //no enunciado o nome desse método é: obtemNumeroOcupantes, mas decidi manter o nome atual por ele estar na main.
		return numPessoas;
	}
 
  	//Série de 2 setters
	void defineTotalAndares(int ta) {
		totalAndares = ta;
	}
	
	void defineCapacidade(int cap) {
		capacidade = cap;
	}
  

	//método movimenta
	void movimenta(string operacao) {
		for (int i = 0; i<=operacao.size();i++){
			if (operacao.compare(i,1,"+") == 0) entra();
			
			else if (operacao.compare(i,1,"^") == 0) sobe();
			
			else if (operacao.compare(i,1,"v") == 0) desce();
			
			else if (operacao.compare(i,1,"-") == 0) sai();
			
			//else 
			//	cout << "Erro, informação não encontrada" << endl;
    } 
	}
/*essa comparação funciona, mas se colocar um else escrevendo um aviso de caso algo dê errado esse else será ativado, então é requerido maior investigação.*/
};

int main() {
  Elevador *e;
  int capacidade, totalAndares;
  string operacao;
  
  // LEITURA
  cin >> capacidade;
  cin >> totalAndares;
  cin >> operacao;
  // TESTE DE FUNCIONAMENTO
  e = new Elevador();
  if ( e->obtemAndarAtual()!=0 || e->obtemCapacidade()!=0 ||
       e->obtemNumPessoas()!=0 || e->obtemTotalAndares()!=0 )
      return 1;
  e->defineCapacidade(capacidade);
  if ( e->obtemAndarAtual()!=0 || e->obtemTotalAndares()!=0 ||
       e->obtemNumPessoas()!=0 || e->obtemCapacidade()!=capacidade )
      return 1;
  e->defineTotalAndares(totalAndares);
  if ( e->obtemAndarAtual()!=0 || e->obtemTotalAndares()!=totalAndares ||
       e->obtemNumPessoas()!=0 || e->obtemCapacidade()!=capacidade )
      return 1;
  for (int i=0; i<=totalAndares+2; ++i) {
      e->sobe();
      if ( e->obtemAndarAtual() > totalAndares ) return 1;
  }
  for (int i=0; i<=totalAndares+2; ++i) {
      e->desce();
      if ( e->obtemAndarAtual() < 0 ) return 1;
  }
  for (int i=0; i<=capacidade+2; ++i) {
      e->entra();
      if ( e->obtemNumPessoas() > capacidade ) return 1;
  }
  for (int i=0; i<=capacidade+2; ++i) {
      e->sai();
      if ( e->obtemNumPessoas() < 0 ) return 1;
  }
  // OPERACAO
  e->movimenta(operacao);
  // SAIDA
  cout << e->obtemNumPessoas() << " " << e->obtemAndarAtual() << endl;
  delete e;
  return 0;
}
