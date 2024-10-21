#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_LINHA 100
#define MAX_ARGS 64

int indLinha = 0;
FILE *fpSai, *fpEnt, *fpLst;
int indRotulo = 0;
int passo = 0;
char vIdent[256][100];
char vValor[256][100];
int posMemoria = 0;
int ENDEncontrado = 0;

int IP = 0;
int mem[256];

enum { LABEL, MNEMO, ARG1, ARG2, COMENT };

typedef enum {
  EQU = 1,
  ORG,
  DB,
  END,
  MOV,
  ADD,
  SUB,
  CMP,
  INC,
  DEC,
  JC,
  JNC,
  JZ,
  JNZ,
  JBE,
  JA,
  JMP,
  CALL,
  RET,
  HLT
} CodMnemoDiret;

void erro(const char msg[]) {
  printf("Erro: Linha %d: %s\n", indLinha, msg);
  fprintf(fpLst, "Erro: Linha %d: %s\n", indLinha, msg);
}

void aviso(const char msg[]) {
  printf("Aviso: Linha %d: %s\n", indLinha, msg);
  fprintf(fpLst, "Aviso: Linha %d: %s\n", indLinha, msg);
}

char *buscaIdent(char *ident) {
  int i;
  for (i = 0; i < indRotulo; i++) {
    if (!strcmp(vIdent[i], ident)) {
      return vValor[i];
    }
  }
  return NULL;
}

int insereIdent(char *ident, char *valor) {
  if (buscaIdent(ident) == NULL) {
    strcpy(vIdent[indRotulo], ident);
    strcpy(vValor[indRotulo++], valor);
    return 1;
  }
  return 0;
}

CodMnemoDiret codMnemoDiret(char str[]) {
  if (!strcmp(str, "equ")) {
    return EQU;
  } else if (!strcmp(str, "org")) {
    return ORG;
  } else if (!strcmp(str, "db")) {
    return DB;
  } else if (!strcmp(str, "end")) {
    return END;
  } else if (!strcmp(str, "mov")) {
    return MOV;
  } else if (!strcmp(str, "add")) {
    return ADD;
  } else if (!strcmp(str, "sub")) {
    return SUB;
  } else if (!strcmp(str, "cmp")) {
    return CMP;
  } else if (!strcmp(str, "inc")) {
    return INC;
  } else if (!strcmp(str, "dec")) {
    return DEC;
  } else if (!strcmp(str, "call")) {
    return CALL;
  } else if (!strcmp(str, "ret")) {
    return RET;
  } else if (!strcmp(str, "hlt")) {
    return HLT;
  } else if (!strcmp(str, "jc")) {
    return JC;
  } else if (!strcmp(str, "jmp")) {
    return JMP;
  } else if (!strcmp(str, "jnc")) {
    return JNC;
  } else if (!strcmp(str, "jz")) {
    return JZ;
  } else if (!strcmp(str, "jnz")) {
    return JNZ;
  } else if (!strcmp(str, "jbe")) {
    return JBE;
  } else if (!strcmp(str, "ja")) {
    return JA;
  } else {
    return (CodMnemoDiret)0;
  }
}

void divide(char linha[TAM_LINHA], char rotulo[TAM_LINHA],
            char mnemo[TAM_LINHA], char args[][TAM_LINHA],
            char coment[TAM_LINHA]) {
  rotulo[0] = mnemo[0] = coment[0] = '\0';

  char *pVirg = strchr(linha, ';');
  if (pVirg != NULL) {
    strcpy(coment, pVirg);
    *pVirg = '\0'; // retira comentario ate' final da linha;
  }

  // Separa o rotulo
  int i = 0;
  if (isalpha(linha[i]) || linha[i] == '_') {
    while (linha[i] && (isalnum(linha[i]) || linha[i] == '_')) {
      rotulo[i] = tolower(linha[i]);
      i++;
    }
    rotulo[i] = 0;
  }

  while (linha[i] && (linha[i] == ' ' || linha[i] == '\t')) {
    i++;
  }

  // Separa o Mnemonico
  int iAux = 0;
  while (linha[i] && (isalnum(linha[i]) || linha[i] == '_')) {
    mnemo[iAux++] = tolower(linha[i++]);
  }
  mnemo[iAux] = '\0';

  while (linha[i] && isspace(linha[i])) {
    i++;
  }

  // Separa os argumentos
  int iArg = 0;
  int virgula;
  do {
    virgula = 0;
    int iAux = 0;
    while (linha[i] && (isalnum(linha[i]) || linha[i] == '_' ||
                        linha[i] == '[' || linha[i] == ']')) {
      args[iArg][iAux++] = tolower(linha[i++]);
    }
    args[iArg][iAux] = '\0';

    iArg++;
    while (linha[i] && (linha[i] == ' ' || linha[i] == '\t')) {
      i++;
    }
    if (linha[i] == ',') {
      i++;
      virgula = 1;
    }
    while (linha[i] && (linha[i] == ' ' || linha[i] == '\t')) {
      i++;
    }
  } while (linha[i] && virgula);

  if (linha[i] != '\0') {
    erro("Erro de sintaxe.");
  }

  // Limpa os argumentos não usados
  for (; iArg < MAX_ARGS; iArg++) {
    args[iArg][0] = '\0';
  }
}

