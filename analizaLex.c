#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char letrasminusculas[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char letrasmayusculas[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char digito[10]={'0','1','2','3','4','5','6','7','8','9'};
struct reservadas{
    char lexema[30];
    int codigo;
}reservadas[15];
int comparaReser(char palabra[30]){
    for(int i=0;i<15;i++){
        if(palabra==reservadas[i].lexema)
            return reservadas[i].codigo;
    }
    return 0;
}
void inicializa(){
    strcpy(reservadas[8].lexema,"for");
    reservadas[0].codigo=100;
    strcpy(reservadas[8].lexema,"while");
    reservadas[1].codigo=101;
    strcpy(reservadas[2].lexema,"do");
    reservadas[2].codigo=102;
    strcpy(reservadas[3].lexema,"printf");
    reservadas[3].codigo=103;
    strcpy(reservadas[4].lexema,"scanf");
    reservadas[4].codigo=104;
    strcpy(reservadas[5].lexema,"if");
    reservadas[5].codigo=105;
    strcpy(reservadas[6].lexema,"else");
    reservadas[6].codigo=106;
    strcpy(reservadas[7].lexema,"break");
    reservadas[7].codigo=107;
    strcpy(reservadas[8].lexema,"switch");
    reservadas[8].codigo=108;
    strcpy(reservadas[9].lexema,"case");
    reservadas[9].codigo=109;
    strcpy(reservadas[10].lexema,"pow");
    reservadas[10].codigo=110;
    strcpy(reservadas[11].lexema,"sqrt");
    reservadas[11].codigo=111;
    strcpy(reservadas[12].lexema,"fprint");
    reservadas[12].codigo=112;
    strcpy(reservadas[13].lexema,"fscan");
    reservadas[13].codigo=113;
    strcpy(reservadas[14].lexema,"return");
    reservadas[14].codigo=114;
}

char comparaChar(char caracter){
    for(int i=0;i<26;i++){
        if(caracter==letrasmayusculas[i]){
            return 1;            
        }
        if(caracter==letrasminusculas[i]){
            return 1;            
        }
    }
    for(int j=0;j<10;j++){
        if(caracter==digito[j])
            return 2;
    }
}
int cambiaEstado(int actual, char caracter){
    switch(actual){
        case 0: return 1;
        case 1: if(caracter=='/')
                    return 2;
                if(caracter=='"')
                    return 5;
                if(caracter=='<')
                    return 7;
                if(caracter=='>')
                    return 9;
                if(caracter=='=')
                    return 11;
                if(caracter=='!')
                    return 13;
                if(caracter=='+')
                    return 15;
                if(caracter=='-')
                    return 17;
                if(caracter=='*')
                    return 19;
                if(caracter=='&')
                    return 20;
                if(caracter=='|')
                    return 22;
                if(comparaChar(caracter)==1)
                    return 24;
                if(comparaChar(caracter)==2)
                    return 25;
                if(caracter=='#')
                    return 31;
                return 1;
                break;
        case 2: if(caracter=='/')
                    return 3;
                return 1;
                break;
        case 3: if(caracter=='\n')
                    return 4;
                return 3;
                break;
        case 4: return 1;
                break;
        case 5: if(caracter=='"')
                    return 6;
                return 5;
                break;
        case 6: return 1;
                break;
        case 7: if(caracter=='=')
                    return 8;
                return 1;
                break;
        case 8: return 1;
                break;
        case 9: if(caracter=='=')
                    return 10;
                return 1;
                break;
        case 10: return 1;
                break;
        case 11: if(caracter=='=')
                    return 12;
                return 1;
                break;
        case 12: return 1;
                break;
        case 13: if(caracter=='=')
                    return 14;
                return 1;
                break;
        case 14: return 1;
                break;
        case 15: if(caracter=='+')
                    return 16;
                return 1;
                break;
        case 16: return 1;
                break;
        case 17: if(caracter=='-')
                    return 18;
                return 1;
                break;
        case 18: return 1;
                break;
        case 19: return 1;
                break;
        case 20: if(caracter=='&')
                    return 21;
                return 1;
                break;
        case 21: return 1;
                break;
        case 22: if(caracter=='|')
                    return 23;
                return 1;
                break;
        case 23: return 1;
                break;
        case 24: if(comparaChar(caracter)==1||comparaChar(caracter)==2||caracter=='_')
                    return 24;
                return 1;
                break;
        case 25: if(comparaChar(caracter)==2)
                    return 25;
                if(caracter=='.')
                    return 26;
                if(caracter=='E'||caracter=='e')
                    return 28;
                return 1;
                break;
        case 26: if(comparaChar(caracter)==2)
                    return 27;
                return 1;
                break;
        case 27: if(caracter=='E'||caracter=='e')
                    return 28;
                return 1;
                break;
        case 28: if(caracter=='+'||caracter=='-')
                    return 29;
                if(comparaChar(caracter)==2)
                    return 30;
                return 1;
                break;
        case 29: if(comparaChar(caracter)==2)
                    return 30;
                return 1;
                break;
        case 30: if(comparaChar(caracter)==2)
                    return 30;
                return 1;
                break;
        case 31: if(caracter=='i')
                    return 32;
                return 1;
                break;
        case 32: if(caracter=='n')
                    return 33;
                return 1;
                break;
        case 33: if(caracter=='c')
                    return 34;
                return 1;
                break;
        case 34: if(caracter=='l')
                    return 35;
                return 1;
                break;
        case 35: if(caracter=='u')
                    return 36;
                return 1;
                break;
        case 36: if(caracter=='d')
                    return 37;
                return 1;
                break;
        case 37: if(caracter=='e')
                    return 38;
                return 1;
                break;
        case 38: return 1;
                break;
        default: return 1;
                break;
    }
}

