#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <fstream>

using namespace std;




// create a variable 'bank' representing a vector, to store words of type string
// the variable 'word' is created in an auxiliary way, so that there is not a series of messages received through the bank

string banco[100], palavra;


// the aux variable will be executed to define the range of the words that can be drawn
//
int aux = 0, tam = 0, game = 0;
	
	



// variable created that refers to the word drawn, because the game works with vectors, this vector will be filled by the user
// where the words drawn will be copied to this vector of char 'word_sort', we use the size of 30 because users words up to 30 characters
// if the word has more, only increase the size of this vector, and if the word has fewer characters, decrease the size of the vector

char palavra_sort[30];


// the user responsible for the user inputs, that is, will be responsible for what the user types
// will be responsible for recognition and fill-in based on data entry
char palavra_dig[30];

char ind_palavra;





// create the draw function so that it returns a random value in relation to the words
int Sorteia ()
{
	
// where the variable 'word' of type string, will receive the value in relation to the word drawn on the 'bench'
// where 'it will help define the size to which this random generation system will go
// the 'rand' function is part of the library 'stdlib.h'
// to use the Windows clock function, to generate random numbers, and to assign to a word, with
// relearning to our word bank, we assign the library 'time.h'
	
	palavra = banco [rand() % aux];
}

// function to print the word
void imprime_palavra_dig ()
{
	
	
	// prints as a hint to the user how many letters will have the words drawn during the game
	// responsible for counting the letters of the word drawn, according to their size, and giving output as a "hint" to the user for filling the force
	// using the 'strlen' command, to count this size, according to the number of characters of the word drawn
	cout << "\n     " << strlen(palavra_sort) << " letras \n\n     ";
	
	
// to print a word it is necessary to create a repeat loop to separate the string and check
// each character that exists in the word drawn, so it is passed to the variable 'word sort', to check the number of CHARACTERS, existing in the word drawn
// use the 'srtlen' command to find the size of a variable of type string, command that belongs to library 'string.h', traversing to the last position / char of the word drawn
	 
	for (int i = 0; i < strlen(palavra_sort); i ++)
	{
		cout << palavra_dig[i] << " ";
	}
}

// function that will be responsible for copying the word from 'bank', to the 'word_sort'
// where it was created the for ind, referring to the index of the word drawn, as parameter
void copia(int ind)
{
	// based on the word drawn, you will receive the string 'drawn'
	string sorteada = banco[rand() % aux];
	// repetition loop responsible for assigning the word drawn to a vector
	for (int i = 0; i < 30; i ++)
	{	
		palavra_sort[i] = sorteada[i];
	}
}


// to not generate memory garbage according to the initial value of the variable, the function 'clean_palavra_dig' is created, which will be set
// space for all vector positions
void limpa_palavra_dig()
{
	// repeat loop created to have GUARANTEE that vector 'word_dig' is blank
	// assigns the srtlen command to scroll the size of the word drawn according to its size
	for (int i = 0; i < strlen(palavra_sort); i++)
	{	
		// where will be assigned to each POSITION of the vector 'word_dig' a ??"_"
		palavra_dig [i] = '_';
	}
	
}


// function that will be responsible for printing the drawing of the gallows, will receive as a parameter the letters that the user missed, for their update

void imprime_forca (int let_erro)
{
	
	// created a switch with the update parameter on top of user errors	
	switch (let_erro)
	{
		case 0:
		cout << "  ____________"<< endl;
		cout << " |            "<< endl;
		cout << " |            "<< endl;
		cout << " |	           "<< endl;
		cout << " |            "<< endl;
			break;
		
		case 1:
		cout << "  ____________"<< endl;
		cout << " |           O"<< endl;
		cout << " |            "<< endl;
		cout << " |            "<< endl;
		cout << " |            "<< endl;
			break;
		
		case 2:
		cout << "  ____________"<< endl;
		cout << " |           O"<< endl;
		cout << " |           |"<< endl;
		cout << " |            "<< endl;
		cout << " |            "<< endl;
			break;
		
		case 3:
		cout << "  ____________"<< endl;
		cout << " |           O"<< endl;
		cout << " |          /|"<< endl;
		cout << " |            "<< endl;
		cout << " |            "<< endl;	
			break;
		
		case 4:
		cout << "  __________  "<< endl;
		cout << " |          O "<< endl;
		cout << " |         /|\\"<< endl;
		cout << " |            "<< endl;
		cout << " |            "<< endl;		
			break;
		
		
		
		case 5:	
		cout << "  __________  "<< endl;
		cout << " |          O "<< endl;
		cout << " |         /|\\"<< endl;
		cout << " |         /  "<< endl;
		cout << " |            "<< endl;		
			break;
		
		
		
		case 6:
		cout << "  __________  "<< endl;
		cout << " |          O "<< endl;
		cout << " |         /|\\"<< endl;
		cout << " |         / \\"<< endl;
		cout << " |            "<< endl;		
			break;
			
	}
	

}

