#include <iostream>
#include<math.h>
using namespace std;
void decodificar (int semilla , int met, string nom , string sali);
void lect_print(string nombre_archivo);//lee e imprime todo lo que hay en un txt
void save(string nombre,string texto,int metodo,int semilla);//guarda la codificacion en un archivo
void saveDeco(string nombre,string texto);//guarda la decodificacion en un archivo
string texto_deco(string texto_para_volver_legible);//pasa el texto de binario a lenguaje legible
string lect_copy(string nombre_archivo);//copia todo el texto codificado a un string para poder decodificarlo despues

int main()
{
    for (int i=0;i<=50;i++)
    {
        cout<<endl;
    }
    string nombre, textobin, texto_codi, letra, guardar;
    int semi, met;
    cout<<"Bienvenido al sistema de decodificacion de texto"<<endl;
    cout<<"Digite el nombre de el archivo(sin extension) que desea decodificar: ";cin>>nombre;
    nombre+=".txt";//Se le agrega la extension
    cout<<"Digite en que semilla se codifico originalmente el texto: ";cin>>semi;
    while ((semi<2) || (semi>20))
    {
        cout<<"Digite en que semilla se codifico originalmente el texto: ";cin>>semi;
    }
    cout<<"Digite con que metodo se codifico originalmente el texto: ";cin>>met;
    while ((met<1) || (met>2))
    {
        cout<<"Digite con que metodo se codifico originalmente el texto: ";cin>>met;
    }
    cout<<endl;
    cout<<"Ingrese el nombre del archivo en el que desea guardarlo(sin extension): ";cin>>guardar;
    decodificar(semi,met,nombre,guardar);//se llama a la funcion que decodifica con los datos recibidos
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"Su texto fue decodificado."<<endl<<endl;
    cout<<endl<<endl;
    int term;
    cout<<"Archivo guardado, ingrese 1 para terminar o 2 para seguir usando el programa: ";cin>>term;
    while ((term<1) || (term>2))
    {
        cout<<"Ingrese 1 para terminar o 2 para seguir usando el programa: ";cin>>term;
    }
    bool terminar=false;
    if(term==1)
    {
        terminar=true;
    }
    else
    {
        terminar=false;
        for (int i=0;i<=50;i++)
        {
            cout<<endl;
        }
    }


    return 0;
}
void decodificar (int semilla , int met, string nom , string sali)
{
    string texto_codificado=lect_copy(nom), textonormal;
    if (met==1)
    {
        int posi=0,posi2=0, len=texto_codificado.length(), unos=0, ceros=0;
           string textofin,texto,textoaux,textoaux2,letra;
           int limite_ite=(len-1)/semilla,limite_interno;
           for (int i=0;i<=limite_ite;i++)
           {
               if(i==0)//si es la primera vez se invierte todo
               {
                   texto="";
                   for(int k=0;k<=semilla-1;k++)//se saca el bloque segun la semilla y se guarda en texto
                   {
                       if (posi>=len)
                           break;
                       letra=texto_codificado[posi];
                       texto+=letra;
                       posi++;
                   }
                   textoaux="";
                   for (int j=0;j<=semilla-1;j++)
                   {
                       letra=texto[j];
                       if(letra=="1")
                           textoaux+="0";
                       else
                           textoaux+="1";
                   }
                   textofin+=textoaux;
                   textoaux2=textoaux;
                   posi=0;
               }
               else//si no es la primera vez revisar el bloque anterior
               {
                   texto="";
                   for(int k=0;k<=semilla-1;k++)//se saca el bloque segun la semilla y se guarda en texto
                   {
                       if (posi>=len)
                           break;
                       letra=texto_codificado[posi];
                       texto+=letra;
                       posi++;
                   }
                   ceros=0;
                   unos=0;
                   for (int j=0;j<=semilla-1;j++)//se cuentan cuantos 0's y 1's hay
                   {
                       letra=textoaux2[j];
                       if(letra=="1")
                           unos++;
                       else
                           ceros++;
                   }
                   textoaux2="";
                   if(unos>ceros)//si hay mas 1's que 0's
                   {
                       texto="";
                       for(int k=0;k<=semilla-1;k++)//se saca el bloque segun la semilla y se guarda en texto
                       {
                           if (posi>=len)
                               break;
                           letra=texto_codificado[posi];
                           texto+=letra;
                           posi++;
                       }
                       limite_interno=texto.length();
                       posi-=semilla;
                       posi2=0;
                       for(int k=0;k<=limite_interno-1;k++)
                       {
                           letra=texto[k];
                           if(posi2==2)
                           {
                               if(letra=="1")
                                   letra="0";
                               else
                                   letra="1";
                               posi2=-1;
                           }
                           textoaux2+=letra;
                           posi2++;
                       }
                   }
                   else if(ceros>unos)//si hay mas 0's que 1's
                   {
                       texto="";
                       for(int k=0;k<=semilla-1;k++)//se saca el bloque segun la semilla y se guarda en texto
                       {
                           if (posi>=len)
                               break;
                           letra=texto_codificado[posi];
                           texto+=letra;
                           posi++;
                       }
                       limite_interno=texto.length();
                       posi-=semilla;
                       posi2=0;
                       for(int k=0;k<=limite_interno-1;k++)
                       {
                           letra=texto[k];
                           if(posi2==1)
                           {
                               if(letra=="1")
                                   letra="0";
                               else
                                   letra="1";
                               posi2=-1;
                           }
                           textoaux2+=letra;
                           posi2++;
                       }
                   }
                   else//si hay igual cantidad de 1's que de 0's se invierte todo
                   {
                       texto="";
                       for(int k=0;k<=semilla-1;k++)//se saca el bloque segun la semilla y se guarda en texto
                       {
                           if (posi>=len)
                               break;
                           letra=texto_codificado[posi];
                           texto+=letra;
                           posi++;
                       }
                       limite_interno=texto.length();
                       posi-=semilla;
                       for (int k=0;k<=limite_interno-1;k++)
                       {
                           letra=texto[k];
                           if(letra=="1")
                               letra="0";
                           else
                               letra="1";
                           textoaux2+=letra;
                       }
                   }
                   textofin+=textoaux2;
               }
           }
           textonormal=texto_deco(textofin);
           saveDeco(sali, textonormal);
    }
    else
    {
        int posi=0,len=texto_codificado.length(),nueva_pos;
            string textofin,texto,textoaux,letra;
            char pasochar;
            int limite_ite=(len-1)/semilla,limite_interno;
            for (int i=0;i<=limite_ite;i++)
            {
                texto="";
                for(int k=0;k<=semilla-1;k++)//se saca el bloque segun la semilla y se guarda en texto
                {
                    if (posi>=len)
                        break;
                    letra=texto_codificado[posi];
                    texto+=letra;
                    posi++;
                }
                limite_interno=texto.length();
                textoaux=texto;
                for(int k=0;k<=limite_interno-1;k++)
                {
                    pasochar=texto[k];
                    nueva_pos=k-1;
                    if(nueva_pos<0)
                        nueva_pos=limite_interno-1;
                    if(pasochar=='1' or pasochar=='0')
                        textoaux[nueva_pos]=pasochar;
                }
                textofin+=textoaux;
            }
            textonormal=texto_deco(textofin);
            saveDeco(sali, textonormal);
    }
}
void lect_print(string nombre)
{
    std::ifstream archivo;
    string texto;
    archivo.open("../Practica_3"+nombre, ios::in);//archivo en modo lectura
    if(archivo.fail())
    {
        cout<<"El archivo no se pudo abrir"<<endl;
        exit(1);
    }

    while(!archivo.eof())//Mientras no llegue a en End Of File
    {
        getline(archivo,texto);
        cout<<texto<<endl;
    }
    archivo.close();
}