int substituiRotulo(char *arg) {
  char temp[100];
  char *p;
  if (arg[0] == '[') {
    strcpy(temp, &arg[1]);
    int tam = strlen(temp);
    temp[tam - 1] = '\0';
    p = buscaIdent(temp);
    if (p != NULL) {
      sprintf(arg, "[%s]", p);
    }
  } else {
    p = buscaIdent(arg);
    if (p != NULL) {
      strcpy(arg, p);
    }
  }
  return 1;
}

int verificaArgumento(char arg[], const char a[]) {
  if (strcmp(arg, "[b]") && !strcmp(a, "[l]")) {
    int tam = strlen(arg);
    if (arg[0] != '[' || arg[tam - 1] != ']' || tam < 3) {
      return 0;
    }
  } else if (strcmp(arg, "b") && !strcmp(a, "l")) {
    int tam = strlen(arg);
    if (tam < 1) {
      return 0; // se arg não é igual ao padrão esperado
    }
  } else {
    if (strcmp(a, arg)) {
      return 0; // se arg não é igual ao padrão esperado
    }
  }
  return 1;
}

int verificaArgumentos1e2(char args[][TAM_LINHA], const char a1[],
                          const char a2[]) {
  if (!verificaArgumento(args[0], a1)) {
    return 0;
  }
  if (!verificaArgumento(args[1], a2)) {
    return 0;
  }
  if (args[2][0] != '\0') {
    return 0;
  }
  return 1;
}

int convParaInt(char str[]) {
  int tam, val = 0;

  if (passo != 1) {
    substituiRotulo(str);
  }

  tam = strlen(str);
  if (str[0] == '[' && str[tam - 1] == ']') {
    str = &str[1];
    tam -= 2;
  }
  if (isdigit(str[0]) || str[0] == '+' || str[0] == '-') {
    char *ptr;
    if (str[tam - 1] == 'h') {
      tam--;
      val = strtol(str, &ptr, 16);
    } else {
      val = strtol(str, &ptr, 10);
    }
    if ((ptr - str) <= tam - 1) {
      erro("Valor inválido no argumento ou simbolo não encontrado.");
    }
  } else {
    if (passo != 1) {
      erro("Simbolo não encontrado.");
    }
  }
  if (val < 0) {
    val = 256 - val;
  }
  if (val > 255) {
    erro("O valor deve ter no máximo 1 byte [0..255].");
  }
  return val;
}

void atribMemIP(int dado) {
  mem[IP] = dado;
  if (passo == 2) {
    fprintf(fpLst, "    [%03d]: %02xh\n", IP, dado);
  }
  IP++;
}

/**************************************
 * INSTRUÇÕES
 * ************************************/
void mnemoMOV(char args[][TAM_LINHA]) {
  if (verificaArgumentos1e2(args, "a", "b")) {
    atribMemIP(0x88);
  } else if (verificaArgumentos1e2(args, "b", "a")) {
    atribMemIP(0x8a);
  } else if (verificaArgumentos1e2(args, "a", "[l]")) {
    atribMemIP(0xa0);
    atribMemIP(convParaInt(args[1]));
  } else if (verificaArgumentos1e2(args, "a", "[b]")) {
    atribMemIP(0xa1);
  } else if (verificaArgumentos1e2(args, "[l]", "a")) {
    atribMemIP(0xa2);
    atribMemIP(convParaInt(args[0]));
  } else if (verificaArgumentos1e2(args, "[b]", "a")) {
    atribMemIP(0xa3);
  } else if (verificaArgumentos1e2(args, "a", "l")) {
    atribMemIP(0xb0);
    atribMemIP(convParaInt(args[1]));
  } else {
    erro("Argumento inválido.");
  }
}

void mnemoADD(char args[][TAM_LINHA]) {
  if (verificaArgumentos1e2(args, "a", "[l]")) {
    atribMemIP(0x02);
    atribMemIP(convParaInt(args[1]));
  } else if (verificaArgumentos1e2(args, "a", "[b]")) {
    atribMemIP(0x03);
  } else if (verificaArgumentos1e2(args, "a", "l")) {
    atribMemIP(0x04);
    atribMemIP(convParaInt(args[1]));
  } else {
    erro("Argumento inválido.");
  }
}