// function responsible for the verification of data entries by the user, where he will pass returns, according to the vector "digitized_letter"
// receives as parameter, a variable of type char 'letter' that will be responsible for checking if the letter was actually typed, and will go through the vector of the word
// which is represented in the variable of type char 'vector', with the range of 26 = number of letters in the alphabet, and will return if in case the information is true will computer and replace
// the "_" of the force, or if it does not exist in the word drawn, and will be assigned to the vector that is responsible for the input of typed letters, and output in this data to the user
// if the letter is equal to the vector variable;
// we use strlen for memory optimization, so that it only traverses the number of characters of the typed word, not the 26 houses, which are responsible for allocating the whole alphabet in the vector
bool verifica_letra(char letra, char vetor[26])
{
	for (int i = 0; i < strlen (vetor); i++)
	{
		
	// if the letter has already been typed, if it returns true, in order not to count the error or the correctness
		if (letra == vetor[i])
		{
			return true;
		}
	}
	// if it has not yet been typed it will get the error or the hit computer, and assign to the vector of typed letters
	return false;
}


// function resposable by traversing the vector, and replace with a letter, according to the parameter passed in this function
void substitui(char letra)
{
	
	// will scroll the size of the word drawn, depending on the condition of the strlen command
	for (int i = 0; i < strlen (palavra_sort); i++)
	{
		// if the word drawn is equal to the input letter
		if (palavra_sort[i] == letra)
		{		
		// the word typed in the position, will receive / replace with a letter (user input)	
			palavra_dig[i] = letra;
		}
	}
}


// responsible for printing the letters entered by the user
// we use together the size of the vector letters as parameter, to ensure that no memory garbage is generated, if we used the command srtlen
//
void imprime_let_dig (char letras[], int tam)
{
	cout << "\n\n LETRAS DIGITADAS: "; 
	for (int i = 0; i < tam; i ++)
	{	
	// output of typed letters for presentation to the user
		cout << letras[i] << ", ";
	}
	
	cout << "\n";
	
}


// if the word is complete
bool palavra_completa()
{
	
	// if all positions of letters typed are different from "_"
	for (int i = 0; i < strlen(palavra_sort); i++)
	{
		// if the current position is equal to "_", it means that the word is NOT complete
		if (palavra_dig[i] == '_')
		{
			return false;
		}
	}
	
	// if the word is completely filled, it will generate the victory condition
	return true;
}

