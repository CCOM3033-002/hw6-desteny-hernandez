#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

// prototipos de funciones

char menu2_seleccion();

double get_radio(char);
double get_altura(char);
double get_largo();
double get_ancho();

bool inputValidation(double); // input validation para los numeros que el usuario escoga
bool inputValidation(char);	// input validation para las selecciones hechas

double volumen(double, double); // volumen del cilindro
double area(double, double);	  // area del cilindro

double volumen(double); // volumen de la esfera
double area(double);    // area de la esfera

double volumen(double, double, double); // volumen de la prisma rectangular
double area(double, double, double);	// area de la prisma rectangular

const double pi = 3.14159; // constante global PI

double radio, altura, largo, ancho; // declaramos variables para las figuras 3D

int main()
{
	cout << "Este programa calcula el volumen y el area de la superficie de tres figuras." << endl;
	cout << endl;

	bool inputValido; // declaramos un flag para validar inputs.

	char seleccionMenu1, seleccionMenu2; // declaramos variable de seleccion para el menu1 y menu2

	do
	{
		// menu1: le pedimos al usuario que seleccione una de tres figuras disponibles

		cout << "Escoga una figura:\n \ta. Cilindro\n \tb. Esfera\n \tc. Prisma rectangular" << endl;
		cout << "Seleccion: ";

		cin >> seleccionMenu1; // le pide al usuario su seleccion de figura

		switch (seleccionMenu1) // de acuerdo a su seleccion...
		{
		case 'a': // a. Cilindro

			do
			{
				seleccionMenu2 = menu2_seleccion();		  // desplega el menu 2 para seleccionar entre 'a. Volumen' y 'b. Area'
				inputValido = inputValidation(seleccionMenu2); // input validation de la seleccion
			} while (!inputValido);						  // se itera si la seleccion no fue ni 'a' ni 'b'

			do
			{
				radio = get_radio('a');			   // le pide al usuario el radio del Cilindro
				inputValido = inputValidation(radio); // inputValidation del 'radio'
			} while (!inputValido);				   // se itera si 'radio' no es valido

			do
			{
				altura = get_altura('a');		    // le pide al usuario la altura del Cilindro
				inputValido = inputValidation(altura); // inputValidation de la altura
			} while (!inputValido);				    // se itera si la 'altura' no es valida

			switch (seleccionMenu2) // dependiendo de la seleccion en el menu2 se desplega en pantalla el resultaldo de volumen() o area()
			{
			case 'a': // si la seleccion fue a. volumen
				cout << "El volumen del cilindro es " << setprecision(2) << fixed << volumen(radio, altura) << endl;
				break;
			case 'b': // si la seleccion fue b. area de la superficie
				cout << "El area del cilindro es " << setprecision(2) << fixed << area(radio, altura) << endl;
				break;
			}

			break; // se sale del case a. Cilindro

		case 'b': // b. Esfera

			do
			{
				seleccionMenu2 = menu2_seleccion();		  // desplega el menu 2 para seleccionar entre 'a. Volumen' y 'b. Area'
				inputValido = inputValidation(seleccionMenu2); // input validation de la seleccion
			} while (!inputValido);						  // se itera si la seleccion no fue ni 'a' ni 'b'

			do
			{
				radio = get_radio('b');			   // le pide al usuario el radio de la Esfera
				inputValido = inputValidation(radio); // inputValidation del 'radio'
			} while (!inputValido);				   // se itera si 'radio' no es valido

			switch (seleccionMenu2) // dependiendo de la seleccion en el menu2 se desplega en pantalla el resultaldo de volumen() o area()
			{
			case 'a': // si la seleccion fue a. volumen
				cout << "El volumen de la esfera es " << setprecision(2) << fixed << volumen(radio) << endl;
				break;
			case 'b': // si la seleccion fue b. area de la superficie
				cout << "El area de la esfera es " << setprecision(2) << fixed << area(radio) << endl;
				break;
			}
			break; // se sale del case b. Esfera

		case 'c': // c. Prisma Rectangular
			do
			{
				seleccionMenu2 = menu2_seleccion();		  // desplega el menu 2 para seleccionar entre 'a. Volumen' y 'b. Area'
				inputValido = inputValidation(seleccionMenu2); // input validation de la seleccion
			} while (!inputValido);						  // se itera si la seleccion no fue ni 'a' ni 'b'

			do
			{
				altura = get_altura('c');		    // le pide al usuario la altura de la Prisma Rectangular
				inputValido = inputValidation(altura); // inputValidation de la altura
			} while (!inputValido);				    // se itera si la 'altura' no es valida

			do
			{
				largo = get_largo();			   // le pide al usuario el largo de la Prisma Rectangular
				inputValido = inputValidation(largo); // inputValidation del 'largo'
			} while (!inputValido);				   // se itera si 'largo' no es valido

			do
			{
				ancho = get_ancho();			   // le pide al usuario el ancho de la Prisma Rectangular
				inputValido = inputValidation(ancho); // inputValidation del 'ancho'
			} while (!inputValido);				   // se itera si 'ancho' no es valido

			switch (seleccionMenu2) // dependiendo de la seleccion en el menu2 se desplega en pantalla el resultaldo de volumen() o area()
			{
			case 'a': // si la seleccion fue a. volumen
				cout << "El volumen de la prisma rectangular es " << setprecision(2) << fixed << volumen(altura, largo, ancho) << endl;
				break;
			case 'b': // si la seleccion fue b. area de la superficie
				cout << "El area de la prisma rectangular es " << setprecision(2) << fixed << area(altura, largo, ancho) << endl;
				break;
			}

			break; // se sale del case 'c'

		default:
			inputValido = false; // el input del menu 1 fue invalido
			cout << "\nSu seleccion fue incorrecta... intente denuevo." << endl;
		}
	} while (!inputValido); // se itera si el input del menu 1 fue invalido
	return 0;
}

