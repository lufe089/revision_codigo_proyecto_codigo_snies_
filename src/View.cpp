#include "View.h"

View::View()
{
    string ruta1 = string("C:/SNIES_EXTRACTOR/inputs/programas.csv");
    string ruta2 = string("C:/SNIES_EXTRACTOR/inputs/admitidos");
    string ruta3 = string("C:/SNIES_EXTRACTOR/inputs/graduados");
    string ruta4 = string("C:/SNIES_EXTRACTOR/inputs/inscritos");
    string ruta5 = string("C:/SNIES_EXTRACTOR/inputs/matriculados");
    string ruta6 = string("C:/SNIES_EXTRACTOR/inputs/matriculadosPrimerSemestre");
    string ruta7 = string("C:/SNIES_EXTRACTOR/outputs/");
    controlador = SNIESController(ruta1, ruta2, ruta3, ruta4, ruta5, ruta6, ruta7);
}

View::~View()
{
    controlador.~SNIESController();
}

bool View::pantallaBienvenido()
{
    bool parametrizacionBool = false;

    cout << "Bienvenido al SNIES-Extractor!" << endl;
    cout << "=========================================" << endl;
    cout << "Recuerde que para el correcto funcionamiento del programa tuvo que haber parametrizado" << endl;
    cout << "antes la carpeta SNIES_EXTRACTOR en el disco duro C:, con sus respectivas carpetas inputs y outputs" << endl;
    cout << "y todos los archivo CSV del SNIES." << endl;
    cout << "Si ya hizo esto, escriba 'Y', de lo contrario 'N', y Enter: ";
    char userAnswer;
    cin >> userAnswer;
    cout << endl;
    userAnswer = tolower(userAnswer);
    if (userAnswer == 'y')
    {
        parametrizacionBool = true;

        string userText;
        cout << "A continuacion se procesaran los datos de los programas academicos seleccionados en /programas.csv..." << endl;
        cout << "Presione 'OK' y Enter para continuar: ";
        cin >> userText;
        cout << endl;

        string ano1("abc");
        string ano2("abc");
        string anoAux;
        int i = 0;
        bool anosValido = false;
        // Bucle para leer un valor valido del año1
        while (!(isConvetibleToInt(ano1)))
        {
            if (i == 1)
            {
                cout << "El valor ingresado fue invalido!" << endl;
                cout << "Por favor ingrese un valor valido la proxima" << endl;
                cout << "Presione 'OK' y Enter para continuar: ";
                cin >> userText;
                cout << endl;
            }
            cout << "Escriba el primer ano de busqueda: ";
            cin >> ano1;
            cout << endl;
            i = 1;
        }

        i = 0;
        // Bucle para leer un valor valido del año2
        while (!(isConvetibleToInt(ano2)))
        {
            if (i == 1)
            {
                cout << "El valor ingresado fue invalido!" << endl;
                cout << "Por favor ingrese un valor valido la proxima" << endl;
                cout << "Presione 'OK' y Enter para continuar: ";
                cin >> userText;
                cout << endl;
            }
            cout << "Escriba el segundo ano de busqueda: ";
            cin >> ano2;
            cout << endl;
            i = 1;
        }

        // Organizo los años
        if (stoi(ano2) < stoi(ano1))
        {
            anoAux = ano1;
            ano1 = ano2;
            ano2 = anoAux;
        }

        cout << "Procesando datos ..." << endl;
        controlador.procesarDatosCsv(ano1, ano2);
        cout << "Datos procesados con exito!" << endl;
    }

    return parametrizacionBool;
}

void View::salir()
{
    cout << "Cerrando programa..." << endl;
    cout << "Recuerde revisar la carpeta de outputs para los archivos .csv exportados" << endl;
    cout << "Programa Cerrado con exito!" << endl;
}

void View::visualizacionDatosExtra()
{
    char opcionYN;
    cout << "A continuacion vamos a mostrar datos relevantes de los programas academicos seleccionados" << "\n";
    cout << "Desea Convertir los datos a un archivo CSV?(Y/N): ";
    cin >> opcionYN;
    opcionYN = tolower(opcionYN);
    cout << "\n";

    if (opcionYN == 'y')
    {
        controlador.calcularDatosExtra(true);
    }

    else
    {
        controlador.calcularDatosExtra(false);
    }
}

void View::buscarPorPalabraClaveYFormacion()
{
    char opcionYN = 'y', opcionCSV;
    string palabraClave;
    bool convertirCSV;
    int idFormacionAcademica;

    while (opcionYN == 'y')
    {
        cout << "Desea hacer una busqueda por palabra clave del nombre del programa(Y/N): ";
        cin >> opcionYN;
        cout << "\n";
        opcionYN = tolower(opcionYN);

        if (opcionYN == 'y')
        {
            cout << "Deseas convertir convertir los datos del programa academico a un CSV?(Y/N): ";
            cin >> opcionCSV;
            cout << "\n";
            opcionCSV = tolower(opcionCSV);

            if (opcionCSV == 'y')
            {
                convertirCSV = true;
            }

            else
            {
                convertirCSV = false;
            }

            cout << "Escriba la palabra clave para buscar los programas por nombre:" << endl;
            cin >> palabraClave;
            cout << endl;

            cout << "Seleccione un nivel de formacion para filtrar: \n 1->Especializacion Universitaria\n 2->Maestria\n 3->Doctorado\n 4->Formacion Tecnica Profesional \n 5->Tecnologico\n 6->Universitario\n 7->Especializacion Tecnico Profesional\n 8->Especializacion Tecnologica\n 10->Especializacion Medico Quirurgica\n ";
            cin >> idFormacionAcademica;
            cout << "\n";
            while ((idFormacionAcademica > 10) || (idFormacionAcademica == 9) || (idFormacionAcademica < 1))
            {
                cout << "Seleccione una opcion entre 1-10 excluyendo el 9\n";
                cin >> idFormacionAcademica;
            }

            controlador.buscarProgramas(convertirCSV, palabraClave, idFormacionAcademica);
        }
    }
}

bool View::isConvetibleToInt(const string &str)
{
    try
    {
        std::size_t pos;
        int num = std::stoi(str, &pos);

        // Verificamos si se ha convertido toda la cadena
        return pos == str.length();
    }
    catch (const std::invalid_argument &)
    {
        // No se pudo convertir: la cadena no es un número válido
        return false;
    }
    catch (const std::out_of_range &)
    {
        // No se pudo convertir: el número está fuera del rango de int
        return false;
    }
}