void mnemoSUB(char args[][TAM_LINHA]) {
  if (verificaArgumentos1e2(args, "a", "[l]")) {
    atribMemIP(0x2a);
    atribMemIP(convParaInt(args[1]));
  } else if (verificaArgumentos1e2(args, "a", "[b]")) {
    atribMemIP(0x2b);
  } else if (verificaArgumentos1e2(args, "a", "l")) {
    atribMemIP(0x2c);
    atribMemIP(convParaInt(args[1]));
  } else {
    erro("Argumento inválido.");
  }
}

void mnemoCMP(char args[][TAM_LINHA]) {
  if (verificaArgumentos1e2(args, "a", "[l]")) {
    atribMemIP(0x3a);
    atribMemIP(convParaInt(args[1]));
  } else if (verificaArgumentos1e2(args, "a", "[b]")) {
    atribMemIP(0x3b);
  } else if (verificaArgumentos1e2(args, "a", "l")) {
    atribMemIP(0x3c);
    atribMemIP(convParaInt(args[1]));
  } else {
    erro("Argumento inválido.");
  }
}

void mnemoINC(char args[][TAM_LINHA]) {
  if (verificaArgumentos1e2(args, "a", "")) {
    atribMemIP(0x40);
  } else if (verificaArgumentos1e2(args, "b", "")) {
    atribMemIP(0x41);
  } else {
    erro("Argumento inválido.");
  }
}

void mnemoDEC(char args[][TAM_LINHA]) {
  if (verificaArgumentos1e2(args, "a", "")) {
    atribMemIP(0x42);
  } else if (verificaArgumentos1e2(args, "b", "")) {
    atribMemIP(0x43);
  } else {
    erro("Argumento inválido.");
  }
}

void mnemoJUMP(CodMnemoDiret mnemo, char args[][TAM_LINHA]) {
  if (verificaArgumentos1e2(args, "l", "")) {
    switch (mnemo) {
    case JC:
      atribMemIP(0x72);
      break;
    case JNC:
      atribMemIP(0x73);
      break;
    case JZ:
      atribMemIP(0x74);
      break;
    case JNZ:
      atribMemIP(0x75);
      break;
    case JBE:
      atribMemIP(0x76);
      break;
    case JA:
      atribMemIP(0x77);
      break;
    case JMP:
      atribMemIP(0xeb);
    }
    atribMemIP(convParaInt(args[0]));
  } else {
    erro("Argumento inválido.");
  }
}

void mnemoCALL(char args[][TAM_LINHA]) {
  if (verificaArgumentos1e2(args, "l", "")) {
    atribMemIP(0xe8);
    atribMemIP(convParaInt(args[0]));
  } else {
    erro("Argumento inválido.");
  }
}

void mnemoRET(char args[][TAM_LINHA]) {
  if (verificaArgumentos1e2(args, "", "")) {
    atribMemIP(0xc3);
  } else {
    erro("Argumento inválido.");
  }
}

void mnemoHLT(char args[][TAM_LINHA]) {
  if (verificaArgumentos1e2(args, "", "")) {
    atribMemIP(0xf4);
  } else {
    erro("Argumento inválido.");
  }
}

void diretEQU(char rotulo[], char args[][TAM_LINHA]) {
  if (passo == 1) {
    if (verificaArgumentos1e2(args, "l", "")) {
      if (!insereIdent(rotulo, args[0])) {
        erro("O rotulo ja' foi declarado anteriormente.");
      }
    } else {
      erro("Argumento inválido.");
    }
  }
}

void diretORG(char rotulo[], char args[][TAM_LINHA]) {
  if (verificaArgumentos1e2(args, "l", "")) {
    IP = convParaInt(args[0]);
  } else {
    erro("Argumento inválido.");
  }
}

void diretDB(char rotulo[], char args[][TAM_LINHA]) {
  int i = 0;
  while (verificaArgumento(args[i], "l")) {
    atribMemIP(convParaInt(args[i]));
    i++;
  }
  if (args[i][0] != '\0') {
    erro("Argumento inválido.");
  }
}

void diretEND(char rotulo[], char args[][TAM_LINHA]) {
  if (verificaArgumentos1e2(args, "", "")) {
    ENDEncontrado = 1;
  } else {
    erro("Argumento inválido.");
  }
}

void monta(char rotulo[], CodMnemoDiret mnemo, char args[][TAM_LINHA]) {
  switch (mnemo) {
  case EQU:
    diretEQU(rotulo, args);
    break;
  case ORG:
    diretORG(rotulo, args);
    break;
  case DB:
    diretDB(rotulo, args);
    break;
  case END:
    diretEND(rotulo, args);
    break;
  case ADD:
    mnemoADD(args);
    break;
  case SUB:
    mnemoSUB(args);
    break;
  case CMP:
    mnemoCMP(args);
    break;
  case MOV:
    mnemoMOV(args);
    break;
  case INC:
    mnemoINC(args);
    break;
  case DEC:
    mnemoDEC(args);
    break;
  case CALL:
    mnemoCALL(args);
    break;
  case RET:
    mnemoRET(args);
    break;
  case HLT:
    mnemoHLT(args);
    break;
  case JMP:
  case JC:
  case JNC:
  case JZ:
  case JNZ:
  case JBE:
  case JA:
    mnemoJUMP(mnemo, args);
  }
}