int main() 
{
	reset:
	
	game = 0;
	
	// Clean screen	
	system("cls");
	
	cout << "PRODUZIDO POR: EDUARDO, PEDRO E PAULO " << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	
	
	
	cout << "=========================O JOGAO DA FORCA=========================" << endl;
	cout << endl;
	cout << "\t\t\t\ MAIN MENU" << endl;
	cout << endl;
	cout << "\t\t\t\ New Game press (1)" << endl;
	cout << "\t\t\t\ Exit press (2)" << endl;
	cin >> game;

	
	
	if(game == 1){
		// Start the random number generator
		// call the seed rand function, where you create a "starting point", to start our word collection
		// based on the current time.
	    time_t t;
	    srand((unsigned) time(&t));
	    
		
		ifstream arquivo;
		string linha;
		
		// open file
		arquivo.open("testexto.txt");
		
		// If the file opens, it reads line by line
		if(arquivo.is_open()){
			while(getline(arquivo, linha)){
				banco[aux] =  linha;
				aux++;					
			}
		}
	
		// If it does not open, it displays message on screen
		else{
			cout << "Nao foi possivel abrir o arquivo txt" << endl;
		}
		
		
		// call the function 'Sorts' where no parameter is assigned	
		int Sorteia ();
		
		
		// function that will copy the word extracted from the bank, to the word drawn, passing the word indicated / drawn as parameter
		// where you will read the word "_" for the word drawn 		
		copia(ind_palavra);
		
		// Function responsible for clearing the vector of the typed word and replacing all characters with "_"
		limpa_palavra_dig ();
		
		// digital counter, starts at 0
		int cont_let_dig = 0;
		
		
		// start the error counter
		int cont_erros = 0;
		
		// resposable for storing the typed letters, the size of this vector is based on all alphabetic letters	
		char letras_digitadas[26]{};
		
		
		// variable responsible for user input
		char letra;
	
		
		// The 'while' will be responsible for capturing the input data, and interpretation of what the user will be typing
		// based on the drawing of the character of the gallows, it was attributed that as long as the number of errors is less than 6 he continues to execute this block	
		while (cont_erros< 6)
		{
			
			// clears the screen to refresh with the new information entered by the user	
			system ("cls");
			
			
			// print of the force at the beginning of the game, passing as parameter the error counter, where it starts in the command switch case 0, when there are 0 errors.
			imprime_forca(cont_erros);
	
			
			// function call referring to the printing of the word drawn
			// to check the function of calling this function, just assign a parameter, with the variable of type char 'ind_word'
			imprime_palavra_dig();
			
			
			// not to put all the letters together, the function of printing of the digital letters is created, where it receives the letters entered by the user as parameter
			// and also the typed letter counter, so that it is updated, and output to the user
			imprime_let_dig(letras_digitadas, cont_let_dig);
			
			
			cout << "\n\n Tentativas restantes: " << 6 - cont_erros << "\n\n";
			cout << "\n\n";
			cout << "Digite uma letra: ";
			cin >> letra;
			
			
			// as our word bank through the words generated from the external file, we add the 'tolower' command that is part of the library 'ctype.h'
			// where in case the user type letters in capital, it will revert these entries to minicuslos, so that one does not have errors when one has to hit
			// in case of input of fonts in upper case
			letra = tolower (letra);
			
			
			// if the letter exists, we will print the message on the screen that the letter has already been typed
			if (verifica_letra(letra, letras_digitadas))
			{
				cout << "LETRA JA FOI DIGITADA ! \n\n";
				system ("pause");
			}
			
			// if the letter is NOT between the letters typed
			else 
			{
				// you assign a vector that counts the letter you typed, where it will receive the variable letter
				letras_digitadas[cont_let_dig] = letra;
				
				// update char counter, for any letter typed, whether it is correct or error	
				cont_let_dig++;
				
				
				// vetation of the letter, if the letter exists in the word drawn	
				if (verifica_letra(letra, palavra_sort))
				{
					// se sim, substitui o "_" e imprime a letra
					substitui(letra);
				}
				
				
				// if the letter DOES NOT form part of the word drawn,
				else 
				{
					cout << "LETRA INCORRETA !" << endl;
					// we encrementamos / we update the error counter
					cont_erros++;
					system("pause");
				}
			}
			
			// if the number of errors is = or greater than 6
			if (cont_erros >= 6)
			{
				// the game will pause
				cout << "\n\nGAME OVER !" << endl;	
				
				// we will print to the user which word is typed
				cout << "\n\nA PALAVRA ERA: " << palavra_sort << endl << endl;
				system("pause");
				
				// and reset the game,
				goto reset;
				
			}
			
			
			// If the word is correct and complete (all positions that are "_" are filled, we will pass the function of victory
			if (palavra_completa())
			{
				cout << "\n\nYOU WIN ! CONGRATULATIONS !!" << endl;	
				// confirming the word drawn
				cout << "\n\nA PALAVRA ERA: " << palavra_sort << endl << endl;
				system("pause");
				// and reset the game
				goto reset;
			}				
		}
	}
	
	else if(game == 2){
		return 0;
	}
	else{
		cout << "CODIGO INVALIDO !" <<endl;
		system("pause");
		goto reset;
	}
	
	return 0;
}
