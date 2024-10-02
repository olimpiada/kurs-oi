// Autor: Bart³omiej Wo³owiec
// Zadanie: Ta¶ma

/*
 * Przyk³adowy weryfikator danych wej¶ciowych
 * (nale¿y zmieniæ funkcjê InputChecker::check())
 *
 * Autor: Tomasz Czajka, 2002
 * Modyfikacje: Piotr Nied¿wied¿, 2008
 */
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <vector>
using namespace std;

#define TOKEN_STD       0
#define TOKEN_EOF      -1
#define TOKEN_EOLN     -2
#define TOKEN_DOS_EOLN -3
#define TOKEN_SPACE    -4
#define TOKEN_TAB      -5
#define MAX_TOKEN_LEN 512

class TextFile {
  public:
    TextFile();
    ~TextFile();
    int init(const char *filename);
    int compare(TextFile *t);
    int getToken(char *token, int max_len);
    int eof();  
    int readInt(int min,int max);
    int readEof();
    int readSpace();  
    int readEoln();
    int readEolnOrEof();
    int error(const char *message);
    /* JRAD: */
    void spr();

  private:
    FILE *f;
    int line;
    int tno;
    char *token2str(int token, char *t_str);
    int err(const char *expectedtoken, char *readtoken);
};


#define WHITE(ch) (ch==' ' || ch=='\t' || ch==13 || ch==EOF)
#define WHITE_OR_EOLN(ch) (ch==' ' || ch=='\t' || ch==13 || ch=='\n' || ch==EOF)

// ----------------------------------------------------------------------

class InputChecker : public TextFile {
  public:
    int check();
};


int main(int argc, char *argv[]) {
  InputChecker *ic;


  ic=new InputChecker;

  if (argc==2) {
    if (ic->init(argv[1])) {
      fprintf(stderr,"can't open: %s\n",argv[1]);
      return 1;
    }
  } else {
    if (ic->init("")) {
      fprintf(stderr,"can't open: stdin\n");	
    }
  }

  ic->check();
  return 0;
}

//----
/**
 * Klasa wspomagaj±ca obs³ugê plików tekstowych
 */

/**
 * Konstruktor, inicjalizacja wewnêtrznych struktur
 */
TextFile::TextFile() {
  f=NULL;
  line=1;
  tno=0;
}

/**
 * Destruktor, zamkniêcie pliku
 */
TextFile::~TextFile() {
  if (f!=NULL) fclose(f);
}

/**
 * Otworzenie pliku
 * @param filename nazwa pliku
 */
int TextFile::init(const char *filename) {
  if (strlen(filename)) {
    f=fopen(filename,"r");
    if (f==NULL) return -1;
  } else {
    f=stdin;
  }
  return 0;
}

/**
 * Pobranie pojedynczego tokena z pliku
 * @param token wska¼nik do miejsca na wynik
 * @param max_len maksymalna d³ugo¶æ wyniku
 */
int TextFile::getToken(char *token,int max_len) {
  int i;
  int ch;

  token[0]=0;

  // omijanie bialych znakow
  ch=EOF;
  if (!feof(f)) ch=fgetc(f);

  if (ch==EOF)   return TOKEN_EOF;
  if (ch==' ')   return TOKEN_SPACE;
  if (ch=='\t')  return TOKEN_TAB;
  if (ch=='\n')  return TOKEN_EOLN;
  if (ch==13)    return TOKEN_DOS_EOLN;

  i=0;
  while (!WHITE_OR_EOLN(ch)) {
    token[i]=ch;
    i++;
    if (feof(f)) break;
    if (i==max_len-1) break;
    ch=fgetc(f);
  }
  token[i]=0;

  if (WHITE_OR_EOLN(ch)) ungetc(ch,f);

  tno++;
  return TOKEN_STD;
}

int TextFile::readInt(int min,int max) {
  char buf[11];  
  int token=getToken(buf,sizeof(buf));
  if (token!=TOKEN_STD) {
    err("Int",token2str(token,buf));
  }
  // teraz trzeba policzyc wartosc
  long long value=0;
  int minus=0;
  int i,n;
  i=0;n=strlen(buf);
  if (buf[0]=='-') { i++; minus=1; }
  while (i<n) {
    if (buf[i]<'0' || buf[i]>'9')        err("Int",buf);
    if (buf[i]=='0' && value==0 && n!=1) err("Int",buf);
    value=value*10+(buf[i]-'0');
    if (value>LONG_MAX)  err("Int",buf);
    i++;
  }
  if (minus) value=-value;
  char int_desc[100];
  snprintf(int_desc,sizeof(int_desc),"Int[%d,%d]",min,max);
  if (value>max || value<min) err(int_desc,buf);
  return value;
}

int TextFile::readEoln() {  
  char buf[100];
  int token=getToken(buf,sizeof(buf));
  if (token!=TOKEN_EOLN) err("EOLN",token2str(token,buf));
  line++;tno=0;
  return 0;
}

int TextFile::readEof() {  
  char buf[100];
  int token=getToken(buf,sizeof(buf));
  if (token!=TOKEN_EOF) err("EOF",token2str(token,buf));
  return 0;
}

int TextFile::readSpace() {  
  char buf[100];
  int token=getToken(buf,sizeof(buf));
  if (token!=TOKEN_SPACE) err("SPACE",token2str(token,buf));
  return 0;
}

int TextFile::readEolnOrEof() {
  char buf[100];
  int token=getToken(buf,sizeof(buf));
  if (token!=TOKEN_EOLN && token!=TOKEN_EOF) 
    err("EOLN_OR_EOF",token2str(token,buf));
  if (token==TOKEN_EOLN) {
    line++;tno=0;
  }
  return token;
}

/**
 * Czy osi±gniêto koniec pliku
 */
int TextFile::eof() {
  return feof(f);
}

char *TextFile::token2str(int token, char *t_str) {
  static char buf[1024];
  bzero(&buf,sizeof(buf));
  switch(token) {
    case TOKEN_STD:   strncpy(buf,t_str,sizeof(buf)-1); break;
    case TOKEN_EOF:   sprintf(buf,"EOF");   break;
    case TOKEN_EOLN:  sprintf(buf,"EOLN");  break;
    case TOKEN_SPACE: sprintf(buf,"SPACE"); break;
    case TOKEN_TAB:   sprintf(buf,"TAB");   break;
    case TOKEN_DOS_EOLN: sprintf(buf,"DOS_EOLN");  break;
    default:
                         sprintf(buf,"UNKNOWN");
  }
  return (char *)&buf;
}

int TextFile::err(const char *expectedtoken, char *readtoken) {  
  fprintf(stdout,"ERROR[line:%d,token:%d] expected: %s, read: %s\n",
      line,tno,expectedtoken,readtoken);
  exit(1);
}

int TextFile::error(const char *message) 
{

  fprintf(stdout,"ERROR[line:%d] %s\n",
      line,message);
  exit(1);
}

// Autor: Bart³omiej Wo³owiec
// Zadanie: Ta¶ma

#define MIN_N 1
#define MAX_N 500000
#define MIN_A 1
#define MAX_A (int)1e9

int InputChecker::check()
{
    vector<int> v;
    int n;
        n = readInt(MIN_N, MAX_N);
        v.push_back(n);
        readEoln();
        for(int j=0; j<n; j++){
            if(j) readSpace();
            readInt(MIN_A, MAX_A);
        }
        readEoln();
    readEof();
    printf("OK %d\n",n);
    return 0;
}