void atribuiRotulo(char rotulo[], CodMnemoDiret mnemo) {
  // label que não é definido por EQU
  if (rotulo[0] != '\0' && mnemo != EQU) {
    char val[TAM_LINHA];
    sprintf(val, "%d", IP);
    if (!insereIdent(rotulo, val)) {
      erro("O rotulo ja' foi declarado anteriormente.");
    }
  }
}

void comoUsar() {
  printf("Como usar este programa:\n  montador arq_entrada [arq_saida]\n");
}

int retiraExtensaoASM(char nome[]) {
  int tam = strlen(nome);
  if (nome[tam - 4] == '.' && nome[tam - 3] == 'a' && nome[tam - 2] == 's' &&
      nome[tam - 1] == 'm') {
    nome[tam - 4] = '\0';
    return 1;
  }
  return 0;
}

void abreArquivos(int argc, char *argv[]) {
  char nomeLst[1024];
  char nomeSai[1024];
  char nomeAsm[1024];

  if (retiraExtensaoASM(argv[1])) {
    sprintf(nomeAsm, "%s.asm", argv[1]);
  } else {
    strcpy(nomeAsm, argv[1]);
  }
  if (argc == 2) {
    sprintf(nomeSai, "%s.sai", argv[1]);
  } else {
    strcpy(nomeSai, argv[2]);
  }
  sprintf(nomeLst, "%s.lst", argv[1]);
  fpEnt = fopen(nomeAsm, "rt");
  if (fpEnt == NULL) {
    printf("Erro na abertura do arquivo %s.\n", nomeAsm);
  }
  fpSai = fopen(nomeSai, "wt");
  if (fpSai == NULL) {
    printf("Erro na abertura do arquivo %s.\n", nomeSai);
    fclose(fpEnt);
    exit(1);
  }
  fpLst = fopen(nomeLst, "wt");
  if (fpLst == NULL) {
    printf("Erro na abertura do arquivo %s.\n", nomeLst);
    fclose(fpEnt);
    fclose(fpSai);
    exit(1);
  }
  fprintf(fpLst, "Listagem da montagem do arquivo %s\n\n", nomeAsm);
}

int main(int argc, char *argv[]) {
  char linha[TAM_LINHA];
  char rotulo[TAM_LINHA];
  char mnemo[TAM_LINHA];
  char args[256][TAM_LINHA];
  char coment[TAM_LINHA];
  CodMnemoDiret codMneDir;

  int i;
  if (argc < 2 || argc > 3) {
    comoUsar();
    exit(1);
  }

  abreArquivos(argc, argv);

  for (passo = 1; passo < 3; passo++) {
    printf("Passo %d\n", passo);
    indLinha = 0;
    ENDEncontrado = 0;
    IP = 0;
    while (fgets(linha, TAM_LINHA, fpEnt)) {
      int tam = strlen(linha);
      if (iscntrl(linha[tam - 1]))
        linha[tam - 1] = '\0';
      indLinha++;
      // if (indLinha == 30) {
      //   printf("debug");
      // }
      if (passo == 2) {
        fprintf(fpLst, "%3d: %s \n", indLinha, linha);
      }

      divide(linha, rotulo, mnemo, args, coment);
      codMneDir = codMnemoDiret(mnemo);

      if (passo == 1) {
        if (ENDEncontrado) {
          continue;
        }
        atribuiRotulo(rotulo, codMneDir);
      } else {
        if (ENDEncontrado &&
            (rotulo[0] != '\0' || mnemo[0] != '\0' || args[0][0] != '\0')) {
          aviso("As linha apos a diretiva END serao ignoradas.");
        }
      }

      monta(rotulo, codMneDir, args);
    }

    if (passo == 1) {
      fprintf(fpLst, "Tabela de simbolos:\n");
      // Imprime os rotulos
      for (i = 0; i < indRotulo; i++) {
        fprintf(fpLst, "%15s %4s\n", vIdent[i], vValor[i]);
      }
      fprintf(fpLst, "\nPrograma e montagem:\n");
      rewind(fpEnt);
    } else {
      // Salva opcodes
      for (i = 0; i < 256; i++) {
        fprintf(fpSai, "%02xh\n", mem[i]);
      }
    }
  }

  fclose(fpSai);
  fclose(fpEnt);
  fclose(fpLst);
  return 0;
}