void save(string nombre, string texto, int metodo, int semilla)
{
    ofstream escritura;
    string met=to_string(metodo), semi=to_string(semilla);
    string nombre_completo=nombre+"_met"+met+"_sem"+semi+".txt";
    escritura.open("../Practica_3"+nombre_completo);// Crear o abrir un archivo para escritura
    escritura<<texto;
    escritura.close();
}

void saveDeco(string nombre, string texto)
{
    ofstream escritura;
    string nombre_completo=nombre+"(decodificado)"+".txt";
    escritura.open("../Practica_3"+nombre_completo);// Crear o abrir un archivo para escritura
    escritura<<texto;
    escritura.close();
}

string binario(int digi)
{
    string binario, caracter,binar;
    for (int i=0;i<8;i++)
    {
        caracter=to_string(digi%2);
        binario+=caracter;
        digi/=2;
    }
    for (int i=7;i>=0;i--)
    {
        caracter=binario[i];
        binar+=caracter;
    }
    return binar;
}

string texto_bin(string nombre)
{
    ifstream archivo;
    string texto,caracter,bin;
    char caracter2;
    int numero;
    archivo.open("../Practica_3"+nombre, ios::in);//archivo en modo lectura
    if(archivo.fail())
    {
        cout<<"El archivo no se pudo abrir"<<endl;
        exit(1);
    }

    while(!archivo.eof())//Mientras no llegue a en End Of File
    {
        caracter2=archivo.get();
        if (archivo.eof())
            break;
        numero=caracter2;
        bin=binario(numero);
        texto+=bin;
    }
    archivo.close();
    return texto;
}

string texto_deco(string binario)
{
    int posi=0,len=binario.length();
    string textofin, texto, letra,texto2;
    int limite_ite=(len-1)/8, numero, suma;
    char caracter;
    for (int i=0;i<=limite_ite;i++)
    {
        texto="";
        suma=0;
        for(int k=0;k<=7;k++)//se saca el bloque segun la semilla y se guarda en texto
        {
            letra=binario[posi];
            texto+=letra;
            posi++;
        }
        texto2="";
        for(int k=7;k>=0;k--)
        {
            letra=texto[k];
            texto2+=letra;
        }
        texto=texto2;
        for (int k=0;k<=7;k++)
        {
            letra=texto[k];
            if(letra=="1")
            {
                numero= pow(2,k);
                suma+=numero;
            }
        }
        caracter=suma;
        textofin+=caracter;
    }
    return textofin;
}

string lect_copy(string nombre)
{
    ifstream archivo;
    string texto, textofin;
    archivo.open("../Practica_3"+nombre, ios::in);//archivo en modo lectura
    if(archivo.fail())
    {
        cout<<"El archivo no se pudo abrir"<<endl;
        exit(1);
    }

    while(!archivo.eof())//Mientras no llegue a en End Of File
    {
        getline(archivo,texto);
        textofin+=texto+"\n";
    }
    archivo.close();
    int len=textofin.length()-1;
    textofin.erase(len);
    return textofin;
}

void leerPasw(char frase[])
{
    int i=0;
    cout.flush();
    do
    {
        frase[i] = (unsigned char)getc();
        if(frase[i]!=8)  // no es retroceso
        {
            cout << '*';  // muestra por pantalla
            i++;
        }
        else if(i>0)    // es retroceso y hay caracteres
        {
            cout << (char)8 << (char)32 << (char)8;
            i--;  //el caracter a borrar e el backspace
        }
        cout.flush();
    }
    while(frase[i-1]!=13);  // si presiona ENTER
    frase[i-1] = NULL;
    cout << endl;
}

string convertir(char c)
{
    return string(1,c);
}