char* estadoFinal(int estado, char cadena[]){
    int c;
    switch(estado)
    {
    case 4: printf("COMENTARIO"); return "200";
        break;
    case 6: printf("CADENA");  return "201";
        break;
    case 7: printf("OPR_MENOR");  return "300";
        break;
    case 8: printf("OPR_MENORIGUAL");  return "301";
        break;
    case 9: printf("OPR_MAYOR");  return "302";
        break;
    case 10: printf("OPR_MAYORIGUAL");  return "303";
        break;
    case 11: printf("ASIGNACION");  return "202";
        break;
    case 12: printf("OPR_IGUAL"); return "304";
        break;
    case 13: printf("OPL_NOT"); return "400";
        break;
    case 14: printf("OPL_DIFERENTE"); return "305";
        break;
    case 15: printf("OPL_SUMA"); return "500";
        break;
    case 16: printf("OPL_INCREMENTO"); return "501";
        break;
    case 17: printf("OPL_RESTA"); return "502";
        break;
    case 18: printf("OPL_DECREMENTO"); return "503";
        break;
    case 19: printf("OPL_MULTIPLICACION"); return "504";
        break;
    case 21: printf("OPL_AND"); return "401";
        break;
    case 23: printf("OPL_OR"); return "402";
        break;
    case 24: c=comparaReser(cadena);
            if(c!=0)
                return c;
            printf("ID");
            return "203";
            break;
    case 25: printf("NUM_ENTERO"); return "204";
            break;
    case 27: printf("NUM_FLOTANTE"); return "205";
            break;
    case 30: printf("NUM_EXPONENCIAL"); return "206";
            break;
    case 38: printf("PR_INCLUDE"); return "115";
            break;
    default: return "0";
        break;
    }
}

int main (){
    char bufer[500];
    FILE *archivoEntrada,*archivoSalida;
    int e_anterior=1, e_siguiente=1;
    char linea[100]={};
    int numlinea=1,lin=0;
    char *codigo;
    char c_anterior,c_siguiente;
    int i=0;
    archivoEntrada=fopen("texto.txt","r");
    archivoSalida=fopen("salida.txt","w");
    if(archivoEntrada == NULL){
        exit(1);
        printf("Ocurrio un error con el archivo");
    }else{
        e_anterior=e_siguiente;
		while (feof(archivoEntrada) == 0) {
            lin++;
			c_siguiente = fgetc(archivoEntrada);
            e_anterior=e_siguiente;
            c_anterior=c_siguiente;
            e_siguiente=cambiaEstado(e_anterior,c_siguiente);
            if(c_siguiente=='\n'){
                numlinea++;
                lin=0;
            }
                if(e_siguiente!=1){
                    linea[i]=c_anterior;
                    i++;
                }
                if(e_siguiente==1){
                   
                    codigo=estadoFinal(e_anterior,linea);
                     if(codigo=="0"){
                        printf("Error linea: %d columna:%d\n",numlinea,lin);
                     }else{
                        printf(" linea: %d columna: %d lexema: %s \n",numlinea,lin,linea);
                    if(codigo!=0){
                        if(i>1){
                        fputs(codigo,archivoSalida);
                        fputs(" ",archivoSalida);
                        fputs(linea,archivoSalida);
                        for(int x=0; x<strlen(linea);x++){
                            linea[x]=' ';
                        }
                        i=0;
                        i++;
                    }else{
                        fputs(codigo,archivoSalida);
                        fputs(" ",archivoSalida);
                        fputs(linea,archivoSalida);
                        for(int x=0; x<strlen(linea);x++){
                            linea[x]=' ';
                        }
                    }
                    fputs("\n",archivoSalida);
                    }
                     }
                    
                }
		}
        fclose(archivoSalida);
		fclose(archivoEntrada);
    } 
}