// definiciones de funciones

// uso: se desplega el menu2 en pantalla menu donde el usuario escoge entre a. Volumen y b. Area de la superficie
// input: -
// output: caracter con la la seleccion del menu2
char menu2_seleccion()
{
	cout << "\nescoga entre las siguientes opciones: \n \ta. Volumen \n \tb. Area de la superficie. \n Seleccion: ";
	char seleccion;   // declaramos variable para la seleccion
	cin >> seleccion; // le pide al usuario su 'seleccion'
	return seleccion; // retorna el caracter escrito por el usuario
}

// uso: valida el input de la seleccion del menu2
// input: un caracter con la la seleccion del menu2
// output: dato booleano
bool inputValidation(char seleccion)
{
	if ((seleccion == 'a') || (seleccion == 'b')) // input valido si es 'a' o 'b'
		return true;
	// else el input es invalido
	cout << "\nSeleccion incorrecta. ";
	return false;
}

// uso: valida el input de numeros entrados
// input: numero real
// output: dato booleano
bool inputValidation(double num)
{
	if (num >= 0) // input valido si no es negativo
		return true;
	// else el input es invalido
	cout << "\nNumero no puede ser negativo. ";
	return false;
}

// uso: le pide al usuario el radio, dependiendo de la figura seleccionada en el menu1
// input: caracter con la seleccion del menu1
// output: el radio
double get_radio(char seleccionMenu1)
{
	switch (seleccionMenu1) // se toma en cuenta la seleccion del usuario en el menu1
	{
	case 'a': // a. Cilindro...
		cout << "\nEntre el radio del cilindro: ";
		break;

	case 'b': // b. Esfera...
		cout << "\nEntre el radio de la esfera: ";
		break;
	}
	cin >> radio; // se le pide el 'radio' al usuario
	return radio;
}

// uso: le pide al usuario la altura, dependiendo de la figura seleccionada en el menu1
// input: caracter con la seleccion del menu1
// output: la altura
double get_altura(char seleccionMenu1) // cilindro y la prisma rectangular
{
	switch (seleccionMenu1) // se toma en cuenta la seleccion del usuario en el menu1
	{
	case 'a': // a. Cilindro
		cout << "Entre la altura del cilindro: ";
		break;

	case 'c': // c. Prisma Rectangular
		cout << "\nEntre la altura de la prisma rectangular: ";
		break;
	}
	cin >> altura; // se le pide la 'altura' al usuario
	return altura;
}

// uso: le pide al usuario el largo de la prisma rectangular
// input: -
// output: el largo
double get_largo() // la prisma rectangular
{
	cout << "Entre el largo de la prisma rectangular: ";
	cin >> largo; // se le pide el 'largo' al usuario
	return largo;
}

// uso: le pide al usuario el ancho de la prisma rectangular
// input: -
// output: el ancho
double get_ancho() // la prisma rectangular
{
	cout << "Entre el ancho de la prisma rectangular: ";
	cin >> ancho; // se le pide el 'ancho' al usuario
	return ancho;
}

// uso: calcula el volumen de un cilindro
// input: el radio y la altura
// output: el volumen del cilindro
double volumen(double radio, double altura)
{
	double result = pi * altura * (radio * radio);
	return result;
}

// uso: calcula el area de un cilindro
// input: radio y la altura
// output: el area de la superficie de un cilindro
double area(double radio, double altura)
{
	double result = 2 * pi * radio * altura + 2 * pi * (radio * radio);
	return result;
}

// uso: calcula el volumen de la esfera
// input: el radio
// output: el volumen de la esfera
double volumen(double radio)
{
	double result = (4.0 / 3.0) * pi * (radio * radio * radio);
	return result;
}

// uso: calcula el area de la esfera
// input: el radio
// output: el area de la esfera
double area(double radio)
{
	double result = 4 * pi * (radio * radio);
	return result;
}

// uso: calcula el volumen de la prisma rectangular
// input: la altura, el largo, y el acho de una prisma rectangular
// output: el volumen
double volumen(double altura, double largo, double ancho)
{
	double result = altura * largo * ancho;
	return result;
}

// uso: calcula el area de la prisma rectangular
// input: la altura, el largo, y el acho de una prisma rectangular
// output: el area
double area(double altura, double largo, double ancho)
{
	double result = 2 * (largo * ancho + largo * altura + ancho * altura);
	return result;
}