// Detecta Windows

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h> // para usleep() e POSIX funções
#endif

void limpar_tela();
void pausar_tela();
void locale_UTF();
void criar_menu();