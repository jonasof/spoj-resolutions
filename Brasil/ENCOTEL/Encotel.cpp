#include <iostream>
#include <string>

using namespace std;

class TecladoDeTelefone {
    private:
        char numeros[9999];

    public:
        TecladoDeTelefone() {
			this->numeros['A'] = this->numeros['B'] = this->numeros['C'] = '2';
            this->numeros['D'] = this->numeros['E'] = this->numeros['F'] = '3';
            this->numeros['G'] = this->numeros['H'] = this->numeros['I'] = '4';
            this->numeros['J'] = this->numeros['K'] = this->numeros['L'] = '5';
            this->numeros['M'] = this->numeros['N'] = this->numeros['O'] = '6';
            this->numeros['P'] = this->numeros['Q'] = this->numeros['R'] = this->numeros['S'] = '7';
            this->numeros['T'] = this->numeros['U'] = this->numeros['V'] = '8';
            this->numeros['W'] = this->numeros['X'] = this->numeros['Y'] = this->numeros['Z'] = '9';

            for (int i = 0; i < 10; i++)
                this->numeros['0' + i] = '0' + i;

            this->numeros['-'] = '-';
		}

        char obterDigito(char letra) {
            return this->numeros[letra];
        }

        string obterNumeroDaPalavra(string palavra) {
            string digitos = "";

            for(int i=0; i < palavra.length(); i++) {
                char letra = palavra[i];
                digitos += this->obterDigito(letra);
            }
            return digitos;
        }
};

int main(){

	string palavra;
    TecladoDeTelefone teclado = TecladoDeTelefone();

	while (getline(cin,palavra))
        cout << teclado.obterNumeroDaPalavra(palavra) << endl;

	return 0;
}
