#include <iostream>
#include <string>

using namespace std;

class Autor {
private:
    string nome;

public:
    Autor(string n) : nome(n) {}

    string getNome() {
        return nome;
    }
};

class Livro {
private:
    string titulo;
    int anoPublicacao;
    Autor* autor;

public:
    Livro(string t, int ano, Autor* a) : titulo(t), anoPublicacao(ano), autor(a) {}

    void exibirDetalhes() {
        cout << "Título: " << titulo << endl;
        cout << "Ano de Publicação: " << anoPublicacao << endl;
        cout << "Autor: " << autor->getNome() << endl;
    }
};

int main() {
    string nomeAutor, tituloLivro;
    int ano;

    // Leitura dos dados do autor
    cout << "Digite o nome do autor: ";
    getline(cin, nomeAutor);

    // Leitura dos dados do livro
    cout << "Digite o título do livro: ";
    getline(cin, tituloLivro);
    cout << "Digite o ano de publicação: ";
    cin >> ano;

    // Criação do objeto Autor
    Autor autor(nomeAutor);

    // Criação do objeto Livro com ponteiro para o Autor
    Livro livro(tituloLivro, ano, &autor);

    // Exibição dos detalhes
    cout << endl;
    livro.exibirDetalhes();

    return 0;
}